/*
 * test_date.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../fixture/fixture_date.hpp"

namespace hessian {
namespace parser_test {

#define TEST_DATE(CASE) TEST_REPLY(test_parse_date_##CASE, hessian_##CASE, date_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_parse_date, fixture::fixture_date)

TEST_DATE(0);
TEST_DATE(1);
TEST_DATE(2);

BOOST_AUTO_TEST_SUITE_END()

}
}
