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

namespace client {

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
	std::cout << "fault = " << content << std::endl;
}

class session_impl
{
protected:
	session_impl(const std::string& host, const boost::uint16_t port, const std::string& path);
	virtual ~session_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	hessian::content_t call(const std::string& method, const hessian::list_t& arguments);

private:
	Poco::Net::HTTPClientSession _session;
	std::string _path;
};

session_impl::session_impl(const std::string& host, const boost::uint16_t port, const std::string& path)
:
	_session(host, port),
	_path(path)
{
}

hessian::content_t
session_impl::call(const std::string& method, const hessian::list_t& arguments)
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
	public session_impl
{
public:
	service_impl(const std::string& host, const boost::uint16_t port);
	virtual ~service_impl() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual void test_int_0();
	virtual void test_double_0_0();
	virtual void test_object_1(const object_1& dto);
};

service_impl::service_impl(const std::string& host, const boost::uint16_t port)
:
	service_base(),
	session_impl(host, port, "/test/test2")
{
}

void
service_impl::test_int_0()
{
	const hessian::int_t object = 0;
	const hessian::content_t content = call("argInt_0", hessian::make_list(object));
	boost::apply_visitor(content_visitor(), content);
}

void
service_impl::test_double_0_0()
{
	const hessian::double_t object = 0.0;
	const hessian::content_t content = call("argDouble_0_0", hessian::make_list(object));
	boost::apply_visitor(content_visitor(), content);
}

void
service_impl::test_object_1(const object_1& dto)
{
	const hessian::object_t object = hessian::make_object("_value", dto.get_value());
	const hessian::content_t content = call("argObject_1", hessian::make_list(object));
	boost::apply_visitor(content_visitor(), content);
}

service
make_service(const std::string& host, const boost::uint16_t port)
{
	return boost::make_shared<service_impl>(host, port);
}

}
