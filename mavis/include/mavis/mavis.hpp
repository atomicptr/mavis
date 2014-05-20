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
#define __MVAIS_HPP__

#define mavis_assert_true(expr) (mavis::assert_true((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_false(expr) (mavis::assert_false((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_equals(x, y) (mavis::assert_equals((x), (y), __PRETTY_FUNCTION__, __FILE__, __LINE__))

#include <string>

namespace mavis {
	void assert_true(bool, std::string, std::string, int);
	void assert_false(bool, std::string, std::string, int);

	void assert_equals(int, int, std::string, std::string, int);
	void assert_equals(const char*, const char*, std::string, std::string, int);
	void assert_equals(bool, bool, std::string, std::string, int);

	static void print_result(bool, std::string, std::string, std::string, std::string, int);
}

#endif