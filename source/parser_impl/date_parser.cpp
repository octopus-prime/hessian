/*
 * date_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "date_parser.hpp"
#include "../constant.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;
namespace pt = boost::posix_time;

namespace hessian {
namespace parser_impl {

date_parser::date_parser()
:
	date_parser::base_type(_date),
	_date(),
	_date_1(),
	_date_2()
{
	_date =
			_date_1
			|
			_date_2
	;

	_date_1 =
			qi::lit('\x4a')					[qi::_val = px::construct<date_t>(constant::EPOCH)]
			>>
			qi::big_qword					[qi::_val += px::construct<pt::milliseconds>(qi::_1)]
	;

	_date_2 =
			qi::lit('\x4b')					[qi::_val = px::construct<date_t>(constant::EPOCH)]
			>>
			qi::big_dword					[qi::_val += px::construct<pt::minutes>(qi::_1)]
	;
}

}
}
