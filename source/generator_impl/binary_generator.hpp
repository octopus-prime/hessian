/*
 * binary_generator.hpp
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

class binary_generator
:
	public ka::grammar<output_iterator_t, binary_t()>
{
public:
	binary_generator();

private:
	ka::rule<output_iterator_t, binary_t()> _binary;
	ka::rule<output_iterator_t, binary_t()> _binary_1;
	ka::rule<output_iterator_t, binary_t()> _binary_2;
	ka::rule<output_iterator_t, void(std::size_t)> _length;
	ka::rule<output_iterator_t, void(std::size_t)> _length_1;
	ka::rule<output_iterator_t, void(std::size_t)> _length_2;
	ka::rule<output_iterator_t, void(std::size_t)> _length_3;
	ka::rule<output_iterator_t, void()> _length_4;
};

}
}
