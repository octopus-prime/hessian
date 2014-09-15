/*
 * test_long.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "hessian_test_pch.hpp"
#include "value_helper.hpp"
#include "../fixture/fixture_long.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, long_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_long, fixture::fixture_long)

TEST_EQUAL_SAME_TYPE(long_0, long_1);
TEST_EQUAL_OTHER_TYPES(long_t, other_types);
TEST_LESS_SAME_TYPE(long_0, long_1);
TEST_LESS_OTHER_TYPES(long_t, other_types);
TEST_HASH(long_0, long_1);
TEST_OUTPUT(long_0, L"long(0)");

BOOST_AUTO_TEST_SUITE_END()

}
}
