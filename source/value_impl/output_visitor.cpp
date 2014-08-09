/*
 * output_visitor.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "output_visitor.hpp"
#include <boost/date_time/posix_time/time_formatters_limited.hpp>
#include <iomanip>

namespace hessian {
namespace value_impl {

output_visitor::output_visitor(std::ostream& stream)
:
	boost::static_visitor<>(),
	_stream(stream)
{
}

output_visitor::result_type
output_visitor::operator()(const null_t& value)
{
	_stream << "null";
}

output_visitor::result_type
output_visitor::operator()(const boolean_t& value)
{
	_stream << "boolean(" << std::boolalpha << value << std::noboolalpha << ')';
}

output_visitor::result_type
output_visitor::operator()(const int_t& value)
{
	_stream << "int(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const long_t& value)
{
	_stream << "long(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const double_t& value)
{
	_stream << "double(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const date_t& value)
{
	_stream << "date(" << boost::posix_time::to_iso_extended_string(value) << ')';
}

output_visitor::result_type
output_visitor::operator()(const string_t& value)
{
	_stream << "string('" << value << "')";
}

output_visitor::result_type
output_visitor::operator()(const binary_t& value)
{
	_stream << "binary('" << std::hex << std::setfill('0') << std::setw(2);
	std::copy(value.begin(), value.end(), std::ostream_iterator<boost::int16_t>(_stream));
	_stream << "')";
}

output_visitor::result_type
output_visitor::operator()(const list_t& value)
{
	_stream << "list(";
	for (list_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << ", ";
		boost::apply_visitor(*this, *element);
	}
	_stream << ')';
}

output_visitor::result_type
output_visitor::operator()(const map_t& value)
{
	using boost::apply_visitor;
	_stream << "map(";
	for (map_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << ", ";
		boost::apply_visitor(*this, element->first);
		_stream << " = ";
		boost::apply_visitor(*this, element->second);
	}
	_stream << ')';
}

output_visitor::result_type
output_visitor::operator()(const object_t& value)
{
	_stream << "object(";
	for (object_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << ", ";
		(*this)(element->first);
		_stream << " = ";
		boost::apply_visitor(*this, element->second);
	}
	_stream << ')';
}

}
}
