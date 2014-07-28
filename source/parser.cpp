/*
 * reply_parser.cpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#include <hessian/parser.hpp>
#include "parser_impl/input_iterator.hpp"
#include "parser_impl/version_parser.hpp"
#include "parser_impl/reply_parser.hpp"
#include "parser_impl/fault_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/format.hpp>
#include <stdexcept>

namespace qi = boost::spirit::qi;

namespace hessian {

typedef qi::expectation_failure<boost::spirit::istream_iterator> expectation_failure;

class expectation_exception
:
	public parser_exception
{
public:
	expectation_exception(const expectation_failure& failure);
	virtual ~expectation_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;

protected:
	static std::string build(const expectation_failure& failure);

private:
	std::string _what;
};

parser::parser(std::istream& stream)
:
	_stream(stream)
{
}

content_t
parser::operator()()
{
	parser_impl::version_parser version;
	parser_impl::reply_parser reply;
	parser_impl::fault_parser fault;

	content_t content;

	try
	{
		const bool success = qi::parse
		(
			parser_impl::input_iterator_t(_stream), parser_impl::input_iterator_t(),
			qi::eps
			>
			version
			>
			(
				reply
				|
				fault
			),
			content
		);

		if (!success)
			throw std::runtime_error("failed");
	}
	catch(const expectation_failure& failure)
	{
		throw expectation_exception(failure);
	}

	return content;
}

expectation_exception::expectation_exception(const expectation_failure& failure)
:
	parser_exception(),
	_what(build(failure))
{
}

const char*
expectation_exception::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _what.c_str();
}

std::string
expectation_exception::build(const expectation_failure& failure)
{
	boost::format what("Expected %s but found \"%s\".");
	what % failure.what_;
	what % std::string(failure.first, failure.last);
	return what.str();
}

}
