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
	_string_1(),
	_string_2(),
	_length(),
	_length_1(),
	_length_2(),
	_length_3(),
	_length_4()
{
	_string =
			_string_1
			|
			_string_2
	;

	_string_1 =
			_length(px::bind(&string_t::size, ka::_val))
			<<
			ka::string
	;

	_string_2 =
			_length_4
			<<
			ka::string [ka::_1 = px::bind(&string_t::substr, ka::_val, 0, 0xffff)]
			<<
			_string [ka::_1 = px::bind(&string_t::substr, ka::_val, 0xffff, std::string::npos)]
	;

	_length =
			_length_1(ka::_r1)
			|
			_length_2(ka::_r1)
			|
			_length_3(ka::_r1)
	;

	_length_1 =
			ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x1f)
			<<
			ka::byte_ [ka::_1 = ka::_r1]
	;

	_length_2 =
			ka::eps (ka::_r1 >= 0x20 && ka::_r1 <= 0x3ff)
			<<
			ka::byte_ [ka::_1 = (ka::_r1 >> 8) + 0x30]
			<<
			ka::byte_ [ka::_1 = ka::_r1 & 0xff]
	;

	_length_3 =
			ka::eps (ka::_r1 >= 0x400 && ka::_r1 <= 0xffff)
			<<
			ka::lit('S')
			<<
			ka::big_word [ka::_1 = ka::_r1]
	;

	_length_4 =
			ka::lit('R')
			<<
			ka::big_word [ka::_1 = 0xffff]
	;
}

}
}
