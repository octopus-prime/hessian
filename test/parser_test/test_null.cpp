/*
 * test_null.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_null)

TEST_REPLY
(
	test_null,
	string_t("N", 1),
	null_t()
)

BOOST_AUTO_TEST_SUITE_END()

}
}
