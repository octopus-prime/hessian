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
	boolean_t(true),
	string_t("T", 1)
)

TEST_CALL
(
	test_false,
	boolean_t(false),
	string_t("F", 1)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
