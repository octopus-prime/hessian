/*
 * test_boolean.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_boolean)

TEST_REPLY
(
	test_true,
	string_t("T", 1),
	boolean_t(true)
)

TEST_REPLY
(
	test_false,
	string_t("F", 1),
	boolean_t(false)
)

BOOST_AUTO_TEST_SUITE_END()

}
}
