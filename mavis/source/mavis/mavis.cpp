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

using namespace std;
using namespace mavis_unit;

shared_ptr<mavis> mavis::instance() {
	static shared_ptr<mavis> _instance = shared_ptr<mavis>(new mavis());
	return _instance;
}

shared_ptr<unit> mavis::create_test_unit(string name) {
	shared_ptr<unit> test_unit = make_shared<unit>(name);

	test_units.push_back(test_unit);

	return test_unit;
}

void mavis::run_tests() {
	for_each(test_units.begin(), test_units.end(), [](shared_ptr<unit> test_unit) {
		test_unit->run_tests();
	});
}

test_result_t mavis::assert_true(bool expr, string func, string file, int line) {
	return mavis::instance()->assert_equals(true, expr, func, file, line);
}

test_result_t mavis::assert_false(bool expr, string func, string file, int line) {
	return mavis::instance()->assert_equals(false, expr, func, file, line);
}

test_result_t mavis::fail(std::string message, std::string func, std::string file, int line) {
	test_result_t t_result;

	t_result.result = false;
	t_result._force_fail = true;
	t_result.expected = message;
	t_result.got = "";
	t_result.func = func;
	t_result.file = file;
	t_result.line = line;

	return t_result;
}

void mavis::print_result(bool result, std::string expected, std::string got, std::string func, std::string file, int line) {
	cout << (result ? "PASS" : "FAIL") << ": " << func << ", expected " << expected
		<< " got " << got << " at file: " << file << ", line: " << line << endl;
}

test_result_t mavis::make_result(bool reuslt, std::string expected, std::string got, std::string func, std::string file, int line) {
	test_result_t t_result;

	t_result.result = expected == got;
	t_result._force_fail = false;
	t_result.expected = expected;
	t_result.got = got;
	t_result.func = func;
	t_result.file = file;
	t_result.line = line;

	return t_result;
}