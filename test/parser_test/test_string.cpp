/*
 * test_string.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_string.hpp"

namespace hessian {
namespace parser_test {

#define TEST_STRING(CASE) TEST_REPLY(test_parse_string_##CASE, hessian_##CASE, string_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_string, fixture::fixture_string)

TEST_STRING(0);
TEST_STRING(1);
TEST_STRING(31);
TEST_STRING(32);
TEST_STRING(1023);
TEST_STRING(1024);
TEST_STRING(65535);
TEST_STRING(65536);
TEST_STRING(unicode);

BOOST_AUTO_TEST_SUITE_END()

}
}
