#include "../test_framework.h"

#if VECTORMATH_ENABLE_CLANG_EXT

DEFINE_UNIT_TEST("clang: vec2.xx")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_xx(a);
    const vec2 c = a.xx;

	TEST(a.x == b.x && a.x == b.y);
	TEST(a.x == c.x && a.x == c.y);
	TEST(b.x == c.x && b.y == c.y);
}

DEFINE_UNIT_TEST("clang: vec2.yy")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yy(a);
    const vec2 c = a.yy;
	TEST(a.y == b.x && a.y == b.y);
	TEST(a.y == c.x && a.y == c.y);
	TEST(b.x == c.x && b.y == c.y);
}

DEFINE_UNIT_TEST("vec2_yz(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yx(a);
    const vec2 c = a.yx;
	TEST(a.x == b.y && a.y == b.x);
	TEST(a.x == c.y && a.y == c.x);
	TEST(b.x == c.x && b.y == c.y);
}

#endif // VECTORMATH_ENABLE_CLANG_EXT

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
