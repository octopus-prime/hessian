/*
 * binary_generator.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "binary_generator.hpp"
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

namespace px = boost::phoenix;

namespace boost { namespace spirit { namespace traits
{
    template <>
    struct transform_attribute<hessian::binary_t const, hessian::string_t, karma::domain>
    {
        typedef hessian::string_t type;
        static type pre(hessian::binary_t const& value)
        {
        	return type(value.begin(), value.end());
        }
    };
}}}

namespace hessian {
namespace generator_impl {

binary_generator::binary_generator()
:
	binary_generator::base_type(_binary),
	_binary(),
	_binary_1(),
	_binary_2(),
	_length(),
	_length_1(),
	_length_2(),
	_length_3(),
	_length_4()
{
	_binary =
			_binary_1
			|
			_binary_2
	;

	_binary_1 =
			_length(px::bind(&binary_t::size, ka::_val))
			<<
			ka::string
	;

	_binary_2 =
			_length_4
//			TODO: Does not compile, so test_generate_binary_65536 fails :(
//			<<
//			ka::string [ka::_1 = px::bind(&binary_t::substr, ka::_val, 0, 0xffff)]
			<<
			_binary [ka::_1 = px::bind(&binary_t::substr, ka::_val, 0xffff, binary_t::npos)]
	;

	_length =
			_length_1(ka::_r1)
			|
			_length_2(ka::_r1)
			|
			_length_3(ka::_r1)
	;

	_length_1 =
			ka::eps (ka::_r1 >= 0x00 && ka::_r1 <= 0x0f)
			<<
			ka::byte_ [ka::_1 = ka::_r1 + 0x20]
	;

	_length_2 =
			ka::eps (ka::_r1 >= 0x10 && ka::_r1 <= 0x3ff)
			<<
			ka::byte_ [ka::_1 = (ka::_r1 >> 8) + 0x34]
			<<
			ka::byte_ [ka::_1 = ka::_r1 & 0xff]
	;

	_length_3 =
			ka::eps (ka::_r1 >= 0x400 && ka::_r1 <= 0xffff)
			<<
			ka::lit('B')
			<<
			ka::big_word [ka::_1 = ka::_r1]
	;

	_length_4 =
			ka::lit('A')
			<<
			ka::big_word [ka::_1 = 0xffff]
	;
}

}
}
