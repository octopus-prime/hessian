/*
 * fault_exception.hpp
 *
 *  Created on: 04.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/types.hpp>
#include <caucho/exception.hpp>

namespace caucho {

class fault_exception
:
	public virtual exception
{
protected:
	virtual ~fault_exception() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual const string_t& code() const BOOST_NOEXCEPT_OR_NOTHROW = 0;
	virtual const string_t& message() const BOOST_NOEXCEPT_OR_NOTHROW = 0;
};

}
