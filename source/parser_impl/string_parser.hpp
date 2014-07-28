/*
 * string_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class string_parser
:
	public qi::grammar<input_iterator_t, string_t()>
{
public:
	string_parser();

private:
	qi::rule<input_iterator_t, string_t()> _string;
	qi::rule<input_iterator_t, string_t(), qi::locals<std::size_t> > _string_1;
	qi::rule<input_iterator_t, string_t(), qi::locals<std::size_t> > _string_2;
	qi::rule<input_iterator_t, std::size_t()> _length;
	qi::rule<input_iterator_t, std::size_t()> _length_1;
	qi::rule<input_iterator_t, std::size_t()> _length_2;
	qi::rule<input_iterator_t, std::size_t()> _length_3;
	qi::rule<input_iterator_t, std::size_t()> _length_4;
};

}
}
