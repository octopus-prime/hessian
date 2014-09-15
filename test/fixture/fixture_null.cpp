/*
 * fixture_null.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_null.hpp"

namespace hessian {
namespace fixture {

const null_t fixture_null::null = null_t();

const std::string fixture_null::hessian = std::string("N", 1);

}
}
