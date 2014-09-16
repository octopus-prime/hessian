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
class HESSIAN_EXPORT parser_exception
:
	public virtual exception
{
protected:
	virtual ~parser_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
};

/**
 * Implements parser.
 */
class HESSIAN_EXPORT parser
{
public:
	/**
	 * Constructor.
	 * @param stream The stream.
	 */
	parser(std::istream& stream);

	/**
	 * Parses content from stream.
	 * @return The content.
	 * @throws parser_exception Failure while parsing.
	 */
	content_t operator()();

private:
	std::istream& _stream;
};

}
