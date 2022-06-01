#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec2")
{
    const vec2 a = vec2_new(0.0f, 0.0f);
    const vec2 b = a;
    TEST(vec2_equal(a, b));
}