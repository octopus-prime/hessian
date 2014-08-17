/*
 * string_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "string_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/regex/pending/unicode_iterator.hpp>

///////////////////////////////////////////////////////////////////////////////
// definition the place holder
namespace boost { namespace spirit { namespace qi { namespace ext {
    BOOST_SPIRIT_TERMINAL(unicode_char)
}}}}

///////////////////////////////////////////////////////////////////////////////
// implementation the enabler
namespace boost { namespace spirit {

// We want custom_parser::unicode_char to be usable as a terminal only, and
// only for parser expressions (qi::domain).
template <>
struct use_terminal<qi::domain, qi::ext::tag::unicode_char>
:
	mpl::true_
{};

}}

///////////////////////////////////////////////////////////////////////////////
// implementation of the parser
namespace boost { namespace spirit { namespace qi { namespace ext {

struct unicode_char_parser
:
	primitive_parser<unicode_char_parser>
{
	// Define the attribute type exposed by this parser component
	template <typename Context, typename Iterator>
	struct attribute
	{
		typedef wchar_t type;
	};

	// This function is called during the actual parsing process
	template <typename Iterator, typename Context , typename Skipper, typename Attribute>
	bool parse(Iterator& first, Iterator const& last, Context& context, Skipper const& skipper, Attribute& attr) const
	{
		skip_over(first, last, skipper);
		if (first == last) return false;

		u8_to_u32_iterator<Iterator> f(first);
		u8_to_u32_iterator<Iterator> l(last);
		if (f == l) return false;

		attr = *f++;
		first = f.base();
		return true;
	}

	// This function is called during error handling to create a human
	// readable string for the error context.
	template <typename Context>
	info what(Context&) const
	{
		return info("unicode_char");
	}
};

}}}}

///////////////////////////////////////////////////////////////////////////////
// instantiation of the parser
namespace boost { namespace spirit { namespace qi {

// This is the factory function object invoked in order to create an
// instance of our unicode_char_parser.
template <typename Modifiers>
struct make_primitive<ext::tag::unicode_char, Modifiers>
{
	typedef ext::unicode_char_parser result_type;

	result_type operator()(unused_type, unused_type) const
	{
		return result_type();
	}
};

}}}

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

string_parser::string_parser()
:
	string_parser::base_type(_string),
	_string(),
	_string_1(),
	_string_2(),
	_length(),
	_length_1(),
	_length_2(),
	_length_3(),
	_length_4()
{
	_string =
			_string_1
			|
			_string_2
	;

	_string_1 =
			qi::omit
			[
				_length						[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::ext::unicode_char
			]
	;

	_string_2 =
			qi::omit
			[
				_length_4					[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				qi::ext::unicode_char
			]
			>>
			_string
	;

	_length =
			_length_1
			|
			_length_2
			|
			_length_3
	;

	_length_1 =
			qi::char_('\x00', '\x1f')
	;

	_length_2 =
			qi::char_('\x30', '\x33')		[qi::_val = (qi::_1 - 0x30) << 8]
			>>
			qi::byte_						[qi::_val += qi::_1]
	;

	_length_3 =
			qi::lit('S')
			>>
			qi::big_word
	;

	_length_4 =
			qi::lit('R')
			>>
			qi::big_word
	;
}

}
}
