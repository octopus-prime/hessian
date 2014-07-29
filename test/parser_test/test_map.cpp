/*
 * test_map.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

using boost::assign::map_list_of;
using boost::assign::list_of;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_map)

static const map_t map_0 = map_t();
static const map_t map_1 = map_list_of<string_t, int_t>("a", 0);
static const map_t map_2 = map_list_of<int_t, string_t>(0, "a")(1, "b");
static const map_t map_3 = map_list_of<list_t, int_t>(list_of<string_t>("a"),	0);

TEST_REPLY
(
	test_map_untyped_0,
	string_t("H""Z", 2),
	map_0
)

TEST_REPLY
(
	test_map_untyped_1,
	string_t("H""\x01""a""\x90""Z", 5),
	map_1
)

TEST_REPLY
(
	test_map_untyped_2,
	string_t("H""\x90""\x01""a""\x91""\x01""b""Z", 8),
	map_2
)

TEST_REPLY
(
	test_map_untyped_3,
	string_t("H""\x79""\x01""a""\x90""Z", 6),
	map_3
)

TEST_REPLY
(
	test_map_typed_0,
	string_t("M""\x13""java.lang.Hashtable""Z", 22),
	map_0
)

TEST_REPLY
(
	test_map_typed_1,
	string_t("M""\x13""java.lang.Hashtable""\x01""a""\x90""Z", 25),
	map_1
)

TEST_REPLY
(
	test_map_typed_2,
	string_t("M""\x13""java.lang.Hashtable""\x90""\x01""a""\x91""\x01""b""Z", 28),
	map_2
)

TEST_REPLY
(
	test_map_typed_3,
	string_t("M""\x13""java.lang.Hashtable""\x79""\x01""a""\x90""Z", 26),
	map_3
)

BOOST_AUTO_TEST_SUITE_END()

}
}
