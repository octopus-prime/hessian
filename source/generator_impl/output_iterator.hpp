/*
 * output_iterator.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <boost/spirit/include/support_ostream_iterator.hpp>

namespace hessian {
namespace generator_impl {

typedef boost::spirit::ostream_iterator output_iterator_t;

}
}
