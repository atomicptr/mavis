/*
	Copyright (c) 2014 Christopher Kaster <http://christopher.kaster.ws>

	This file is part of the "mavis" C++ unit testing framework <https://github.com/kasoki/mavis>

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/
#ifndef __MAVIS_HPP__
#define __MAVIS_HPP__

#define mavis_assert_true(expr) (mavis_unit::mavis::instance()->assert_true((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_false(expr) (mavis_unit::mavis::instance()->assert_false((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_fail(message) (mavis_unit::mavis::instance()->fail((message), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_null(expr) (mavis_unit::mavis::instance()->assert_null((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_equals(x, y) (mavis_unit::mavis::instance()->assert_equals((x), (y), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_array_equals(x, y) (mavis_unit::mavis::instance()->assert_collection_equals((x), (y), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_vector_equals(x, y) (mavis_unit::mavis::instance()->assert_collection_equals((x), (y), __PRETTY_FUNCTION__, __FILE__, __LINE__))

#include <mavis/helper/convert.hpp>

#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <iterator>
#include <string>
#include <type_traits>
#include <memory>
#include <functional>

namespace mavis_unit {

	class mavis {

	private:
		mavis() {};
		void print_result(bool, std::string, std::string, std::string, std::string, int);

		template<typename T> bool assert_null_helper(std::true_type, T t) {
			return !t;
		}

		template<typename T> bool assert_null_helper(std::false_type, T t) {
			return false;
		}

		std::vector<std::function<void(void)>> test_cases;

	public:
		static std::shared_ptr<mavis> instance();

		void add_test_case(std::string, std::function<void(void)>);
		void run_tests();

		void assert_true(bool, std::string, std::string, int);
		void assert_false(bool, std::string, std::string, int);

		void fail(std::string, std::string, std::string, int);

		template<typename T> void assert_null(T got, std::string func, std::string file, int line) {
			std::is_pointer<T> tmp;

			bool result = assert_null_helper(tmp, got);

			std::string str_got = "something else";

			if(result) {
				str_got = "NULL";
			}

			print_result(result, "NULL", str_got, func, file, line);
		}

		template<typename T> void assert_collection_equals(T expected, T got, std::string func,
				std::string file, int line) {
			bool result = std::equal(std::begin(expected), std::end(expected), std::begin(got));

			print_result(result, mavis_unit::convert::collection_to_string(expected), mavis_unit::convert::collection_to_string(got), func, file, line);
		}

		template<typename T, typename U> void assert_equals(T expected, U got, std::string func,
				std::string file, int line) {
			print_result(expected == got, mavis_unit::convert::to_string(expected), mavis_unit::convert::to_string(got), func, file, line);
		}
	};

	template<> void mavis::assert_equals<const char*, const char*>(const char *expected, const char *got,
			std::string func, std::string file, int line) {
		std::string str_expected(expected);
		std::string str_got(got);

		mavis::instance()->print_result(str_expected == str_got, str_expected, str_got, func, file, line);
	}

	template<> void mavis::assert_equals<bool, bool>(bool expected, bool got, std::string func,
			std::string file, int line) {
		mavis::instance()->print_result(expected == got, mavis_unit::convert::bool_to_string(expected), mavis_unit::convert::bool_to_string(got), func, file, line);
	}

	template<> void mavis::assert_equals<double, double>(double expected, double got, std::string func,
			std::string file, int line) {
		bool result = std::abs(expected - got) < 0.0000001;

		mavis::instance()->print_result(result, mavis_unit::convert::to_string(expected), mavis_unit::convert::to_string(got), func, file, line);
	}

	template<> void mavis::assert_equals<float, float>(float expected, float got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<double, float>(double expected, float got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals(expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<float, double>(float expected, double got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, got, func, file, line);
	}

	template<> void mavis::assert_equals<int, float>(int expected, float got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<float, int>(float expected, int got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<int, double>(int expected, double got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, got, func, file, line);
	}

	template<> void mavis::assert_equals<double, int>(double expected, int got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals(expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<long, float>(long expected, float got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<float, long>(float expected, long got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<long, double>(long expected, double got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, got, func, file, line);
	}

	template<> void mavis::assert_equals<double, long>(double expected, long got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals(expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<short, float>(short expected, float got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<float, short>(float expected, short got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, (double)got, func, file, line);
	}

	template<> void mavis::assert_equals<short, double>(short expected, double got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals((double)expected, got, func, file, line);
	}

	template<> void mavis::assert_equals<double, short>(double expected, short got, std::string func,
			std::string file, int line) {
		mavis::instance()->assert_equals(expected, (double)got, func, file, line);
	}
}

#endif