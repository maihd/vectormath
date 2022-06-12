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

DEFINE_UNIT_TEST("Test sign()")
{
    const int a = sign(1);
    const int b = 1;
    TEST(a == b);

    const int c = sign(-1);
    const int d = -1;
    TEST(c == d);
}