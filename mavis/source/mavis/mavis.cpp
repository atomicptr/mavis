#include <mavis/mavis.hpp>

mavis::unit mavis::create_test_unit(std::string name) {
    return mavis::unit(name);
}

mavis::test mavis::assert_true(bool expr, std::string func, std::string file, int line) {
    return mavis::assert_equals(true, expr, func, file, line);
}

mavis::test mavis::assert_false(bool expr, std::string func, std::string file, int line) {
    return mavis::assert_equals(false, expr, func, file, line);
}

/*mavis::test mavis::fail(std::string message, std::string func, std::string file, int line) {
    // TODO add something
}*/