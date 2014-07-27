/*
 * type_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include "int_parser.hpp"
#include "string_parser.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class type_parser
:
	public qi::grammar<input_iterator, void()>
{
public:
	type_parser();

private:
	qi::rule<input_iterator, void()> _type;
	int_parser _int;
	string_parser _string;
};

}
}
