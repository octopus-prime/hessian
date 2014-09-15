/*
 * fixture_long.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
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

const std::string fixture_long::hessian_0 = std::string("\xe0", 1);
const std::string fixture_long::hessian_1 = std::string("\xe1", 1);
const std::string fixture_long::hessian_15 = std::string("\xef", 1);
const std::string fixture_long::hessian_m8 = std::string("\xd8", 1);
const std::string fixture_long::hessian_0x10 = std::string("\xf8\x10", 2);
const std::string fixture_long::hessian_0x7ff = std::string("\xff\xff", 2);
const std::string fixture_long::hessian_m9 = std::string("\xf7\xf7", 2);
const std::string fixture_long::hessian_m0x800 = std::string("\xf0\x00", 2);
const std::string fixture_long::hessian_0x800 = std::string("\x3c\x08\x00", 3);
const std::string fixture_long::hessian_m0x801 = std::string("\x3b\xf7\xff", 3);
const std::string fixture_long::hessian_0x3ffff = std::string("\x3f\xff\xff", 3);
const std::string fixture_long::hessian_m0x40000 = std::string("\x38\x00\x00", 3);
const std::string fixture_long::hessian_0x40000 = std::string("Y\x00\x04\x00\x00", 5);
const std::string fixture_long::hessian_m0x40001 = std::string("Y\xff\xfb\xff\xff", 5);
const std::string fixture_long::hessian_0x7fffffff = std::string("Y\x7f\xff\xff\xff", 5);
const std::string fixture_long::hessian_m0x80000000 = std::string("Y\x80\x00\x00\x00", 5);
const std::string fixture_long::hessian_0x80000000 = std::string("L\x00\x00\x00\x00\x80\x00\x00\x00", 9);
const std::string fixture_long::hessian_m0x80000001 = std::string("L\xff\xff\xff\xff\x7f\xff\xff\xff", 9);

}
}
