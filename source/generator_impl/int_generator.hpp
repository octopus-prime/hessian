/*
 * int_generator.hpp
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

class int_generator
:
	public ka::grammar<output_iterator_t, int_t()>
{
public:
	int_generator();

private:
	ka::rule<output_iterator_t, int_t()> _int;
	ka::rule<output_iterator_t, int_t()> _int_1;
	ka::rule<output_iterator_t, int_t()> _int_2;
	ka::rule<output_iterator_t, int_t()> _int_3;
	ka::rule<output_iterator_t, int_t()> _int_4;
};

}
}
