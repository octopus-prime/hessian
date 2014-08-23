/*
 * exception.hpp
 *
 *  Created on: 04.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <string>
#include <caucho/exception.hpp>

namespace caucho {

class fault_exception
:
	public exception
{
protected:
	virtual ~fault_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const std::wstring& code() const BOOST_NOEXCEPT_OR_NOTHROW = 0;
	virtual const std::wstring& message() const BOOST_NOEXCEPT_OR_NOTHROW = 0;
};

}
