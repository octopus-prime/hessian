/*
 * fixture_binary.cpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "fixture_binary.hpp"
#include "string_helper.hpp"

namespace hessian {
namespace fixture {

static const string_t string_0 = string_t();
static const string_t string_1 = string_t(L"0");
static const string_t string_15 = string_t(L"012345678901234");
static const string_t string_16 = string_t(L"0123456789012345");
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

const std::string fixture_binary::hessian_0 = std::string("\x20", 1) + binary_0;
const std::string fixture_binary::hessian_1 = std::string("\x21", 1) + binary_1;
const std::string fixture_binary::hessian_15 = std::string("\x2f", 1) + binary_15;
const std::string fixture_binary::hessian_16 = std::string("\x34\x10", 2) + binary_16;
const std::string fixture_binary::hessian_1023 = std::string("\x37\xff", 2) + binary_1023;
const std::string fixture_binary::hessian_1024 = std::string("B\x04\x00", 3) + binary_1024;
const std::string fixture_binary::hessian_65535 = std::string("A\x80\x00", 3) + std::string(binary_65535).insert(32768, std::string("B\x7f\xff", 3));
const std::string fixture_binary::hessian_65536 = std::string("A\xff\xff", 3) + std::string(binary_65536).insert(65535, 1, '\x21');

}
}
