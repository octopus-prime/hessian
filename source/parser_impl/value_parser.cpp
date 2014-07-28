/*
 * value_parser.cpp
 *
 *  Created on: 22.10.2013
 *      Author: mgresens
 */

#include "value_parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

namespace px = boost::phoenix;

namespace hessian {
namespace parser_impl {

value_parser::value_parser()
:
	value_parser::base_type(_value),
	_value(std::string("value")),
	_terminal(),
	_type(),
	_def(),
	_int(),
	_ref(),
	_def_value(),
	_nonterminal(),
	_list(),
	_list_1(),
	_list_2(),
	_length_1(),
	_length_2(),
	_length_3(),
	_length_4(),
	_map(),
	_map_1(),
	_map_2(),
	_object(),
	_index_1(),
	_index_2(),
	_defs(),
	_refs()
{
	_value =
			_terminal
			|
			_ref
			|
			_def_value
			|
			_nonterminal
	;

	_ref =
			qi::lit('Q')
			>>
			_int							[qi::_val = px::at(px::ref(_refs), qi::_1)]
	;

	_def_value =
			qi::omit
			[
				_def 						[px::push_back(px::ref(_defs), qi::_1)]
			]
			>>
			_value
	;

	_nonterminal =
			qi::eps						[qi::_a = px::bind(&std::vector<value_t>::size, px::ref(_refs)), px::push_back(px::ref(_refs), px::construct<value_t>())]
			>>
			(
				_list
				|
				_map
				|
				_object
			)									[px::at(px::ref(_refs), qi::_a) = qi::_1, qi::_val = qi::_1]
			|
			qi::eps 					[px::erase(px::ref(_refs), px::bind<refs_t::iterator>(&refs_t::begin, px::ref(_refs)) + qi::_a), qi::_pass = false]
	;

	_list =
			_list_1
			|
			_list_2
	;

	_list_1 =
			qi::lit('W')
			>>
			*(_value - qi::lit('Z'))
			>>
			qi::lit('Z')
	;

	_list_2 =
			qi::omit
			[
				_length 					[qi::_a = qi::_1]
			]
			>>
			qi::repeat(qi::_a)
			[
				_value
			]
	;

	_length =
			_length_1
			|
			_length_2
			|
			_length_3
			|
			_length_4
	;

	_length_1 =
			qi::char_('\x78', '\x7f') 		[qi::_val = qi::_1 - 0x78]
	;

	_length_2 =
			qi::lit('X')
			>>
			_int
	;

	_length_3 =
			qi::char_('\x70', '\x77')		[qi::_val = qi::_1 - 0x70]
			>>
			_type
	;

	_length_4 =
			qi::lit('V')
			>>
			_type
			>>
			_int
	;

	_map =
			_map_1
			|
			_map_2
	;

	_map_1 =
			qi::lit('H')
    	>>
			*(
				(_value - qi::lit('Z'))
				>>
				_value
			)
			>>
			qi::lit('Z')
	;

	_map_2 =
			qi::lit('M')
			>>
			_type
   		>>
			*(
				(_value - qi::lit('Z'))
				>>
				_value
			)
			>>
			qi::lit('Z')
	;

	_object =
			qi::omit
			[
				_index 						[qi::_a = px::bind<defs_t::const_iterator>(&defs_t::begin, px::ref(_defs)) + qi::_1, qi::_b = px::bind(&def_t::size, *qi::_a), qi::_c = 0]
			]
			>>
			qi::repeat(qi::_b)
			[
				qi::attr(px::at(*qi::_a, qi::_c++))
				>>
				_value
			]
	;

	_index =
			_index_1
			|
			_index_2
	;

	_index_1 =
			qi::char_('\x60', '\x6f')		[qi::_val = qi::_1 - 0x60]
	;

	_index_2 =
			qi::lit('O')
			>>
			_int
	;
}

}
}
