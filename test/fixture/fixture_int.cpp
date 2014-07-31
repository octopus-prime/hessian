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

const string_t fixture_int::hessian_0 = string_t("\x90", 1);
const string_t fixture_int::hessian_1 = string_t("\x91", 1);
const string_t fixture_int::hessian_47 = string_t("\xbf", 1);
const string_t fixture_int::hessian_m16 = string_t("\x80", 1);
const string_t fixture_int::hessian_m17 = string_t("\xc7\xef", 2);
const string_t fixture_int::hessian_0x30 = string_t("\xc8\x30", 2);
const string_t fixture_int::hessian_0x7ff = string_t("\xcf\xff", 2);
const string_t fixture_int::hessian_m0x800 = string_t("\xc0\x00", 2);
const string_t fixture_int::hessian_0x800 = string_t("\xd4\x08\x00", 3);
const string_t fixture_int::hessian_m0x801 = string_t("\xd3\xf7\xff", 3);
const string_t fixture_int::hessian_0x3ffff = string_t("\xd7\xff\xff", 3);
const string_t fixture_int::hessian_m0x40000 = string_t("\xd0\x00\x00", 3);
const string_t fixture_int::hessian_0x40000 = string_t("I\x00\x04\x00\x00", 5);
const string_t fixture_int::hessian_m0x40001 = string_t("I\xff\xfb\xff\xff", 5);
const string_t fixture_int::hessian_0x7fffffff = string_t("I\x7f\xff\xff\xff", 5);
const string_t fixture_int::hessian_m0x80000000 = string_t("I\x80\x00\x00\x00", 5);

}
}
