/*
 * test2_service.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include "service.hpp"
#include <string>
#include <boost/cstdint.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>

namespace caucho {

class object_1
{
public:
	object_1(const boost::int32_t value);
	boost::int32_t get_value() const;

private:
	boost::int32_t _value;
};

typedef boost::variant<bool, std::wstring> result_t;

class test2_service_base
:
	public virtual service_base
{
protected:
	virtual ~test2_service_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual result_t arg_int_0(const boost::int32_t value) = 0;
	virtual result_t arg_double_0_0(const double value) = 0;
//	virtual bool arg_object_1(const object_1& dto) = 0;
//	virtual object_1 reply_object_1() = 0;
	virtual void fault() = 0;
};

typedef boost::shared_ptr<test2_service_base> test2_service;

}
