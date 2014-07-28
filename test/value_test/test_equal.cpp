/*
 * test_equal.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include <hessian/hessian.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/mpl/map.hpp>

namespace mpl = boost::mpl;

namespace hessian {
namespace value_test {

typedef mpl::map
<
	mpl::pair<null_t, boolean_t>,
	mpl::pair<null_t, int_t>,
	mpl::pair<null_t, long_t>,
	mpl::pair<null_t, double_t>,
	mpl::pair<null_t, date_t>,
	mpl::pair<null_t, string_t>,
	mpl::pair<null_t, binary_t>,

	mpl::pair<boolean_t, int_t>,
	mpl::pair<boolean_t, long_t>,
	mpl::pair<boolean_t, double_t>,
	mpl::pair<boolean_t, date_t>,
	mpl::pair<boolean_t, string_t>,
	mpl::pair<boolean_t, binary_t>,

	mpl::pair<int_t, long_t>,
	mpl::pair<int_t, double_t>,
	mpl::pair<int_t, date_t>,
	mpl::pair<int_t, string_t>,
	mpl::pair<int_t, binary_t>,

	mpl::pair<long_t, double_t>,
	mpl::pair<long_t, date_t>
//	mpl::pair<long_t, string_t>,
//	mpl::pair<long_t, binary_t>

//	mpl::pair<double_t, date_t>,
//	mpl::pair<double_t, string_t>
//	mpl::pair<double_t, binary_t>

//	mpl::pair<date_t, string_t>
//	mpl::pair<date_t, binary_t>

//	mpl::pair<string_t, binary_t>
> equal_different_types;

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

BOOST_AUTO_TEST_CASE_TEMPLATE(equal_different, T, equal_different_types)
{
	typedef typename T::first F;
	typedef typename T::second S;
	BOOST_CHECK_EQUAL(equal_to()(F(), S()), false);
	BOOST_CHECK_EQUAL(equal_to()(S(), F()), false);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
