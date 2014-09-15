/*
 * value.hpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#pragma once

#include <hessian/config.hpp>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <boost/blank.hpp>
#include <boost/cstdint.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/unordered_map.hpp>
#include <boost/variant/variant_fwd.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/assign/list_of.hpp>

namespace hessian {

struct less;
struct equal_to;
struct hash;

/**
 * Defines null type.
 */
typedef boost::blank null_t;

/**
 * Defines boolean type.
 */
typedef bool boolean_t;

/**
 * Defines int type.
 */
typedef boost::int32_t int_t;

/**
 * Defines long type.
 */
typedef boost::int64_t long_t;

/**
 * Defines double type.
 */
typedef double double_t;

/**
 * Defines date type.
 */
typedef boost::posix_time::ptime date_t;

/**
 * Defines string type.
 */
typedef std::wstring string_t;

/**
 * Defines binary type.
 */
typedef std::string binary_t;

/**
 * Defines value type.
 */
typedef boost::make_recursive_variant
<
	null_t,
	boolean_t,
	int_t,
	long_t,
	double_t,
	date_t,
	string_t,
	binary_t,
	std::vector<boost::recursive_variant_>,									// list_t
	std::map<boost::recursive_variant_, boost::recursive_variant_, less>,	// map_t
	boost::unordered_map<string_t, boost::recursive_variant_>				// object_t
>::type value_t;

/**
 * Function object for performing comparisons.
 */
struct HESSIAN_EXPORT less
:
	std::binary_function<value_t, value_t, bool>
{
	/**
	 * Compares two values.
	 * @param value1 The 1st value.
	 * @param value2 The 2nd value.
	 * @return <code>true</code> if value1 is less than value2.
	 */
	result_type
	operator()(const first_argument_type& value1, const second_argument_type& value2) const;
};

/**
 * Function object for performing comparisons.
 */
struct HESSIAN_EXPORT equal_to
:
	std::binary_function<value_t, value_t, bool>
{
	/**
	 * Compares two values.
	 * @param value1 The 1st value.
	 * @param value2 The 2nd value.
	 * @return <code>true</code> if value1 is equal to value2.
	 */
	result_type
	operator()(const first_argument_type& value1, const second_argument_type& value2) const;
};

/**
 * Function object for performing hashing.
 */
struct HESSIAN_EXPORT hash
:
	std::unary_function<value_t, std::size_t>
{
	/**
	 * Hashes a value.
	 * @param value The value.
	 * @return The hash.
	 */
	result_type
	operator()(const argument_type& value) const;
};

/**
 * Defines list type.
 */
typedef std::vector<value_t> list_t;

/**
 * Defines map type.
 */
typedef std::map<value_t, value_t, less> map_t;

/**
 * Defines object type.
 */
typedef boost::unordered_map<string_t, value_t> object_t;

HESSIAN_EXPORT
/**
 * Builds list.
 * @param value The value.
 * @return The builder.
 */
boost::assign_detail::generic_list<list_t::value_type>
make_list(const list_t::value_type& value);

HESSIAN_EXPORT
/**
 * Builds map.
 * @param key The key.
 * @param value The value.
 * @return The builder.
 */
boost::assign_detail::generic_list<std::pair<map_t::key_type, map_t::mapped_type> >
make_map(const map_t::key_type& key, const map_t::mapped_type& value);

HESSIAN_EXPORT
/**
 * Builds object.
 * @param key The key.
 * @param value The value.
 * @return The builder.
 */
boost::assign_detail::generic_list<std::pair<object_t::key_type, object_t::mapped_type> >
make_object(const object_t::key_type& key, const object_t::mapped_type& value);

HESSIAN_EXPORT
/**
 * Output operator.
 * @param stream The stream.
 * @param value The value.
 * @return The stream.
 */
std::wostream&
operator<<(std::wostream& stream, const value_t& value);

}

// Workaround for MSVC :-(
namespace boost {

template <>
inline void
swap(hessian::value_t& lhs, hessian::value_t& rhs)
{
	std::swap(lhs, rhs);
}

}
