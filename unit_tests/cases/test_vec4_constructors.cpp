#include "../test_framework.h"


DEFINE_UNIT_TEST("vec4 constructor with 1 scalar")
{
    const vec4 v = vec4(1.0f);
    TEST(v.x == 1.0f && v.y == 1.0f && v.z == 1.0f && v.w == 1.0f);
}


DEFINE_UNIT_TEST("vec4 constructor with 4 scalars, component-based initialize")
{
    const vec4 v = vec4(1.0f, 2.0f, 3.0f, 4.0f);
    TEST(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f && v.w == 4.0f);
}


// DEFINE_UNIT_TEST("use vec4 constructor for vec2 cast to vec4")
// {
//     const vec2 v2 = vec2_new(3.0f, 4.0f);
//     const vec3 v3 = vec3(v2);
//     TEST(v3.x == v2.x && v3.y == v2.y);
//     TEST(v3.x == 3.0f && v3.y == 4.0f && v3.z == 0.0f);
// }


// DEFINE_UNIT_TEST("use vec4 construct for vec3 cast to vec4")
// {
//     const vec4 v4 = vec4_new(3.0f, 4.0f, 5.0f, 6.0f);
//     const vec3 v3 = vec3(v4);
//     TEST(v3.x == v4.x && v3.y == v4.y && v3.z == v4.z);
//     TEST(v3.x == 3.0f && v3.y == 4.0f && v3.z == 5.0f);
// }


DEFINE_UNIT_TEST("use vec4 construct for redundant cast of vec4 to vec4")
{
    const vec4 v4_0 = vec4_new(3.0f, 4.0f, 5.0f, 6.0f);
    const vec4 v4_1 = vec4(v4_0);
    TEST(v4_1.x == v4_0.x && v4_1.y == v4_0.y && v4_1.z == v4_0.z && v4_1.w == v4_0.w);
    TEST(v4_1.x == 3.0f && v4_1.y == 4.0f && v4_1.z == 5.0f && v4_1.w == 6.0f);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++ 
