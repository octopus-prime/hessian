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

static std::vector<std::string>
get_keys(const object_t& object)
{
	std::vector<std::string> keys;
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
	_list(),
	_list_1(),
	_list_2(),
	_map(),
	_pair(),
	_object(),
	_index(),
	_index_1(),
	_index_2(),
	_defs()
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
			_list
			|
			_map
			|
			_object
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

	/*
	 * Idee: def a = get keys, pair<size,optional<def>> b = find_def, << pair.second << index << pair.first << get_values
	 */

	_object =
			ka::eps							[ka::_a = px::bind(&value_generator::def, this, ka::_val)]
			<<
			(-_def)							[ka::_1 = px::bind(&value_generator::magic_t::first, ka::_a)]
			<<
//			ka::lit('\x60')
			_index							[ka::_1 = px::bind(&value_generator::magic_t::second, ka::_a)]
			<<
			(*_value)						[ka::_1 = px::bind(get_values, ka::_val)];

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
}

value_generator::magic_t
value_generator::def(const object_t& object)
{
	const def_t def = get_keys(object);
	const defs_t::const_iterator found = std::find
	(
		_defs.begin(), _defs.end(),
		def
	);
	if (found != _defs.end())
		return std::make_pair(boost::none_t(), found - _defs.begin());
	_defs.push_back(def);
	return std::make_pair(def, _defs.size() - 1);
}

}
}
