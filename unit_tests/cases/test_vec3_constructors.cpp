#include "../test_framework.h"


DEFINE_UNIT_TEST("vec3 constructor without parameters")
{
    const vec3 v = vec3();
    TEST(v.x == 0.0f && v.y == 0.0f && v.z == 0.0f);
}


DEFINE_UNIT_TEST("vec3 constructor with 1 scalar")
{
    const vec3 v = vec3(1.0f);
    TEST(v.x == 1.0f && v.y == 1.0f && v.z == 1.0f);
}


DEFINE_UNIT_TEST("vec3 constructor with 3 scalars, component-based initialize")
{
    const vec3 v = vec3(1.0f, 2.0f, 3.0f);
    TEST(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f);
}


DEFINE_UNIT_TEST("use vec3 constructor for vec2 cast to vec3")
{
    const vec2 v2 = vec2_new(3.0f, 4.0f);
    const vec3 v3 = vec3(v2);
    TEST(v3.x == v2.x && v3.y == v2.y);
    TEST(v3.x == 3.0f && v3.y == 4.0f && v3.z == 0.0f);
}


DEFINE_UNIT_TEST("use vec3 construct for vec4 cast to vec3")
{
    const vec4 v4 = vec4_new(3.0f, 4.0f, 5.0f, 6.0f);
    const vec3 v3 = vec3(v4);
    TEST(v3.x == v4.x && v3.y == v4.y && v3.z == v4.z);
    TEST(v3.x == 3.0f && v3.y == 4.0f && v3.z == 5.0f);
}


DEFINE_UNIT_TEST("use vec3 construct for redundant cast of vec3 to vec3")
{
    const vec3 v3_0 = vec3_new(3.0f, 4.0f, 5.0f);
    const vec3 v3_1 = vec3(v3_0);
    TEST(v3_1.x == v3_0.x && v3_1.y == v3_0.y && v3_1.z == v3_0.z);
    TEST(v3_1.x == 3.0f && v3_1.y == 4.0f && v3_1.z == 5.0f);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++ 
