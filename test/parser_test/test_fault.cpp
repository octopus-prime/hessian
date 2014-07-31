/*
 * test_fault.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include "../fixture/fixture_fault.hpp"

namespace hessian {
namespace parser_test {

#define TEST_FAULT_(CASE) TEST_FAULT(test_parse_fault_##CASE, hessian_##CASE, fault_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_fault, fixture::fixture_fault)

TEST_FAULT_(0);
TEST_FAULT_(1);

BOOST_AUTO_TEST_SUITE_END()

}
}
