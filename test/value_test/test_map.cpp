/*
 * test_map.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_map.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, map_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_map, fixture::fixture_map)

TEST_EQUAL_SAME_TYPE(map_0, map_1);
TEST_EQUAL_OTHER_TYPES(map_t, other_types);
TEST_LESS_SAME_TYPE(map_0, map_1);
TEST_LESS_OTHER_TYPES(map_t, other_types);
TEST_HASH(map_0, map_1);
TEST_OUTPUT(map_1, L"map(string('a') = int(0))");

BOOST_AUTO_TEST_SUITE_END()

}
}
