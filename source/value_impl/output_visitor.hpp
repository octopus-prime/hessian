/*
 * output_visitor.hpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/value.hpp>
#include <iostream>

namespace hessian {
namespace value_impl {

class output_visitor
:
	public boost::static_visitor<>
{
public:
	output_visitor(std::ostream& stream);
	result_type operator()(const null_t& value);
	result_type operator()(const boolean_t& value);
	result_type operator()(const int_t& value);
	result_type operator()(const long_t& value);
	result_type operator()(const double_t& value);
	result_type operator()(const date_t& value);
	result_type operator()(const string_t& value);
	result_type operator()(const binary_t& value);
	result_type operator()(const list_t& value);
	result_type operator()(const map_t& value);
	result_type operator()(const object_t& value);

private:
	std::ostream& _stream;
};

}
}
