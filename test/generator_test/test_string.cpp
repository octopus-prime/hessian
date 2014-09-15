/*
 * test_string.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "generator_helper.hpp"
#include "../fixture/fixture_string.hpp"

namespace hessian {
namespace generator_test {

#define TEST_STRING(CASE) TEST_CALL(test_generate_string_##CASE, string_##CASE, hessian_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_string, fixture::fixture_string)

TEST_STRING(0);
TEST_STRING(1);
TEST_STRING(31);
TEST_STRING(32);
TEST_STRING(1023);
TEST_STRING(1024);
//TEST_STRING(65535);
TEST_STRING(65536);

#ifndef _WIN32
TEST_STRING(unicode);
#endif

BOOST_AUTO_TEST_SUITE_END()

}
}
