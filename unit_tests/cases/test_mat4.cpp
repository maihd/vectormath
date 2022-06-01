#include "../test_framework.h"

#include <type_traits>
static_assert(std::is_standard_layout<mat4>::value, "mat4 is not standard layout, cannot mempcy");

DEFINE_UNIT_TEST("mat4 translation")
{
    const vec3 position = vec3_new(1.0f, 1.0f, 1.0f);
    const mat4 translation = mat4_translation(1.0f, 1.0f, 1.0f);
    const vec3 newPosition = mat4_mul_vec3(translation, position);

    TEST(newPosition.x == 2.0f && newPosition.y == 2.0f && newPosition.z == 2.0f);
}

DEFINE_UNIT_TEST("mat4 translation 2")
{
    const vec3 position = vec3_new(1.0f, 2.0f, 3.0f);
    const mat4 translation = mat4_translation(3.0f, 2.0f, 1.0f);
    const vec3 newPosition = mat4_mul_vec3(translation, position);

    TEST(newPosition.x == 4.0f && newPosition.y == 4.0f && newPosition.z == 4.0f);
}

DEFINE_UNIT_TEST("mat4 scalation")
{
    const vec3 size = vec3_new(1.0f, 1.0f, 1.0f);
    const mat4 scalation = mat4_scalation(2.0f, 2.0f, 2.0f);
    const vec3 newSize = mat4_mul_vec3(scalation, size);

    TEST(newSize.x == 2.0f && newSize.y == 2.0f && newSize.z == 2.0f);
}

DEFINE_UNIT_TEST("mat4 scalation 2")
{
    const vec3 size = vec3_new(1.0f, 2.0f, 3.0f);
    const mat4 scalation = mat4_scalation(4.0f, 5.0f, 6.0f);
    const vec3 newSize = mat4_mul_vec3(scalation, size);

    TEST(newSize.x == 4.0f && newSize.y == 10.0f && newSize.z == 18.0f);
}

DEFINE_UNIT_TEST("mat4 ortho")
{
    const vec3 a = vec3_new(1.0f, 1.0f, 1.0f);
    const mat4 m = mat4_scalation(2.0f, 2.0f, 2.0f);
    const vec3 b = mat4_mul_vec3(m, a);

    TEST(b.x == 2.0f && b.y == 2.0f && b.z == 2.0f);
}
