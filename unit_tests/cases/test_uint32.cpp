#include "../test_framework.h"

#include <vectormath/scalarmath.h>

DEFINE_UNIT_TEST("uint32_t uint32_min(uint32_t, uint32_t)")
{
    TEST_EQUAL(uint32_min(1, 2), 1);
    TEST_EQUAL(uint32_min(2, 1), 1);

    TEST_EQUAL(uint32_min(99, 100), 99);
    TEST_EQUAL(uint32_min(100, 99), 99);
}

DEFINE_UNIT_TEST("uint32_t uint32_max(uint32_t, uint32_t)")
{
    TEST_EQUAL(uint32_max(1, 2), 2);
    TEST_EQUAL(uint32_max(2, 1), 2);

    TEST_EQUAL(uint32_max(99, 100), 100);
    TEST_EQUAL(uint32_max(100, 99), 100);
}

DEFINE_UNIT_TEST("uint32_t uint32_clamp(uint32_t, uint32_t, uint32_t)")
{
    TEST_EQUAL(uint32_clamp(0, 1, 2), 1);
    TEST_EQUAL(uint32_clamp(3, 1, 2), 2);

    TEST_EQUAL(uint32_clamp(99, 100, 101), 100);
    TEST_EQUAL(uint32_clamp(98, 99, 100), 99);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
