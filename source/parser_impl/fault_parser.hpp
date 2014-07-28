/*
 * fault_parser.hpp
 *
 *  Created on: 25.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <hessian/parser.hpp>
#include "input_iterator.hpp"
#include "value_parser.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class fault_parser
:
	public qi::grammar<input_iterator_t, fault_t()>
{
public:
	fault_parser();

private:
	qi::rule<input_iterator_t, fault_t()> _fault;
	value_parser _value;
};

}
}
