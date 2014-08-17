/*
 * value.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include <hessian/value.hpp>
#include "value_impl/less_visitor.hpp"
#include "value_impl/equal_visitor.hpp"
#include "value_impl/hash_visitor.hpp"
#include "value_impl/output_visitor.hpp"

namespace hessian {

boost::assign_detail::generic_list<list_t::value_type>
make_list(const list_t::value_type& value)
{
	return boost::assign::list_of<list_t::value_type>(value);
}

boost::assign_detail::generic_list<std::pair<map_t::key_type, map_t::mapped_type> >
make_map(const map_t::key_type& key, const map_t::mapped_type& value)
{
	return boost::assign::map_list_of<map_t::key_type, map_t::mapped_type>(key, value);
}

boost::assign_detail::generic_list<std::pair<object_t::key_type, object_t::mapped_type> >
make_object(const object_t::key_type& key, const object_t::mapped_type& value)
{
	return boost::assign::map_list_of<object_t::key_type, object_t::mapped_type>(key, value);
}

less::result_type
less::operator()(const first_argument_type& value1, const second_argument_type& value2) const
{
	value_impl::less_visitor visitor;
	return boost::apply_visitor(visitor, value1, value2);
}

equal_to::result_type
equal_to::operator()(const first_argument_type& value1, const second_argument_type& value2) const
{
	value_impl::equal_visitor visitor;
	return boost::apply_visitor(visitor, value1, value2);
}

hash::result_type
hash::operator()(const argument_type& value) const
{
	value_impl::hash_visitor visitor;
	return boost::apply_visitor(visitor, value);
}

std::wostream&
operator<<(std::wostream& stream, const value_t& value)
{
	value_impl::output_visitor visitor(stream);
	boost::apply_visitor(visitor, value);
	return stream;
}

}
