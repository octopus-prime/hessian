/*
 * long_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "long_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

long_parser::long_parser()
:
	long_parser::base_type(_long),
	_long(),
	_long_1(),
	_long_2(),
	_long_3(),
	_long_4(),
	_long_5()
{
	_long =
			_long_1
			|
			_long_2
			|
			_long_3
			|
			_long_4
			|
			_long_5
	;

	_long_1 =
		qi::char_('\xd8', '\xef')			[qi::_val = px::construct<boost::uint8_t>(qi::_1) - 0xe0]
	;

	_long_2 =
		qi::char_('\xf0', '\xff')			[qi::_val = (px::construct<boost::uint8_t>(qi::_1) - 0xf8) << 8]
		>>
		qi::byte_							[qi::_val += qi::_1]
	;

	_long_3 =
		qi::char_('\x38', '\x3f')			[qi::_val = (px::construct<boost::uint8_t>(qi::_1) - 0x3c) << 16]
		>>
		qi::big_word						[qi::_val += qi::_1]
	;

	_long_4 =
		qi::lit('\x59')
		>>
		qi::big_dword						[qi::_val = px::construct<boost::int32_t>(qi::_1)]
	;

	_long_5 =
		qi::lit('\x4c')
		>>
		qi::big_qword						[qi::_val = px::construct<boost::int64_t>(qi::_1)]
	;
}

}
}
