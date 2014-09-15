/*
 * binary_parser.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "binary_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

binary_parser::binary_parser()
:
	binary_parser::base_type(_binary),
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
			qi::omit
			[
				_length						[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::byte_
			]
	;

	_binary_2 =
			qi::omit
			[
				_length_4					[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::byte_
			]
			>>
			_binary
	;

	_length =
			_length_1
			|
			_length_2
			|
			_length_3
	;

	_length_1 =
			qi::char_('\x20', '\x2f')		[qi::_val = qi::_1 - 0x20]
	;

	_length_2 =
			qi::char_('\x34', '\x37')		[qi::_val = (qi::_1 - 0x34) << 8]
			>>
			qi::byte_						[qi::_val += qi::_1]
	;

	_length_3 =
			qi::lit('B')
			>>
			qi::big_word
	;

	_length_4 =
			qi::lit('A')
			>>
			qi::big_word
	;
}

}
}
