/*
 * test_null.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include <hessian/hessian.hpp>
#include "../../source/constant.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/hex.hpp>

using boost::algorithm::hex;

namespace hessian {
namespace generator_test {

BOOST_AUTO_TEST_SUITE(test_null)

BOOST_AUTO_TEST_CASE(test_null)
{
	std::ostringstream stream;
	generator generate(stream);

	BOOST_REQUIRE_NO_THROW
	(
			generate("method", make_list(null_t()));
	)

	BOOST_CHECK_EQUAL(hex(stream.str()), hex(constant::VERSION + "C\x06method\x91N"));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
