/*
 * fixture_date.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_date.hpp"
#include <boost/date_time.hpp>

using boost::posix_time::from_iso_string;

namespace hessian {
namespace fixture {

const date_t fixture_date::date_0 = from_iso_string("19700101T000000");
const date_t fixture_date::date_1 = from_iso_string("19980508T095131");
const date_t fixture_date::date_2 = from_iso_string("19980508T095100");

const string_t fixture_date::hessian_0 = string_t("\x4b\x00\x00\x00\x00", 5);
const string_t fixture_date::hessian_1 = string_t("\x4a\x00\x00\x00\xd0\x4b\x92\x84\xb8", 9);
const string_t fixture_date::hessian_2 = string_t("\x4b\x00\xe3\x83\x8f", 5);

}
}
