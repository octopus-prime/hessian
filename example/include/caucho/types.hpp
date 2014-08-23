/*
 * types.hpp
 *
 *  Created on: 21.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <string>
#include <boost/cstdint.hpp>
#include <boost/variant.hpp>

namespace caucho {

typedef bool boolean_t;
typedef boost::int32_t int_t;
typedef boost::int64_t long_t;
typedef double double_t;
typedef std::wstring string_t;

typedef boost::variant<boolean_t, string_t> result_t;

}
