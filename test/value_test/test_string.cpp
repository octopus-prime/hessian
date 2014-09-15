/*
 * test_string.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "hessian_test_pch.hpp"
#include "value_helper.hpp"
#include "../fixture/fixture_string.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, string_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_string, fixture::fixture_string)

TEST_EQUAL_SAME_TYPE(string_0, string_1);
TEST_EQUAL_OTHER_TYPES(string_t, other_types);
TEST_LESS_SAME_TYPE(string_0, string_1);
TEST_LESS_OTHER_TYPES(string_t, other_types);
TEST_HASH(string_0, string_1);
TEST_OUTPUT(string_1, L"string('0')");

BOOST_AUTO_TEST_SUITE_END()

}
}
