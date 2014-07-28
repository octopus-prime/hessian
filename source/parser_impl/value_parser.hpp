/*
 * value_parser.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "input_iterator.hpp"
#include "terminal_parser.hpp"
#include "type_parser.hpp"
#include "def_parser.hpp"
#include "int_parser.hpp"
#include <boost/spirit/include/qi_grammar.hpp>

namespace qi = boost::spirit::qi;

namespace hessian {
namespace parser_impl {

class value_parser
:
	public qi::grammar<input_iterator_t, value_t()>
{
public:
	value_parser();

private:
	qi::rule<input_iterator_t, value_t()> _value;

	terminal_parser _terminal;
	type_parser _type;
	def_parser _def;
	int_parser _int;

	qi::rule<input_iterator_t, value_t()> _ref;
	qi::rule<input_iterator_t, value_t()> _def_value;
	qi::rule<input_iterator_t, value_t()> _nonterminal;

	qi::rule<input_iterator_t, list_t()> _list;
	qi::rule<input_iterator_t, list_t(), qi::locals<std::size_t> > _list_1;
	qi::rule<input_iterator_t, list_t(), qi::locals<std::size_t, std::size_t> > _list_2;
	qi::rule<input_iterator_t, std::size_t()> _length;
	qi::rule<input_iterator_t, std::size_t()> _length_1;
	qi::rule<input_iterator_t, std::size_t()> _length_2;
	qi::rule<input_iterator_t, std::size_t()> _length_3;
	qi::rule<input_iterator_t, std::size_t()> _length_4;
	qi::rule<input_iterator_t, map_t()> _map;
	qi::rule<input_iterator_t, map_t(), qi::locals<std::size_t> > _map_1;
	qi::rule<input_iterator_t, map_t(), qi::locals<std::size_t> > _map_2;
	qi::rule<input_iterator_t, object_t(), qi::locals<std::size_t, std::size_t> > _object;
	qi::rule<input_iterator_t, std::size_t()> _index;
	qi::rule<input_iterator_t, std::size_t()> _index_1;
	qi::rule<input_iterator_t, std::size_t()> _index_2;

	std::vector<std::vector<string_t> > _defs;
	std::vector<value_t> _refs;
};

}
}
