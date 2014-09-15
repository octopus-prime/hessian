/*
 * initializer.cpp
 *
 *  Created on: 27.08.2014
 *      Author: mike_gresens
 */

#include "hessian_example_pch.hpp"
#include "initializer.hpp"
#include <Poco/Net/HTTPSessionInstantiator.h>
#include <Poco/Net/HTTPStreamFactory.h>

#ifndef _WIN32
#include <Poco/Net/Context.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/ConsoleCertificateHandler.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Net/HTTPSSessionInstantiator.h>
#include <Poco/Net/HTTPSStreamFactory.h>
#endif

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
#ifndef _WIN32
		const net::Context::Ptr context(new net::Context(net::Context::CLIENT_USE, "", "", ""));
		const net::SSLManager::InvalidCertificateHandlerPtr certificateHandler(new net::AcceptCertificateHandler(false));
		const net::SSLManager::InvalidCertificateHandlerPtr certificateHandler(new net::ConsoleCertificateHandler(false));
#endif

		net::initializeNetwork();

#ifndef _WIN32
		net::initializeSSL();
		net::SSLManager::instance().initializeClient(NULL, certificateHandler, context);
#endif

		net::HTTPSessionInstantiator::registerInstantiator();
		net::HTTPStreamFactory::registerFactory();

#ifndef _WIN32
		net::HTTPSSessionInstantiator::registerInstantiator();
		net::HTTPSStreamFactory::registerFactory();
#endif
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
		net::HTTPSessionInstantiator::unregisterInstantiator();

#ifndef _WIN32
		net::HTTPSSessionInstantiator::unregisterInstantiator();
		net::uninitializeSSL();
#endif

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
