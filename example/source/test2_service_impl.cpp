/*
 * test2_service_impl.cpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#include "test2_service_impl.hpp"

namespace caucho {

test2_service_impl::test2_service_impl(const boost::shared_ptr<client_impl>& client)
:
	test2_service_base(),
	abstract_service_impl(client, "/test/test2")
{
}

bool
test2_service_impl::arg_int_0(const boost::int32_t value)
{
	const hessian::reply_t reply = call(L"argInt_0", hessian::make_list(value));
	return boost::get<hessian::boolean_t>(reply);
}

bool
test2_service_impl::arg_double_0_0(const double value)
{
	const hessian::reply_t reply = call(L"argDouble_0_0", hessian::make_list(value));
	return boost::get<hessian::boolean_t>(reply);
}

}
