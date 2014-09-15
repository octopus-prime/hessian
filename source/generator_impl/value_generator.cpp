/*
 * value_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "value_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted/std_pair.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/bind.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

static std::vector<string_t>
get_keys(const object_t& object)
{
	std::vector<string_t> keys;
	boost::transform
	(
		object,
		std::back_inserter(keys),
		boost::bind(&object_t::value_type::first, _1)
	);
	return keys;
}

static std::vector<value_t>
get_values(const object_t& object)
{
	std::vector<value_t> values;
	boost::transform
	(
		object,
		std::back_inserter(values),
		boost::bind(&object_t::value_type::second, _1)
	);
	return values;
}

value_generator::value_generator()
:
	value_generator::base_type(_value),
	_value(),
	_null(),
	_boolean(),
	_int(),
	_long(),
	_double(),
	_date(),
	_string(),
	_binary(),
	_def(),
	_list_or_ref(),
	_list(),
	_list_1(),
	_list_2(),
	_map_or_ref(),
	_map(),
	_pair(),
	_object_or_ref(),
	_object(),
	_index(),
	_index_1(),
	_index_2(),
	_ref(),
	_defs(),
	_refs()
{
	_value =
			_null
			|
			_boolean
			|
			_int
			|
			_long
			|
			_double
			|
			_date
			|
			_string
			|
			_binary
			|
			_list_or_ref
			|
			_map_or_ref
			|
			_object_or_ref
	;

	_list_or_ref =
			_ref							[ka::_pass = !px::bind(&list_t::empty, ka::_val), ka::_1 = px::construct<value_t>(ka::_val)]
			|
			_list
	;

	_list = ka::eps							[ka::_a = px::bind(&list_t::size, ka::_val)]
	        <<
			(
				_list_1(ka::_a)
				|
				_list_2(ka::_a)
			)
			<<
			(*_value)						[ka::_1 = ka::_val];

	_list_1 =
			ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x07)
			<<
			ka::byte_						[ka::_1 = ka::_r1 + 0x78];

	_list_2 =
			ka::lit('X')
			<<
			_int							[ka::_1 = ka::_r1]
	;

	_map_or_ref =
			_ref							[ka::_pass = !px::bind(&map_t::empty, ka::_val), ka::_1 = px::construct<value_t>(ka::_val)]
			|
			_map
	;

	_map =
			ka::lit('H')
			<<
			*_pair
			<<
			ka::lit('Z')
	;

	_pair =
			_value
			<<
			_value
	;

	_object_or_ref =
			_ref							[ka::_pass = !px::bind(&object_t::empty, ka::_val), ka::_1 = px::construct<value_t>(ka::_val)]
			|
			_object
	;

	_object =
			(
			ka::eps							[ka::_a = px::bind(&value_generator::def, this, ka::_val)]
			<<
			(-_def)							[ka::_1 = px::bind(&value_generator::def_index_t::first, ka::_a)]
			<<
			_index							[ka::_1 = px::bind(&value_generator::def_index_t::second, ka::_a)]
			<<
			(*_value)						[ka::_1 = px::bind(get_values, ka::_val)]
			)
	;

	_index =
			_index_1
			|
			_index_2
	;

	_index_1 =
			ka::eps (ka::_val >= 0x00 && ka::_val <= 0x0f)
			<<
			ka::byte_						[ka::_1 = ka::_val + 0x60];
	;

	_index_2 =
			ka::lit('O')
			<<
			_int
	;

	_ref =
			ka::eps							[ka::_a = px::bind(&value_generator::ref, this, ka::_val)]
			<<
			ka::eps (!px::bind(&value_generator::ref_index_t::first, ka::_a))	// no emplace => was emplaced before => use ref
			<<
			ka::lit('Q')
			<<
			_int							[ka::_1 = px::bind(&value_generator::ref_index_t::second, ka::_a)]
	;
}

value_generator::def_index_t
value_generator::def(const object_t& object)
{
	const std::pair<defs_t::const_iterator, bool> emplaced = _defs.emplace
	(
		get_keys(object),
		_defs.size()
	);
	return std::make_pair
	(
		boost::make_optional
		(
			emplaced.second,
			boost::cref(emplaced.first->first)
		),
		emplaced.first->second
	);
}

value_generator::ref_index_t
value_generator::ref(const value_t& value)
{
	const std::pair<refs_t::const_iterator, bool> emplaced = _refs.emplace
	(
		value,
		_refs.size()
	);
	return std::make_pair
	(
		emplaced.second,
		emplaced.first->second
	);
}

}
}
