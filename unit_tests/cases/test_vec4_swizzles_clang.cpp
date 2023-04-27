#include "../test_framework.h"

DEFINE_UNIT_TEST("vec4.xxxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxx(a);
    const vec4 c = a.xxxx;
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
    TEST(a.x == c.x && a.x == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxy(a);
    const vec4 c = a.xxxy;
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
    TEST(a.x == c.x && a.x == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxz(a);
    const vec4 c = a.xxxz;
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
    TEST(a.x == c.x && a.x == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxw(a);
    const vec4 c = a.xxxw;
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
    TEST(a.x == c.x && a.x == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyx(a);
    const vec4 c = a.xxyx;
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
    TEST(a.x == c.x && a.x == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyy(a);
    const vec4 c = a.xxyy;
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
    TEST(a.x == c.x && a.x == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyz(a);
    const vec4 c = a.xxyz;
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
    TEST(a.x == c.x && a.x == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyw(a);
    const vec4 c = a.xxyw;
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
    TEST(a.x == c.x && a.x == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzx(a);
    const vec4 c = a.xxzx;
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
    TEST(a.x == c.x && a.x == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzy(a);
    const vec4 c = a.xxzy;
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
    TEST(a.x == c.x && a.x == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzz(a);
    const vec4 c = a.xxzz;
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
    TEST(a.x == c.x && a.x == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xxzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzw(a);
    const vec4 c = a.xxzw;
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
    TEST(a.x == c.x && a.x == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxx(a);
    const vec4 c = a.xyxx;
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
    TEST(a.x == c.x && a.y == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxy(a);
    const vec4 c = a.xyxy;
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
    TEST(a.x == c.x && a.y == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxz(a);
    const vec4 c = a.xyxz;
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
    TEST(a.x == c.x && a.y == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxw(a);
    const vec4 c = a.xyxw;
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
    TEST(a.x == c.x && a.y == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyx(a);
    const vec4 c = a.xyyx;
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.x == b.w);
    TEST(a.x == c.x && a.y == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyz(a);
    const vec4 c = a.xyyz;
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
    TEST(a.x == c.x && a.y == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyw(a);
    const vec4 c = a.xyyw;
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
    TEST(a.x == c.x && a.y == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzx(a);
    const vec4 c = a.xyzx;
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
    TEST(a.x == c.x && a.y == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzy(a);
    const vec4 c = a.xyzy;
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.y == b.w);
    TEST(a.x == c.x && a.y == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xyzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzz(a);
    const vec4 c = a.xyzz;
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.z == b.w);
    TEST(a.x == c.x && a.y == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxx(a);
    const vec4 c = a.xzxx;
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
    TEST(a.x == c.x && a.z == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxy(a);
    const vec4 c = a.xzxy;
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
    TEST(a.x == c.x && a.z == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxz(a);
    const vec4 c = a.xzxz;
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
    TEST(a.x == c.x && a.z == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxw(a);
    const vec4 c = a.xzxw;
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
    TEST(a.x == c.x && a.z == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyx(a);
    const vec4 c = a.xzyx;
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
    TEST(a.x == c.x && a.z == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyy(a);
    const vec4 c = a.xzyy;
    TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
    TEST(a.x == c.x && a.z == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyz(a);
    const vec4 c = a.xzyz;
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
    TEST(a.x == c.x && a.z == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyw(a);
    const vec4 c = a.xzyw;
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
    TEST(a.x == c.x && a.z == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzx(a);
    const vec4 c = a.xzzx;
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
    TEST(a.x == c.x && a.z == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzy(a);
    const vec4 c = a.xzzy;
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
    TEST(a.x == c.x && a.z == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzz(a);
    const vec4 c = a.xzzz;
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
    TEST(a.x == c.x && a.z == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzw(a);
    const vec4 c = a.xzzw;
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
    TEST(a.x == c.x && a.z == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwx(a);
    const vec4 c = a.xzwx;
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
    TEST(a.x == c.x && a.z == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwy(a);
    const vec4 c = a.xzwy;
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
    TEST(a.x == c.x && a.z == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwz(a);
    const vec4 c = a.xzwz;
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
    TEST(a.x == c.x && a.z == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xzww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzww(a);
    const vec4 c = a.xzww;
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
    TEST(a.x == c.x && a.z == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxx(a);
    const vec4 c = a.xwxx;
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
    TEST(a.x == c.x && a.w == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxy(a);
    const vec4 c = a.xwxy;
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
    TEST(a.x == c.x && a.w == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxz(a);
    const vec4 c = a.xwxz;
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
    TEST(a.x == c.x && a.w == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxw(a);
    const vec4 c = a.xwxw;
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
    TEST(a.x == c.x && a.w == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyx(a);
    const vec4 c = a.xwyx;
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
    TEST(a.x == c.x && a.w == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyz(a);
    const vec4 c = a.xwyz;
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
    TEST(a.x == c.x && a.w == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyw(a);
    const vec4 c = a.xwyw;
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
    TEST(a.x == c.x && a.w == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzx(a);
    const vec4 c = a.xwzx;
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
    TEST(a.x == c.x && a.w == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzy(a);
    const vec4 c = a.xwzy;
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
    TEST(a.x == c.x && a.w == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzz(a);
    const vec4 c = a.xwzz;
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
    TEST(a.x == c.x && a.w == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzw(a);
    const vec4 c = a.xwzw;
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
    TEST(a.x == c.x && a.w == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwx(a);
    const vec4 c = a.xwwx;
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
    TEST(a.x == c.x && a.w == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwy(a);
    const vec4 c = a.xwwy;
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
    TEST(a.x == c.x && a.w == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwz(a);
    const vec4 c = a.xwwz;
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
    TEST(a.x == c.x && a.w == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.xwww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwww(a);
    const vec4 c = a.xwww;
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
    TEST(a.x == c.x && a.w == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxx(a);
    const vec4 c = a.yxxx;
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
    TEST(a.y == c.x && a.x == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxy(a);
    const vec4 c = a.yxxy;
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
    TEST(a.y == c.x && a.x == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxz(a);
    const vec4 c = a.yxxz;
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
    TEST(a.y == c.x && a.x == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxw(a);
    const vec4 c = a.yxxw;
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
    TEST(a.y == c.x && a.x == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyx(a);
    const vec4 c = a.yxyx;
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
    TEST(a.y == c.x && a.x == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyy(a);
    const vec4 c = a.yxyy;
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
    TEST(a.y == c.x && a.x == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyz(a);
    const vec4 c = a.yxyz;
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
    TEST(a.y == c.x && a.x == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyw(a);
    const vec4 c = a.yxyw;
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
    TEST(a.y == c.x && a.x == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzx(a);
    const vec4 c = a.yxzx;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
    TEST(a.y == c.x && a.x == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzy(a);
    const vec4 c = a.yxzy;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
    TEST(a.y == c.x && a.x == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzz(a);
    const vec4 c = a.yxzz;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
    TEST(a.y == c.x && a.x == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzw(a);
    const vec4 c = a.yxzw;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
    TEST(a.y == c.x && a.x == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwx(a);
    const vec4 c = a.yxwx;
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
    TEST(a.y == c.x && a.x == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwy(a);
    const vec4 c = a.yxwy;
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
    TEST(a.y == c.x && a.x == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwz(a);
    const vec4 c = a.yxwz;
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
    TEST(a.y == c.x && a.x == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yxww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxww(a);
    const vec4 c = a.yxww;
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
    TEST(a.y == c.x && a.x == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxx(a);
    const vec4 c = a.yyxx;
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
    TEST(a.y == c.x && a.y == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxy(a);
    const vec4 c = a.yyxy;
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
    TEST(a.y == c.x && a.y == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxz(a);
    const vec4 c = a.yyxz;
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
    TEST(a.y == c.x && a.y == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxw(a);
    const vec4 c = a.yyxw;
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
    TEST(a.y == c.x && a.y == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyyz(a);
    const vec4 c = a.yyyz;
	TEST(a.y == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
    TEST(a.y == c.x && a.y == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyyw(a);
    const vec4 c = a.yyyw;
    TEST(a.y == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
    TEST(a.y == c.x && a.y == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yywx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywx(a);
    const vec4 c = a.yywx;
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
    TEST(a.y == c.x && a.y == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yywy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywy(a);
    const vec4 c = a.yywy;
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
    TEST(a.y == c.x && a.y == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yywz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywz(a);
    const vec4 c = a.yywz;
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
    TEST(a.y == c.x && a.y == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yyww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyww(a);
    const vec4 c = a.yyww;
    TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
    TEST(a.y == c.x && a.y == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxx(a);
    const vec4 c = a.yzxx;
    TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
    TEST(a.y == c.x && a.z == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxy(a);
    const vec4 c = a.yzxy;
    TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
    TEST(a.y == c.x && a.z == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxz(a);
    const vec4 c = a.yzxz;
    TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
    TEST(a.y == c.x && a.z == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxw(a);
    const vec4 c = a.yzxw;
    TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
    TEST(a.y == c.x && a.z == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyx(a);
    const vec4 c = a.yzyx;
    TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
    TEST(a.y == c.x && a.z == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyy(a);
    const vec4 c = a.yzyy;
    TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
    TEST(a.y == c.x && a.z == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyz(a);
    const vec4 c = a.yzyz;
    TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
    TEST(a.y == c.x && a.z == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyw(a);
    const vec4 c = a.yzyw;
    TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
    TEST(a.y == c.x && a.z == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzx(a);
    const vec4 c = a.yzzx;
    TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
    TEST(a.y == c.x && a.z == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzy(a);
    const vec4 c = a.yzzy;
    TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
    TEST(a.y == c.x && a.z == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzz(a);
    const vec4 c = a.yzzz;
    TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
    TEST(a.y == c.x && a.z == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzw(a);
    const vec4 c = a.yzzw;
    TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
    TEST(a.y == c.x && a.z == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwx(a);
    const vec4 c = a.yzwx;
    TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
    TEST(a.y == c.x && a.z == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwy(a);
    const vec4 c = a.yzwy;
    TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
    TEST(a.y == c.x && a.z == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwz(a);
    const vec4 c = a.yzwz;
    TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
    TEST(a.y == c.x && a.z == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.yzww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzww(a);
    const vec4 c = a.yzww;
    TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
    TEST(a.y == c.x && a.z == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxx(a);
    const vec4 c = a.ywxx;
    TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
    TEST(a.y == c.x && a.w == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxy(a);
    const vec4 c = a.ywxy;
    TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
    TEST(a.y == c.x && a.w == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxz(a);
    const vec4 c = a.ywxz;
    TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
    TEST(a.y == c.x && a.w == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxw(a);
    const vec4 c = a.ywxw;
    TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
    TEST(a.y == c.x && a.w == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywyz(a);
    const vec4 c = a.ywyz;
    TEST(a.y == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
    TEST(a.y == c.x && a.w == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywyw(a);
    const vec4 c = a.ywyw;
    TEST(a.y == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
    TEST(a.y == c.x && a.w == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzx(a);
    const vec4 c = a.ywzx;
    TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
    TEST(a.y == c.x && a.w == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzy(a);
    const vec4 c = a.ywzy;
    TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
    TEST(a.y == c.x && a.w == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzz(a);
    const vec4 c = a.ywzz;
    TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
    TEST(a.y == c.x && a.w == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwx(a);
    const vec4 c = a.ywwx;
    TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
    TEST(a.y == c.x && a.w == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwy(a);
    const vec4 c = a.ywwy;
    TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
    TEST(a.y == c.x && a.w == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwz(a);
    const vec4 c = a.ywwz;
    TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
    TEST(a.y == c.x && a.w == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.ywww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywww(a);
    const vec4 c = a.ywww;
    TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
    TEST(a.y == c.x && a.w == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxx(a);
    const vec4 c = a.zxxx;
    TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
    TEST(a.z == c.x && a.x == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxy(a);
    const vec4 c = a.zxxy;
    TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
    TEST(a.z == c.x && a.x == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxz(a);
    const vec4 c = a.zxxz;
    TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
    TEST(a.z == c.x && a.x == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxw(a);
    const vec4 c = a.zxxw;
    TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
    TEST(a.z == c.x && a.x == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyx(a);
    const vec4 c = a.zxyx;
    TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
    TEST(a.z == c.x && a.x == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyy(a);
    const vec4 c = a.zxyy;
    TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
    TEST(a.z == c.x && a.x == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyz(a);
    const vec4 c = a.zxyz;
    TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
    TEST(a.z == c.x && a.x == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyw(a);
    const vec4 c = a.zxyw;
    TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
    TEST(a.z == c.x && a.x == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzx(a);
    const vec4 c = a.zxzx;
    TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
    TEST(a.z == c.x && a.x == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzy(a);
    const vec4 c = a.zxzy;
    TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
    TEST(a.z == c.x && a.x == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzz(a);
    const vec4 c = a.zxzz;
    TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
    TEST(a.z == c.x && a.x == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzw(a);
    const vec4 c = a.zxzw;
    TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
    TEST(a.z == c.x && a.x == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwx(a);
    const vec4 c = a.zxwx;
    TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
    TEST(a.z == c.x && a.x == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwy(a);
    const vec4 c = a.zxwy;
    TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
    TEST(a.z == c.x && a.x == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwz(a);
    const vec4 c = a.zxwz;
    TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
    TEST(a.z == c.x && a.x == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zxww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxww(a);
    const vec4 c = a.zxww;
    TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
    TEST(a.z == c.x && a.x == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxx(a);
    const vec4 c = a.zyxx;
    TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
    TEST(a.z == c.x && a.y == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxy(a);
    const vec4 c = a.zyxy;
    TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
    TEST(a.z == c.x && a.y == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxz(a);
    const vec4 c = a.zyxz;
    TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
    TEST(a.z == c.x && a.y == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxw(a);
    const vec4 c = a.zyxw;
    TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
    TEST(a.z == c.x && a.y == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyyz(a);
    const vec4 c = a.zyyz;
    TEST(a.z == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
    TEST(a.z == c.x && a.y == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyyw(a);
    const vec4 c = a.zyyw;
    TEST(a.z == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
    TEST(a.z == c.x && a.y == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzx(a);
    const vec4 c = a.zyzx;
    TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
    TEST(a.z == c.x && a.y == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzy(a);
    const vec4 c = a.zyzy;
    TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.y == b.w);
    TEST(a.z == c.x && a.y == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzz(a);
    const vec4 c = a.zyzz;
    TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.z == b.w);
    TEST(a.z == c.x && a.y == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzw(a);
    const vec4 c = a.zyzw;
    TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
    TEST(a.z == c.x && a.y == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zywx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywx(a);
    const vec4 c = a.zywx;
    TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
    TEST(a.z == c.x && a.y == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zywy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywy(a);
    const vec4 c = a.zywy;
    TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
    TEST(a.z == c.x && a.y == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zywz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywz(a);
    const vec4 c = a.zywz;
    TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
    TEST(a.z == c.x && a.y == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zyww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyww(a);
    const vec4 c = a.zyww;
    TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
    TEST(a.z == c.x && a.y == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxx(a);
    const vec4 c = a.zzxx;
    TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
    TEST(a.z == c.x && a.z == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxy(a);
    const vec4 c = a.zzxy;
    TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
    TEST(a.z == c.x && a.z == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxz(a);
    const vec4 c = a.zzxz;
    TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
    TEST(a.z == c.x && a.z == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxw(a);
    const vec4 c = a.zzxw;
    TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
    TEST(a.z == c.x && a.z == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyx(a);
    const vec4 c = a.zzyx;
    TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
    TEST(a.z == c.x && a.z == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyy(a);
    const vec4 c = a.zzyy;
    TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
    TEST(a.z == c.x && a.z == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyz(a);
    const vec4 c = a.zzyz;
    TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
    TEST(a.z == c.x && a.z == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyw(a);
    const vec4 c = a.zzyw;
    TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
    TEST(a.z == c.x && a.z == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzx(a);
    const vec4 c = a.zzzx;
    TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
    TEST(a.z == c.x && a.z == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzy(a);
    const vec4 c = a.zzzy;
    TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
    TEST(a.z == c.x && a.z == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzz(a);
    const vec4 c = a.zzzz;
    TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
    TEST(a.z == c.x && a.z == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzw(a);
    const vec4 c = a.zzzw;
    TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
    TEST(a.z == c.x && a.z == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwx(a);
    const vec4 c = a.zzwx;
    TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
    TEST(a.z == c.x && a.z == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwy(a);
    const vec4 c = a.zzwy;
    TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
    TEST(a.z == c.x && a.z == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwz(a);
    const vec4 c = a.zzwz;
    TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
    TEST(a.z == c.x && a.z == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zzww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzww(a);
    const vec4 c = a.zzww;
    TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
    TEST(a.z == c.x && a.z == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxx(a);
    const vec4 c = a.zwxx;
    TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
    TEST(a.z == c.x && a.w == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxy(a);
    const vec4 c = a.zwxy;
    TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
    TEST(a.z == c.x && a.w == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxz(a);
    const vec4 c = a.zwxz;
    TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
    TEST(a.z == c.x && a.w == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxw(a);
    const vec4 c = a.zwxw;
    TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
    TEST(a.z == c.x && a.w == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyx(a);
    const vec4 c = a.zwyx;
    TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
    TEST(a.z == c.x && a.w == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyy(a);
    const vec4 c = a.zwyy;
    TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.y == b.w);
    TEST(a.z == c.x && a.w == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyz(a);
    const vec4 c = a.zwyz;
    TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
    TEST(a.z == c.x && a.w == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyw(a);
    const vec4 c = a.zwyw;
    TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
    TEST(a.z == c.x && a.w == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzx(a);
    const vec4 c = a.zwzx;
    TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
    TEST(a.z == c.x && a.w == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzy(a);
    const vec4 c = a.zwzy;
    TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
    TEST(a.z == c.x && a.w == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzz(a);
    const vec4 c = a.zwzz;
    TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
    TEST(a.z == c.x && a.w == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzw(a);
    const vec4 c = a.zwzw;
    TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
    TEST(a.z == c.x && a.w == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwx(a);
    const vec4 c = a.zwwx;
    TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
    TEST(a.z == c.x && a.w == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwy(a);
    const vec4 c = a.zwwy;
    TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
    TEST(a.z == c.x && a.w == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwz(a);
    const vec4 c = a.zwwz;
    TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
    TEST(a.z == c.x && a.w == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.zwww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwww(a);
    const vec4 c = a.zwww;
    TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
    TEST(a.z == c.x && a.w == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxx(a);
    const vec4 c = a.wxxx;
    TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
    TEST(a.w == c.x && a.x == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxy(a);
    const vec4 c = a.wxxy;
    TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
    TEST(a.w == c.x && a.x == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxz(a);
    const vec4 c = a.wxxz;
    TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
    TEST(a.w == c.x && a.x == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxw(a);
    const vec4 c = a.wxxw;
    TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
    TEST(a.w == c.x && a.x == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyx(a);
    const vec4 c = a.wxyx;
    TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
    TEST(a.w == c.x && a.x == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyy(a);
    const vec4 c = a.wxyy;
    TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
    TEST(a.w == c.x && a.x == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyz(a);
    const vec4 c = a.wxyz;
    TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
    TEST(a.w == c.x && a.x == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyw(a);
    const vec4 c = a.wxyw;
    TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
    TEST(a.w == c.x && a.x == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzx(a);
    const vec4 c = a.wxzx;
    TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
    TEST(a.w == c.x && a.x == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzy(a);
    const vec4 c = a.wxzy;
    TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
    TEST(a.w == c.x && a.x == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzz(a);
    const vec4 c = a.wxzz;
    TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
    TEST(a.w == c.x && a.x == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzw(a);
    const vec4 c = a.wxzw;
    TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
    TEST(a.w == c.x && a.x == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwx(a);
    const vec4 c = a.wxwx;
    TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
    TEST(a.w == c.x && a.x == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwy(a);
    const vec4 c = a.wxwy;
    TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
    TEST(a.w == c.x && a.x == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwz(a);
    const vec4 c = a.wxwz;
    TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
    TEST(a.w == c.x && a.x == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wxww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxww(a);
    const vec4 c = a.wxww;
    TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
    TEST(a.w == c.x && a.x == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxx(a);
    const vec4 c = a.wyxx;
    TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
    TEST(a.w == c.x && a.y == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxy(a);
    const vec4 c = a.wyxy;
    TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
    TEST(a.w == c.x && a.y == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxz(a);
    const vec4 c = a.wyxz;
    TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
    TEST(a.w == c.x && a.y == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxw(a);
    const vec4 c = a.wyxw;
    TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
    TEST(a.w == c.x && a.y == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyx(a);
    const vec4 c = a.wyyx;
    TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.x == b.w);
    TEST(a.w == c.x && a.y == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyy(a);
    const vec4 c = a.wyyy;
    TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.y == b.w);
    TEST(a.w == c.x && a.y == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyz(a);
    const vec4 c = a.wyyz;
    TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
    TEST(a.w == c.x && a.y == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyw(a);
    const vec4 c = a.wyyw;
    TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
    TEST(a.w == c.x && a.y == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyzx(a);
    const vec4 c = a.wyzx;
    TEST(a.w == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
    TEST(a.w == c.x && a.y == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wywx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywx(a);
    const vec4 c = a.wywx;
    TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
    TEST(a.w == c.x && a.y == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wywy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywy(a);
    const vec4 c = a.wywy;
    TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
    TEST(a.w == c.x && a.y == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wywz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywz(a);
    const vec4 c = a.wywz;
    TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
    TEST(a.w == c.x && a.y == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wyww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyww(a);
    const vec4 c = a.wyww;
    TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
    TEST(a.w == c.x && a.y == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxx(a);
    const vec4 c = a.wzxx;
    TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
    TEST(a.w == c.x && a.z == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxy(a);
    const vec4 c = a.wzxy;
    TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
    TEST(a.w == c.x && a.z == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxz(a);
    const vec4 c = a.wzxz;
    TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
    TEST(a.w == c.x && a.z == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxw(a);
    const vec4 c = a.wzxw;
    TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
    TEST(a.w == c.x && a.z == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyx(a);
    const vec4 c = a.wzyx;
    TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
    TEST(a.w == c.x && a.z == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyy(a);
    const vec4 c = a.wzyy;
    TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
    TEST(a.w == c.x && a.z == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyz(a);
    const vec4 c = a.wzyz;
    TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
    TEST(a.w == c.x && a.z == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyw(a);
    const vec4 c = a.wzyw;
    TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
    TEST(a.w == c.x && a.z == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzx(a);
    const vec4 c = a.wzzx;
    TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
    TEST(a.w == c.x && a.z == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzy(a);
    const vec4 c = a.wzzy;
    TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
    TEST(a.w == c.x && a.z == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzz(a);
    const vec4 c = a.wzzz;
    TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
    TEST(a.w == c.x && a.z == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzw(a);
    const vec4 c = a.wzzw;
    TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
    TEST(a.w == c.x && a.z == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwx(a);
    const vec4 c = a.wzwx;
    TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
    TEST(a.w == c.x && a.z == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwy(a);
    const vec4 c = a.wzwy;
    TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
    TEST(a.w == c.x && a.z == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwz(a);
    const vec4 c = a.wzwz;
    TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
    TEST(a.w == c.x && a.z == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wzww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzww(a);
    const vec4 c = a.wzww;
    TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
    TEST(a.w == c.x && a.z == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwxx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxx(a);
    const vec4 c = a.wwxx;
    TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
    TEST(a.w == c.x && a.w == c.y && a.x == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwxy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxy(a);
    const vec4 c = a.wwxy;
    TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
    TEST(a.w == c.x && a.w == c.y && a.x == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwxz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxz(a);
    const vec4 c = a.wwxz;
    TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
    TEST(a.w == c.x && a.w == c.y && a.x == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwxw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxw(a);
    const vec4 c = a.wwxw;
    TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
    TEST(a.w == c.x && a.w == c.y && a.x == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwyx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyx(a);
    const vec4 c = a.wwyx;
    TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
    TEST(a.w == c.x && a.w == c.y && a.y == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwyy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyy(a);
    const vec4 c = a.wwyy;
    TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.y == b.w);
    TEST(a.w == c.x && a.w == c.y && a.y == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwyz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyz(a);
    const vec4 c = a.wwyz;
    TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
    TEST(a.w == c.x && a.w == c.y && a.y == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwyw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyw(a);
    const vec4 c = a.wwyw;
    TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
    TEST(a.w == c.x && a.w == c.y && a.y == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwzx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzx(a);
    const vec4 c = a.wwzx;
    TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
    TEST(a.w == c.x && a.w == c.y && a.z == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwzy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzy(a);
    const vec4 c = a.wwzy;
    TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
    TEST(a.w == c.x && a.w == c.y && a.z == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwzz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzz(a);
    const vec4 c = a.wwzz;
    TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
    TEST(a.w == c.x && a.w == c.y && a.z == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwzw")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzw(a);
    const vec4 c = a.wwzw;
    TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
    TEST(a.w == c.x && a.w == c.y && a.z == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwwx")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwx(a);
    const vec4 c = a.wwwx;
    TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
    TEST(a.w == c.x && a.w == c.y && a.w == c.z && a.x == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwwy")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwy(a);
    const vec4 c = a.wwwy;
    TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
    TEST(a.w == c.x && a.w == c.y && a.w == c.z && a.y == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwwz")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwz(a);
    const vec4 c = a.wwwz;
    TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
    TEST(a.w == c.x && a.w == c.y && a.w == c.z && a.z == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

DEFINE_UNIT_TEST("vec4.wwww")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwww(a);
    const vec4 c = a.wwww;
    TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
    TEST(a.w == c.x && a.w == c.y && a.w == c.z && a.w == c.w);
    TEST(b.x == c.x && b.y == c.y && b.z == c.z && b.w == c.w);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
