/*
 * test_map.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_map.hpp"

namespace hessian {
namespace parser_test {

#define TEST_MAP_UNTYPED(CASE) TEST_REPLY(test_parse_map_untyped_##CASE, hessian_u_##CASE, map_##CASE)
#define TEST_MAP_TYPED(CASE) TEST_REPLY(test_parse_map_typed_##CASE, hessian_t_##CASE, map_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_map, fixture::fixture_map)

TEST_MAP_UNTYPED(0);
TEST_MAP_UNTYPED(1);
TEST_MAP_UNTYPED(2);
TEST_MAP_UNTYPED(3);

TEST_MAP_TYPED(0);
TEST_MAP_TYPED(1);
TEST_MAP_TYPED(2);
TEST_MAP_TYPED(3);

BOOST_AUTO_TEST_SUITE_END()

}
}
