/*
 * value_generator.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "output_iterator.hpp"
#include "boolean_generator.hpp"
#include "string_generator.hpp"
#include "date_generator.hpp"
#include "null_generator.hpp"
#include "int_generator.hpp"
#include "long_generator.hpp"
#include "double_generator.hpp"
#include "def_generator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class value_generator
:
	public ka::grammar<output_iterator_t, value_t()>
{
public:
	value_generator();

private:
	// Top rule
	ka::rule<output_iterator_t, value_t()> _value;

	// Terminals
	int_generator _int;
	long_generator _long;
	date_generator _date;
	boolean_generator _boolean;
	string_generator _string;
	null_generator _null;
	double_generator _double;
	def_generator _def;

	// Non terminals
	ka::rule<output_iterator_t, map_t()> _map;
	ka::rule<output_iterator_t, map_t::value_type()> _pair;
	ka::rule<output_iterator_t, list_t(), ka::locals<std::size_t> > _list;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_1;
	ka::rule<output_iterator_t, list_t(std::size_t)> _list_2;
	ka::rule<output_iterator_t, object_t()> _object;
};

}
}
