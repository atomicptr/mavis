#include <mavis/test.hpp>

mavis::test::test(bool result, std::string expected, std::string got, std::string func,
    std::string file, int line) :
        result(result), expected(expected), got(got), func(func), file(file), line(line) {}