/*
 * long_generator.hpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>
#include "output_iterator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class long_generator
:
	public ka::grammar<output_iterator_t, long_t()>
{
public:
	long_generator();

private:
	ka::rule<output_iterator_t, long_t()> _long;
	ka::rule<output_iterator_t, long_t()> _long_1;
	ka::rule<output_iterator_t, long_t()> _long_2;
	ka::rule<output_iterator_t, long_t()> _long_3;
	ka::rule<output_iterator_t, long_t()> _long_4;
	ka::rule<output_iterator_t, long_t()> _long_5;
};

}
}
