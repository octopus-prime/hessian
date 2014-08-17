/*
 * test_int.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_int.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, int_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_int, fixture::fixture_int)

TEST_EQUAL_SAME_TYPE(int_0, int_1);
TEST_EQUAL_OTHER_TYPES(int_t, other_types);
TEST_LESS_SAME_TYPE(int_0, int_1);
TEST_LESS_OTHER_TYPES(int_t, other_types);
TEST_HASH(int_0, int_1);
TEST_OUTPUT(int_0, L"int(0)");

BOOST_AUTO_TEST_SUITE_END()

}
}
