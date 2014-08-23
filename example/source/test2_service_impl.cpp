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

result_t
test2_service_impl::arg_int_0(const int_t value)
{
	const hessian::reply_t reply = call(L"argInt_0", hessian::make_list(value));
	return boost::apply_visitor(reply_visitor(), reply);
}

result_t
test2_service_impl::arg_double_0_0(const double_t value)
{
	const hessian::reply_t reply = call(L"argDouble_0_0", hessian::make_list(value));
	return boost::apply_visitor(reply_visitor(), reply);
}

void
test2_service_impl::fault()
{
	call(L"doesNotExist");
}

test2_service_impl::reply_visitor::result_type
test2_service_impl::reply_visitor::operator()(const hessian::boolean_t& reply) const
{
	return reply;
}

test2_service_impl::reply_visitor::result_type
test2_service_impl::reply_visitor::operator()(const hessian::string_t& reply) const
{
	return reply;
}

template <typename T>
test2_service_impl::reply_visitor::result_type
test2_service_impl::reply_visitor::operator()(const T& reply) const
{
	throw std::bad_cast();
}

}
