/*
 * exception.hpp
 *
 *  Created on: 04.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <exception>
#include <boost/config.hpp>

namespace caucho {

class exception
:
	public std::exception
{
protected:
	virtual ~exception() BOOST_NOEXCEPT_OR_NOTHROW {}
};

}
