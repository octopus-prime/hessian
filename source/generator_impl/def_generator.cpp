/*
 * def_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

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
	_string(),
	_null()
{
	_def =
			ka::lit('C')
			<<
			_string [ka::_1 = px::construct<std::string>()]
			<<
			_int [ka::_1 = px::bind(&std::vector<std::string>::size, ka::_val)]
			<<
			(*_string) [ka::_1 = ka::_val];
}

}
}
