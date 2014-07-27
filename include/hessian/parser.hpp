/*
 * parser.hpp
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
 * Defines reply type.
 */
typedef value_t reply_t;

/**
 * Defines fault type.
 */
typedef map_t fault_t;

/**
 * Defines content type.
 */
typedef boost::variant
<
	reply_t,
	fault_t
> content_t;

/**
 * Defines parser exception.
 */
class parser_exception
:
	public exception
{
protected:
	virtual ~parser_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
};

/**
 * Implements parser.
 */
class parser
{
public:
	/**
	 * Constructor.
	 * @param stream The stream.
	 */
	parser(std::istream& stream);

	/**
	 * Parses reply from stream.
	 * @return The reply.
	 * @throws parser_exception
	 */
	content_t operator()();

private:
	std::istream& _stream;
};

}
