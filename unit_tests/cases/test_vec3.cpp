#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec3 assigment")
{
    const vec3 a = vec3_new(0.0f, 0.0f, 1.0f);
    const vec3 b = a;
    TEST(a.x == b.x && a.y == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("Test vec3 operator neg")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = -a;
    TEST(a.x == -b.x && a.y == -b.y && a.z == -b.z);
}

DEFINE_UNIT_TEST("Test vec3 operator+")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = a + b;
    TEST(c.x == 5.0f && c.y == 7.0f && c.z == 9.0f);
}

DEFINE_UNIT_TEST("Test vec3 operator-")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = a - b;
    TEST(c.x == -3.0f && c.y == -3.0f && c.z == -3.0f);
}

DEFINE_UNIT_TEST("Test vec3 operator*")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = a * b;
    TEST(c.x == 4.0f && c.y == 10.0f && c.z == 18.0f);
}

DEFINE_UNIT_TEST("Test vec3 operator/")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = a / b;
    TEST(c.x == 0.25f && c.y == 0.4f && c.z == 0.5f);
}

DEFINE_UNIT_TEST("vec3 vec3_xxx(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_xxx(a);
    TEST(a.x == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxy(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxz(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyx(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyy(a);
	TEST(a.x == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzx(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzy(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzz(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyy(a);
	TEST(a.y == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyx(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyz(a);
	TEST(a.y == b.x && a.y == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxx(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxy(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzy(a);
	TEST(a.y == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzz(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzz(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzx(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzy(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxx(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxy(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxz(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyx(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyy(a);
	TEST(a.z == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyz(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
