#include "../test_framework.h"

DEFINE_UNIT_TEST("vec4 vec4_xxxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxx(a);
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxy(a);
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxz(a);
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxxw(a);
	TEST(a.x == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyx(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyy(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyz(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxyw(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzx(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzy(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzz(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xxzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xxzw(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxx(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxy(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxz(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyxw(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyx(a);
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyz(a);
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyyw(a);
	TEST(a.x == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzx(a);
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzy(a);
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xyzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xyzz(a);
	TEST(a.x == b.x && a.y == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxx(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxy(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxz(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzxw(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyx(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyy(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyz(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzyw(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzx(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzy(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzz(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzzw(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwx(a);
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwy(a);
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzwz(a);
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xzww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xzww(a);
	TEST(a.x == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxx(a);
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxy(a);
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxz(a);
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwxw(a);
	TEST(a.x == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyx(a);
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyz(a);
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwyw(a);
	TEST(a.x == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzx(a);
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzy(a);
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzz(a);
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwzw(a);
	TEST(a.x == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwx(a);
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwy(a);
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwwz(a);
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_xwww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_xwww(a);
	TEST(a.x == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxx(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxy(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxz(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxxw(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyx(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyy(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyz(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxyw(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzx(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzy(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxzw(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwx(a);
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwy(a);
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxwz(a);
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yxww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yxww(a);
	TEST(a.y == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxx(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxy(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxz(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyxw(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyyz(a);
	TEST(a.y == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyyw(a);
	TEST(a.y == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yywx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywx(a);
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yywy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywy(a);
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yywz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yywz(a);
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yyww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yyww(a);
	TEST(a.y == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxx(a);
	TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxy(a);
	TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxz(a);
	TEST(a.y == b.x && a.x == b.z && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzxw(a);
	TEST(a.y == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyx(a);
	TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyy(a);
	TEST(a.y == b.z && a.z == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyz(a);
	TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzyw(a);
	TEST(a.y == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzx(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzy(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzz(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzzw(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwx(a);
	TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwy(a);
	TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzwz(a);
	TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_yzww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_yzww(a);
	TEST(a.y == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxx(a);
	TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxy(a);
	TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxz(a);
	TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywxw(a);
	TEST(a.y == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywyz(a);
	TEST(a.y == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywyw(a);
	TEST(a.y == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzx(a);
	TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzy(a);
	TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywzz(a);
	TEST(a.y == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwx(a);
	TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwy(a);
	TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywwz(a);
	TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_ywww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_ywww(a);
	TEST(a.y == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxx(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxy(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxz(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxxw(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyx(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyy(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyz(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxyw(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzx(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzy(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzz(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxzw(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwx(a);
	TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwy(a);
	TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxwz(a);
	TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zxww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zxww(a);
	TEST(a.z == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxx(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxy(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxz(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyxw(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyyz(a);
	TEST(a.z == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyyw(a);
	TEST(a.z == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzx(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzy(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzz(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyzw(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zywx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywx(a);
	TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zywy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywy(a);
	TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zywz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zywz(a);
	TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zyww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zyww(a);
	TEST(a.z == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxx(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxy(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxz(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzxw(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyx(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyy(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyz(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzyw(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzx(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzy(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzz(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzzw(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwx(a);
	TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwy(a);
	TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzwz(a);
	TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zzww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zzww(a);
	TEST(a.z == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxx(a);
	TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxy(a);
	TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxz(a);
	TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwxw(a);
	TEST(a.z == b.x && a.w == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyx(a);
	TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyy(a);
	TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyz(a);
	TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwyw(a);
	TEST(a.z == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzx(a);
	TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzy(a);
	TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzz(a);
	TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwzw(a);
	TEST(a.z == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwx(a);
	TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwy(a);
	TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwwz(a);
	TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_zwww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_zwww(a);
	TEST(a.z == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxx(a);
	TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxy(a);
	TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxz(a);
	TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxxw(a);
	TEST(a.w == b.x && a.x == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyx(a);
	TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyy(a);
	TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyz(a);
	TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxyw(a);
	TEST(a.w == b.x && a.x == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzx(a);
	TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzy(a);
	TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzz(a);
	TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxzw(a);
	TEST(a.w == b.x && a.x == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwx(a);
	TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwy(a);
	TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxwz(a);
	TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wxww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wxww(a);
	TEST(a.w == b.x && a.x == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxx(a);
	TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxy(a);
	TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxz(a);
	TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyxw(a);
	TEST(a.w == b.x && a.y == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyx(a);
	TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyy(a);
	TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyz(a);
	TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyyw(a);
	TEST(a.w == b.x && a.y == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyzx(a);
	TEST(a.w == b.x && a.y == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wywx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywx(a);
	TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wywy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywy(a);
	TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wywz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wywz(a);
	TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wyww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wyww(a);
	TEST(a.w == b.x && a.y == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxx(a);
	TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxy(a);
	TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxz(a);
	TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzxw(a);
	TEST(a.w == b.x && a.z == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyx(a);
	TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyy(a);
	TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyz(a);
	TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzyw(a);
	TEST(a.w == b.x && a.z == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzx(a);
	TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzy(a);
	TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzz(a);
	TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzzw(a);
	TEST(a.w == b.x && a.z == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwx(a);
	TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwy(a);
	TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzwz(a);
	TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wzww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wzww(a);
	TEST(a.w == b.x && a.z == b.y && a.w == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwxx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxx(a);
	TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwxy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxy(a);
	TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwxz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxz(a);
	TEST(a.w == b.x && a.w == b.y && a.x == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwxw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwxw(a);
	TEST(a.w == b.w && a.w == b.y && a.x == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwyx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyx(a);
	TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwyy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyy(a);
	TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwyz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyz(a);
	TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwyw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwyw(a);
	TEST(a.w == b.x && a.w == b.y && a.y == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwzx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzx(a);
	TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwzy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzy(a);
	TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwzz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzz(a);
	TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwzw(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwzw(a);
	TEST(a.w == b.x && a.w == b.y && a.z == b.z && a.w == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwwx(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwx(a);
	TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.x == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwwy(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwy(a);
	TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.y == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwwz(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwwz(a);
	TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.z == b.w);
}

DEFINE_UNIT_TEST("vec4 vec4_wwww(vec4 v)")
{
	const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 b = vec4_wwww(a);
	TEST(a.w == b.x && a.w == b.y && a.w == b.z && a.w == b.w);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
