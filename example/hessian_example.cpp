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
	const client::object_1 dto(0);
	try
	{
		const client::service service = client::make_service("hessian.caucho.com", 80);
		service->arg_int_0(0);
		service->arg_double_0_0(0.0);
		service->arg_object_1(dto);
		service->reply_object_1();
	}
	catch (const std::exception& exception)
	{
		std::cout << "std error: "<< exception.what() << std::endl;
	}
	return 0;
}
