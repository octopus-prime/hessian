/*
 * test_date.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include <boost/date_time.hpp>

using boost::posix_time::from_iso_string;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_date)

TEST_REPLY
(
	test_date_0,
	string_t("\x4b\x00\x00\x00\x00", 5),
	from_iso_string("19700101T000000")
)

TEST_REPLY
(
	test_date_1,
	string_t("\x4a\x00\x00\x00\xd0\x4b\x92\x84\xb8", 9),
	from_iso_string("19980508T095131")
)

TEST_REPLY
(
	test_date_2,
	string_t("\x4b\x00\xe3\x83\x8f", 5),
	from_iso_string("19980508T095100")
)

BOOST_AUTO_TEST_SUITE_END()

}
}
