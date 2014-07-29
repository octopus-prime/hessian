/*
 * test_object.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

using boost::assign::map_list_of;
using boost::assign::list_of;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_object)

static const object_t object_0 = object_t();
static const object_t object_1 = map_list_of<string_t, int_t>("_value", 0);
static const list_t object_2 = list_of<object_t>(object_1)(map_list_of<string_t, int_t>("_value", 1));
static const list_t object_2a = list_of<object_t>(object_1)(object_1);
static const list_t object_2b = list_of<object_t>(object_1)(object_1);
static const list_t object_16 = list_of<object_t>()()()()()()()()()()()()()()()()();

TEST_REPLY
(
	test_object_0,
	string_t("C""\x1a""com.caucho.hessian.test.A0""\x90""\x60"),
	object_0
)

TEST_REPLY
(
	test_object_1,
	string_t("C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90"),
	object_1
)

TEST_REPLY
(
	test_object_2,
	string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""\x60""\x91"),
	object_2
)

TEST_REPLY
(
	test_object_2a,
	string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""Q""\x91"),
	object_2a
)

TEST_REPLY
(
	test_object_2b,
	string_t("\x7a""C""\x30""\x22""com.caucho.hessian.test.TestObject""\x91""\x06""_value""\x60""\x90""\x60""\x90"),
	object_2b
)

// NOTE: Skipping test_object_3 because of cycles.

TEST_REPLY
(
	test_object_16,
	string_t
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
	),
	object_16
)

BOOST_AUTO_TEST_SUITE_END()

}
}
