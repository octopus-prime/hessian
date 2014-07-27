/*
 * terminal_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include "null_parser.hpp"
#include "boolean_parser.hpp"
#include "int_parser.hpp"
#include "long_parser.hpp"
#include "double_parser.hpp"
#include "date_parser.hpp"
#include "string_parser.hpp"
#include "binary_parser.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class terminal_parser
:
	public qi::grammar<input_iterator, value_t()>
{
public:
	terminal_parser();

private:
	qi::rule<input_iterator, value_t()> _value;
	null_parser _null;
	boolean_parser _boolean;
	int_parser _int;
	long_parser _long;
	double_parser _double;
	date_parser _date;
	string_parser _string;
	binary_parser _binary;
};

}
}
