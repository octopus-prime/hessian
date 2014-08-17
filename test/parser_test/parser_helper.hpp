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
parse_reply(const std::string& reply);

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

fault_t
parse_fault(const std::string& fault);

#define TEST_FAULT(test_name, fault_value, expected_value) \
BOOST_AUTO_TEST_CASE(test_name)\
{\
	fault_t fault;\
\
	BOOST_REQUIRE_NO_THROW\
	(\
		fault = parse_fault(fault_value);\
	)\
\
	BOOST_CHECK(equal_to()(fault, expected_value));\
}

}
}
