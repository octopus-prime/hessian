/*
 * abstract_service_impl.cpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#include "abstract_service_impl.hpp"
#include <boost/format.hpp>

namespace caucho {

class fault_exception
:
	public virtual std::exception
{
public:
	fault_exception(const hessian::fault_t& fault);
	virtual ~fault_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;
//	virtual std::wstring code() const;
//	virtual std::wstring message() const;

protected:
	static std::string build(const hessian::fault_t& fault);

private:
	std::string _what;
};

fault_exception::fault_exception(const hessian::fault_t& fault)
:
	exception(),
	_what(build(fault))
{
}

const char*
fault_exception::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return _what.c_str();
}

std::string
fault_exception::build(const hessian::fault_t& fault)
{
	static const hessian::string_t CODE(L"code");
	static const hessian::string_t MESSAGE(L"message");

	boost::wformat format(L"code = '%s', message = '%s'");
	format % boost::get<hessian::string_t>(fault.at(CODE));
	format % boost::get<hessian::string_t>(fault.at(MESSAGE));
	const hessian::string_t what = format.str();
	return std::string(what.begin(), what.end());
}

class content_visitor
:
	public boost::static_visitor<const hessian::reply_t&>
{
public:
	result_type operator()(const hessian::reply_t& reply) const;
	result_type operator()(const hessian::fault_t& fault) const;
};

content_visitor::result_type
content_visitor::operator()(const hessian::reply_t& reply) const
{
	return reply;
}

content_visitor::result_type
content_visitor::operator()(const hessian::fault_t& fault) const
{
	throw fault_exception(fault);
}

abstract_service_impl::abstract_service_impl(const boost::shared_ptr<client_impl>& client, const std::string& path)
:
	service_base(),
	_client(client),
	_path(path)
{
}

hessian::reply_t
abstract_service_impl::call(const hessian::string_t& method, const hessian::list_t& arguments)
{
	const hessian::content_t content = _client->call(_path, method, arguments);
	return boost::apply_visitor(content_visitor(), content);
}

}
