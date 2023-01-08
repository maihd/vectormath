#include "../test_framework.h"

#include <vectormath/scalarmath.h>

DEFINE_UNIT_TEST("int32_t int32_sign(int32_t)")
{
    TEST_EQUAL(int32_sign(1), 1);
    TEST_EQUAL(int32_sign(-1), -1);
    TEST_EQUAL(int32_sign(0), 0);
}

DEFINE_UNIT_TEST("int32_t int32_min(int32_t, int32_t)")
{
    TEST_EQUAL(int32_min(1, 2), 1);
    TEST_EQUAL(int32_min(2, 1), 1);

    TEST_EQUAL(int32_min(99, 100), 99);
    TEST_EQUAL(int32_min(100, 99), 99);

    TEST_EQUAL(int32_min(-1, -2), -2);
    TEST_EQUAL(int32_min(-2, -1), -2);

    TEST_EQUAL(int32_min(-99, -100), -100);
    TEST_EQUAL(int32_min(-100, -99), -100);
}

DEFINE_UNIT_TEST("int32_t int32_max(int32_t, int32_t)")
{
    TEST_EQUAL(int32_max(1, 2), 2);
    TEST_EQUAL(int32_max(2, 1), 2);

    TEST_EQUAL(int32_max(99, 100), 100);
    TEST_EQUAL(int32_max(100, 99), 100);

    TEST_EQUAL(int32_max(-1, -2), -1);
    TEST_EQUAL(int32_max(-2, -1), -1);

    TEST_EQUAL(int32_max(-99, -100), -99);
    TEST_EQUAL(int32_max(-100, -99), -99);
}

DEFINE_UNIT_TEST("int32_t int32_clamp(int32_t, int32_t, int32_t)")
{
    TEST_EQUAL(int32_clamp(0, 1, 2), 1);
    TEST_EQUAL(int32_clamp(3, 1, 2), 2);

    TEST_EQUAL(int32_clamp(99, 100, 101), 100);
    TEST_EQUAL(int32_clamp(98, 99, 100), 99);

    TEST_EQUAL(int32_clamp(-3, -2, -1), -2);
    TEST_EQUAL(int32_clamp( 0, -2, -1), -1);

    TEST_EQUAL(int32_clamp(-99, -101, -100), -100);
    TEST_EQUAL(int32_clamp(-98, -100, -99), -99);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
