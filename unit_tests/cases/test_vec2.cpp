#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec2 assigment")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = a;
    TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("Test vec2 operator neg")
{
    const vec2 a = vec2_new(1.0f, 2.0f, 3.0f);
    const vec2 b = -a;
    TEST(a.x == -b.x && a.y == -b.y);
}

DEFINE_UNIT_TEST("Test vec2 operator+")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a + b;
    TEST(c.x == 4.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("Test vec2 operator-")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 6.0f);
    const vec2 c = a - b;
    TEST(c.x == -2.0f && c.y == -4.0f);
}

DEFINE_UNIT_TEST("Test vec2 operator*")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a * b;
    TEST(c.x == 3.0f && c.y == 8.0f);
}

DEFINE_UNIT_TEST("Test vec2 operator/")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 0.5f);
}

