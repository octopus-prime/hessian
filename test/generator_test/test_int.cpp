/*
 * test_int.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"

namespace hessian {
namespace generator_test {

BOOST_AUTO_TEST_SUITE(test_int)

TEST_CALL
(
	test_int_0,
	int_t(0),
	string_t("\x90", 1)
)

TEST_CALL
(
	test_int_1,
	int_t(1),
	string_t("\x91", 1)
)

TEST_CALL
(
	test_int_47,
	int_t(47),
	string_t("\xbf", 1)
)

TEST_CALL
(
	test_int_m16,
	int_t(-16),
	string_t("\x80", 1)
)

TEST_CALL
(
	test_int_m17,
	int_t(-17),
	string_t("\xc7\xef", 2)
)

TEST_CALL
(
	test_int_0x30,
	int_t(0x30),
	string_t("\xc8\x30", 2)
)

TEST_CALL
(
	test_int_0x7ff,
	int_t(0x7ff),
	string_t("\xcf\xff", 2)
)

TEST_CALL
(
	test_int_m0x800,
	int_t(-0x800),
	string_t("\xc0\x00", 2)
)

TEST_CALL
(
	test_int_0x800,
	int_t(0x800),
	string_t("\xd4\x08\x00", 3)
)

TEST_CALL
(
	test_int_m0x801,
	int_t(-0x801),
	string_t("\xd3\xf7\xff", 3)
)

TEST_CALL
(
	test_int_0x3ffff,
	int_t(0x3ffff),
	string_t("\xd7\xff\xff", 3)
)

TEST_CALL
(
	test_int_m0x40000,
	int_t(-0x40000),
	string_t("\xd0\x00\x00", 3)
)

TEST_CALL
(
	test_int_0x40000,
	int_t(0x40000),
	string_t("I\x00\x04\x00\x00", 5)
)

TEST_CALL
(
	test_int_m0x40001,
	int_t(-0x40001),
	string_t("I\xff\xfb\xff\xff", 5)
)

TEST_CALL
(
	test_int_0x7fffffff,
	int_t(0x7fffffff),
	string_t("I\x7f\xff\xff\xff", 5)
)

TEST_CALL
(
	test_int_m0x80000000,
	int_t(-0x80000000),
	string_t("I\x80\x00\x00\x00", 5)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
