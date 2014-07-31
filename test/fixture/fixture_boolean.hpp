/*
 * fixture_boolean.hpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace fixture {

struct fixture_boolean
{
	static const boolean_t boolean_true;
	static const boolean_t boolean_false;

	static const string_t hessian_true;
	static const string_t hessian_false;
};

}
}
