/*
 * test_long.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"

namespace hessian {
namespace generator_test {

BOOST_AUTO_TEST_SUITE(test_long)

TEST_CALL
(
	test_long_0,
	long_t(0LL),
	string_t("\xe0", 1)
)

TEST_CALL
(
	test_long_1,
	long_t(1LL),
	string_t("\xe1", 1)
)

TEST_CALL
(
	test_long_15,
	long_t(15LL),
	string_t("\xef", 1)
)

TEST_CALL
(
	test_long_m8,
	long_t(-8LL),
	string_t("\xd8", 1)
)

TEST_CALL
(
	test_long_0x10,
	long_t(0x10LL),
	string_t("\xf8\x10", 2)
)

TEST_CALL
(
	test_long_0x7ff,
	long_t(0x7ffLL),
	string_t("\xff\xff", 2)
)

TEST_CALL
(
	test_long_m9,
	long_t(-9LL),
	string_t("\xf7\xf7", 2)
)

TEST_CALL
(
	test_long_m0x800,
	long_t(-0x800LL),
	string_t("\xf0\x00", 2)
)

TEST_CALL
(
	test_long_0x800,
	long_t(0x800LL),
	string_t("\x3c\x08\x00", 3)
)

TEST_CALL
(
	test_long_m0x801,
	long_t(-0x801LL),
	string_t("\x3b\xf7\xff", 3)
)

TEST_CALL
(
	test_long_0x3ffff,
	long_t(0x3ffffLL),
	string_t("\x3f\xff\xff", 3)
)

TEST_CALL
(
	test_long_m0x40000,
	long_t(-0x40000LL),
	string_t("\x38\x00\x00", 3)
)

TEST_CALL
(
	test_long_0x40000,
	long_t(0x40000LL),
	string_t("Y\x00\x04\x00\x00", 5)
)

TEST_CALL
(
	test_long_m0x40001,
	long_t(-0x40001LL),
	string_t("Y\xff\xfb\xff\xff", 5)
)

TEST_CALL
(
	test_long_0x7fffffff,
	long_t(0x7fffffffLL),
	string_t("Y\x7f\xff\xff\xff", 5)
)

TEST_CALL
(
	test_long_m0x80000000,
	long_t(-0x80000000LL),
	string_t("Y\x80\x00\x00\x00", 5)
)

TEST_CALL
(
	test_long_0x80000000,
	long_t(0x80000000LL),
	string_t("L\x00\x00\x00\x00\x80\x00\x00\x00", 9)
)

TEST_CALL
(
	test_long_m0x80000001,
	long_t(-0x80000001LL),
	string_t("L\xff\xff\xff\xff\x7f\xff\xff\xff", 9)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
