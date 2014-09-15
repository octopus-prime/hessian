/*
 * test_null.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_null.hpp"

namespace hessian {
namespace parser_test {

#define TEST_NULL() TEST_REPLY(test_parse_null, hessian, null)

BOOST_FIXTURE_TEST_SUITE(test_parse_null, fixture::fixture_null)

TEST_NULL();

BOOST_AUTO_TEST_SUITE_END()

}
}
