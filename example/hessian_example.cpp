/*
 * hessian_example.cpp
 *
 *  Created on: 21.07.2014
 *      Author: mike_gresens
 */

#include <hessian/hessian.hpp>
#include <iostream>
#include <sstream>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace hessian;

static void
test_list()
{
	const list_t x = make_list(string_t("foo"))(true)(string_t("bar"))(null_t());
	const list_t y = make_list(string_t("foo"))(true)(string_t("bar"))(int_t());

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << equal_to()(x, y) << std::endl;
	std::cout << less()(x, y) << std::endl;
	std::cout << less()(y, x) << std::endl;
	std::cout << hash()(x) << std::endl;
	std::cout << hash()(y) << std::endl;
}

static void
test_map()
{
	const map_t x = make_map(string_t("foo"), true)(string_t("bar"), null_t());
	const map_t y = make_map(string_t("foo"), true)(string_t("bar"), int_t());

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << equal_to()(x, y) << std::endl;
	std::cout << less()(x, y) << std::endl;
	std::cout << less()(y, x) << std::endl;
	std::cout << hash()(x) << std::endl;
	std::cout << hash()(y) << std::endl;
}

static void
test_object()
{
	const object_t x = make_object("foo", true)("bar", null_t());
	const object_t y = make_object("foo", true)("bar", int_t());

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << equal_to()(x, y) << std::endl;
	std::cout << less()(x, y) << std::endl;
	std::cout << less()(y, x) << std::endl;
	std::cout << hash()(x) << std::endl;
	std::cout << hash()(y) << std::endl;
}

class content_visitor
:
	public boost::static_visitor<void>
{
public:
	result_type operator()(const reply_t& content) const
	{
		std::cout << "reply = " << content << std::endl;
	}

	result_type operator()(const fault_t& content) const
	{
		std::cout << "fault = " << content << std::endl;
	}
};

class test2_base
{
protected:
	virtual ~test2_base() BOOST_NOEXCEPT_OR_NOTHROW {}

public:
	virtual bool reply_true() = 0;
	virtual bool reply_false() = 0;
	virtual bool reply_fault() = 0;
};

typedef boost::shared_ptr<test2_base> test2;

class test2_impl
:
	public virtual test2_base
{
	class bool_visitor
	:
		public boost::static_visitor<bool>
	{
	public:
		result_type operator()(const reply_t& content) const
		{
			return boost::get<boolean_t>(content);
		}

		result_type operator()(const fault_t& content) const
		{
			throw std::runtime_error(std::string("fault: a = ") + boost::get<string_t>(content.at(string_t("a"))));
		}
	};

public:
	test2_impl()
	:
		test2_base()
	{
	}

	virtual ~test2_impl() BOOST_NOEXCEPT_OR_NOTHROW {}

	virtual bool reply_true()
	{
		return reply(std::string("H\x02\x00""RT", 5));
	}

	virtual bool reply_false()
	{
		return reply(std::string("H\x02\x00""RF", 5));
	}

	virtual bool reply_fault()
	{
		return reply(std::string("H\x02\x00""F\x01""a""\x01""b""Z", 9));
	}

protected:
	static bool reply(const std::string& response)
	{
		std::istringstream stream (response);
		parser parse(stream);
		const content_t content = parse();
		return boost::apply_visitor(bool_visitor(), content);
	}
};

int
main()
{
	try
	{
//		test_list();
//		test_map();
//		test_object();
//
//		std::ostringstream request;
//		generator generate(request);
//		generate("foo", make_list(string_t("foo"))(true)(string_t("bar"))(int_t()));
//		std::cout << request.str() << std::endl;

//		std::istringstream response(std::string("H\x02\x00RT", 5));
//		std::istringstream response(std::string("H\x02\x00""F\x00\x00""Z", 7));
//		std::istringstream response(std::string("H\x02\x00""F\x00\x00""Z", 6));
//		std::istringstream response("Hfoo");
//		parser parse(response);
//		const content_t content = parse();
//		boost::apply_visitor(content_visitor(), content);

		const test2 test2 = boost::make_shared<test2_impl>();
		std::cout << "a = " << test2->reply_true() << std::endl;
		std::cout << "b = " << test2->reply_false() << std::endl;
		std::cout << "c = " << test2->reply_fault() << std::endl;
	}
	catch (hessian::exception& e)
	{
		std::cout << "hessian error: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "std error: "<< e.what() << std::endl;
	}
	return 0;
}
