/*
 * exception.hpp
 *
 *  Created on: 26.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <exception>
#include <boost/config/suffix.hpp>

namespace hessian {

/**
 * Defines exception.
 */
class exception
:
	public std::exception
{
protected:
	virtual ~exception() BOOST_NOEXCEPT_OR_NOTHROW {}
};

}
