/*
 * string_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "string_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

string_generator::string_generator()
:
	string_generator::base_type(_string),
	_string(),
	_length_1(),
	_length_2(),
	_length_3()
{
	_string =
			ka::eps [ka::_a = px::bind(&string_t::size, ka::_val)]
			<<
			(
				_length_1(ka::_a)
				|
				_length_2(ka::_a)
				|
				_length_3(ka::_a)
			)
			<<
			ka::string [ka::_1 = ka::_val];

	_length_1 =
			ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x1f)
			<<
			ka::byte_ [ka::_1 = ka::_r1];

	_length_2 =
			ka::eps (ka::_r1 >= 0x20 && ka::_r1 <= 0x3ff)
			<<
			ka::byte_ [ka::_1 = (ka::_r1 >> 8) + 0x30]
			<<
			ka::byte_ [ka::_1 = ka::_r1 & 0xff];

	_length_3 =
			ka::eps (ka::_r1 >= 0x400 && ka::_r1 <= 0xffff)
			<<
			ka::lit('S')
			<<
			ka::big_word [ka::_1 = ka::_r1];
}

}
}
