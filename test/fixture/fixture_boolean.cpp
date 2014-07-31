/*
 * fixture_boolean.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_boolean.hpp"

namespace hessian {
namespace fixture {

const boolean_t fixture_boolean::boolean_true = boolean_t(true);
const boolean_t fixture_boolean::boolean_false = boolean_t(false);

const string_t fixture_boolean::hessian_true = string_t("T", 1);
const string_t fixture_boolean::hessian_false = string_t("F", 1);

}
}
