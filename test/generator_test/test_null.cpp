/*
 * test_null.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "generator_helper.hpp"
#include "../fixture/fixture_null.hpp"

namespace hessian {
namespace generator_test {

#define TEST_NULL() TEST_CALL(test_generate_null, null, hessian)

BOOST_FIXTURE_TEST_SUITE(test_generate_null, fixture::fixture_null)

TEST_NULL();

BOOST_AUTO_TEST_SUITE_END()

}
}
