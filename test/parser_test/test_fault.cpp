/*
 * test_fault.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

using boost::assign::map_list_of;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_fault)

static const fault_t fault_0 = fault_t();
static const fault_t fault_1 = map_list_of<string_t, value_t>("code", int_t(7))("message", string_t("This is a fault"));

TEST_FAULT
(
	test_fault_0,
	string_t("Z", 1),
	fault_0
)

TEST_FAULT
(
	test_fault_1,
	string_t("\x04""code""\x97""\x07""message""\x0f""This is a fault""Z", 31),
	fault_1
)

BOOST_AUTO_TEST_SUITE_END()

}
}
