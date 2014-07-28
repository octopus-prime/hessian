/*
 * version_parser.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "version_parser.hpp"
#include "../constant.hpp"
#include <boost/spirit/include/qi.hpp>

namespace hessian {
namespace parser_impl {

version_parser::version_parser()
:
	version_parser::base_type(_version),
	_version(std::string("version"))
{
	_version =
			qi::lit(constant::VERSION)
	;
}

}
}
