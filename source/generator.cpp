/*
 * generator.cpp
 *
 *  Created on: 24.07.2014
 *      Author: mike_gresens
 */

#include <hessian/generator.hpp>
#include "generator_impl/output_iterator.hpp"
#include "generator_impl/version_generator.hpp"
#include "generator_impl/value_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace ka = boost::spirit::karma;
namespace px = boost::phoenix;

namespace hessian {

class generator_failure_exception
:
	public generator_exception
{
public:
	generator_failure_exception();
	virtual ~generator_failure_exception() BOOST_NOEXCEPT_OR_NOTHROW {}
	virtual const char* what() const BOOST_NOEXCEPT_OR_NOTHROW;
};

generator::generator(std::ostream& stream)
:
	_stream(stream)
{
}

void
generator::operator()(const string_t& method, const list_t& arguments)
{
	generator_impl::version_generator version;
	generator_impl::value_generator value;

	const bool success = ka::generate
	(
		generator_impl::output_iterator_t(_stream),
		version										// version
		<<
		ka::lit('C')								// call
		<<
		ka::byte_ << ka::string						// method
		<<
		ka::byte_ << *value,						// arguments
		method.size(),
		method,
		arguments.size() + '\x90',
		arguments
	);

	if (!success)
		throw generator_failure_exception();

	// todo ka::byte_ => int_generator
}

generator_failure_exception::generator_failure_exception()
:
	generator_exception()
{
}

const char*
generator_failure_exception::what() const BOOST_NOEXCEPT_OR_NOTHROW
{
	return "Generating failed.";
}

}
