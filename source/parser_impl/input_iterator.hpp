/*
 * input_iterator.hpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#pragma once

#include <boost/spirit/include/support_istream_iterator.hpp>

namespace hessian {
namespace parser_impl {

typedef boost::spirit::istream_iterator input_iterator_t;

}
}
