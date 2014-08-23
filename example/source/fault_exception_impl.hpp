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
	virtual const std::wstring& code() const BOOST_NOEXCEPT_OR_NOTHROW;
	virtual const std::wstring& message() const BOOST_NOEXCEPT_OR_NOTHROW;

protected:
	static std::string what(const std::wstring& code, const std::wstring& message);

private:
	static const std::wstring CODE;
	static const std::wstring MESSAGE;

	std::wstring _code;
	std::wstring _message;
	std::string _what;
};

}
