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
> less_different_types_1;

typedef mpl::map
<
	mpl::pair<long_t, double_t>,
	mpl::pair<long_t, date_t>,
	mpl::pair<long_t, string_t>,
	mpl::pair<long_t, binary_t>,

	mpl::pair<double_t, date_t>,
	mpl::pair<double_t, string_t>,
	mpl::pair<double_t, binary_t>,

	mpl::pair<date_t, string_t>,
	mpl::pair<date_t, binary_t>,

	mpl::pair<string_t, binary_t>
> less_different_types_2;

#define TEST_LESS(test_name, value1, value2)\
BOOST_AUTO_TEST_CASE(test_name)\
{\
	BOOST_CHECK_EQUAL(less()(value1, value1), false);\
	BOOST_CHECK_EQUAL(less()(value2, value2), false);\
	BOOST_CHECK_EQUAL(less()(value2, value1), false);\
	BOOST_CHECK_EQUAL(less()(value1, value2), true);\
}

BOOST_AUTO_TEST_SUITE(test_less)

const date_t date_1 = boost::posix_time::microsec_clock::universal_time();
const date_t date_2 = boost::posix_time::microsec_clock::universal_time();

BOOST_AUTO_TEST_CASE(less_null)
{
	BOOST_CHECK_EQUAL(less()(null_t(), null_t()), false);
}

TEST_LESS(less_boolean,	boolean_t(false), 	boolean_t(true))
TEST_LESS(less_int,		int_t(1), 			int_t(2))
TEST_LESS(less_long,	long_t(1), 			long_t(2))
TEST_LESS(less_double,	double_t(1),		double_t(2))
TEST_LESS(less_date,	date_1,				date_2)
TEST_LESS(less_string,	string_t("1"),		string_t("2"))
TEST_LESS(less_binary,	binary_t(1, 1),		binary_t(2, 1))

BOOST_AUTO_TEST_CASE_TEMPLATE(less_different_1, T, less_different_types_1)
{
	typedef typename T::first F;
	typedef typename T::second S;
	static const int f = value_t(F()).which();
	static const int s = value_t(S()).which();
	BOOST_CHECK_EQUAL(less()(F(), S()), f < s);
	BOOST_CHECK_EQUAL(less()(S(), F()), s < f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(less_different_2, T, less_different_types_2)
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
