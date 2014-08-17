/*
 * test_list.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_list.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, list_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_list, fixture::fixture_list)

TEST_EQUAL_SAME_TYPE(list_0, list_1);
TEST_EQUAL_OTHER_TYPES(list_t, other_types);
TEST_LESS_SAME_TYPE(list_0, list_1);
TEST_LESS_OTHER_TYPES(list_t, other_types);
TEST_HASH(list_0, list_1);
TEST_OUTPUT(list_1, L"list(string('1'))");

BOOST_AUTO_TEST_SUITE_END()

}
}
