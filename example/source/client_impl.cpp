/*
 * client_impl.cpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#include "client_impl.hpp"
#include "test2_service_impl.hpp"
#include <Poco/URI.h>
#include <Poco/URIStreamOpener.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPSessionFactory.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPMessage.h>
#include <Poco/Net/HTTPResponse.h>
#include <boost/make_shared.hpp>
#include <boost/log/trivial.hpp>
#include <fstream>

namespace caucho {

client_impl::client_impl(const session& session)
:
	client_base(),
	boost::enable_shared_from_this<client_impl>(),
	_session(session),
	_cookies(),
	_mutex()
{
}

test2_service
client_impl::get_test2_service()
{
	return boost::make_shared<test2_service_impl>(shared_from_this());
}

hessian::content_t
client_impl::call(const std::string& path, const hessian::string_t& method, const hessian::list_t& arguments)
{
	boost::unique_lock<boost::mutex> lock(_mutex);
	send_request(path, method, arguments);
	return receive_response();
}

void
client_impl::send_request(const std::string& path, const hessian::string_t& method, const hessian::list_t& arguments)
{
	net::NameValueCollection cookies;
	for (cookies::const_iterator cookie = _cookies.begin(); cookie != _cookies.end(); ++cookie)
		cookies.add(cookie->first, cookie->second);

	net::HTTPRequest request(net::HTTPRequest::HTTP_POST, path, net::HTTPMessage::HTTP_1_1);
	request.setChunkedTransferEncoding(true);
	request.setCookies(cookies);

	std::ostream& request_stream = _session->sendRequest(request);
	hessian::generator generate(request_stream);
	generate(method, arguments);
}

hessian::content_t
client_impl::receive_response()
{
	net::HTTPResponse response;
	std::istream& response_stream = _session->receiveResponse(response);
	if (response.getStatus() != net::HTTPResponse::HTTP_OK)
		throw std::runtime_error(response.getReason());

	std::vector<net::HTTPCookie> cookies;
	response.getCookies(cookies);
	for (std::vector<net::HTTPCookie>::const_iterator cookie = cookies.begin(); cookie != cookies.end(); ++cookie)
		_cookies[cookie->getName()] = cookie->getValue();

	hessian::parser parse(response_stream);
	return parse();
}

static void
destroy_session(net::HTTPClientSession* session)
{
	delete session;
	BOOST_LOG_TRIVIAL(info) << "Destroyed client session";
}

client
make_client(const std::string& uri)
{
	net::HTTPSessionFactory& factory = net::HTTPSessionFactory::defaultFactory();
	const session session(factory.createClientSession(Poco::URI(uri)), destroy_session);
	BOOST_LOG_TRIVIAL(info) << "Created client session to uri '" << uri << "'";
	return boost::make_shared<client_impl>(session);
}

void
download_file(const std::string& uri, const std::string& file)
{
	const Poco::URIStreamOpener& opener = Poco::URIStreamOpener::defaultOpener();
	const std::auto_ptr<std::istream> input_stream(opener.open(uri));
	std::ofstream output_stream(file.c_str());
	const std::size_t bytes = Poco::StreamCopier::copyStream(*input_stream, output_stream);
	output_stream.close();
	BOOST_LOG_TRIVIAL(info) << "Loaded file '" << file << "' (" << bytes << " bytes) down from uri '" << uri << "'";
}

}
