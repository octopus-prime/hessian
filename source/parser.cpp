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

class expectation_exception
:
	public parser_exception
{
public:
	expectation_exception(const qi::expectation_failure<boost::spirit::istream_iterator>& exception)
	:
		parser_exception(),
		_what(build(exception))
	{
	}

	virtual ~expectation_exception() BOOST_NOEXCEPT_OR_NOTHROW {}

	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW
	{
		return _what.c_str();
	}

protected:
	static std::string build(const qi::expectation_failure<boost::spirit::istream_iterator>& exception)
	{
		boost::format what("Expected %s but found \"%s\".");
		what % exception.what_;
		what % std::string(exception.first, exception.last);
		return what.str();
	}

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
			parser_impl::input_iterator(_stream), parser_impl::input_iterator(),
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
	catch(const qi::expectation_failure<parser_impl::input_iterator>& exception)
	{
		throw expectation_exception(exception);
	}

	return content;
}

}
