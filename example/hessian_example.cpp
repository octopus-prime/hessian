/*
 * hessian_example.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "client.hpp"
#include <exception>
#include <iostream>

int
main()
{
	try
	{
		const client::service service = client::make_service("hessian.caucho.com", 80);
		service->arg_int_0(0);
		service->arg_double_0_0(0.0);
		service->arg_object_1(client::object_1(0));
		const client::object_1 object_1 = service->reply_object_1();
		std::cout << object_1.get_value() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << "std error: "<< exception.what() << std::endl;
	}
	return 0;
}
