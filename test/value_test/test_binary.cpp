/*
 * test_binary.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_binary.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, binary_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_binary, fixture::fixture_binary)

TEST_EQUAL_SAME_TYPE(binary_0, binary_1);
TEST_EQUAL_OTHER_TYPES(binary_t, other_types);
TEST_LESS_SAME_TYPE(binary_0, binary_1);
TEST_LESS_OTHER_TYPES(binary_t, other_types);
TEST_HASH(binary_0, binary_1);
TEST_OUTPUT(binary_1, L"binary('30')");

BOOST_AUTO_TEST_SUITE_END()

}
}
