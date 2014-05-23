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
#ifndef __CONVERT_HPP__
#define __CONVERT_HPP__

#include <string>
#include <sstream>

namespace mavis_unit {
	namespace convert {
		std::string bool_to_string(bool);

		template <typename T> std::string collection_to_string(T collection) {
			std::stringstream ss;

			ss << "( ";

			int size = collection.size();

			for(size_t i = 0; i < size; i++) {
				auto element = collection[i];

				ss << element;

				if(i + 1 < size) {
					ss << ", ";
				}
			}

			ss << " )";

			return ss.str();
		}

		template <typename T> std::string to_string(T t) {
				std::stringstream ss;
				ss << t;
				return ss.str();
		}
	}
}

#endif