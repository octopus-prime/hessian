/*
 * parser_helper.hpp
 *
 *  Created on: 28.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/hessian.hpp>
#include <boost/test/unit_test.hpp>

namespace hessian {
namespace parser_test {

reply_t
parse_reply(const string_t& reply);

#define TEST_REPLY(test_name, reply_value, expected_value) \
BOOST_AUTO_TEST_CASE(test_name)\
{\
	reply_t reply;\
\
	BOOST_REQUIRE_NO_THROW\
	(\
		reply = parse_reply(reply_value);\
	)\
\
	BOOST_CHECK(equal_to()(reply, expected_value));\
}

}
}
