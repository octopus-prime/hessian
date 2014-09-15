/*
 * parser_helper.cpp
 *
 *  Created on: 28.07.2014
 *      Author: mike_gresens
 */

#include "hessian_test_pch.hpp"
#include "parser_helper.hpp"
#include "../constant.hpp"
#include <boost/variant/get.hpp>

namespace hessian {
namespace parser_test {

reply_t
parse_reply(const std::string& reply)
{
	std::istringstream stream(constant::VERSION + "R" + reply);
	parser parse(stream);
	const content_t content = parse();
	return boost::get<reply_t>(content);
}

fault_t
parse_fault(const std::string& fault)
{
	std::istringstream stream(constant::VERSION + "F" + fault);
	parser parse(stream);
	const content_t content = parse();
	return boost::get<fault_t>(content);
}

}
}
