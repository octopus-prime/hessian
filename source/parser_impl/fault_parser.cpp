/*
 * fault_parser.cpp
 *
 *  Created on: 25.07.2014
 *      Author: mike_gresens
 */

#include "fault_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

fault_parser::fault_parser()
:
	fault_parser::base_type(_fault),
	_fault(std::string("'F'")),
	_value()
{
	_fault =
			qi::lit('F')
			>
			*(
				(_value - qi::lit('Z'))
				>
				_value
			)
			>
			qi::lit('Z')
	;
}

}
}
