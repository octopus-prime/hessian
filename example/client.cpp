/*
 * client.cpp
 *
 *  Created on: 04.08.2014
 *      Author: mike_gresens
 */

#include "client.hpp"
#include <hessian/hessian.hpp>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPMessage.h>
#include <Poco/Net/HTTPResponse.h>

#include <boost/make_shared.hpp>
#include <boost/format.hpp>

namespace client {

class fault_exception
:
	public virtual exception
{
public:
	fault_exception(const hessian::fault_t& fault);
	virtual ~fault_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;

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
	static const hessian::string_t CODE("code");
	static const hessian::string_t MESSAGE("message");

	boost::format what("code = '%s', message = '%s'");
	what % boost::get<hessian::string_t>(fault.at(CODE));
	what % boost::get<hessian::string_t>(fault.at(MESSAGE));
	return what.str();
}

object_1::object_1(const boost::int32_t value)
:
	_value(value)
{
}

boost::int32_t
object_1::get_value() const
{
	return _value;
}

class content_visitor
:
	public boost::static_visitor<void>
{
public:
	result_type operator()(const hessian::reply_t& content) const;
	result_type operator()(const hessian::fault_t& content) const;
};

content_visitor::result_type
content_visitor::operator()(const hessian::reply_t& content) const
{
	std::cout << "reply = " << content << std::endl;
}

content_visitor::result_type
content_visitor::operator()(const hessian::fault_t& content) const
{
	throw fault_exception(content);
}

class abstract_service_impl
{
protected:
	abstract_service_impl(const std::string& host, const boost::uint16_t port, const std::string& path);
	virtual ~abstract_service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	hessian::content_t call(const std::string& method, const hessian::list_t& arguments);

private:
	Poco::Net::HTTPClientSession _session;
	std::string _path;
};

abstract_service_impl::abstract_service_impl(const std::string& host, const boost::uint16_t port, const std::string& path)
:
	_session(host, port),
	_path(path)
{
}

hessian::content_t
abstract_service_impl::call(const std::string& method, const hessian::list_t& arguments)
{
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, _path, Poco::Net::HTTPMessage::HTTP_1_1);
	request.setChunkedTransferEncoding(true);

	std::ostream& request_stream = _session.sendRequest(request);
	hessian::generator generate(request_stream);
	generate(method, arguments);

	Poco::Net::HTTPResponse response;
	std::istream& response_stream = _session.receiveResponse(response);
	if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_OK)
		throw std::runtime_error(response.getReason());

	hessian::parser parse(response_stream);
	return parse();
}

class service_impl
:
	public virtual service_base,
	public abstract_service_impl
{
public:
	service_impl(const std::string& host, const boost::uint16_t port);
	virtual ~service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual void arg_int_0(const boost::int32_t value);
	virtual void arg_double_0_0(const double value);
	virtual void arg_object_1(const object_1& dto);
	virtual object_1 reply_object_1();
	virtual void fault();
};

service_impl::service_impl(const std::string& host, const boost::uint16_t port)
:
	service_base(),
	abstract_service_impl(host, port, "/test/test2")
{
}

void
service_impl::arg_int_0(const boost::int32_t value)
{
	const hessian::content_t content = call("argInt_0", hessian::make_list(value));
	boost::apply_visitor(content_visitor(), content);
}

void
service_impl::arg_double_0_0(const double value)
{
	const hessian::content_t content = call("argDouble_0_0", hessian::make_list(value));
	boost::apply_visitor(content_visitor(), content);
}

static hessian::object_t
transform_object_1(const object_1& dto)
{
	return hessian::make_object
	(
		"_value",	dto.get_value()
	);
}

void
service_impl::arg_object_1(const object_1& dto)
{
	const hessian::object_t object = transform_object_1(dto);
	const hessian::content_t content = call("argObject_1", hessian::make_list(object));
	boost::apply_visitor(content_visitor(), content);
}

static object_1
transform_object_1(const hessian::object_t& dto)
{
	return object_1
	(
		boost::get<hessian::int_t>(dto.at("_value"))
	);
}

object_1
service_impl::reply_object_1()
{
	const hessian::content_t content = call("replyObject_1", hessian::list_t());
	boost::apply_visitor(content_visitor(), content);
	return transform_object_1(boost::get<hessian::object_t>(boost::get<hessian::reply_t>(content)));
}

void
service_impl::fault()
{
	const hessian::content_t content = call("replyFoo", hessian::list_t());
	boost::apply_visitor(content_visitor(), content);
}

service
make_service(const std::string& host, const boost::uint16_t port)
{
	return boost::make_shared<service_impl>(host, port);
}

}
