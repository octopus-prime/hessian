/*
 * test_long.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_long.hpp"

namespace hessian {
namespace parser_test {

#define TEST_LONG(CASE) TEST_REPLY(test_parse_long_##CASE, hessian_##CASE, long_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_long, fixture::fixture_long)

TEST_LONG(0);
TEST_LONG(1);
TEST_LONG(15);
TEST_LONG(m8);
TEST_LONG(m9);
TEST_LONG(0x10);
TEST_LONG(0x7ff);
TEST_LONG(m0x800);
TEST_LONG(0x800);
TEST_LONG(m0x801);
TEST_LONG(0x3ffff);
TEST_LONG(m0x40000);
TEST_LONG(0x40000);
TEST_LONG(m0x40001);
TEST_LONG(0x7fffffff);
TEST_LONG(m0x80000000);
TEST_LONG(0x80000000);
TEST_LONG(m0x80000001);

BOOST_AUTO_TEST_SUITE_END()

}
}
