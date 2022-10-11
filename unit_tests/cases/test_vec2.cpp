#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec2 assigment")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = a;
    TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("Test vec2 operator neg")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
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

DEFINE_UNIT_TEST("vec2_xx(vec2)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_xx(a);
	TEST(a.x == b.x && a.x == b.y);
}

DEFINE_UNIT_TEST("vec2_yy(vec2)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yy(a);
	TEST(a.y == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2_yz(vec2)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yx(a);
	TEST(a.x == b.y && a.y == b.x);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
