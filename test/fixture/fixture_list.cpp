/*
 * fixture_list.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_list.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::list_of;

namespace hessian {
namespace fixture {

const list_t fixture_list::list_0 = list_t();
const list_t fixture_list::list_1 = list_of<string_t>(L"1");
const list_t fixture_list::list_7 = list_of<string_t>(L"1")(L"2")(L"3")(L"4")(L"5")(L"6")(L"7");
const list_t fixture_list::list_8 = list_of<string_t>(L"1")(L"2")(L"3")(L"4")(L"5")(L"6")(L"7")(L"8");

const std::string fixture_list::hessian_u_0 = std::string("\x78", 1);
const std::string fixture_list::hessian_u_1 = std::string("\x79\x01""1", 3);
const std::string fixture_list::hessian_u_7 = std::string("\x7f\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 15);
const std::string fixture_list::hessian_u_8 = std::string("X\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 18);

const std::string fixture_list::hessian_t_0 = std::string("\x70\x07""[string", 9);
const std::string fixture_list::hessian_t_1 = std::string("\x71\x07""[string""\x01""1", 11);
const std::string fixture_list::hessian_t_7 = std::string("\x77\x07""[string""\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7", 23);
const std::string fixture_list::hessian_t_8 = std::string("V\x07[string\x98\x01""1""\x01""2""\x01""3""\x01""4""\x01""5""\x01""6""\x01""7""\x01""8", 26);

}
}
