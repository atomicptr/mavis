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
#include <mavis/mavis.hpp>

#include "vector3.hpp"

#include <array>

using namespace mavis_unit;

void test_main();

int main() {
	test_main();

	return 0;
}

void test_main() {
	auto test_unit = mavis_create_test_unit("vector3 class test");

	test_unit->add_test_case("vector + vector", []() -> test_result_t {
		vector3 v1(1, 2, 3);
		vector3 v2(3, 2, 1);

		vector3 v3 = v1 + v2;

		bool result = v3.x == 4 && v3.y == 4 && v3.z == 4;

		mavis_assert_true(result);
	});

	test_unit->add_test_case("vector - vector", []() -> test_result_t {
		vector3 v1(1, 2, 3);

		vector3 v2 = v1 - v1;

		bool result = v2.x == 0 && v2.y == 0 && v2.z == 0;

		mavis_assert_true(result);
	});

	test_unit->add_test_case("vector * scalar", []() -> test_result_t {
		vector3 v1(1, 1, 1);

		v1 = v1 * 4;

		bool result = v1.x == 4 && v1.y == 4 && v1.z == 4;

		mavis_assert_true(result);
	});

	// run all test units
	mavis_run_tests();
}

