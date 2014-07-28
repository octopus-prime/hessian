/*
 * date_parser.hpp
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

class date_parser
:
	public qi::grammar<input_iterator_t, date_t()>
{
public:
	date_parser();

private:
	qi::rule<input_iterator_t, date_t()> _date;
	qi::rule<input_iterator_t, date_t()> _date_1;
	qi::rule<input_iterator_t, date_t()> _date_2;
};

}
}
