/*
 * test_date.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "generator_helper.hpp"
#include "../fixture/fixture_date.hpp"

namespace hessian {
namespace generator_test {

#define TEST_DATE(CASE) TEST_CALL(test_generate_date_##CASE, date_##CASE, hessian_##CASE)

BOOST_FIXTURE_TEST_SUITE(test_generate_date, fixture::fixture_date)

TEST_DATE(0);
TEST_DATE(1);
TEST_DATE(2);

BOOST_AUTO_TEST_SUITE_END()

}
}
