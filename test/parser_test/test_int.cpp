/*
 * test_int.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include "../fixture/fixture_int.hpp"

namespace hessian {
namespace parser_test {

#define TEST_INT(CASE) TEST_REPLY(test_parse_int_##CASE, hessian_##CASE, int_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_int, fixture::fixture_int)

TEST_INT(0);
TEST_INT(1);
TEST_INT(47);
TEST_INT(m16);
TEST_INT(m17);
TEST_INT(0x30);
TEST_INT(0x7ff);
TEST_INT(m0x800);
TEST_INT(0x800);
TEST_INT(m0x801);
TEST_INT(0x3ffff);
TEST_INT(m0x40000);
TEST_INT(0x40000);
TEST_INT(m0x40001);
TEST_INT(0x7fffffff);
TEST_INT(m0x80000000);

BOOST_AUTO_TEST_SUITE_END()

}
}
