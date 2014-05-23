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
#ifndef __MAVIS_UNIT_HPP__
#define __MAVIS_UNIT_HPP__

#include <mavis/test_case.hpp>

#include <string>
#include <functional>
#include <vector>

namespace mavis_unit {

	class unit {

	public:
		unit(const std::string);
		void add_test_case(std::string, std::function<void(void)>);
		void run_tests();

	private:
		std::string name;
		std::vector<test_case_t> test_cases;
	};
};

#endif