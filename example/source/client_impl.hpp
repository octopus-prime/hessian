/*
 * client_impl.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/client.hpp>
#include <hessian/hessian.hpp>
#include <Poco/Net/HTTPClientSession.h>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/unordered_map.hpp>
#include <boost/thread/mutex.hpp>

namespace net = Poco::Net;

namespace caucho {

typedef boost::shared_ptr<net::HTTPClientSession> session;

class client_impl
:
	public virtual client_base,
	public boost::enable_shared_from_this<client_impl>
{
	typedef boost::unordered_map<std::string, std::string> cookies;

public:
	client_impl(const session& session);
	virtual ~client_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual test2_service get_test2_service();

	hessian::content_t call(const std::string& path, const hessian::string_t& method, const hessian::list_t& arguments);

protected:
	void send_request(const std::string& path, const hessian::string_t& method, const hessian::list_t& arguments);
	hessian::content_t receive_response();

private:
	session _session;
	cookies _cookies;
	boost::mutex _mutex;
};

}
