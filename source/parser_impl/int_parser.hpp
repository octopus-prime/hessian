/*
 * int_parser.hpp
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

class int_parser
:
	public qi::grammar<input_iterator_t, int_t()>
{
public:
	int_parser();

private:
	qi::rule<input_iterator_t, int_t()> _int;
	qi::rule<input_iterator_t, int_t()> _int_1;
	qi::rule<input_iterator_t, int_t()> _int_2;
	qi::rule<input_iterator_t, int_t()> _int_3;
	qi::rule<input_iterator_t, int_t()> _int_4;
};

}
}
