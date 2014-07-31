/*
 * fixture_map.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_map.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::map_list_of;
using boost::assign::list_of;

namespace hessian {
namespace fixture {

const map_t fixture_map::map_0 = map_t();
const map_t fixture_map::map_1 = map_list_of<string_t, int_t>("a", 0);
const map_t fixture_map::map_2 = map_list_of<int_t, string_t>(0, "a")(1, "b");
const map_t fixture_map::map_3 = map_list_of<list_t, int_t>(list_of<string_t>("a"),	0);

const string_t fixture_map::hessian_u_0 = string_t("H""Z", 2);
const string_t fixture_map::hessian_u_1 = string_t("H""\x01""a""\x90""Z", 5);
const string_t fixture_map::hessian_u_2 = string_t("H""\x90""\x01""a""\x91""\x01""b""Z", 8);
const string_t fixture_map::hessian_u_3 = string_t("H""\x79""\x01""a""\x90""Z", 6);

const string_t fixture_map::hessian_t_0 = string_t("M""\x13""java.lang.Hashtable""Z", 22);
const string_t fixture_map::hessian_t_1 = string_t("M""\x13""java.lang.Hashtable""\x01""a""\x90""Z", 25);
const string_t fixture_map::hessian_t_2 = string_t("M""\x13""java.lang.Hashtable""\x90""\x01""a""\x91""\x01""b""Z", 28);
const string_t fixture_map::hessian_t_3 = string_t("M""\x13""java.lang.Hashtable""\x79""\x01""a""\x90""Z", 26);

}
}
