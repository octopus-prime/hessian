/*
 * boolean_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include <boost/spirit/include/qi_symbols.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class boolean_parser
:
	public qi::symbols<char, boolean_t>
{
public:
	boolean_parser();
};

}
}
