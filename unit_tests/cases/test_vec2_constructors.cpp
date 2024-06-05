#include "../test_framework.h"


DEFINE_UNIT_TEST("vec2 constructor without parameters")
{
    const vec2 v = vec2();
    TEST(v.x == 0.0f && v.y == 0.0f);
}


DEFINE_UNIT_TEST("vec2 constructor with 1 scalar")
{
    const vec2 v = vec2(1.0f);
    TEST(v.x == 1.0f && v.y == 1.0f);
}


DEFINE_UNIT_TEST("vec2 constructor with 2 scalars, component-based initialize")
{
    const vec2 v = vec2(1.0f, 2.0f);
    TEST(v.x == 1.0f && v.y == 2.0f);
}


DEFINE_UNIT_TEST("use vec2 constructor for vec3 cast to vec2")
{
    const vec3 v3 = vec3_new(3.0f, 4.0f, 5.0f);
    const vec2 v2 = vec2(v3);
    TEST(v2.x == v3.x && v2.y == v3.y);
    TEST(v2.x == 3.0f && v2.y == 4.0f);
}


DEFINE_UNIT_TEST("use vec2 construct for vec4 cast to vec2")
{
    const vec4 v4 = vec4_new(3.0f, 4.0f, 5.0f, 6.0f);
    const vec2 v2 = vec2(v4);
    TEST(v2.x == v4.x && v2.y == v4.y);
    TEST(v2.x == 3.0f && v2.y == 4.0f);
}


DEFINE_UNIT_TEST("use vec2 construct for redundant cast of vec2 to vec2")
{
    const vec2 v2_0 = vec2_new(3.0f, 4.0f);
    const vec2 v2_1 = vec2(v2_0);
    TEST(v2_1.x == v2_0.x && v2_1.y == v2_0.y);
    TEST(v2_1.x == 3.0f && v2_1.y == 4.0f);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++ 
