/*
 * equal_visitor.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "equal_visitor.hpp"
#include <boost/algorithm/cxx14/equal.hpp>

namespace hessian {
namespace value_impl {

equal_visitor::result_type
equal_visitor::operator()(const null_t& value1, const null_t& value2) const
{
	return true;
}

equal_visitor::result_type
equal_visitor::operator()(const list_t& value1, const list_t& value2) const
{
	return boost::algorithm::equal(value1.begin(), value1.end(), value2.begin(), value2.end());
}

equal_visitor::result_type
equal_visitor::operator()(const map_t& value1, const map_t& value2) const
{
	return boost::algorithm::equal(value1.begin(), value1.end(), value2.begin(), value2.end());
}

equal_visitor::result_type
equal_visitor::operator()(const object_t& value1, const object_t& value2) const
{
	return boost::algorithm::equal(value1.begin(), value1.end(), value2.begin(), value2.end());
}

}
}
