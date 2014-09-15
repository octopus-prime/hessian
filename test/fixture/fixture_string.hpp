/*
 * fixture_string.hpp
 *
 *  Created on: 31.07.2014
 *      Author: mgresens
 */

#pragma once

#include <hessian/value.hpp>

namespace hessian {
namespace fixture {

struct fixture_string
{
	static const string_t string_0;
	static const string_t string_1;
	static const string_t string_31;
	static const string_t string_32;
	static const string_t string_1023;
	static const string_t string_1024;
	static const string_t string_65535;
	static const string_t string_65536;

	static const std::string hessian_0;
	static const std::string hessian_1;
	static const std::string hessian_31;
	static const std::string hessian_32;
	static const std::string hessian_1023;
	static const std::string hessian_1024;
	static const std::string hessian_65535;
	static const std::string hessian_65536;

#ifndef _WIN32

	static const string_t string_unicode;
	static const std::string hessian_unicode;

#endif
};

}
}
