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
	_int(),
	_long(),
	_date(),
	_boolean(),
	_string(),
	_null(),
	_double(),
	_def(),
	_map(),
	_pair(),
	_list(),
	_list_1(),
	_list_2(),
	_object()
{
	_value = _int | _long | _date | _boolean | _string | _list | _map | _null | _double | _object;

	_map = ka::lit('H') << *_pair << ka::lit('Z');

	_pair = _value << _value;

	_list = ka::eps [ka::_a = px::bind(&list_t::size, ka::_val)]
	        <<
			(
				_list_1(ka::_a)
				|
				_list_2(ka::_a)
			)
			<<
			(*_value) [ka::_1 = ka::_val];

	_list_1 = ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x07) << ka::byte_ [ka::_1 = ka::_r1 + 0x78];

	_list_2 = ka::lit('X') << _int [ka::_1 = ka::_r1];

	_object = _def [ka::_1 = px::bind(get_keys, ka::_val)] << ka::lit('\x60') << (*_value) [ka::_1 = px::bind(get_values, ka::_val)];
}

}
}
