/*
 * boolean_generator.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include <boost/spirit/include/karma_symbols.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class boolean_generator
:
	public ka::symbols<boolean_t, char const*>
{
public:
	boolean_generator();
};

}
}
