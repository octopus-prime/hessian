/*
 * def_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "def_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

def_parser::def_parser()
:
	def_parser::base_type(_def),
	_def(),
	_int(),
	_string()
{
	_def =
			qi::lit('C')
			>>
			qi::omit
			[
				_string
				>>
				_int						[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				_string
			]
	;
}

}
}
