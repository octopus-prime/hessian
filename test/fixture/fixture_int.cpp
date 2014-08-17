/*
 * fixture_int.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_int.hpp"

namespace hessian {
namespace fixture {

const int_t fixture_int::int_0 = int_t(0);
const int_t fixture_int::int_1 = int_t(1);
const int_t fixture_int::int_47 = int_t(47);
const int_t fixture_int::int_m16 = int_t(-16);
const int_t fixture_int::int_m17 = int_t(-17);
const int_t fixture_int::int_0x30 = int_t(0x30);
const int_t fixture_int::int_0x7ff = int_t(0x7ff);
const int_t fixture_int::int_m0x800 = int_t(-0x800);
const int_t fixture_int::int_0x800 = int_t(0x800);
const int_t fixture_int::int_m0x801 = int_t(-0x801);
const int_t fixture_int::int_0x3ffff = int_t(0x3ffff);
const int_t fixture_int::int_m0x40000 = int_t(-0x40000);
const int_t fixture_int::int_0x40000 = int_t(0x40000);
const int_t fixture_int::int_m0x40001 = int_t(-0x40001);
const int_t fixture_int::int_0x7fffffff = int_t(0x7fffffff);
const int_t fixture_int::int_m0x80000000 = int_t(-0x80000000);

const std::string fixture_int::hessian_0 = std::string("\x90", 1);
const std::string fixture_int::hessian_1 = std::string("\x91", 1);
const std::string fixture_int::hessian_47 = std::string("\xbf", 1);
const std::string fixture_int::hessian_m16 = std::string("\x80", 1);
const std::string fixture_int::hessian_m17 = std::string("\xc7\xef", 2);
const std::string fixture_int::hessian_0x30 = std::string("\xc8\x30", 2);
const std::string fixture_int::hessian_0x7ff = std::string("\xcf\xff", 2);
const std::string fixture_int::hessian_m0x800 = std::string("\xc0\x00", 2);
const std::string fixture_int::hessian_0x800 = std::string("\xd4\x08\x00", 3);
const std::string fixture_int::hessian_m0x801 = std::string("\xd3\xf7\xff", 3);
const std::string fixture_int::hessian_0x3ffff = std::string("\xd7\xff\xff", 3);
const std::string fixture_int::hessian_m0x40000 = std::string("\xd0\x00\x00", 3);
const std::string fixture_int::hessian_0x40000 = std::string("I\x00\x04\x00\x00", 5);
const std::string fixture_int::hessian_m0x40001 = std::string("I\xff\xfb\xff\xff", 5);
const std::string fixture_int::hessian_0x7fffffff = std::string("I\x7f\xff\xff\xff", 5);
const std::string fixture_int::hessian_m0x80000000 = std::string("I\x80\x00\x00\x00", 5);

}
}
