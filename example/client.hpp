/*
 * client.hpp
 *
 *  Created on: 04.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <string>
#include <boost/cstdint.hpp>
#include <boost/shared_ptr.hpp>

namespace client {

class object_1
{
public:
	object_1(const boost::int32_t value);
	boost::int32_t get_value() const;

private:
	boost::int32_t _value;
};

class service_base
{
protected:
	virtual ~service_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual void test_int_0() = 0;
	virtual void test_double_0_0() = 0;
	virtual void test_object_1(const object_1& dto) = 0;
};

typedef boost::shared_ptr<service_base> service;

service
make_service(const std::string& host, const boost::uint16_t port);

}
