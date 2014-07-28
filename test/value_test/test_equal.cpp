/*
 * test_equal.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include <hessian/hessian.hpp>
#include <boost/test/unit_test.hpp>

namespace hessian {
namespace value_test {

BOOST_AUTO_TEST_SUITE(test_equal)

BOOST_AUTO_TEST_CASE(equal_null)
{
	BOOST_CHECK_EQUAL(equal_to()(null_t(), null_t()), true);
}

BOOST_AUTO_TEST_CASE(equal_int)
{
	BOOST_CHECK_EQUAL(equal_to()(int_t(1), int_t(1)), true);
	BOOST_CHECK_EQUAL(equal_to()(int_t(2), int_t(1)), false);
	BOOST_CHECK_EQUAL(equal_to()(int_t(1), int_t(2)), false);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
