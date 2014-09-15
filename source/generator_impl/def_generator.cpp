/*
 * def_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "hessian_pch.hpp"
#include "def_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace generator_impl {

def_generator::def_generator()
:
	def_generator::base_type(_def),
	_def(),
	_int(),
	_string()
{
	_def =
			ka::lit('C')
			<<
			_string 						[ka::_1 = px::construct<string_t>()]
			<<
			_int 							[ka::_1 = px::bind(&std::vector<string_t>::size, ka::_val)]
			<<
			(*_string) 						[ka::_1 = ka::_val];
}

}
}
