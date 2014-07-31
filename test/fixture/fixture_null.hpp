/*
 * fixture_null.hpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace fixture {

struct fixture_null
{
	static const null_t null;

	static const string_t hessian;
};

}
}
