/*
 * initializer.cpp
 *
 *  Created on: 27.08.2014
 *      Author: mike_gresens
 */

#include "initializer.hpp"
#include <Poco/Net/Context.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/ConsoleCertificateHandler.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Net/HTTPSessionInstantiator.h>
#include <Poco/Net/HTTPSSessionInstantiator.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/HTTPSStreamFactory.h>
#include <boost/make_shared.hpp>
#include <iostream>

namespace net = Poco::Net;

namespace caucho {

const boost::shared_ptr<initializer>
initializer::INITIALIZER = boost::make_shared<initializer>();

initializer::initializer()
{
	try
	{
		const net::Context::Ptr context(new net::Context(net::Context::CLIENT_USE, "", "", ""));
		const net::SSLManager::InvalidCertificateHandlerPtr certificateHandler(new net::AcceptCertificateHandler(false));
//		const net::SSLManager::InvalidCertificateHandlerPtr certificateHandler(new net::ConsoleCertificateHandler(false));

		net::initializeNetwork();
		net::initializeSSL();
		net::SSLManager::instance().initializeClient(NULL, certificateHandler, context);
		net::HTTPSessionInstantiator::registerInstantiator();
		net::HTTPSSessionInstantiator::registerInstantiator();
		net::HTTPStreamFactory::registerFactory();
		net::HTTPSStreamFactory::registerFactory();
	}
	catch (const Poco::Exception& exception)
	{
		std::cerr << exception.displayText() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (...)
	{
	}
}

initializer::~initializer() BOOST_NOEXCEPT_OR_NOTHROW
{
	try
	{
//		net::HTTPSStreamFactory::unregisterFactory();
//		net::HTTPStreamFactory::unregisterFactory();
		net::HTTPSSessionInstantiator::unregisterInstantiator();
		net::HTTPSessionInstantiator::unregisterInstantiator();
		net::uninitializeSSL();
		net::uninitializeNetwork();
	}
	catch (const Poco::Exception& exception)
	{
		std::cerr << exception.displayText() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (...)
	{
	}
}

}
