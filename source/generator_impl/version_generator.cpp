/*
 * version_generator.cpp
 *
 *  Created on: 14.12.2013
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "version_generator.hpp"
#include "../constant.hpp"
#include <boost/spirit/include/karma.hpp>

namespace hessian {
namespace generator_impl {

version_generator::version_generator()
:
	version_generator::base_type(_version),
	_version()
{
	_version =
//			ka::lit(constant::VERSION);	// FIXME: After karma::lit() fix.
			ka::lit('H')
			<<
			ka::lit('\x02')
			<<
			ka::lit('\00')
	;
}

}
}
