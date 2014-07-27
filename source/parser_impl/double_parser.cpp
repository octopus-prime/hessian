/*
 * double_parser.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "double_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

double_parser::double_parser()
:
	double_parser::base_type(_double),
	_double(),
	_double_1(),
	_double_2(),
	_double_3(),
	_double_4(),
	_double_5()
{
	_double =
			_double_1
			|
			_double_2
			|
			_double_3
			|
			_double_4
			|
			_double_5
	;

	_double_1.add
			("\x5b", 0.0)
			("\x5c", 1.0)
	;

	_double_2 =
			qi::lit('D')
			>>
			qi::big_bin_double
	;

	_double_3 =
			qi::lit('\x5f')
			>>
			qi::big_dword					[qi::_val = px::construct<boost::int32_t>(qi::_1) * 0.001]
	;

	_double_4 =
			qi::lit('\x5d')
			>>
			qi::char_
	;

	_double_5 =
			qi::lit('\x5e')
			>>
			qi::big_word					[qi::_val = px::construct<boost::int16_t>(qi::_1)]
	;
}

}
}
