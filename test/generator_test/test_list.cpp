/*
 * test_list.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"
#include "../fixture/fixture_list.hpp"

namespace hessian {
namespace generator_test {

#define TEST_LIST_UNTYPED(CASE) TEST_CALL(test_generate_list_untyped_##CASE, list_##CASE, hessian_u_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_list, fixture::fixture_list)

TEST_LIST_UNTYPED(0);
TEST_LIST_UNTYPED(1);
TEST_LIST_UNTYPED(7);
TEST_LIST_UNTYPED(8);

BOOST_AUTO_TEST_SUITE_END()

}
}
