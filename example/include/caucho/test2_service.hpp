/*
 * test2_service.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/types.hpp>
#include <caucho/service.hpp>
#include <boost/shared_ptr.hpp>

namespace caucho {

class test2_service_base
:
	public virtual service_base
{
protected:
	virtual ~test2_service_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual result_t arg_int_0(const int_t value) = 0;
	virtual result_t arg_double_0_0(const double_t value) = 0;
	virtual void fault() = 0;
};

typedef boost::shared_ptr<test2_service_base> test2_service;

}
