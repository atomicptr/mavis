# mavis

Lightweight, header only C++14 unit test framework inspired by [jasmine](http://jasmine.github.io).

100% Macro free!

## Usage

Just put the ``mavis.hpp`` somewhere into your project and use it like this:

    #include "path/to/mavis.hpp"

    // whereever you want to write your tests

    mavis::describe("A suite", [](auto &suite) {
        int a = 0;

        suite.it("contains spec with an expectation", [&a](auto &spec) {
            spec.expect_equals(a, 0);
        });

        suite.it("contains specs with multiple expectations", [&a](auto &spec) {
            spec.expect_equals(a + 2, 2);
            spec.expect_equals(a * 2, 0);
        });
    });

Please note that ``expect_equals`` also works with custom types if you override:

* operator==(...)
* operator<<(std::ostream&, custom_type&)

For more informations please [read the documentation](https://github.com/kasoki/mavis/wiki)

## License

MIT
