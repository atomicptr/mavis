#include <mavis/unit.hpp>

mavis::unit::unit(std::string name) : name(name) {}

void mavis::unit::add_test(std::function<mavis::test()> test) {
    this->tests.push_back(test);
}

void mavis::unit::run_tests() const {
    for(auto test : this->tests) {
        auto result = test();

        this->print_result(result);
    }
}

void mavis::unit::print_result(mavis::test test) const {
    std::cout << (test.result ? "PASS" : "FAIL") << ": " << test.func << ", expected " << test.expected
        << " got " << test.got << " at file: " << test.file << ", line: " << test.line << std::endl;
}