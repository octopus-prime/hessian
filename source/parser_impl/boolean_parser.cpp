/*
 * boolean_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "boolean_parser.hpp"

namespace hessian {
namespace parser_impl {

boolean_parser::boolean_parser()
:
	qi::symbols<char, boolean_t>()
{
	add
		("T", true)
		("F", false)
	;
}

}
}
