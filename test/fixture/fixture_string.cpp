/*
 * fixture_string.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "fixture_string.hpp"
#include "string_helper.hpp"

namespace hessian {
namespace fixture {

const string_t fixture_string::string_0 = string_t();
const string_t fixture_string::string_1 = string_t(L"0");
const string_t fixture_string::string_31 = string_t(L"0123456789012345678901234567890");
const string_t fixture_string::string_32 = string_t(L"01234567890123456789012345678901");
const string_t fixture_string::string_1023 = make_string_1023();
const string_t fixture_string::string_1024 = make_string_1024();
const string_t fixture_string::string_65535 = make_string_65535();
const string_t fixture_string::string_65536 = make_string_65536();
const string_t fixture_string::string_unicode = string_t(L"a""1""是""本""文");

const std::string fixture_string::hessian_0 = std::string("\x00", 1) + std::string(string_0.begin(), string_0.end());
const std::string fixture_string::hessian_1 = std::string("\x01", 1) + std::string(string_1.begin(), string_1.end());
const std::string fixture_string::hessian_31 = std::string("\x1f", 1) + std::string(string_31.begin(), string_31.end());
const std::string fixture_string::hessian_32 = std::string("\x30\x20", 2) + std::string(string_32.begin(), string_32.end());
const std::string fixture_string::hessian_1023 = std::string("\x33\xff", 2) + std::string(string_1023.begin(), string_1023.end());
const std::string fixture_string::hessian_1024 = std::string("S\x04\x00", 3) + std::string(string_1024.begin(), string_1024.end());
const std::string fixture_string::hessian_65535 = std::string("R\x80\x00", 3) + std::string(string_65535.begin(), string_65535.end()).insert(32768, std::string("S\x7f\xff", 3));
const std::string fixture_string::hessian_65536 = std::string("R\xff\xff", 3) + std::string(string_65536.begin(), string_65536.end()).insert(65535, 1, '\x01');
const std::string fixture_string::hessian_unicode = std::string("\x05", 1) + std::string(string_unicode.begin(), string_unicode.end());

}
}
