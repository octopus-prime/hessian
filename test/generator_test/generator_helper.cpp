/*
 * generator_helper.cpp
 *
 *  Created on: 30.07.2014
 *      Author: mgresens
 */

#include "generator_helper.hpp"

namespace hessian {
namespace generator_test {

std::string
generate_call(const list_t& arguments)
{
	std::ostringstream stream;
	generator generate(stream);
	generate(L"method", arguments);
	return stream.str();
}

}
}
