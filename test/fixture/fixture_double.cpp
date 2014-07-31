/*
 * fixture_double.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_double.hpp"

namespace hessian {
namespace fixture {

const double_t fixture_double::double_0_0 = double_t(0.0);
const double_t fixture_double::double_1_0 = double_t(1.0);
const double_t fixture_double::double_2_0 = double_t(2.0);
const double_t fixture_double::double_127_0 = double_t(127.0);
const double_t fixture_double::double_m128_0 = double_t(-128.0);
const double_t fixture_double::double_128_0 = double_t(128.0);
const double_t fixture_double::double_m129_0 = double_t(-129.0);
const double_t fixture_double::double_32767_0 = double_t(32767.0);
const double_t fixture_double::double_m32768_0 = double_t(-32768.0);
const double_t fixture_double::double_0_001 = double_t(0.001);
const double_t fixture_double::double_m0_001 = double_t(-0.001);
const double_t fixture_double::double_65_536 = double_t(65.536);
const double_t fixture_double::double_3_14159 = double_t(3.14159);

const string_t fixture_double::hessian_0_0 = string_t("\x5b", 1);
const string_t fixture_double::hessian_1_0 = string_t("\x5c", 1);
const string_t fixture_double::hessian_2_0 = string_t("\x5d\x02", 2);
const string_t fixture_double::hessian_127_0 = string_t("\x5d\x7f", 2);
const string_t fixture_double::hessian_m128_0 = string_t("\x5d\x80", 2);
const string_t fixture_double::hessian_128_0 = string_t("\x5e\x00\x80", 3);
const string_t fixture_double::hessian_m129_0 = string_t("\x5e\xff\x7f", 3);
const string_t fixture_double::hessian_32767_0 = string_t("\x5e\x7f\xff", 3);
const string_t fixture_double::hessian_m32768_0 = string_t("\x5e\x80\x00", 3);
const string_t fixture_double::hessian_0_001 = string_t("\x5f\x00\x00\x00\x01", 5);
const string_t fixture_double::hessian_m0_001 = string_t("\x5f\xff\xff\xff\xff", 5);
const string_t fixture_double::hessian_65_536 = string_t("\x5f\x00\x01\x00\x00", 5);
const string_t fixture_double::hessian_3_14159 = string_t("D\x40\x09\x21\xf9\xf0\x1b\x86\x6e", 9);

}
}
