/*
 * fixture_binary.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_binary.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string/erase.hpp>

using boost::format;
using boost::algorithm::erase_tail_copy;

namespace hessian {
namespace fixture {

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

const binary_t fixture_binary::binary_0 = binary_t(string_0.begin(), string_0.end());
const binary_t fixture_binary::binary_1 = binary_t(string_1.begin(), string_1.end());
const binary_t fixture_binary::binary_15 = binary_t(string_15.begin(), string_15.end());
const binary_t fixture_binary::binary_16 = binary_t(string_16.begin(), string_16.end());
const binary_t fixture_binary::binary_1023 = binary_t(string_1023.begin(), string_1023.end());
const binary_t fixture_binary::binary_1024 = binary_t(string_1024.begin(), string_1024.end());
const binary_t fixture_binary::binary_65535 = binary_t(string_65535.begin(), string_65535.end());
const binary_t fixture_binary::binary_65536 = binary_t(string_65536.begin(), string_65536.end());

const string_t fixture_binary::hessian_0 = string_t("\x20", 1) + string_0;
const string_t fixture_binary::hessian_1 = string_t("\x21", 1) + string_1;
const string_t fixture_binary::hessian_15 = string_t("\x2f", 1) + string_15;
const string_t fixture_binary::hessian_16 = string_t("\x34\x10", 2) + string_16;
const string_t fixture_binary::hessian_1023 = string_t("\x37\xff", 2) + string_1023;
const string_t fixture_binary::hessian_1024 = string_t("B\x04\x00", 3) + string_1024;
const string_t fixture_binary::hessian_65535 = string_t("A\x80\x00", 3) + string_t(string_65535).insert(32768, string_t("B\x7f\xff", 3));
const string_t fixture_binary::hessian_65536 = string_t("A\xff\xff", 3) + string_t(string_65536).insert(65535, 1, '\x21');

}
}
