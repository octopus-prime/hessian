/*
 * fault_exception_impl.cpp
 *
 *  Created on: 23.08.2014
 *      Author: mike_gresens
 */

#include "fault_exception_impl.hpp"
#include <boost/format.hpp>
#include <boost/regex/pending/unicode_iterator.hpp>

namespace caucho {

template <typename Iterator>
boost::u32_to_u8_iterator<Iterator>
make_u32_to_u8_iterator(const Iterator iterator)
{
	return boost::u32_to_u8_iterator<Iterator>(iterator);
}

const std::wstring
fault_exception_impl::CODE(L"code");

const std::wstring
fault_exception_impl::MESSAGE(L"message");

fault_exception_impl::fault_exception_impl(const hessian::fault_t& fault)
:
	fault_exception(),
	_code(boost::get<hessian::string_t>(fault.at(CODE))),
	_message(boost::get<hessian::string_t>(fault.at(MESSAGE))),
	_what(what(_code, _message))
{
}

const char*
fault_exception_impl::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _what.c_str();
}

const std::wstring&
fault_exception_impl::code() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _code;
}

const std::wstring&
fault_exception_impl::message() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _message;
}

std::string
fault_exception_impl::what(const std::wstring& code, const std::wstring& message)
{
	boost::wformat format(L"Fault: Code = '%s', Message = '%s'");
	const std::wstring wwhat = (format % code % message).str();
	return std::string
	(
		make_u32_to_u8_iterator(wwhat.begin()),
		make_u32_to_u8_iterator(wwhat.end())
	);
}

}
