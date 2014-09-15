/*
 * hessian_example.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "hessian_example_pch.hpp"	// windows... wth!
#include <caucho/client.hpp>
#include <Poco/Exception.h>
#include <exception>
#include <iostream>

int
main()
{
	try
	{
		caucho::download_file("http://httpbin.org/stream/100", "out.txt");

#ifndef _WIN32
		caucho::download_file("https://sslcheck.globalsign.com/images/special-offer-sticker.png", "special-offer-sticker.png");
#endif

		const caucho::client client = caucho::make_client("http://hessian.caucho.com");

		const caucho::test2_service service = client->get_test2_service();

		std::wcout << std::boolalpha;
		std::wcout << service->arg_int_0(0) << std::endl;
		std::wcout << service->arg_int_0(1) << std::endl;
		std::wcout << service->arg_double_0_0(0.0) << std::endl;
		std::wcout << service->arg_double_0_0(1.0) << std::endl;

		service->fault();
	}
	catch (const caucho::fault_exception& exception)
	{
		std::wcerr << L"fault: " << exception.code() << L": " << exception.message() << std::endl;
	}
	catch (const Poco::Exception& exception)
	{
		std::cerr << "error: " << exception.displayText() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "error: " << exception.what() << std::endl;
	}
	return 0;
}
