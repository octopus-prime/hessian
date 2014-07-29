/*
 * test_double.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_double)

TEST_REPLY(test_double_0_0,				string_t("\x5b", 1),															double_t(0.0))
TEST_REPLY(test_double_1_0,				string_t("\x5c", 1),															double_t(1.0))
TEST_REPLY(test_double_2_0,				string_t("\x5d\x02", 2),													double_t(2.0))
TEST_REPLY(test_double_127_0,			string_t("\x5d\x7f", 2),													double_t(127.0))
TEST_REPLY(test_double_m128_0,		string_t("\x5d\x80", 2),													double_t(-128.0))
TEST_REPLY(test_double_128_0,			string_t("\x5e\x00\x80", 3),											double_t(128.0))
TEST_REPLY(test_double_m129_0,		string_t("\x5e\xff\x7f", 3),											double_t(-129.0))
TEST_REPLY(test_double_32767_0,		string_t("\x5e\x7f\xff", 3),											double_t(32767.0))
TEST_REPLY(test_double_m32768_0,	string_t("\x5e\x80\x00", 3),											double_t(-32768.0))
TEST_REPLY(test_double_0_001,			string_t("\x5f\x00\x00\x00\x01", 5),							double_t(0.001))
TEST_REPLY(test_double_m0_001,		string_t("\x5f\xff\xff\xff\xff", 5),							double_t(-0.001))
TEST_REPLY(test_double_65_536,		string_t("\x5f\x00\x01\x00\x00", 5),							double_t(65.536))
TEST_REPLY(test_double_3_14159,		string_t("D\x40\x09\x21\xf9\xf0\x1b\x86\x6e", 9),	double_t(3.14159))

BOOST_AUTO_TEST_SUITE_END()

}
}
