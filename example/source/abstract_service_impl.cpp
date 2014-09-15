/*
 * abstract_service_impl.cpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#include "hessian_example_pch.hpp"
#include "abstract_service_impl.hpp"
#include "fault_exception_impl.hpp"

namespace caucho {

abstract_service_impl::abstract_service_impl(const boost::shared_ptr<client_impl>& client, const std::string& path)
:
	service_base(),
	_client(client),
	_path(path)
{
}

hessian::reply_t
abstract_service_impl::call(const hessian::string_t& method, const hessian::list_t& arguments)
{
	const hessian::content_t content = _client->call(_path, method, arguments);
	return boost::apply_visitor(content_visitor(), content);
}

abstract_service_impl::content_visitor::result_type
abstract_service_impl::content_visitor::operator()(const hessian::reply_t& reply) const
{
	return reply;
}

abstract_service_impl::content_visitor::result_type
abstract_service_impl::content_visitor::operator()(const hessian::fault_t& fault) const
{
	throw fault_exception_impl(fault);
}

}
