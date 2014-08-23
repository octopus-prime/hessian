/*
 * fault_exception_impl.hpp
 *
 *  Created on: 23.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <caucho/fault_exception.hpp>
#include <hessian/hessian.hpp>

namespace caucho {

class fault_exception_impl
:
	public virtual fault_exception
{
public:
	fault_exception_impl(const hessian::fault_t& fault);
	virtual ~fault_exception_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;
	virtual const string_t& code() const BOOST_NOEXCEPT_OR_NOTHROW;
	virtual const string_t& message() const BOOST_NOEXCEPT_OR_NOTHROW;

protected:
	static std::string what(const string_t& code, const string_t& message);

private:
	static const string_t CODE;
	static const string_t MESSAGE;

	string_t _code;
	string_t _message;
	std::string _what;
};

}
