/*
 * test_map.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "generator_helper.hpp"
#include "../fixture/fixture_map.hpp"

namespace hessian {
namespace generator_test {

#define TEST_MAP_UNTYPED(CASE) TEST_CALL(test_generate_map_untyped_##CASE, map_##CASE, hessian_u_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_map, fixture::fixture_map)

TEST_MAP_UNTYPED(0);
TEST_MAP_UNTYPED(1);
TEST_MAP_UNTYPED(2);
TEST_MAP_UNTYPED(3);

BOOST_AUTO_TEST_SUITE_END()

}
}
