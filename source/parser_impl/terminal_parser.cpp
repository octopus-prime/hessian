/*
 * terminal_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "terminal_parser.hpp"
#include <boost/spirit/include/qi.hpp>

namespace hessian {
namespace parser_impl {

terminal_parser::terminal_parser()
:
	terminal_parser::base_type(_value),
	_value(),
	_null(),
	_boolean(),
	_int(),
	_long(),
	_double(),
	_date(),
	_string(),
	_binary()
{
	_value =
			_null
			|
			_boolean
			|
			_int
			|
			_long
			|
			_double
			|
			_date
			|
			_string
			|
			_binary
	;
}

}
}
