/*
 * generator.cpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#include <hessian/generator.hpp>
#include <boost/spirit/include/karma.hpp>

namespace karma = boost::spirit::karma;

namespace hessian {

generator::generator(std::ostream& stream)
:
	_stream(stream)
{
}

void
generator::operator()(const string_t& method, const list_t& arguments)
{
	_stream << method << ": " << arguments;
}

}
