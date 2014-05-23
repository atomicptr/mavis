#ifndef __MAVIS_TEST_RESULT_HPP__
#define __MAVIS_TEST_RESULT_HPP__

#include <string>

namespace mavis_unit {

	struct test_result_t {
		bool result;
		bool _force_fail;
		std::string expected;
		std::string got;
		std::string func;
		std::string file;
		int line;
	};
}

#endif