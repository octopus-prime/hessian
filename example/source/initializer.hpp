/*
 * initializer.hpp
 *
 *  Created on: 27.08.2014
 *      Author: mike_gresens
 */

#pragma once

#include <boost/shared_ptr.hpp>

namespace caucho {

class initializer
{
public:
	initializer();
	~initializer() BOOST_NOEXCEPT_OR_NOTHROW;

private:
	static const boost::shared_ptr<initializer> INITIALIZER;
};

}
