/*
 * client.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/test2_service.hpp>
#include <string>
#include <boost/cstdint.hpp>
#include <boost/shared_ptr.hpp>

namespace caucho {

class client_base
{
protected:
	virtual ~client_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual test2_service get_test2_service() = 0;
};

typedef boost::shared_ptr<client_base> client;

client
make_http_client(const std::string& host, const boost::uint16_t port);

client
make_https_client(const std::string& host, const boost::uint16_t port);

}
