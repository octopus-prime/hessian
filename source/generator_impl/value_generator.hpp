/*
 * value_generator.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "output_iterator.hpp"
#include "null_generator.hpp"
#include "boolean_generator.hpp"
#include "int_generator.hpp"
#include "long_generator.hpp"
#include "double_generator.hpp"
#include "date_generator.hpp"
#include "string_generator.hpp"
#include "binary_generator.hpp"
#include "def_generator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>
#include <boost/optional.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class value_generator
:
	public ka::grammar<output_iterator_t, value_t()>
{
	typedef std::vector<string_t> def_t;
	typedef std::vector<def_t> defs_t;
	typedef std::pair<boost::optional<def_t>, std::size_t> magic_t;

public:
	value_generator();

protected:
	magic_t def(const object_t& object);

private:
	// Top rule
	ka::rule<output_iterator_t, value_t()> _value;

	// Terminals
	null_generator _null;
	boolean_generator _boolean;
	int_generator _int;
	long_generator _long;
	double_generator _double;
	date_generator _date;
	string_generator _string;
	binary_generator _binary;
	def_generator _def;

	// Non terminals
	ka::rule<output_iterator_t, list_t(), ka::locals<std::size_t> > _list;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_1;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_2;
	ka::rule<output_iterator_t, map_t()> _map;
	ka::rule<output_iterator_t, map_t::value_type()> _pair;
	ka::rule<output_iterator_t, object_t(), ka::locals<magic_t > > _object;
	ka::rule<output_iterator_t, std::size_t()> _index;
	ka::rule<output_iterator_t, std::size_t()> _index_1;
	ka::rule<output_iterator_t, std::size_t()> _index_2;

	defs_t _defs;
};

}
}
