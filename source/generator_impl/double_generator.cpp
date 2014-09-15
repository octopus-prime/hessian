/*
 * double_generator.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "double_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <limits>
#include <cmath>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

static inline bool
has_no_fractions(const double value)
{
	double buffer;
	return std::modf(value, &buffer) == 0.0;
}

// TODO: See this grammar !!!

double_generator::double_generator()
:
	double_generator::base_type(_double),
	_double(),
	_double_1(),
	_double_2(),
	_double_3(),
	_double_4(),
	_double_5()
{
	_double =
			_double_5
			|
			_double_3
			|
			_double_4
			|
			_double_2
			|
			_double_1
	;

	_double_1 =
			ka::lit('D')
			<<
			ka::big_bin_double
	;

	_double_2 =
			ka::eps 						[ka::_b = 1000.0 * ka::_val]
			<<
			ka::eps 						[ka::_a = px::bind(has_no_fractions, ka::_b)]
			<<
			ka::eps(ka::_a && ka::_b >= std::numeric_limits<boost::int32_t>::min() && ka::_b <= std::numeric_limits<boost::int32_t>::max())
			<<
			ka::lit('\x5f')
			<<
			ka::big_dword					[ka::_1 = px::construct<boost::int32_t>(ka::_b)]
	;

	_double_3 =
			ka::eps 						[ka::_a = px::bind(has_no_fractions, ka::_val)]
			<<
			ka::eps(ka::_a && ka::_val >= std::numeric_limits<boost::int8_t>::min() && ka::_val <= std::numeric_limits<boost::int8_t>::max())
			<<
			ka::lit('\x5d')
			<<
			ka::char_ 						[ka::_1 = ka::_val]
	;

	_double_4 =
			ka::eps 						[ka::_a = px::bind(has_no_fractions, ka::_val)]
			<<
			ka::eps(ka::_a && ka::_val >= std::numeric_limits<boost::int16_t>::min() && ka::_val <= std::numeric_limits<boost::int16_t>::max())
			<<
			ka::lit('\x5e')
			<<
			ka::big_word					[ka::_1 = px::construct<boost::int16_t>(ka::_val)]
	;

	_double_5.add
			(0.0, "\x5b")
			(1.0, "\x5c")
	;
}

}
}
