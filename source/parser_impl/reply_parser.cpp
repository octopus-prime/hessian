/*
 * reply_parser.cpp
 *
 *  Created on: 25.07.2014
 *      Author: mike_gresens
 */

#include "reply_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

reply_parser::reply_parser()
:
	reply_parser::base_type(_reply),
	_reply(),
	_value()
{
	_reply =
			qi::lit('R')
			>>
			_value
	;
}

}
}
