# mavis

Very lightweight zero dependency C++11 unit test framework.

## Install

### homebrew (OS X)

    brew install https://raw.githubusercontent.com/kasoki/mavis/master/misc/mavis.rb

## Usage

First you obviously need to add the header file:

    #include <mavis/mavis.hpp>

now lets create some simple test cases for + and -

    mavis::test test_add() {
        int x = 2 + 2;

        return mavis_assert_equals(x, 4);
    }

    mavis::test test_sub() {
        int x = 44 - 2;

        return mavis_assert_true(x == 42);
    }

and now you'll need to add the test cases to a test unit:

    auto test_unit = mavis::create_test_unit("simple + and - test");

    test_unit.add_test(test_add);
    test_unit.add_test(test_sub);

at last you only need to run the tests with:

    test_unit.run_tests();

## License

The project is licensed under the terms of the MIT license (read the "LICENSE" file for more informations)
