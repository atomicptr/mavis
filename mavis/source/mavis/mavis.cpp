#include <mavis/mavis.hpp>

#include <iostream>

using namespace std;

void mavis::assert_true(bool expr, string func, string file, int line) {
	cout << (expr ? "PASS" : "FAIL") << ": " << func << ", excepted true got " << (expr ? "true" : "false") << " at file: " << file << ", line: " << line << endl;
}

void mavis::assert_false(bool expr, string func, string file, int line) {
	mavis::assert_true(!expr, func, file, line);
}