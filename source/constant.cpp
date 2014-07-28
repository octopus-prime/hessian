/*
 * constant.cpp
 *
 *  Created on: 28.07.2014
 *      Author: mgresens
 */

#include "constant.hpp"

namespace hessian {

const date_t constant::EPOCH(boost::gregorian::date(1970, 1, 1));
const string_t constant::VERSION("H\x02\x00", 3);

}
