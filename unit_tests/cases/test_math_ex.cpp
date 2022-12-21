#include "../test_framework.h"

DEFINE_UNIT_TEST("float float_rad2deg(float)")
{
    const float a = float_rad2deg(180.0f);
    const float b = FLOAT_PI;
    TEST(a == b);
}

DEFINE_UNIT_TEST("float float_deg2rad(float)")
{
    const float a = float_deg2rad(FLOAT_PI);
    const float b = 180.0f;
    TEST(a == b);
}

DEFINE_UNIT_TEST("int32_t int32_sign(int32_t)")
{
    const int32_t a = int32_sign(1);
    const int32_t b = 1;
    TEST(a == b);

    const int32_t c = int32_sign(-1);
    const int32_t d = -1;
    TEST(c == d);
}

DEFINE_UNIT_TEST("int32_t float_sign(float)")
{
    const int32_t e = float_sign(1.0f);
    const int32_t f = 1;
    TEST(e == f);

    const int32_t g = float_sign(-1.0f);
    const int32_t h = -1;
    TEST(g == h);
}