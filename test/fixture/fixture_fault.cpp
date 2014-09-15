/*
 * fixture_fault.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_fault.hpp"
#include <boost/assign/list_of.hpp>

using boost::assign::map_list_of;

namespace hessian {
namespace fixture {

const fault_t fixture_fault::fault_0 = fault_t();
const fault_t fixture_fault::fault_1 = map_list_of<string_t, value_t>(L"code", int_t(7))(L"message", string_t(L"This is a fault"));

const std::string fixture_fault::hessian_0 = std::string("HZ", 2);
const std::string fixture_fault::hessian_1 = std::string("H""\x04""code""\x97""\x07""message""\x0f""This is a fault""Z", 32);

}
}
