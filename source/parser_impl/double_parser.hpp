/*
 * double_parser.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_symbols.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class double_parser
:
	public qi::grammar<input_iterator_t, double_t()>
{
public:
	double_parser();

private:
	qi::rule<input_iterator_t, double_t()> _double;
	qi::symbols<char, double_t> _double_1;
	qi::rule<input_iterator_t, double_t()> _double_2;
	qi::rule<input_iterator_t, double_t()> _double_3;
	qi::rule<input_iterator_t, double_t()> _double_4;
	qi::rule<input_iterator_t, double_t()> _double_5;
};

}
}
