/*
 * int_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "int_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

int_parser::int_parser()
:
	int_parser::base_type(_int),
	_int(),
	_int_1(),
	_int_2(),
	_int_3(),
	_int_4()
{
	_int =
			_int_1
			|
			_int_2
			|
			_int_3
			|
			_int_4
	;

	_int_1 =
		qi::char_('\x80', '\xbf')			[qi::_val = px::construct<boost::uint8_t>(qi::_1) - 0x90]
	;

	_int_2 =
		qi::char_('\xc0', '\xcf')			[qi::_val = (px::construct<boost::uint8_t>(qi::_1) - 0xc8) << 8]
		>>
		qi::byte_							[qi::_val += qi::_1]
	;

	_int_3 =
		qi::char_('\xd0', '\xd7')			[qi::_val = (px::construct<boost::uint8_t>(qi::_1) - 0xd4) << 16]
		>>
		qi::big_word						[qi::_val += qi::_1]
	;

	_int_4 =
		qi::lit('I')
		>>
		qi::big_dword
	;
}

}
}
