/*
 * long_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "long_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

long_generator::long_generator()
:
	long_generator::base_type(_long),
	_long(),
	_long_1(),
	_long_2(),
	_long_3(),
	_long_4(),
	_long_5()
{
	_long = _long_1 | _long_2 | _long_3 | _long_4 | _long_5;

	_long_1 =
		ka::eps (ka::_val >= -0x08 && ka::_val <= +0x0f)
		<<
		ka::char_ [ka::_1 = ka::_val + 0xe0]
	;

	_long_2 =
		ka::eps (ka::_val >= -0x800 && ka::_val <= 0x7ff)
		<<
		ka::char_ [ka::_1 = (ka::_val >> 8) + 0xf8]
	   	<<
	   	ka::char_ [ka::_1 = ka::_val & 0xff]
	;

	_long_3 =
		ka::eps (ka::_val >= -0x40000 && ka::_val <= 0x3ffff)
		<<
		ka::char_ [ka::_1 = (ka::_val >> 16) + 0x3c]
   	   	<<
	   	ka::big_word [ka::_1 = ka::_val & 0xffff]
	;

	_long_4 =
		ka::eps (ka::_val >= std::numeric_limits<boost::int32_t>::min() && ka::_val <= std::numeric_limits<boost::int32_t>::max())
		<<
		ka::lit('Y')
		<<
		ka::big_dword	[ka::_1 = ka::_val]
	;

	_long_5 =
		ka::lit('L')
		<<
		ka::big_qword	[ka::_1 = ka::_val]
	;
}

}
}
