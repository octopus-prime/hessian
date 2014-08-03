/*
 * binary_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "binary_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

static string_t
workaround_for_string_issue(const binary_t& binary)
{
	const binary_t substr = binary.substr(0, 0xffff);
	return string_t(substr.begin(), substr.end());
}

binary_generator::binary_generator()
:
	binary_generator::base_type(_binary),
	_binary(),
	_binary_1(),
	_binary_2(),
	_length(),
	_length_1(),
	_length_2(),
	_length_3(),
	_length_4()
{
	_binary =
			_binary_1
			|
			_binary_2
	;

	_binary_1 =
			_length(px::bind(&binary_t::size, ka::_val))
			<<
			ka::string
	;

	_binary_2 =
			_length_4
//			TODO: Does not compile, so we use bad workaround here.
//			<<
//			ka::string [ka::_1 = px::bind(&binary_t::substr, ka::_val, 0, 0xffff)]
			<<
			ka::string [ka::_1 = px::bind(workaround_for_string_issue, ka::_val)]
			<<
			_binary [ka::_1 = px::bind(&binary_t::substr, ka::_val, 0xffff, binary_t::npos)]
	;

	_length =
			_length_1(ka::_r1)
			|
			_length_2(ka::_r1)
			|
			_length_3(ka::_r1)
	;

	_length_1 =
			ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x0f)
			<<
			ka::byte_ [ka::_1 = ka::_r1 + 0x20]
	;

	_length_2 =
			ka::eps (ka::_r1 >= 0x10 && ka::_r1 <= 0x3ff)
			<<
			ka::byte_ [ka::_1 = (ka::_r1 >> 8) + 0x34]
			<<
			ka::byte_ [ka::_1 = ka::_r1 & 0xff]
	;

	_length_3 =
			ka::eps (ka::_r1 >= 0x400 && ka::_r1 <= 0xffff)
			<<
			ka::lit('B')
			<<
			ka::big_word [ka::_1 = ka::_r1]
	;

	_length_4 =
			ka::lit('A')
			<<
			ka::big_word [ka::_1 = 0xffff]
	;
}

}
}
