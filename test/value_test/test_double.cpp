/*
 * test_double.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_double.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, double_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_double, fixture::fixture_double)

TEST_EQUAL_SAME_TYPE(double_0_0, double_1_0);
TEST_EQUAL_OTHER_TYPES(double_t, other_types);
TEST_LESS_SAME_TYPE(double_0_0, double_1_0);
TEST_LESS_OTHER_TYPES(double_t, other_types);
TEST_HASH(double_0_0, double_1_0);
TEST_OUTPUT(double_0_0, "double(0)");

BOOST_AUTO_TEST_SUITE_END()

}
}
