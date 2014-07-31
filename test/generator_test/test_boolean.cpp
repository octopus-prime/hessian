/*
 * test_boolean.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"
#include "../fixture/fixture_boolean.hpp"

namespace hessian {
namespace generator_test {

#define TEST_BOOLEAN(CASE) TEST_CALL(test_generate_boolean_##CASE, boolean_##CASE, hessian_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_boolean, fixture::fixture_boolean)

TEST_BOOLEAN(true);
TEST_BOOLEAN(false);

BOOST_AUTO_TEST_SUITE_END()

}
}
