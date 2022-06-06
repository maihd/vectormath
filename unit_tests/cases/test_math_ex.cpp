#include "../test_framework.h"

DEFINE_UNIT_TEST("Test radians()")
{
    const float a = radians(180.0f);
    const float b = PI;
    TEST(a == b);
}

DEFINE_UNIT_TEST("Test degrees()")
{
    const float a = degrees(PI);
    const float b = 180.0f;
    TEST(a == b);
}