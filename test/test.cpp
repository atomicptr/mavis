#include <mavis/mavis.hpp>

#include "vector3.hpp"

#include <array>

mavis::test vector_plus_vector() {
    vector3 v1(1, 2, 3);
    vector3 v2(3, 2, 1);

    vector3 v3 = v1 + v2;

    bool result = v3.x == 4 && v3.y == 4 && v3.z == 4;

    return mavis_assert_true(result);
}

mavis::test vector_minus_vector() {
    vector3 v1(1, 2, 3);

    vector3 v2 = v1 - v1;

    bool result = v2.x == 0 && v2.y == 0 && v2.z == 0;

    return mavis_assert_true(result);
}

mavis::test vector_mul_scalar() {
    vector3 v1(1, 1, 1);

    v1 = v1 * 4;

    bool result = v1.x == 4 && v1.y == 4 && v1.z == 4;

    return mavis_assert_true(result);
}

mavis::test vector_equals_vector() {
    vector3 v1(1, 1, 1);
    vector3 v2(1, 1, 1);

    // if you want to test your own types you'll need to override operator== and
    // overload ostream& operator<<(ostream&, YOUR_CLASS)
    return mavis_assert_equals(v1, v2);
}

int main() {
    auto test_unit = mavis::create_test_unit("vector3 class test");

    test_unit.add_test(vector_plus_vector);
    test_unit.add_test(vector_minus_vector);
    test_unit.add_test(vector_mul_scalar);
    test_unit.add_test(vector_equals_vector);

    test_unit.run_tests();

    return 0;
}

