/*
 * fixture_long.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_long.hpp"

namespace hessian {
namespace fixture {

const long_t fixture_long::long_0 = long_t(0LL);
const long_t fixture_long::long_1 = long_t(1LL);
const long_t fixture_long::long_15 = long_t(15LL);
const long_t fixture_long::long_m8 = long_t(-8LL);
const long_t fixture_long::long_0x10 = long_t(0x10LL);
const long_t fixture_long::long_0x7ff = long_t(0x7ffLL);
const long_t fixture_long::long_m9 = long_t(-9LL);
const long_t fixture_long::long_m0x800 = long_t(-0x800LL);
const long_t fixture_long::long_0x800 = long_t(0x800LL);
const long_t fixture_long::long_m0x801 = long_t(-0x801LL);
const long_t fixture_long::long_0x3ffff = long_t(0x3ffffLL);
const long_t fixture_long::long_m0x40000 = long_t(-0x40000LL);
const long_t fixture_long::long_0x40000 = long_t(0x40000LL);
const long_t fixture_long::long_m0x40001 = long_t(-0x40001LL);
const long_t fixture_long::long_0x7fffffff = long_t(0x7fffffffLL);
const long_t fixture_long::long_m0x80000000 = long_t(-0x80000000LL);
const long_t fixture_long::long_0x80000000 = long_t(0x80000000LL);
const long_t fixture_long::long_m0x80000001 = long_t(-0x80000001LL);

const string_t fixture_long::hessian_0 = string_t("\xe0", 1);
const string_t fixture_long::hessian_1 = string_t("\xe1", 1);
const string_t fixture_long::hessian_15 = string_t("\xef", 1);
const string_t fixture_long::hessian_m8 = string_t("\xd8", 1);
const string_t fixture_long::hessian_0x10 = string_t("\xf8\x10", 2);
const string_t fixture_long::hessian_0x7ff = string_t("\xff\xff", 2);
const string_t fixture_long::hessian_m9 = string_t("\xf7\xf7", 2);
const string_t fixture_long::hessian_m0x800 = string_t("\xf0\x00", 2);
const string_t fixture_long::hessian_0x800 = string_t("\x3c\x08\x00", 3);
const string_t fixture_long::hessian_m0x801 = string_t("\x3b\xf7\xff", 3);
const string_t fixture_long::hessian_0x3ffff = string_t("\x3f\xff\xff", 3);
const string_t fixture_long::hessian_m0x40000 = string_t("\x38\x00\x00", 3);
const string_t fixture_long::hessian_0x40000 = string_t("Y\x00\x04\x00\x00", 5);
const string_t fixture_long::hessian_m0x40001 = string_t("Y\xff\xfb\xff\xff", 5);
const string_t fixture_long::hessian_0x7fffffff = string_t("Y\x7f\xff\xff\xff", 5);
const string_t fixture_long::hessian_m0x80000000 = string_t("Y\x80\x00\x00\x00", 5);
const string_t fixture_long::hessian_0x80000000 = string_t("L\x00\x00\x00\x00\x80\x00\x00\x00", 9);
const string_t fixture_long::hessian_m0x80000001 = string_t("L\xff\xff\xff\xff\x7f\xff\xff\xff", 9);

}
}
