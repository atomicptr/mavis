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

// f(x) = x^2
int f(int);
void test_f();
void string_tests();

int main() {

	test_f();
	
	// some other tests
	mavis_assert_true(false);
	mavis_assert_true(true);
	
	string_tests();
	
	mavis_assert_equals(1L, 5L);
	
	return 0;
}

int f(int x) {
	return x * x;
}

void test_f() {
	// should pass
	mavis_assert_equals(16, f(4));
	mavis_assert_equals(25, f(5));
	
	// should fail
	mavis_assert_equals(2, f(1));
}

void string_tests() {
	// should pass
	mavis_assert_equals("wtf", "wtf");
	
	// should fail
	mavis_assert_equals("rofl", "wurst");
}

