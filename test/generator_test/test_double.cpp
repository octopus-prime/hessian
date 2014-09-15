/*
 * test_double.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "generator_helper.hpp"
#include "../fixture/fixture_double.hpp"

namespace hessian {
namespace generator_test {

#define TEST_DOUBLE(CASE) TEST_CALL(test_generate_double_##CASE, double_##CASE, hessian_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_double, fixture::fixture_double)

TEST_DOUBLE(0_0);
TEST_DOUBLE(1_0);
TEST_DOUBLE(2_0);
TEST_DOUBLE(127_0);
TEST_DOUBLE(m128_0);
TEST_DOUBLE(128_0);
TEST_DOUBLE(m129_0);
TEST_DOUBLE(32767_0);
TEST_DOUBLE(m32768_0);
TEST_DOUBLE(0_001);
TEST_DOUBLE(m0_001);
TEST_DOUBLE(65_536);
TEST_DOUBLE(3_14159);

BOOST_AUTO_TEST_SUITE_END()

}
}
