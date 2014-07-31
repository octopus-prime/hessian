/*
 * fixture_object.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_object.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::map_list_of;
using boost::assign::list_of;

namespace hessian {
namespace fixture {

const object_t fixture_object::object_0 = object_t();
const object_t fixture_object::object_1 = map_list_of<string_t, int_t>("_value", 0);
const list_t fixture_object::object_2 = list_of<object_t>(object_1)(map_list_of<string_t, int_t>("_value", 1));
const list_t fixture_object::object_2a = list_of<object_t>(object_1)(object_1);
const list_t fixture_object::object_2b = list_of<object_t>(object_1)(object_1);
const list_t fixture_object::object_16 = list_of<object_t>()()()()()()()()()()()()()()()()();

const string_t fixture_object::hessian_0 = string_t("C""\x1a""com.caucho.hessian.test.A0""\x90""\x60");
const string_t fixture_object::hessian_1 = string_t("C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90");
const string_t fixture_object::hessian_2 = string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""\x60""\x91");
const string_t fixture_object::hessian_2a = string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""Q""\x91");
const string_t fixture_object::hessian_2b = string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""\x60""\x90");
const string_t fixture_object::hessian_16 = 	string_t
(
	"X""\xa1"
	"C""\x1a""com.caucho.hessian.test.A0""\x90""\x60"
	"C""\x1a""com.caucho.hessian.test.A1""\x90""\x61"
	"C""\x1a""com.caucho.hessian.test.A2""\x90""\x62"
	"C""\x1a""com.caucho.hessian.test.A3""\x90""\x63"
	"C""\x1a""com.caucho.hessian.test.A4""\x90""\x64"
	"C""\x1a""com.caucho.hessian.test.A5""\x90""\x65"
	"C""\x1a""com.caucho.hessian.test.A6""\x90""\x66"
	"C""\x1a""com.caucho.hessian.test.A7""\x90""\x67"
	"C""\x1a""com.caucho.hessian.test.A8""\x90""\x68"
	"C""\x1a""com.caucho.hessian.test.A9""\x90""\x69"
	"C""\x1b""com.caucho.hessian.test.A10""\x90""\x6a"
	"C""\x1b""com.caucho.hessian.test.A11""\x90""\x6b"
	"C""\x1b""com.caucho.hessian.test.A12""\x90""\x6c"
	"C""\x1b""com.caucho.hessian.test.A13""\x90""\x6d"
	"C""\x1b""com.caucho.hessian.test.A14""\x90""\x6e"
	"C""\x1b""com.caucho.hessian.test.A15""\x90""\x6f"
	"C""\x1b""com.caucho.hessian.test.A16""\x90""O""\xa0"
);

}
}
