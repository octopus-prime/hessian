/*
 * less_visitor.hpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace value_impl {

class less_visitor
:
	public boost::static_visitor<less::result_type>
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
less_visitor::result_type
less_visitor::operator()(const X& value1, const Y& value2) const
{
	static const int which1 = value_t(X()).which();
	static const int which2 = value_t(Y()).which();
	return which1 < which2;
}

template <typename X>
less_visitor::result_type
less_visitor::operator()(const X& value1, const X& value2) const
{
	return std::less<X>()(value1, value2);
}

}
}
