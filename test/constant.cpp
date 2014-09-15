/*
 * constant.cpp
 *
 *  Created on: 28.07.2014
 *      Author: mgresens
 */

#include "hessian_test_pch.hpp"
#include "constant.hpp"

namespace hessian {

const date_t constant::EPOCH(boost::gregorian::date(1970, 1, 1));
const std::string constant::VERSION("H\x02\x00", 3);

}
