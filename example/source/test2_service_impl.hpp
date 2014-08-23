/*
 * test2_service_impl.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/test2_service.hpp>
#include "abstract_service_impl.hpp"

namespace caucho {

class test2_service_impl
:
	public virtual test2_service_base,
	public abstract_service_impl
{
	class reply_visitor
	:
		public boost::static_visitor<result_t>
	{
	public:
		template <typename T>
		result_type operator()(const T& reply) const;
		result_type operator()(const hessian::boolean_t& reply) const;
		result_type operator()(const hessian::string_t& reply) const;
	};

public:
	test2_service_impl(const boost::shared_ptr<client_impl>& client);
	virtual ~test2_service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual result_t arg_int_0(const int_t value);
	virtual result_t arg_double_0_0(const double_t value);
	virtual void fault();
};

}
