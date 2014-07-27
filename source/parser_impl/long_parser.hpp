/*
 * long_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class long_parser
:
	public qi::grammar<input_iterator, long_t()>
{
public:
	long_parser();

private:
	qi::rule<input_iterator, long_t()> _long;
	qi::rule<input_iterator, long_t()> _long_1;
	qi::rule<input_iterator, long_t()> _long_2;
	qi::rule<input_iterator, long_t()> _long_3;
	qi::rule<input_iterator, long_t()> _long_4;
	qi::rule<input_iterator, long_t()> _long_5;
};

}
}
