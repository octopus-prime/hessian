/*
 * test_boolean.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_boolean.hpp"

namespace hessian {
namespace parser_test {

#define TEST_BOOLEAN(CASE) TEST_REPLY(test_parse_boolean_##CASE, hessian_##CASE, boolean_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_boolean, fixture::fixture_boolean)

TEST_BOOLEAN(true);
TEST_BOOLEAN(false);

BOOST_AUTO_TEST_SUITE_END()

}
}
