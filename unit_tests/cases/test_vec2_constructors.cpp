#include "../test_framework.h"


DEFINE_UNIT_TEST("vec2 constructor without parameters")
{
    const vec2 v = vec2();
    TEST(v.x == 0.0f && v.y == 0.0f);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++ 
