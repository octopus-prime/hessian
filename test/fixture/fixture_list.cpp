/*
 * fixture_list.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_list.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::list_of;

namespace hessian {
namespace fixture {

const list_t fixture_list::list_0 = list_t();
const list_t fixture_list::list_1 = list_of<string_t>("1");
const list_t fixture_list::list_7 = list_of<string_t>("1")("2")("3")("4")("5")("6")("7");
const list_t fixture_list::list_8 = list_of<string_t>("1")("2")("3")("4")("5")("6")("7")("8");

const string_t fixture_list::hessian_u_0 = string_t("\x78", 1);
const string_t fixture_list::hessian_u_1 = string_t("\x79\x01""1", 3);
const string_t fixture_list::hessian_u_7 = string_t("\x7f\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 15);
const string_t fixture_list::hessian_u_8 = string_t("X\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 18);

const string_t fixture_list::hessian_t_0 = string_t("\x70\x07""[string", 9);
const string_t fixture_list::hessian_t_1 = string_t("\x71\x07""[string""\x01""1", 11);
const string_t fixture_list::hessian_t_7 = string_t("\x77\x07""[string""\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 23);
const string_t fixture_list::hessian_t_8 = string_t("V\x07[string\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 26);

}
}
