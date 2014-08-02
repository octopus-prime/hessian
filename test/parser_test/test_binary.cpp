/*
 * test_binary.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include "../fixture/fixture_binary.hpp"

namespace hessian {
namespace parser_test {

#define TEST_BINARY(CASE) TEST_REPLY(test_parse_binary_##CASE, hessian_##CASE, binary_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_binary, fixture::fixture_binary)

TEST_BINARY(0);
TEST_BINARY(1);
TEST_BINARY(15);
TEST_BINARY(16);
TEST_BINARY(1023);
TEST_BINARY(1024);
TEST_BINARY(65535);
TEST_BINARY(65536);

BOOST_AUTO_TEST_SUITE_END()

}
}
