/*
 * fixture_string.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_string.hpp"
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

const string_t fixture_string::string_0 = string_t();
const string_t fixture_string::string_1 = string_t("0");
const string_t fixture_string::string_31 = string_t("0123456789012345678901234567890");
const string_t fixture_string::string_32 = string_t("01234567890123456789012345678901");
const string_t fixture_string::string_1023 = make_string_1023();
const string_t fixture_string::string_1024 = make_string_1024();
const string_t fixture_string::string_65535 = make_string_65535();
const string_t fixture_string::string_65536 = make_string_65536();

const string_t fixture_string::hessian_0 = string_t("\x00", 1) + string_0;
const string_t fixture_string::hessian_1 = string_t("\x01", 1) + string_1;
const string_t fixture_string::hessian_31 = string_t("\x1f", 1) + string_31;
const string_t fixture_string::hessian_32 = string_t("\x30\x20", 2) + string_32;
const string_t fixture_string::hessian_1023 = string_t("\x33\xff", 2) + string_1023;
const string_t fixture_string::hessian_1024 = string_t("S\x04\x00", 3) + string_1024;
const string_t fixture_string::hessian_65535 = string_t("R\x80\x00", 3) + string_t(string_65535).insert(32768, string_t("S\x7f\xff", 3));
const string_t fixture_string::hessian_65536 = string_t("R\xff\xff", 3) + string_t(string_65536).insert(65535, 1, '\x01');

}
}
