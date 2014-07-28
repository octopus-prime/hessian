/*
 * parser_helper.cpp
 *
 *  Created on: 28.07.2014
 *      Author: mike_gresens
 */

#include "parser_helper.hpp"
#include "../../source/constant.hpp"

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

}
}
