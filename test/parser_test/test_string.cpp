/*
 * test_string.cpp
 *
 *  Created on: 18.11.2013
 *      Author: mgresens
 */

#include "parser_helper.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string/erase.hpp>

using boost::format;
using boost::algorithm::erase_tail_copy;

namespace hessian {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_string)

static string_t
make_string_1024()
{
	format f("%02d 456789012345678901234567890123456789012345678901234567890123\n");

	string_t value;
	for (std::size_t i = 0; i < 16; i++)
		value += (f % i).str();
	return value;
}

static string_t
make_string_1023()
{
	return erase_tail_copy(make_string_1024(), 1);
}

static string_t
make_string_65536()
{
	format f("%03d 56789012345678901234567890123456789012345678901234567890123\n");

	string_t value;
	for (std::size_t j = 0; j < 2; j++)
		for (std::size_t i = 0; i < 32 * 16; i++)
			value += (f % i).str();
	return value;
}

static const string_t string_0 = string_t();
static const string_t string_1 = string_t("0");
static const string_t string_31 = string_t("0123456789012345678901234567890");
static const string_t string_32 = string_t("01234567890123456789012345678901");
static const string_t string_1023 = make_string_1023();
static const string_t string_1024 = make_string_1024();
static const string_t string_65536 = make_string_65536();

TEST_REPLY
(
	test_string_0,
	string_t("\x00", 1) + string_0,
	string_0
)

TEST_REPLY
(
	test_string_1,
	string_t("\x01", 1) + string_1,
	string_1
)

TEST_REPLY
(
	test_string_31,
	string_t("\x1f", 1) + string_31,
	string_31
)

TEST_REPLY
(
	test_string_32,
	string_t("\x30\x20", 2) + string_32,
	string_32
)

TEST_REPLY
(
	test_string_1023,
	string_t("\x33\xff", 2) + string_1023,
	string_1023
)

TEST_REPLY
(
	test_string_1024,
	string_t("S\x04\x00", 3) + string_1024,
	string_1024
)

TEST_REPLY
(
	test_string_65536,
	string_t("R\xff\xff", 3) + string_t(string_65536).insert(65535, 1, '\x01'),
	string_65536
)

BOOST_AUTO_TEST_SUITE_END()

}
}
