/*
 * hessian_example.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include <caucho/client.hpp>
#include <exception>
#include <iostream>

int
main()
{
	try
	{
		const caucho::client client = caucho::make_http_client("hessian.caucho.com", 80);
		const caucho::test2_service service = client->get_test2_service();
		std::wcout << std::boolalpha;
		std::wcout << service->arg_int_0(0) << std::endl;
		std::wcout << service->arg_int_0(1) << std::endl;
		std::wcout << service->arg_double_0_0(0.0) << std::endl;
		std::wcout << service->arg_double_0_0(1.0) << std::endl;
//		service->arg_object_1(client::object_1(0));
//		const client::object_1 object_1 = service->reply_object_1();
//		std::cout << object_1.get_value() << std::endl;
		service->fault();
	}
	catch (const caucho::fault_exception& exception)
	{
		std::wcerr << L"fault: " << exception.code() << L": " << exception.message() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "error: " << exception.what() << std::endl;
	}
	return 0;
}
