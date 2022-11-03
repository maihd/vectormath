#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec2 assigment")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = a;
    TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = -a;
    TEST(a.x == -b.x && a.y == -b.y);
}

DEFINE_UNIT_TEST("vec2 operator+(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a + b;
    TEST(c.x == 4.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 6.0f);
    const vec2 c = a - b;
    TEST(c.x == -2.0f && c.y == -4.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a * b;
    TEST(c.x == 3.0f && c.y == 8.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 0.5f);
}

DEFINE_UNIT_TEST("vec2 operator+(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a + b;
    TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a - b;
    TEST(c.x == -2.0f && c.y == -1.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a * b;
    TEST(c.x == 3.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 2.0f / 3.0f);
}

DEFINE_UNIT_TEST("vec2 operator+(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a + b;
    TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a - b;
    TEST(c.x == -2.0f && c.y == -3.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a * b;
    TEST(c.x == 3.0f && c.y == 4.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 0.25f);
}

DEFINE_UNIT_TEST("vec2 vec2_new(float x, float y)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = { 1.0f, 2.0f };
    TEST(a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_new1(float s)")
{
    const vec2 a = vec2_new1(1.0f);
    const vec2 b = { 1.0f, 1.0f };
    TEST(a.x == a.y && a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 1.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_from_vec3(vec3 v)")
{
	const vec3 a = { 1.0f, 2.0f, 3.0f };
	const vec2 b = vec2_from_vec3(a);
	TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2 vec2_neg(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_neg(a);
	TEST(a.x == -b.x && a.y == -b.y);
}

DEFINE_UNIT_TEST("vec2 vec2_add(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_add(a, b);
	TEST(c.x == 4.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_sub(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_sub(a, b);
	TEST(c.x == -2.0f && c.y == -2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_mul(a, b);
	TEST(c.x == 3.0f && c.y == 8.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_div(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_div(a, b);
	TEST(c.x == 1.0f / 3.0f && c.y == 0.5f);
}

DEFINE_UNIT_TEST("vec2 vec2_add1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_add1(a, b);
	TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_sub1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_sub1(a, b);
	TEST(c.x == -2.0f && c.y == -1.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_mul1(a, b);
	TEST(c.x == 3.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_div1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_div1(a, b);
	TEST(c.x == 1.0f / 3.0f && c.y == 2.0f / 3.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul_add(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_new(5.0f, 6.0f);
    const vec2 d = vec2_mul_add(a, b, c);
	TEST(d.x == 8.0f && d.y == 14.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul_sub(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_new(5.0f, 6.0f);
    const vec2 d = vec2_mul_sub(a, b, c);
    TEST(d.x == 2.0f && d.y == -2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_equal(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    TEST(!vec2_equal(a, b));
}

DEFINE_UNIT_TEST("vec2 vec2_not_equal(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    TEST(vec2_not_equal(a, b));
}

DEFINE_UNIT_TEST("vec2_xx(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_xx(a);
	TEST(a.x == b.x && a.x == b.y);
}

DEFINE_UNIT_TEST("vec2_yy(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yy(a);
	TEST(a.y == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2_yz(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yx(a);
	TEST(a.x == b.y && a.y == b.x);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
