#ifndef __MAVIS_TEST_CASE_HPP__
#define __MAVIS_TEST_CASE_HPP__

#include <string>
#include <functional>

struct test_case_t {
	std::string name;
	std::function<void(void)> func;
};

#endif