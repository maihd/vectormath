#include "../test_framework.h"

DEFINE_UNIT_TEST("clang: vec3.xxx")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_xxx(a);
	const vec3 c = a.xxx;
    TEST(a.x == b.x && a.x == b.y && a.x == b.z);
	TEST(a.x == c.x && a.x == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xxy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxy(a);
	const vec3 c = a.xxy;
	TEST(a.x == b.x && a.x == b.y && a.y == b.z);
	TEST(a.x == c.x && a.x == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xxz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxz(a);
	const vec3 c = a.xxz;
	TEST(a.x == b.x && a.x == b.y && a.z == b.z);
	TEST(a.x == c.x && a.x == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xyx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyx(a);
	const vec3 c = a.xyx;
	TEST(a.x == b.x && a.y == b.y && a.x == b.z);
	TEST(a.x == c.x && a.y == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xyy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyy(a);
	const vec3 c = a.xyy;
	TEST(a.x == b.x && a.y == b.y && a.y == b.z);
	TEST(a.x == c.x && a.y == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xzx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzx(a);
	const vec3 c = a.xzx;
	TEST(a.x == b.x && a.z == b.y && a.x == b.z);
	TEST(a.x == c.x && a.z == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xzy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzy(a);
	const vec3 c = a.xzy;
	TEST(a.x == b.x && a.z == b.y && a.y == b.z);
	TEST(a.x == c.x && a.z == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.xzz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzz(a);
	const vec3 c = a.xzz;
	TEST(a.x == b.x && a.z == b.y && a.z == b.z);
	TEST(a.x == c.x && a.z == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yyy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyy(a);
	const vec3 c = a.yyy;
	TEST(a.y == b.x && a.y == b.y && a.y == b.z);
	TEST(a.y == c.x && a.y == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yyx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyx(a);
	const vec3 c = a.yyx;
	TEST(a.y == b.x && a.y == b.y && a.x == b.z);
	TEST(a.y == c.x && a.y == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yyz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyz(a);
	const vec3 c = a.yyz;
	TEST(a.y == b.x && a.y == b.y && a.z == b.z);
	TEST(a.y == c.x && a.y == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yxx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxx(a);
	const vec3 c = a.yxx;
	TEST(a.y == b.x && a.x == b.y && a.x == b.z);
	TEST(a.y == c.x && a.x == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yxy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxy(a);
	const vec3 c = a.yxy;
	TEST(a.y == b.x && a.x == b.y && a.y == b.z);
	TEST(a.y == c.x && a.x == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yxz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	const vec3 c = a.yxz;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
	TEST(a.y == c.x && a.x == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yzx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	const vec3 c = a.yxz;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
	TEST(a.y == c.x && a.x == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yzy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzy(a);
	const vec3 c = a.yzy;
	TEST(a.y == b.x && a.z == b.y && a.y == b.z);
	TEST(a.y == c.x && a.z == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yxz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	const vec3 c = a.yxz;
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
	TEST(a.y == c.x && a.x == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.yzz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzz(a);
	const vec3 c = a.yzz;
	TEST(a.y == b.x && a.z == b.y && a.z == b.z);
	TEST(a.y == c.x && a.z == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zzz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzz(a);
	const vec3 c = a.zzz;
	TEST(a.z == b.x && a.z == b.y && a.z == b.z);
	TEST(a.z == c.x && a.z == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zzx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzx(a);
	const vec3 c = a.zzx;
	TEST(a.z == b.x && a.z == b.y && a.x == b.z);
	TEST(a.z == c.x && a.z == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zzy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzy(a);
	const vec3 c = a.zzy;
	TEST(a.z == b.x && a.z == b.y && a.y == b.z);
	TEST(a.z == c.x && a.z == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zxx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxx(a);
	const vec3 c = a.zxx;
	TEST(a.z == b.x && a.x == b.y && a.x == b.z);
	TEST(a.z == c.x && a.x == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zxy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxy(a);
	const vec3 c = a.zxy;
	TEST(a.z == b.x && a.x == b.y && a.y == b.z);
	TEST(a.z == c.x && a.x == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zxz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxz(a);
	const vec3 c = a.zxz;
	TEST(a.z == b.x && a.x == b.y && a.z == b.z);
	TEST(a.z == c.x && a.x == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zyx")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyx(a);
	const vec3 c = a.zyx;
	TEST(a.z == b.x && a.y == b.y && a.x == b.z);
	TEST(a.z == c.x && a.y == c.y && a.x == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zyy")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyy(a);
	const vec3 c = a.zyy;
	TEST(a.z == b.x && a.y == b.y && a.y == b.z);
	TEST(a.z == c.x && a.y == c.y && a.y == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

DEFINE_UNIT_TEST("clang: vec3.zyz")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyz(a);
	const vec3 c = a.zyz;
	TEST(a.z == b.x && a.y == b.y && a.z == b.z);
	TEST(a.z == c.x && a.y == c.y && a.z == c.z);
	TEST(b.x == c.x && b.y == c.y && b.z == c.z);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
