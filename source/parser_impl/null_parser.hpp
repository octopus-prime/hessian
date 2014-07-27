/*
 * null_parser.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <boost/spirit/include/qi_symbols.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class null_parser
:
	public qi::symbols<char, null_t>
{
public:
	null_parser();
};

}
}
