/*
 * test_date.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_date.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, date_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_date, fixture::fixture_date)

TEST_EQUAL_SAME_TYPE(date_0, date_1);
TEST_EQUAL_OTHER_TYPES(date_t, other_types);
TEST_LESS_SAME_TYPE(date_0, date_1);
TEST_LESS_OTHER_TYPES(date_t, other_types);
TEST_HASH(date_0, date_1);
TEST_OUTPUT(date_1, L"date(1998-05-08T09:51:31)");

BOOST_AUTO_TEST_SUITE_END()

}
}
