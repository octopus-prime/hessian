/*
 * service.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <boost/shared_ptr.hpp>

namespace caucho {

class service_base
{
protected:
	virtual ~service_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
};

typedef boost::shared_ptr<service_base> service;

}
