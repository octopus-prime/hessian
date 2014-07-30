/*
 * test_binary.cpp
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

BOOST_AUTO_TEST_SUITE(test_binary)

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

static string_t
make_string_65535()
{
	return erase_tail_copy(make_string_65536(), 1);
}

static const string_t string_0 = string_t();
static const string_t string_1 = string_t("0");
static const string_t string_15 = string_t("012345678901234");
static const string_t string_16 = string_t("0123456789012345");
static const string_t string_1023 = make_string_1023();
static const string_t string_1024 = make_string_1024();
static const string_t string_65535 = make_string_65535();
static const string_t string_65536 = make_string_65536();

static const binary_t binary_0 = binary_t(string_0.begin(), string_0.end());
static const binary_t binary_1 = binary_t(string_1.begin(), string_1.end());
static const binary_t binary_15 = binary_t(string_15.begin(), string_15.end());
static const binary_t binary_16 = binary_t(string_16.begin(), string_16.end());
static const binary_t binary_1023 = binary_t(string_1023.begin(), string_1023.end());
static const binary_t binary_1024 = binary_t(string_1024.begin(), string_1024.end());
static const binary_t binary_65535 = binary_t(string_65535.begin(), string_65535.end());
static const binary_t binary_65536 = binary_t(string_65536.begin(), string_65536.end());

TEST_REPLY
(
	test_binary_0,
	string_t("\x20", 1) + string_0,
	binary_0
)

TEST_REPLY
(
	test_binary_1,
	string_t("\x21", 1) + string_1,
	binary_1
)

TEST_REPLY
(
	test_binary_15,
	string_t("\x2f", 1) + string_15,
	binary_15
)

TEST_REPLY
(
	test_binary_16,
	string_t("\x34\x10", 2) + string_16,
	binary_16
)

TEST_REPLY
(
	test_binary_1023,
	string_t("\x37\xff", 2) + string_1023,
	binary_1023
)

TEST_REPLY
(
	test_binary_1024,
	string_t("B\x04\x00", 3) + string_1024,
	binary_1024
)

TEST_REPLY
(
	test_binary_65535,
	string_t("A\x80\x00", 3) + string_t(string_65535).insert(32768, string_t("B\x7f\xff", 3)),
	binary_65535
)

TEST_REPLY
(
	test_binary_65536,
	string_t("A\xff\xff", 3) + string_t(string_65536).insert(65535, 1, '\x21'),
	binary_65536
)

BOOST_AUTO_TEST_SUITE_END()

}
}
