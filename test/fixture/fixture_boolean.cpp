/*
 * fixture_boolean.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_boolean.hpp"

namespace hessian {
namespace fixture {

const boolean_t fixture_boolean::boolean_true = boolean_t(true);
const boolean_t fixture_boolean::boolean_false = boolean_t(false);

const std::string fixture_boolean::hessian_true = std::string("T", 1);
const std::string fixture_boolean::hessian_false = std::string("F", 1);

}
}
