/*
 * config.hpp
 *
 *  Created on: 15.09.2014
 *      Author: developer
 */

#pragma once

// Windows declspec terror

#ifdef _WIN32
	#ifdef EXPORT_HESSIAN
		#define HESSIAN_EXPORT __declspec( dllexport )
	#else
		#define HESSIAN_EXPORT
	#endif
#else
	#define HESSIAN_EXPORT
#endif
