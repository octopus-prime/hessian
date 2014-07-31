/*
 * test_date.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"
#include <boost/date_time.hpp>

using boost::posix_time::from_iso_string;

namespace hessian {
namespace generator_test {

BOOST_AUTO_TEST_SUITE(test_date)

TEST_CALL
(
	test_date_0,
	from_iso_string("19700101T000000"),
	string_t("\x4b\x00\x00\x00\x00", 5)
)

TEST_CALL
(
	test_date_1,
	from_iso_string("19980508T095131"),
	string_t("\x4a\x00\x00\x00\xd0\x4b\x92\x84\xb8", 9)
)

TEST_CALL
(
	test_date_2,
	from_iso_string("19980508T095100"),
	string_t("\x4b\x00\xe3\x83\x8f", 5)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
