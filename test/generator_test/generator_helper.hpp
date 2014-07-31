/*
 * generator_helper.hpp
 *
 *  Created on: 30.07.2014
 *      Author: mgresens
 */

#pragma once

#include <hessian/hessian.hpp>
#include "../../source/constant.hpp"
#include <boost/test/unit_test.hpp>

namespace hessian {
namespace generator_test {

string_t
generate_call(const list_t& argument);

#define TEST_CALL(test_name, argument, expected) \
BOOST_AUTO_TEST_CASE(test_name)\
{\
	string_t call;\
\
	BOOST_REQUIRE_NO_THROW\
	(\
		call = generate_call(make_list(argument));\
	)\
\
	BOOST_CHECK_EQUAL(call, constant::VERSION + "C""\x06""method""\x91" + expected);\
}

}
}
