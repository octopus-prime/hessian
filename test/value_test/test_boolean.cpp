/*
 * test_boolean.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "hessian_test_pch.hpp"
#include "value_helper.hpp"
#include "../fixture/fixture_boolean.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, boolean_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_boolean, fixture::fixture_boolean)

TEST_EQUAL_SAME_TYPE(boolean_false, boolean_true);
TEST_EQUAL_OTHER_TYPES(boolean_t, other_types);
TEST_LESS_SAME_TYPE(boolean_false, boolean_true);
TEST_LESS_OTHER_TYPES(boolean_t, other_types);
TEST_HASH(boolean_false, boolean_true);
TEST_OUTPUT(boolean_true, L"boolean(true)");

BOOST_AUTO_TEST_SUITE_END()

}
}
