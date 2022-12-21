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

DEFINE_UNIT_TEST("vec3 vec3_new(float x, float y)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = { 1.0f, 2.0f, 3.0f };
    TEST(a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 2.0f && a.z == b.z && a.z == 3.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_new1(float s)")
{
    const vec3 a = vec3_new1(1.0f);
    const vec3 b = { 1.0f, 1.0f, 1.0f };
    TEST(a.x == a.y && a.y == a.z && a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 1.0f && a.z == b.y && a.z == 1.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_from_vec2(vec2 v)")
{
    const vec2 a = { 1.0f, 2.0f };
    const vec3 b = vec3_from_vec2(a);
    TEST(a.x == b.x && a.y == b.y && b.z == 0.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_from_vec4(vec4 v)")
{
    const vec4 a = { 1.0f, 2.0f, 3.0f, 4.0f };
    const vec3 b = vec3_from_vec4(a);
    TEST(a.x == b.x && a.y == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_neg(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_neg(a);
    TEST(a.x == -b.x && a.y == -b.y && a.z == -b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_add(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_add(a, b);
    TEST(c.x == 5.0f && c.y == 7.0f && c.z == 9.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_sub(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_sub(a, b);
    TEST(c.x == -3.0f && c.y == -3.0f && c.z == -3.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_mul(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_mul(a, b);
    TEST(c.x == 4.0f && c.y == 10.0f && c.z == 18.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_div(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_div(a, b);
    TEST(c.x == 0.25f && c.y == 0.4f && c.z == 0.5f);
}

DEFINE_UNIT_TEST("vec3 vec3_add1(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const float b = 3.0f;
    const vec3  c = vec3_add1(a, b);
    TEST(c.x == 4.0f && c.y == 5.0f && c.z == 6.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_sub1(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const float b = 3.0f;
    const vec3  c = vec3_sub1(a, b);
    TEST(c.x == -2.0f && c.y == -1.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_mul1(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const float b = 3.0f;
    const vec3  c = vec3_mul1(a, b);
    TEST(c.x == 3.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_div1(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const float b = 3.0f;
    const vec3  c = vec3_div1(a, b);
    TEST(c.x == 1.0f / 3.0f && c.y == 2.0f / 3.0f && c.z == 1.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_mul_add(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_new(7.0f, 8.0f, 9.0f);
    const vec3 d = vec3_mul_add(a, b, c);
    TEST(d.x == 11.0f && d.y == 18.0f && d.z == 27.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_mul_sub(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_new(7.0f, 8.0f, 9.0f);
    const vec3 d = vec3_mul_sub(a, b, c);
    TEST(d.x == 3.0f && d.y == -2.0f && d.z == -9.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_equal(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    TEST(!vec3_equal(a, b));
}

DEFINE_UNIT_TEST("vec3 vec3_not_equal(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    TEST(vec3_not_equal(a, b));
}

DEFINE_UNIT_TEST("vec3 vec3_sign(vec3 v)")
{
    const vec3  a = vec3_new(1.0f, -1.0f, 0.0f);
    const ivec3 b = vec3_sign(a);
    TEST(b.x == 1 && b.y == -1 && b.z == 0);
}

DEFINE_UNIT_TEST("vec3 vec3_abs(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, -1.0f, 0.0f);
    const vec3 b = vec3_abs(a);
    TEST(b.x == 1.0f && b.y == 1.0f && b.z == 0.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_cos(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_cos(a);
    // This test is obviously dumb!
    TEST(float_isclose(b.x, cosf(a.x)));
    TEST(float_isclose(b.y, cosf(a.y)));
    TEST(float_isclose(b.z, cosf(a.z)));
}

DEFINE_UNIT_TEST("vec3 vec3_sin(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_sin(a);
    // This test is obviously dumb!
    TEST(b.x == sinf(a.x));
    TEST(b.y == sinf(a.y));
    TEST(b.z == sinf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_tan(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_tan(a);
    // This test is obviously dumb!
    TEST(b.x == tanf(a.x));
    TEST(b.y == tanf(a.y));
    TEST(b.z == tanf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_cosh(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_cosh(a);
    // This test is obviously dumb!
    TEST(b.x == coshf(a.x));
    TEST(b.y == coshf(a.y));
    TEST(b.z == coshf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_sinh(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_sinh(a);
    // This test is obviously dumb!
    TEST(b.x == sinhf(a.x));
    TEST(b.y == sinhf(a.y));
    TEST(b.z == sinhf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_tanh(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_tanh(a);
    // This test is obviously dumb!
    TEST(b.x == tanhf(a.x));
    TEST(b.y == tanhf(a.y));
    TEST(b.z == tanhf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_acos(vec3 v)")
{
    const vec3 a = vec3_new(-1.0f, 0.0f, 1.0f);
    const vec3 b = vec3_acos(a);
    // This test is obviously dumb!
    TEST(float_isclose(b.x, acosf(a.x)));
    TEST(float_isclose(b.y, acosf(a.y)));
    TEST(float_isclose(b.z, acosf(a.z)));
}

DEFINE_UNIT_TEST("vec3 vec3_asin(vec3 v)")
{
    const vec3 a = vec3_new(-1.0f, 0.0f, 1.0f);
    const vec3 b = vec3_asin(a);
    // This test is obviously dumb!
    TEST(float_isclose(b.x, asinf(a.x)));
    TEST(float_isclose(b.y, asinf(a.y)));
    TEST(float_isclose(b.z, asinf(a.z)));
}

DEFINE_UNIT_TEST("vec3 vec3_atan(vec3 v)")
{
    const vec3 a = vec3_new(-1.0f, 0.0f, 1.0f);
    const vec3 b = vec3_atan(a);
    // This test is obviously dumb!
    TEST(float_isclose(b.x, atanf(a.x)));
    TEST(float_isclose(b.y, atanf(a.y)));
    TEST(float_isclose(b.z, atanf(a.z)));
}

DEFINE_UNIT_TEST("vec3 vec3_exp(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_exp(a);
    // This test is obviously dumb!
    TEST(b.x == expf(a.x));
    TEST(b.y == expf(a.y));
    TEST(b.z == expf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_exp2(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_exp2(a);
    // This test is obviously dumb!
    TEST(b.x == exp2f(a.x));
    TEST(b.y == exp2f(a.y));
    TEST(b.z == exp2f(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_log(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_log(a);
    // This test is obviously dumb!
    TEST(b.x == logf(a.x));
    TEST(b.y == logf(a.y));
    TEST(b.z == logf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_log2(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_log2(a);
    // This test is obviously dumb!
    TEST(b.x == log2f(a.x));
    TEST(b.y == log2f(a.y));
    TEST(b.z == log2f(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_log10(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_log10(a);
    // This test is obviously dumb!
    TEST(b.x == log10f(a.x));
    TEST(b.y == log10f(a.y));
    TEST(b.z == log10f(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_pow(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3  b = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3  c = vec3_pow(a, b);
    // This test is obviously dumb!
    TEST(c.x == powf(a.x, b.x));
    TEST(c.y == powf(a.y, b.y));
    TEST(c.z == powf(a.z, b.z));
}

DEFINE_UNIT_TEST("vec3 vec3_frac(vec3 v)")
{
    const vec3 a = vec3_new(1.2f, 3.4f, 5.6f);
    const vec3 b = vec3_frac(a);
    // This test is obviously dumb!
    TEST(b.x == float_frac(a.x));
    TEST(b.y == float_frac(a.y));
    TEST(b.z == float_frac(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_fmod(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 c = vec3_fmod(a, b);
    // This test is obviously dumb!
    TEST(c.x == fmodf(a.x, b.x));
    TEST(c.y == fmodf(a.y, b.y));
    TEST(c.z == fmodf(a.z, b.z));
}

DEFINE_UNIT_TEST("vec3 vec3_ceil(vec3 v)")
{
    const vec3 a = vec3_new(1.2f, 3.4f, 5.6f);
    const vec3 b = vec3_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == ceilf(a.x));
    TEST(b.y == ceilf(a.y));
    TEST(b.z == ceilf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_floor(vec3 v)")
{
    const vec3 a = vec3_new(1.2f, 3.4f, 5.6f);
    const vec3 b = vec3_floor(a);
    // This test is obviously dumb!
    TEST(b.x == floorf(a.x));
    TEST(b.y == floorf(a.y));
    TEST(b.z == floorf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_round(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == roundf(a.x));
    TEST(b.y == roundf(a.y));
    TEST(b.z == roundf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_trunc(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == truncf(a.x));
    TEST(b.y == truncf(a.y));
    TEST(b.z == truncf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_min(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 c = vec3_min(a, b);
    // This test is obviously dumb!
    TEST(c.x == float_min(a.x, b.x));
    TEST(c.y == float_min(a.y, b.y));
    TEST(c.z == float_min(a.z, b.z));
}

DEFINE_UNIT_TEST("vec3 vec3_max(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 c = vec3_max(a, b);
    // This test is obviously dumb!
    TEST(c.x == float_max(a.x, b.x));
    TEST(c.y == float_max(a.y, b.y));
    TEST(c.z == float_max(a.z, b.z));
}

DEFINE_UNIT_TEST("vec3 vec3_clamp(vec3 v, vec3 min, vec3 max)")
{
    const vec3 v        = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 min      = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 max      = vec3_new(7.0f, 8.0f, 9.0f);
    const vec3 clamped  = vec3_clamp(v, min, max);
    // This test is obviously dumb!
    TEST(clamped.x == float_clamp(v.x, min.x, max.x));
    TEST(clamped.y == float_clamp(v.y, min.y, max.y));
    TEST(clamped.z == float_clamp(v.z, min.z, max.z));
}

DEFINE_UNIT_TEST("vec3 vec3_saturate(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_saturate(a);
    // This test is obviously dumb!
    TEST(b.x == float_saturate(a.x));
    TEST(b.y == float_saturate(a.y));
    TEST(b.z == float_saturate(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_lerp(vec3 a, vec3 b, vec3 t)")
{
    const vec3 a        = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b        = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 t        = vec3_new(-1.0f, 0.0f, 1.0f);
    const vec3 lerped   = vec3_lerp(a, b, t);
    // This test is obviously dumb!
    TEST(lerped.x == float_lerp(a.x, b.x, t.x));
    TEST(lerped.y == float_lerp(a.y, b.y, t.y));
    TEST(lerped.z == float_lerp(a.z, b.z, t.z));
}

DEFINE_UNIT_TEST("vec3 vec3_lerp1(vec3 a, vec3 b, float t)")
{
    const vec3  a       = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3  b       = vec3_new(4.0f, 5.0f, 6.0f);;
    const float t       = 0.5f;
    const vec3  lerped  = vec3_lerp1(a, b, t);
    // This test is obviously dumb!
    TEST(lerped.x == float_lerp(a.x, b.x, t));
    TEST(lerped.y == float_lerp(a.y, b.y, t));
    TEST(lerped.z == float_lerp(a.z, b.z, t));
}

DEFINE_UNIT_TEST("vec3 vec3_smoothstep(vec3 a, vec3 b, vec3 t)")
{
    const vec3 a        = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b        = vec3_new(4.0f, 5.0f, 6.0f);;
    const vec3 t        = vec3_new(-1.0f, 0.0f, 1.0f);
    const vec3 smoothed = vec3_smoothstep(a, b, t);
    // This test is obviously dumb!
    TEST(smoothed.x == float_smoothstep(a.x, b.x, t.x));
    TEST(smoothed.y == float_smoothstep(a.y, b.y, t.y));
    TEST(smoothed.z == float_smoothstep(a.z, b.z, t.z));
}

DEFINE_UNIT_TEST("vec3 vec3_sqrt(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_sqrt(a);
    // This test is obviously dumb!
    TEST(b.x == sqrtf(a.x));
    TEST(b.y == sqrtf(a.y));
    TEST(b.z == sqrtf(a.z));
}

DEFINE_UNIT_TEST("vec3 vec3_rsqrt(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_rsqrt(a);
    // This test is obviously dumb!
    TEST(b.x == float_rsqrt(a.x));
    TEST(b.y == float_rsqrt(a.y));
    TEST(b.z == float_rsqrt(a.z));
}

DEFINE_UNIT_TEST("float vec3_dot(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3  b = vec3_new(4.0f, 5.0f, 6.0f);
    const float c = vec3_dot(a, b);
    TEST(c == 32.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_cross(vec3 a, vec3 b)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_new(4.0f, 5.0f, 6.0f);
    const vec3 c = vec3_cross(a, b);
    TEST(c.x == -3.0f && c.y == 6.0f && c.z == -3.0f);
}

DEFINE_UNIT_TEST("float vec3_lensqr(vec3 v)")
{
    const vec3  v = vec3_new(1.0f, 2.0f, 3.0f);
    const float lensqr = vec3_lensqr(v);
    TEST(lensqr == 14.0f);
}

DEFINE_UNIT_TEST("float vec3_length(vec3 v)")
{
    const vec3  v = vec3_new(1.0f, 2.0f, 3.0f);
    const float length = vec3_length(v);
    TEST(length == sqrtf(14.0f));
}

DEFINE_UNIT_TEST("float vec3_distance(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3  b = vec3_new(4.0f, 5.0f, 6.0f);
    const float distance = vec3_distance(a, b);
    TEST(distance == sqrtf(27.0f));
}

DEFINE_UNIT_TEST("float vec3_distsqr(vec3 a, vec3 b)")
{
    const vec3  a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3  b = vec3_new(4.0f, 5.0f, 6.0f);
    const float distsqr = vec3_distsqr(a, b);
    TEST(distsqr == 27.0f);
}

DEFINE_UNIT_TEST("vec3 vec3_normalize(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_normalize(a);
    const vec3 c = vec3_new(0.0f, 0.0f, 0.0f);
    const vec3 d = vec3_normalize(c);

    TEST(float_isclose(vec3_lensqr(b), 1.0f));
    TEST(float_isclose(vec3_lensqr(c), 0.0f));
    TEST(float_isclose(vec3_lensqr(d), 0.0f));
}

DEFINE_UNIT_TEST("vec3 vec3_reflect(vec3 v, vec3 n)")
{
    // NO TEST BY NOW
}

DEFINE_UNIT_TEST("vec3 vec3_refract(vec3 v, vec3 n, float eta)")
{
    // NO TEST BY NOW
}

DEFINE_UNIT_TEST("vec3 vec3_xxx(vec3 v)")
{
    const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
    const vec3 b = vec3_xxx(a);
    TEST(a.x == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxy(a);
	TEST(a.x == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xxz(a);
	TEST(a.x == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyx(a);
	TEST(a.x == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xyy(a);
	TEST(a.x == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzx(a);
	TEST(a.x == b.x && a.z == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzy(a);
	TEST(a.x == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_xzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_xzz(a);
	TEST(a.x == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyy(a);
	TEST(a.y == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyx(a);
	TEST(a.y == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yyz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yyz(a);
	TEST(a.y == b.x && a.y == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxx(a);
	TEST(a.y == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxy(a);
	TEST(a.y == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzy(a);
	TEST(a.y == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yxz(a);
	TEST(a.y == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_yzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_yzz(a);
	TEST(a.y == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzz(a);
	TEST(a.z == b.x && a.z == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzx(a);
	TEST(a.z == b.x && a.z == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zzy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zzy(a);
	TEST(a.z == b.x && a.z == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxx(a);
	TEST(a.z == b.x && a.x == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxy(a);
	TEST(a.z == b.x && a.x == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zxz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zxz(a);
	TEST(a.z == b.x && a.x == b.y && a.z == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyx(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyx(a);
	TEST(a.z == b.x && a.y == b.y && a.x == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyy(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyy(a);
	TEST(a.z == b.x && a.y == b.y && a.y == b.z);
}

DEFINE_UNIT_TEST("vec3 vec3_zyz(vec3 v)")
{
	const vec3 a = vec3_new(1.0f, 2.0f, 3.0f);
	const vec3 b = vec3_zyz(a);
	TEST(a.z == b.x && a.y == b.y && a.z == b.z);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
