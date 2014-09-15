/*
 * fixture_map.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_map.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::map_list_of;
using boost::assign::list_of;

namespace hessian {
namespace fixture {

const map_t fixture_map::map_0 = map_t();
const map_t fixture_map::map_1 = map_list_of<string_t, int_t>(L"a", 0);
const map_t fixture_map::map_2 = map_list_of<int_t, string_t>(0, L"a")(1, L"b");
const map_t fixture_map::map_3 = map_list_of<list_t, int_t>(list_of<string_t>(L"a"), 0);

const std::string fixture_map::hessian_u_0 = std::string("H""Z", 2);
const std::string fixture_map::hessian_u_1 = std::string("H""\x01""a""\x90""Z", 5);
const std::string fixture_map::hessian_u_2 = std::string("H""\x90""\x01""a""\x91""\x01""b""Z", 8);
const std::string fixture_map::hessian_u_3 = std::string("H""\x79""\x01""a""\x90""Z", 6);

const std::string fixture_map::hessian_t_0 = std::string("M""\x13""java.lang.Hashtable""Z", 22);
const std::string fixture_map::hessian_t_1 = std::string("M""\x13""java.lang.Hashtable""\x01""a""\x90""Z", 25);
const std::string fixture_map::hessian_t_2 = std::string("M""\x13""java.lang.Hashtable""\x90""\x01""a""\x91""\x01""b""Z", 28);
const std::string fixture_map::hessian_t_3 = std::string("M""\x13""java.lang.Hashtable""\x79""\x01""a""\x90""Z", 26);

}
}
