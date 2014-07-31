/*
 * fixture_fault.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_fault.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::map_list_of;

namespace hessian {
namespace fixture {

const fault_t fixture_fault::fault_0 = fault_t();
const fault_t fixture_fault::fault_1 = map_list_of<string_t, value_t>("code", int_t(7))("message", string_t("This is a fault"));

const string_t fixture_fault::hessian_0 = string_t("Z", 1);
const string_t fixture_fault::hessian_1 = string_t("\x04""code""\x97""\x07""message""\x0f""This is a fault""Z", 31);

}
}
