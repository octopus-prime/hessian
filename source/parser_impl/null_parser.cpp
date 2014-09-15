/*
 * null_parser.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "null_parser.hpp"

namespace hessian {
namespace parser_impl {

null_parser::null_parser()
:
	qi::symbols<char, null_t>()
{
	add
		("N", null_t())
	;
}

}
}
