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
public:
	test2_service_impl(const boost::shared_ptr<client_impl>& client);
	virtual ~test2_service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual bool arg_int_0(const boost::int32_t value);
	virtual bool arg_double_0_0(const double value);
//	virtual bool arg_object_1(const object_1& dto);
//	virtual object_1 reply_object_1();
//	virtual void fault();
};

}
