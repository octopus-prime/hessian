/*
 * generator.hpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <hessian/exception.hpp>
#include <iostream>

namespace hessian {

/**
 * Defines generator exception.
 */
class generator_exception
:
	public exception
{
protected:
	virtual ~generator_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
};

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
	 * Generates content into stream.
	 * @param method The method.
	 * @param arguments The arguments.
	 * @throws generator_exception Failure while generating.
	 */
	void operator()(const string_t& method, const list_t& arguments);

private:
	std::ostream& _stream;
};

}
