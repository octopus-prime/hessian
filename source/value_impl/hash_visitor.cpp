/*
 * hash_visitor.cpp
 *
 *  Created on: 22.07.2014
 *      Author: mike_gresens
 */

#include "hash_visitor.hpp"
#include "../constant.hpp"

namespace hessian {

hash::result_type
hash_value(const value_t& value);

namespace value_impl {

hash_visitor::result_type
hash_visitor::operator()(const null_t& value) const
{
	static const hash::result_type hash(static_cast<hash::result_type>(0xAAAAAAAAAAAAAAAA));
	return hash;
}

hash_visitor::result_type
hash_visitor::operator()(const date_t& value) const
{
	return static_cast<hash::result_type>((value - constant::EPOCH).ticks());
}

hash_visitor::result_type
hash_visitor::operator()(const list_t& value) const
{
	return boost::hash_range(value.begin(), value.end());
}

hash_visitor::result_type
hash_visitor::operator()(const map_t& value) const
{
	return boost::hash_range(value.begin(), value.end());
}

hash_visitor::result_type
hash_visitor::operator()(const object_t& value) const
{
	return boost::hash_range(value.begin(), value.end());
}

}

hash::result_type
hash_value(const value_t& value)
{
	value_impl::hash_visitor visitor;
	return boost::apply_visitor(visitor, value);
}

}
