/*
 * null_generator.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <boost/spirit/include/karma_symbols.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class null_generator
:
	public ka::symbols<null_t, char const*>
{
public:
	null_generator();
};

}
}
