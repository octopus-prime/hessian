/*
 * int_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "int_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

int_generator::int_generator()
:
	int_generator::base_type(_int),
	_int(),
	_int_1(),
	_int_2(),
	_int_3(),
	_int_4()
{
	_int = _int_1 | _int_2 | _int_3 | _int_4;

	_int_1 =
		ka::eps (ka::_val >= -0x10 && ka::_val <= +0x2f)
		<<
		ka::char_ [ka::_1 = ka::_val + 0x90]
	;

	_int_2 =
		ka::eps (ka::_val >= -0x800 && ka::_val <= 0x7ff)
		<<
		ka::char_ [ka::_1 = (ka::_val >> 8) + 0xc8]
	   	<<
	   	ka::char_ [ka::_1 = ka::_val & 0xff]
	;

	_int_3 =
		ka::eps (ka::_val >= -0x40000 && ka::_val <= 0x3ffff)
		<<
		ka::char_ [ka::_1 = (ka::_val >> 16) + 0xd4]
   	   	<<
	   	ka::big_word [ka::_1 = ka::_val & 0xffff]
	;

	_int_4 =
		ka::lit('I')
		<<
		ka::big_dword	[ka::_1 = ka::_val]
	;
}

}
}
