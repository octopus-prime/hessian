/*
 * less_visitor.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "less_visitor.hpp"

namespace hessian {
namespace value_impl {

struct map_entry_less
:
	std::binary_function<map_t::value_type, map_t::value_type, bool>
{
	result_type
	operator()(const first_argument_type& value1, const second_argument_type& value2) const;
};

struct object_entry_less
:
	std::binary_function<object_t::value_type, object_t::value_type, bool>
{
	result_type
	operator()(const first_argument_type& value1, const second_argument_type& value2) const;
};

less_visitor::result_type
less_visitor::operator()(const null_t& value1, const null_t& value2) const
{
	return false;
}

less_visitor::result_type
less_visitor::operator()(const list_t& value1, const list_t& value2) const
{
	return std::lexicographical_compare(value1.begin(), value1.end(), value2.begin(), value2.end(), less());
}

less_visitor::result_type
less_visitor::operator()(const map_t& value1, const map_t& value2) const
{
	return std::lexicographical_compare(value1.begin(), value1.end(), value2.begin(), value2.end(), map_entry_less());
}

less_visitor::result_type
less_visitor::operator()(const object_t& value1, const object_t& value2) const
{
	return std::lexicographical_compare(value1.begin(), value1.end(), value2.begin(), value2.end(), object_entry_less());
}

map_entry_less::result_type
map_entry_less::operator()(const first_argument_type& value1, const second_argument_type& value2) const
{
	if (less()(value1.first, value2.first))
		return true;
	if (less()(value2.first, value1.first))
		return false;
	return less()(value1.second, value2.second);
}

object_entry_less::result_type
object_entry_less::operator()(const first_argument_type& value1, const second_argument_type& value2) const
{
	if (std::less<object_t::key_type>()(value1.first, value2.first))
		return true;
	if (std::less<object_t::key_type>()(value2.first, value1.first))
		return false;
	return less()(value1.second, value2.second);
}

}
}
