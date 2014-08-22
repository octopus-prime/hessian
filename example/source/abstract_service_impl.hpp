/*
 * abstract_service_impl.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/service.hpp>
#include "client_impl.hpp"

namespace caucho {

class abstract_service_impl
:
	public virtual service_base
{
protected:
	abstract_service_impl(const boost::shared_ptr<client_impl>& client, const std::string& path);
	virtual ~abstract_service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}

	hessian::reply_t call(const hessian::string_t& method, const hessian::list_t& arguments);

private:
	boost::shared_ptr<client_impl> _client;
	std::string _path;
};

}