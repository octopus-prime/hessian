/*
 * test_object.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include "../fixture/fixture_object.hpp"

namespace hessian {
namespace parser_test {

#define TEST_OBJECT(CASE) TEST_REPLY(test_parse_object_##CASE, hessian_##CASE, object_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_object, fixture::fixture_object)

TEST_OBJECT(0);
TEST_OBJECT(1);
TEST_OBJECT(2);
TEST_OBJECT(2a);
TEST_OBJECT(2b);
// TODO: Skipping test_object_3 because of cycles.
TEST_OBJECT(16);

BOOST_AUTO_TEST_SUITE_END()

}
}
