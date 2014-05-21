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
#include <mavis/helper/convert.hpp>

using namespace std;

void mavis::assert_true(bool expr, string func, string file, int line) {
	mavis::assert_equals(expr, true, func, file, line);
}

void mavis::assert_false(bool expr, string func, string file, int line) {
	mavis::assert_equals(expr, false, func, file, line);
}

void mavis::print_result(bool result, std::string expected, std::string got, std::string func, std::string file, int line) {
	cout << (result ? "PASS" : "FAIL") << ": " << func << ", expected " << expected
		<< " got " << got << " at file: " << file << ", line: " << line << endl;
}