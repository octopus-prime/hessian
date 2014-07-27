/*
 * def_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include "int_parser.hpp"
#include "string_parser.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class def_parser
:
	public qi::grammar<input_iterator, std::vector<string_t>(), qi::locals<std::size_t> >
{
public:
	def_parser();

private:
	qi::rule<input_iterator, std::vector<string_t>(), qi::locals<std::size_t> > _def;
	int_parser _int;
	string_parser _string;
};

}
}
