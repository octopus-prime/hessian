/*
 * binary_parser.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class binary_parser
:
	public qi::grammar<input_iterator_t, binary_t()>
{
public:
	binary_parser();

private:
	qi::rule<input_iterator_t, binary_t()> _binary;
	qi::rule<input_iterator_t, binary_t(), qi::locals<std::size_t> > _binary_1;
	qi::rule<input_iterator_t, binary_t(), qi::locals<std::size_t> > _binary_2;
	qi::rule<input_iterator_t, std::size_t()> _length;
	qi::rule<input_iterator_t, std::size_t()> _length_1;
	qi::rule<input_iterator_t, std::size_t()> _length_2;
	qi::rule<input_iterator_t, std::size_t()> _length_3;
	qi::rule<input_iterator_t, std::size_t()> _length_4;
};

}
}
