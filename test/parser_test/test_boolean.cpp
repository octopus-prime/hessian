/*
 * test_boolean.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include <hessian/hessian.hpp>
#include "parser_helper.hpp"
#include <boost/test/unit_test.hpp>

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_boolean)

BOOST_AUTO_TEST_CASE(test_true)
{
	reply_t reply;

	BOOST_REQUIRE_NO_THROW
	(
		reply = parse_reply("T");
	)

	BOOST_CHECK(equal_to()(reply, boolean_t(true)));
}

BOOST_AUTO_TEST_CASE(test_false)
{
	reply_t reply;

	BOOST_REQUIRE_NO_THROW
	(
		reply = parse_reply("F");
	)

	BOOST_CHECK(equal_to()(reply, boolean_t(false)));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
