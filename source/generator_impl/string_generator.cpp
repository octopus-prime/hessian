/*
 * string_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "string_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/regex/pending/unicode_iterator.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

#ifdef _WIN32
	typedef boost::u32_to_u8_iterator<boost::u16_to_u32_iterator<string_t::const_iterator> > utf_iterator;
#else
	typedef boost::u32_to_u8_iterator<string_t::const_iterator> utf_iterator;
#endif

static std::string
sub_std_string(const string_t& string, const std::size_t length)
{
	const string_t substr = string.substr(0, length);
	return std::string
	(
		utf_iterator(substr.begin()),
		utf_iterator(substr.end())
	);
}

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
			ka::string [ka::_1 = px::bind(sub_std_string, ka::_val, px::bind(&string_t::size, ka::_val))]
	;

	_string_2 =
			_length_4
			<<
			ka::string [ka::_1 = px::bind(sub_std_string, ka::_val, px::construct<std::size_t>(0xffff))]
			<<
			_string [ka::_1 = px::bind(&string_t::substr, ka::_val, 0xffff, string_t::npos)]
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
