/*
 * test_list.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"

using boost::assign::list_of;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_list)

static const list_t list_0 = list_t();
static const list_t list_1 = list_of<string_t>("1");
static const list_t list_7 = list_of<string_t>("1")("2")("3")("4")("5")("6")("7");
static const list_t list_8 = list_of<string_t>("1")("2")("3")("4")("5")("6")("7")("8");

TEST_REPLY
(
	test_list_uf_0,
	string_t("\x78", 1),
	list_0
)

TEST_REPLY
(
	test_list_uf_1,
	string_t("\x79\x01""1", 3),
	list_1
)

TEST_REPLY
(
	test_list_uf_7,
	string_t("\x7f\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 15),
	list_7
)

TEST_REPLY
(
	test_list_uf_8,
	string_t("X\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 18),
	list_8
)

TEST_REPLY
(
	test_list_tf_0,
	string_t("\x70\x07""[string", 9),
	list_0
)

TEST_REPLY
(
	test_list_tf_1,
	string_t("\x71\x07""[string""\x01""1", 11),
	list_1
)

TEST_REPLY
(
	test_list_tf_7,
	string_t("\x77\x07""[string""\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 23),
	list_7
)

TEST_REPLY
(
	test_list_tf_8,
	string_t("V\x07[string\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 26),
	list_8
)

BOOST_AUTO_TEST_SUITE_END()

}
}
