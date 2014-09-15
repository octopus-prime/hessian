/*
 * output_visitor.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include "hessian_pch.hpp"
#include "output_visitor.hpp"
#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/algorithm/hex.hpp>

namespace hessian {
namespace value_impl {

output_visitor::output_visitor(std::wostream& stream)
:
	boost::static_visitor<>(),
	_stream(stream)
{
}

output_visitor::result_type
output_visitor::operator()(const null_t& value)
{
	_stream << L"null";
}

output_visitor::result_type
output_visitor::operator()(const boolean_t& value)
{
	_stream << L"boolean(" << std::boolalpha << value << std::noboolalpha << ')';
}

output_visitor::result_type
output_visitor::operator()(const int_t& value)
{
	_stream << L"int(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const long_t& value)
{
	_stream << L"long(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const double_t& value)
{
	_stream << L"double(" << value << ')';
}

output_visitor::result_type
output_visitor::operator()(const date_t& value)
{
	_stream << L"date(" << boost::posix_time::to_iso_extended_wstring(value) << ')';
}

output_visitor::result_type
output_visitor::operator()(const string_t& value)
{
	_stream << L"string('" << value << "')";
}

output_visitor::result_type
output_visitor::operator()(const binary_t& value)
{
	std::wstring temp;
	boost::algorithm::hex(value, std::back_inserter(temp));
	_stream << L"binary('" << temp << "')";
}

output_visitor::result_type
output_visitor::operator()(const list_t& value)
{
	_stream << L"list(";
	for (list_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << L", ";
		boost::apply_visitor(*this, *element);
	}
	_stream << ')';
}

output_visitor::result_type
output_visitor::operator()(const map_t& value)
{
	using boost::apply_visitor;
	_stream << L"map(";
	for (map_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << L", ";
		boost::apply_visitor(*this, element->first);
		_stream << L" = ";
		boost::apply_visitor(*this, element->second);
	}
	_stream << ')';
}

output_visitor::result_type
output_visitor::operator()(const object_t& value)
{
	_stream << L"object(";
	for (object_t::const_iterator element = value.begin(); element != value.end(); ++element)
	{
		if (element != value.begin())
			_stream << L", ";
		(*this)(element->first);
		_stream << L" = ";
		boost::apply_visitor(*this, element->second);
	}
	_stream << ')';
}

}
}
