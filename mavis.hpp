/*
    mavis <https://github.com/kasoki/mavis>

    The MIT License (MIT)

    Copyright (c) 2015 Christopher Kaster <http://christopher.kaster.ws>

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
#ifndef __MAVIS_MAVIS_HPP__
#define __MAVIS_MAVIS_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <vector>

namespace mavis {

    template<typename T>
    auto to_string(T val) {
        std::stringstream ss;
        ss << val;
        return ss.str();
    }

    const std::string SPACE = "    ";
    using reset_func = std::function<void(void)>;

    struct result {
        bool passed;
        std::string expected;
        std::string got;
        std::string message;
    };

    class spec {
    public:
        spec(std::string name) : name_(name) {}

        template<typename T>
        void expect_equals(T expected, T got) {
            auto expected_str = to_string(expected);
            auto got_str = to_string(got);

            result res = {
                .passed = expected == got,
                .expected = expected_str,
                .got = got_str,
                .message = expected_str + " to equal " + got_str
            };

            results_.push_back(res);
        }

        void expect_true(bool expected) {
            auto got = std::string{expected ? "true" : "false"};

            result res = {
                .passed = expected,
                .expected = "true",
                .got = got,
                .message = "true, got " + got
            };

            results_.push_back(res);
        }

        void expect_false(bool expected) {
            auto got = std::string{expected ? "true" : "false"};

            result res = {
                .passed = !expected,
                .expected = "false",
                .got = got,
                .message = "false, got " + got
            };

            results_.push_back(res);
        }

        template<typename T>
        void expect_not_null(T* ptr) {
            result res = {
                .passed = ptr != nullptr,
                .message = "pointer that is not null"
            };

            results_.push_back(res);
        }

        auto& name() const {
            return name_;
        }

        auto passed() const {
            auto pass = true;

            for(auto &r : results_) {
                pass = pass && r.passed;
            }

            return pass;
        }

        auto& results() const {
            return results_;
        }

    private:
        std::string name_;
        std::vector<result> results_;
    };

    using spec_function = std::function<void(spec&)>;

    class suite {
    public:
        suite(std::string name) : name_(name) {}

        void before(reset_func f) {
            before_func_ = f;
        }

        void after(reset_func f) {
            after_func_ = f;
        }

        void it(std::string spec_name, spec_function test_spec) {
            spec s(spec_name);

            before_func_();
            test_spec(s);
            after_func_();

            specs_.push_back(s);
        }

        void print() {
            std::cout << std::endl << "#  " << name_ << std::endl << std::endl;

            auto spec_counter = 0u;
            auto failure_counter = 0u;

            for(auto &spec : specs_) {
                std::cout << "it: " << spec.name() << ": " <<
                    (spec.passed() ? "PASS" : "FAIL") << std::endl;

                auto& results = spec.results();
                spec_counter += results.size();

                if(!spec.passed()) {
                    for(auto &r : results) {
                        std::cout << SPACE << (r.passed ? "+" : "-") <<
                            " expect " << r.message << std::endl;

                        if(!r.passed) {
                            failure_counter++;
                        }
                    }

                    std::cout << std::endl;
                }
            }

            std::cout << spec_counter << " specs, " << failure_counter <<
                    " failures" << std::endl;
        }

    private:
        std::string name_;
        std::vector<spec> specs_;

        reset_func before_func_ = [](){};
        reset_func after_func_ = [](){};
    };

    void describe(std::string name, std::function<void(suite&)> test_suite) {
        suite s(name);

        test_suite(s);

        s.print();
    }
}

#endif
