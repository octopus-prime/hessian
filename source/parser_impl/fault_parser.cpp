/*
 * fault_parser.cpp
 *
 *  Created on: 25.07.2014
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "fault_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

static const map_t&
to_map(const value_t& value)
{
	return boost::get<map_t>(value);
}

fault_parser::fault_parser()
:
	fault_parser::base_type(_fault),
	_fault(),
	_value()
{
	_fault =
			qi::lit("F")
			>>
			_value 										[qi::_val = px::bind(to_map, qi::_1)];
	;
}

}
}
