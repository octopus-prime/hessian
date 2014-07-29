/*
 * test_long.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_long)

TEST_REPLY(test_long_0,						string_t("\xe0", 1),															long_t(0LL))
TEST_REPLY(test_long_1,						string_t("\xe1", 1),															long_t(1LL))
TEST_REPLY(test_long_15,					string_t("\xef", 1),															long_t(15LL))
TEST_REPLY(test_long_m8,					string_t("\xd8", 1),															long_t(-8LL))
TEST_REPLY(test_long_0x10,				string_t("\xf8\x10", 2),													long_t(0x10LL))
TEST_REPLY(test_long_0x7ff,				string_t("\xff\xff", 2),													long_t(0x7ffLL))
TEST_REPLY(test_long_m9,					string_t("\xf7\xf7", 2),													long_t(-9LL))
TEST_REPLY(test_long_m0x800,			string_t("\xf0\x00", 2),													long_t(-0x800LL))
TEST_REPLY(test_long_0x800,				string_t("\x3c\x08\x00", 3),											long_t(0x800LL))
TEST_REPLY(test_long_m0x801,			string_t("\x3b\xf7\xff", 3),											long_t(-0x801LL))
TEST_REPLY(test_long_0x3ffff,			string_t("\x3f\xff\xff", 3),											long_t(0x3ffffLL))
TEST_REPLY(test_long_m0x40000,		string_t("\x38\x00\x00", 3),											long_t(-0x40000LL))
TEST_REPLY(test_long_0x40000,			string_t("Y\x00\x04\x00\x00", 5),									long_t(0x40000LL))
TEST_REPLY(test_long_m0x40001,		string_t("Y\xff\xfb\xff\xff", 5),									long_t(-0x40001LL))
TEST_REPLY(test_long_0x7fffffff,	string_t("Y\x7f\xff\xff\xff", 5),									long_t(0x7fffffffLL))
TEST_REPLY(test_long_m0x80000000,	string_t("Y\x80\x00\x00\x00", 5),									long_t(-0x80000000LL))
TEST_REPLY(test_long_0x80000000,	string_t("L\x00\x00\x00\x00\x80\x00\x00\x00", 9),	long_t(0x80000000LL))
TEST_REPLY(test_long_m0x80000001,	string_t("L\xff\xff\xff\xff\x7f\xff\xff\xff", 9),	long_t(-0x80000001LL))

BOOST_AUTO_TEST_SUITE_END()

}
}
