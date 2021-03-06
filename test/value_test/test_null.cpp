/*
 * test_null.cpp
 *
 *  Created on: 09.08.2014
 *      Author: mike_gresens
 */

#include "hessian_test_pch.hpp"
#include "value_helper.hpp"
#include "../fixture/fixture_null.hpp"

namespace hessian {
namespace value_test {

typedef mpl::remove<all_types, null_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_null, fixture::fixture_null)

BOOST_AUTO_TEST_CASE(test_equal_same_type)
{
	const value_t v1 = null;
	const value_t v2 = null;
	BOOST_CHECK_EQUAL(equal_to()(v1, v1), true);
	BOOST_CHECK_EQUAL(equal_to()(v1, v2), true);
	BOOST_CHECK_EQUAL(equal_to()(v2, v1), true);
}

TEST_EQUAL_OTHER_TYPES(null_t, other_types);

BOOST_AUTO_TEST_CASE(test_less_same_type)
{
	const value_t v1 = null;
	const value_t v2 = null;
	BOOST_CHECK_EQUAL(less()(v1, v1), false);
	BOOST_CHECK_EQUAL(less()(v1, v2), false);
	BOOST_CHECK_EQUAL(less()(v2, v1), false);
}

TEST_LESS_OTHER_TYPES(null_t, other_types);

BOOST_AUTO_TEST_CASE(test_hash)
{
	const value_t v1 = null;
	const value_t v2 = null;
	BOOST_CHECK_EQUAL(hash()(v1), hash()(v1));
	BOOST_CHECK_EQUAL(hash()(v1), hash()(v2));
}

TEST_OUTPUT(null, L"null");

BOOST_AUTO_TEST_SUITE_END()

}
}
