/*
 * test_null.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include <hessian/hessian.hpp>
#include "parser_helper.hpp"
#include <boost/test/unit_test.hpp>

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_null)

BOOST_AUTO_TEST_CASE(test_null)
{
	reply_t reply;

	BOOST_REQUIRE_NO_THROW
	(
		reply = parse_reply("N");
	)

	BOOST_CHECK(equal_to()(reply, null_t()));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
