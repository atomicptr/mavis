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
#include <mavis/unit.hpp>

#include <iostream>

using namespace std;

using namespace mavis_unit;

unit::unit(std::string unit_name) :name(unit_name) {
}

void unit::add_test_case(std::string test_name, std::function<test_result_t()> func) {
	test_case_t test_case;

	test_case.name = test_name;
	test_case.func = func;

	test_cases.push_back(test_case);
}

void unit::run_tests() {
	for_each(test_cases.begin(), test_cases.end(), [](test_case_t test_case) {
		auto result = test_case.func();

		if(!result._force_fail) {
			cout << (result.result ? "PASS" : "FAIL") << ": " << result.func << ", expected " << result.expected
				<< " got " << result.got << " at file: " << result.file << ", line: " << result.line << endl;
		} else {
			cout << "FAIL: " << result.expected << " " << result.func << " at file " << result.file << ", line: " << result.line << endl;
		}
	});
}