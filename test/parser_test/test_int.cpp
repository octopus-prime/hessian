/*
 * test_int.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_int)

TEST_REPLY(test_int_0,				string_t("\x90", 1),				int_t(0))
TEST_REPLY(test_int_1,				string_t("\x91", 1),				int_t(1))
TEST_REPLY(test_int_47,				string_t("\xbf", 1),				int_t(47))
TEST_REPLY(test_int_m16,			string_t("\x80", 1),				int_t(-16))
TEST_REPLY(test_int_m17,			string_t("\xc7\xef", 2),			int_t(-17))
TEST_REPLY(test_int_0x30,			string_t("\xc8\x30", 2),			int_t(0x30))
TEST_REPLY(test_int_0x7ff,			string_t("\xcf\xff", 2),			int_t(0x7ff))
TEST_REPLY(test_int_m0x800,			string_t("\xc0\x00", 2),			int_t(-0x800))
TEST_REPLY(test_int_0x800,			string_t("\xd4\x08\x00", 3),		int_t(0x800))
TEST_REPLY(test_int_m0x801,			string_t("\xd3\xf7\xff", 3),		int_t(-0x801))
TEST_REPLY(test_int_0x3ffff,		string_t("\xd7\xff\xff", 3),		int_t(0x3ffff))
TEST_REPLY(test_int_m0x40000,		string_t("\xd0\x00\x00", 3),		int_t(-0x40000))
TEST_REPLY(test_int_0x40000,		string_t("I\x00\x04\x00\x00", 5),	int_t(0x40000))
TEST_REPLY(test_int_m0x40001,		string_t("I\xff\xfb\xff\xff", 5),	int_t(-0x40001))
TEST_REPLY(test_int_0x7fffffff,		string_t("I\x7f\xff\xff\xff", 5),	int_t(0x7fffffff))
TEST_REPLY(test_int_m0x80000000,	string_t("I\x80\x00\x00\x00", 5),	int_t(-0x80000000))

BOOST_AUTO_TEST_SUITE_END()

}
}
