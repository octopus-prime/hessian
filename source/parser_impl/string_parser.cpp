/*
 * string_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "string_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

string_parser::string_parser()
:
	string_parser::base_type(_string),
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
			qi::omit
			[
				_length						[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::char_
			]
	;

	_string_2 =
			qi::omit
			[
				_length_4					[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::char_
			]
			>>
			_string							[qi::_val += qi::_1]
	;

	_length =
			_length_1
			|
			_length_2
			|
			_length_3
	;

	_length_1 =
			qi::char_('\x00', '\x1f')
	;

	_length_2 =
			qi::char_('\x30', '\x33')		[qi::_val = (qi::_1 - 0x30) << 8]
			>>
			qi::byte_						[qi::_val += qi::_1]
	;

	_length_3 =
			qi::lit('S')
			>>
			qi::big_word
	;

	_length_4 =
			qi::lit('R')
			>>
			qi::big_word
	;
}

}
}
