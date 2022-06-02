#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec4 assigment")
{
    const vec4 a = vec4_new(0.0f, 0.0f, 0.0f, 1.0f);
    const vec4 b = a;
    TEST(a.x == b.x && a.y == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("Test vec4 operator neg")
{
    const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec4 b = -a;
    TEST(a.x == -b.x && a.y == -b.y && a.z == -b.z);
}

DEFINE_UNIT_TEST("Test vec4 operator+")
{
    const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec4 b = vec4_new(5.0f, 6.0f, 7.0f, 8.0f);
    const vec4 c = a + b;
    TEST(c.x == 6.0f && c.y == 8.0f && c.z == 10.0f && c.w == 12.0f);
}

DEFINE_UNIT_TEST("Test vec4 operator-")
{
    const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec4 b = vec4_new(5.0f, 6.0f, 7.0f, 8.0f);
    const vec4 c = a - b;
    TEST(c.x == -4.0f && c.y == -4.0f && c.z == -4.0f && c.w == -4.0f);
}

DEFINE_UNIT_TEST("Test vec4 operator*")
{
    const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec4 b = vec4_new(5.0f, 6.0f, 7.0f, 8.0f);
    const vec4 c = a * b;
    TEST(c.x == 5.0f && c.y == 12.0f && c.z == 21.0f && c.w == 32.0f);
}

DEFINE_UNIT_TEST("Test vec4 operator/")
{
    const vec4 a = vec4_new(1.0f, 2.0f, 3.0f, 4.0f);
    const vec4 b = vec4_new(5.0f, 6.0f, 7.0f, 8.0f);
    const vec4 c = a / b;
    TEST(c.x == 0.2f && c.y == 1.0f / 3.0f && c.z == 3.0f / 7.0f && c.w == 0.5f);
}

//DEFINE_UNIT_TEST("Test vec4_cos")
//{
//    const vec4 a = simd_sinf_cosf(vec4_new(1.0f, 2.0f, 3.0f, 4.0f));
//    const vec4 b = vec4_new(4.0f, 5.0f, 6.0f, 80);
//    TEST(c.x == 0.25f && c.y == 0.4f && c.z == 0.5f);
//}