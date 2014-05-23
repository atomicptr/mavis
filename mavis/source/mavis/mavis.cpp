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

void mavis::assert_true(bool expr, string func, string file, int line) {
	mavis::instance()->assert_equals(expr, true, func, file, line);
}

void mavis::assert_false(bool expr, string func, string file, int line) {
	mavis::instance()->assert_equals(expr, false, func, file, line);
}

void mavis::fail(std::string message, std::string func, std::string file, int line) {
	cout << "FAIL: " << message << " " << func << " at file " << file << ", line: " << line << endl;
}

void mavis::print_result(bool result, std::string expected, std::string got, std::string func, std::string file, int line) {
	cout << (result ? "PASS" : "FAIL") << ": " << func << ", expected " << expected
		<< " got " << got << " at file: " << file << ", line: " << line << endl;
}