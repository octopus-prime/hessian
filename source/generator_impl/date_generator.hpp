/*
 * date_generator.hpp
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

class date_generator
:
	public ka::grammar<output_iterator_t, date_t(), ka::locals<boost::posix_time::time_duration, boost::int64_t> >
{
public:
	date_generator();

private:
	ka::rule<output_iterator_t, date_t(), ka::locals<boost::posix_time::time_duration, boost::int64_t> > _date;
	ka::rule<output_iterator_t, date_t(boost::int64_t)> _date_1;
	ka::rule<output_iterator_t, date_t(boost::int64_t)> _date_2;
};

}
}
