/*
 * null_generator.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "null_generator.hpp"

namespace hessian {
namespace generator_impl {

null_generator::null_generator()
:
	ka::symbols<null_t, char const*>()
{
	add (null_t(), "N");
}

}
}
