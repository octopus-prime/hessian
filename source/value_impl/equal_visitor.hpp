/*
 * equal_visitor.hpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace value_impl {

class equal_visitor
:
	public boost::static_visitor<equal_to::result_type>
{
public:
	template <typename X, typename Y>
	result_type operator()(const X& value1, const Y& value2) const;

	template <typename X>
	result_type operator()(const X& value1, const X& value2) const;

	result_type operator()(const null_t& value1, const null_t& value2) const;
	result_type operator()(const list_t& value1, const list_t& value2) const;
	result_type operator()(const map_t& value1, const map_t& value2) const;
	result_type operator()(const object_t& value1, const object_t& value2) const;
};

template <typename X, typename Y>
equal_visitor::result_type
equal_visitor::operator()(const X& value1, const Y& value2) const
{
	return false;
}

template <typename X>
equal_visitor::result_type
equal_visitor::operator()(const X& value1, const X& value2) const
{
	return std::equal_to<X>()(value1, value2);
}

}
}
