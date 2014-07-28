/*
 * version_generator.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include "output_iterator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class version_generator
:
	public ka::grammar<output_iterator_t>
{
public:
	version_generator();

private:
	ka::rule<output_iterator_t> _version;
};

}
}
