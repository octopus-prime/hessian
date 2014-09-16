/*
 * reply_parser.cpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include <hessian/parser.hpp>
#include "parser_impl/input_iterator.hpp"
#include "parser_impl/version_parser.hpp"
#include "parser_impl/reply_parser.hpp"
#include "parser_impl/fault_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/format.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {

typedef qi::expectation_failure<boost::spirit::istream_iterator> expectation_failure;

class parser_expectation_exception
:
	public virtual parser_exception
{
public:
	parser_expectation_exception(const expectation_failure& failure);
	virtual ~parser_expectation_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;

protected:
	static std::string build(const expectation_failure& failure);

private:
	std::string _what;
};

class parser_failure_exception
:
	public parser_exception
{
public:
	parser_failure_exception();
	virtual ~parser_failure_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;
};

parser::parser(std::istream& stream)
:
	_stream(stream)
{
	_stream.unsetf(std::ios::skipws);
}

content_t
parser::operator()()
{
	parser_impl::version_parser version;
	parser_impl::reply_parser reply;
	parser_impl::fault_parser fault;

	parser_impl::input_iterator_t begin(_stream);
	parser_impl::input_iterator_t end;

	content_t content;

	try
	{
		const bool success = qi::parse
		(
			begin, end,
			version
			>>
			(
				reply
				|
				fault
			),
			content
		);

		if (!success || begin != end)
			throw parser_failure_exception();
	}
	catch(const expectation_failure& failure)
	{
		throw parser_expectation_exception(failure);
	}

	return content;
}

parser_expectation_exception::parser_expectation_exception(const expectation_failure& failure)
:
	parser_exception(),
	_what(build(failure))
{
}

const char*
parser_expectation_exception::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _what.c_str();
}

std::string
parser_expectation_exception::build(const expectation_failure& failure)
{
	boost::format what("Expected %s but found \"%s\".");
	what % failure.what_;
	what % std::string(failure.first, failure.last);
	return what.str();
}

parser_failure_exception::parser_failure_exception()
:
	parser_exception()
{
}

const char*
parser_failure_exception::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return "Parsing failed.";
}

}
