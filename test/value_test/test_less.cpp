/*
 * test_less.cpp
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
	mpl::pair<int_t, binary_t>
> less_different_types;

BOOST_AUTO_TEST_SUITE(test_less)

BOOST_AUTO_TEST_CASE(less_null)
{
	BOOST_CHECK_EQUAL(less()(null_t(), null_t()), false);
}

BOOST_AUTO_TEST_CASE(less_int)
{
	BOOST_CHECK_EQUAL(less()(int_t(1), int_t(1)), false);
	BOOST_CHECK_EQUAL(less()(int_t(2), int_t(1)), false);
	BOOST_CHECK_EQUAL(less()(int_t(1), int_t(2)), true);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(less_different, T, less_different_types)
{
	typedef typename T::first F;
	typedef typename T::second S;
	static const int f = value_t(F()).which();
	static const int s = value_t(S()).which();
	BOOST_CHECK_EQUAL(less()(F(), S()), f < s);
	BOOST_CHECK_EQUAL(less()(S(), F()), s < f);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
