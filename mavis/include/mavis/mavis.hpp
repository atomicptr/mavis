#ifndef __MAVIS_HPP__
#define __MVAIS_HPP__

#define mavis_assert_true(expr) (mavis::assert_true((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))
#define mavis_assert_false(expr) (mavis::assert_false((expr), __PRETTY_FUNCTION__, __FILE__, __LINE__))

#include <string>

namespace mavis {
	void assert_true(bool, std::string, std::string, int);
	void assert_false(bool, std::string, std::string, int);
}

#endif