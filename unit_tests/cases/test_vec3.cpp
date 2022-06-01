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

//DEFINE_UNIT_TEST("Test vec3_cos")
//{
//    const vec3 a = simd_sinf_cosf(vec3_new(1.0f, 2.0f, 3.0f));
//    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
//    TEST(c.x == 0.25f && c.y == 0.4f && c.z == 0.5f);
//}
