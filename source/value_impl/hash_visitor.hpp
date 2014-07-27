/*
 * hash_visitor.hpp
 *
 *  Created on: 22.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace value_impl {

class hash_visitor
:
	public boost::static_visitor<hash::result_type>
{
public:
	template <typename T>
	result_type operator()(const T& value) const;

	result_type operator()(const null_t& value) const;
	result_type operator()(const date_t& value) const;
	result_type operator()(const list_t& value) const;
	result_type operator()(const map_t& value) const;
	result_type operator()(const object_t& value) const;
};

template <typename T>
hash_visitor::result_type
hash_visitor::operator()(const T& value) const
{
	return boost::hash_value(value);
}

}
}
