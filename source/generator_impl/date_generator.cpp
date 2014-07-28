/*
 * date_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "date_generator.hpp"
#include "../constant.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;
namespace pt = boost::posix_time;

namespace hessian {
namespace generator_impl {

date_generator::date_generator()
:
	date_generator::base_type(_date),
	_date(),
	_date_1(),
	_date_2()
{
	_date =
			ka::eps [ka::_a = ka::_val - constant::EPOCH]
			<<
			ka::eps [ka::_b = px::bind(&pt::time_duration::total_milliseconds, ka::_a)]
			<<
			(
				_date_1(ka::_b)
				|
				_date_2(ka::_b)
			)
	;

	_date_1 =
			ka::eps (0 == ka::_r1 % 60000)
			<<
			ka::lit('\x4b')
			<<
			ka::big_dword	[ka::_1 = ka::_r1 / 60000]
	;

	_date_2 =
			ka::lit('\x4a')
			<<
			ka::big_qword	[ka::_1 = ka::_r1]
	;
}

}
}
