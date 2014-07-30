/*
 * test_boolean.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"

namespace hessian {
namespace generator_test {

BOOST_AUTO_TEST_SUITE(test_boolean)

TEST_CALL
(
	test_true,
	make_list(boolean_t(true)),
	std::string("\x91""T", 2)
)

TEST_CALL
(
	test_false,
	make_list(boolean_t(false)),
	std::string("\x91""F", 2)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
