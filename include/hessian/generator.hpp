/*
 * generator.hpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <iostream>

namespace hessian {

/**
 * Implements generator.
 */
class generator
{
public:
	/**
	 * Constructor.
	 * @param stream The stream.
	 */
	generator(std::ostream& stream);

	/**
	 * Generates call into stream.
	 * @param method The method.
	 * @param arguments The arguments.
	 */
	void operator()(const string_t& method, const list_t& arguments);

private:
	std::ostream& _stream;
};

}
