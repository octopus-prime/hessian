/*
 * type_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "type_parser.hpp"
#include <boost/spirit/include/qi.hpp>

namespace hessian {
namespace parser_impl {

type_parser::type_parser()
:
	type_parser::base_type(_type),
	_type(),
	_int(),
	_string()
{
	_type =
			_int
			|
			_string
	;
}

}
}
