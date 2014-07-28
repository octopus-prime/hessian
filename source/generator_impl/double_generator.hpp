/*
 * double_generator.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include "output_iterator.hpp"
#include <boost/spirit/include/karma_grammar.hpp>
#include <boost/spirit/include/karma_symbols.hpp>

namespace ka = boost::spirit::karma;

namespace hessian {
namespace generator_impl {

class double_generator
:
	public ka::grammar<output_iterator_t, double_t(), ka::locals<bool,double> >
{
public:
	double_generator();

private:
	ka::rule<output_iterator_t, double_t(), ka::locals<bool,double> > _double;
	ka::rule<output_iterator_t, double_t()> _double_1;
	ka::rule<output_iterator_t, double_t(), ka::locals<bool,double> > _double_2;
	ka::rule<output_iterator_t, double_t(), ka::locals<bool> > _double_3;
	ka::rule<output_iterator_t, double_t(), ka::locals<bool> > _double_4;
	ka::symbols<double_t, char const*> _double_5;
};

}
}
