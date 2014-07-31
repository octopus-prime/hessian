/*
 * test_list.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include "../fixture/fixture_list.hpp"

namespace hessian {
namespace parser_test {

#define TEST_LIST_UNTYPED(CASE) TEST_REPLY(test_parse_list_untyped_##CASE, hessian_u_##CASE, list_##CASE)
#define TEST_LIST_TYPED(CASE) TEST_REPLY(test_parse_list_typed_##CASE, hessian_t_##CASE, list_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_list, fixture::fixture_list)

TEST_LIST_UNTYPED(0);
TEST_LIST_UNTYPED(1);
TEST_LIST_UNTYPED(7);
TEST_LIST_UNTYPED(8);

TEST_LIST_TYPED(0);
TEST_LIST_TYPED(1);
TEST_LIST_TYPED(7);
TEST_LIST_TYPED(8);

BOOST_AUTO_TEST_SUITE_END()

}
}
