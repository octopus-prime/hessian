/*
 * boolean_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "boolean_generator.hpp"

namespace hessian {
namespace generator_impl {

boolean_generator::boolean_generator()
:
	ka::symbols<boolean_t, char const*>()
{
	add
		(true,	"T")
		(false,	"F")
	;
}

}
}
