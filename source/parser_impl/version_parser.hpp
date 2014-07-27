/*
 * version_parser.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include "input_iterator.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class version_parser
:
	public qi::grammar<input_iterator, void()>
{
public:
	version_parser();

private:
	qi::rule<input_iterator, void()> _version;
};

}
}
