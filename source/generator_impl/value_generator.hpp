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
#include <boost/unordered_map.hpp>
#include <boost/ref.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

typedef std::vector<string_t> def_t;
typedef boost::unordered_map<def_t, std::size_t> defs_t;
typedef std::pair<boost::optional<boost::reference_wrapper<const def_t> >, std::size_t> def_index_t;

typedef boost::unordered_map<value_t, std::size_t, hash, equal_to> refs_t;
typedef std::pair<bool, std::size_t> ref_index_t;

class value_generator
:
	public ka::grammar<output_iterator_t, value_t()>
{
public:
	value_generator();

protected:
	def_index_t def(const object_t& object);
	ref_index_t ref(const value_t& value);

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
	ka::rule<output_iterator_t, list_t()> _list_or_ref;
	ka::rule<output_iterator_t, list_t(), ka::locals<std::size_t> > _list;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_1;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_2;
	ka::rule<output_iterator_t, map_t()> _map_or_ref;
	ka::rule<output_iterator_t, map_t()> _map;
	ka::rule<output_iterator_t, map_t::value_type()> _pair;
	ka::rule<output_iterator_t, object_t()> _object_or_ref;
	ka::rule<output_iterator_t, object_t(), ka::locals<def_index_t > > _object;
	ka::rule<output_iterator_t, std::size_t()> _index;
	ka::rule<output_iterator_t, std::size_t()> _index_1;
	ka::rule<output_iterator_t, std::size_t()> _index_2;

	ka::rule<output_iterator_t, value_t(), ka::locals<ref_index_t> > _ref;

	defs_t _defs;
	refs_t _refs;
};

}
}
