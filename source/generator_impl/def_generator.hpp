/*
 * def_generator.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "output_iterator.hpp"
#include "int_generator.hpp"
#include "string_generator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class def_generator
:
	public ka::grammar<output_iterator_t, std::vector<string_t>()>
{
public:
	def_generator();

private:
	// Top rule
	ka::rule<output_iterator_t, std::vector<string_t>()> _def;

	// Terminal rules
	int_generator _int;
	string_generator _string;
};

}
}
