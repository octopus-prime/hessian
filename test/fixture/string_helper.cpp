/*
 * string_helper.cpp
 *
 *  Created on: 04.08.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "string_helper.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string/erase.hpp>

using boost::wformat;
using boost::algorithm::erase_tail_copy;

namespace hessian {
namespace fixture {

string_t
make_string_1024()
{
	wformat f(L"%02d 456789012345678901234567890123456789012345678901234567890123\n");

	string_t value;
	for (std::size_t i = 0; i < 16; i++)
		value += (f % i).str();
	return value;
}

string_t
make_string_1023()
{
	return erase_tail_copy(make_string_1024(), 1);
}

string_t
make_string_65536()
{
	wformat f(L"%03d 56789012345678901234567890123456789012345678901234567890123\n");

	string_t value;
	for (std::size_t j = 0; j < 2; j++)
		for (std::size_t i = 0; i < 32 * 16; i++)
			value += (f % i).str();
	return value;
}

string_t
make_string_65535()
{
	return erase_tail_copy(make_string_65536(), 1);
}

}
}
