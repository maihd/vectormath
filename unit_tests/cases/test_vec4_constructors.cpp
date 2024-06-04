#include "../test_framework.h"


DEFINE_UNIT_TEST("vec4 constructor without parameters")
{
    const vec4 v = vec4();
    TEST(v.x == 0.0f && v.y == 0.0f && v.z == 0.0f && v.w == 0.0f);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++ 
