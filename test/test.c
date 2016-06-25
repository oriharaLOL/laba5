#include <ctest.h>
#include <roots.h>

CTEST(equation_suite, two_roots_test)
{
    // Given
    const double a = 1;
    const double b = 3;
    const double c = 2;

    // When
    double x1;
    double x2;
    int amount;
    roots(a, b, c, &amount, &x1, &x2);

    // Then
    
    const double expected_amount = 2;
    const double expected_x1 = -1;
    const double expected_x2 = -2;

    ASSERT_EQUAL(expected_amount, amount);
    ASSERT_DBL_NEAR(expected_x1, x1);
    ASSERT_DBL_NEAR(expected_x2, x2);
}

CTEST(equation_suite, one_root_test)
{
    // Given
    const double a = 2;
    const double b = -4;
    const double c = 2;

    // When
    double x1;
    double x2;
    int amount;
    roots(a, b, c, &amount, &x1, &x2);

    // Then
    const double expected_amount = 1;
    const double expected_x1 = 1;

    ASSERT_EQUAL(expected_amount, amount);
    ASSERT_DBL_NEAR(expected_x1, x1);
}

CTEST(equation_suite, zero_a_test)
{
    // Given
    const double a = 0;
    const double b = 3;
    const double c = 2;

    // When
    double x1;
    double x2;
    int amount = 0;
    roots(a, b, c, &amount, &x1, &x2);

    // Then
    const int expected_amount = 0;

    ASSERT_EQUAL(expected_amount, amount);
}

CTEST(equation_suite, no_roots_test)
{
    // Given
    const double a = 1;
    const double b = 1;
    const double c = 1;

    // When
    double x1;
    double x2;
    int amount;
    roots(a, b, c, &amount, &x1, &x2);

    // Then
    const double expected_amount = 0;

    ASSERT_EQUAL(expected_amount, amount);
}