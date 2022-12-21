#include "../test_framework.h"

DEFINE_UNIT_TEST("Test vec2 assigment")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = a;
    TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = -a;
    TEST(a.x == -b.x && a.y == -b.y);
}

DEFINE_UNIT_TEST("vec2 operator+(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a + b;
    TEST(c.x == 4.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 6.0f);
    const vec2 c = a - b;
    TEST(c.x == -2.0f && c.y == -4.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a * b;
    TEST(c.x == 3.0f && c.y == 8.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 0.5f);
}

DEFINE_UNIT_TEST("vec2 operator+(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a + b;
    TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a - b;
    TEST(c.x == -2.0f && c.y == -1.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a * b;
    TEST(c.x == 3.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(vec2 a, float b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const float b = 3.0f;
    const vec2  c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 2.0f / 3.0f);
}

DEFINE_UNIT_TEST("vec2 operator+(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a + b;
    TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 operator-(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a - b;
    TEST(c.x == -2.0f && c.y == -3.0f);
}

DEFINE_UNIT_TEST("vec2 operator*(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a * b;
    TEST(c.x == 3.0f && c.y == 4.0f);
}

DEFINE_UNIT_TEST("vec2 operator/(float a, vec2 b)")
{
    const float a = 1.0f;
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = a / b;
    TEST(c.x == 1.0f / 3.0f && c.y == 0.25f);
}

DEFINE_UNIT_TEST("vec2 vec2_new(float x, float y)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = { 1.0f, 2.0f };
    TEST(a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_new1(float s)")
{
    const vec2 a = vec2_new1(1.0f);
    const vec2 b = { 1.0f, 1.0f };
    TEST(a.x == a.y && a.x == b.x && a.x == 1.0f && a.y == b.y && a.y == 1.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_from_vec3(vec3 v)")
{
	const vec3 a = { 1.0f, 2.0f, 3.0f };
	const vec2 b = vec2_from_vec3(a);
	TEST(a.x == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2 vec2_neg(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_neg(a);
	TEST(a.x == -b.x && a.y == -b.y);
}

DEFINE_UNIT_TEST("vec2 vec2_add(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_add(a, b);
	TEST(c.x == 4.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_sub(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_sub(a, b);
	TEST(c.x == -2.0f && c.y == -2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_mul(a, b);
	TEST(c.x == 3.0f && c.y == 8.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_div(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
	const vec2 c = vec2_div(a, b);
	TEST(c.x == 1.0f / 3.0f && c.y == 0.5f);
}

DEFINE_UNIT_TEST("vec2 vec2_add1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_add1(a, b);
	TEST(c.x == 4.0f && c.y == 5.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_sub1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_sub1(a, b);
	TEST(c.x == -2.0f && c.y == -1.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_mul1(a, b);
	TEST(c.x == 3.0f && c.y == 6.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_div1(vec2 a, vec2 b)")
{
	const vec2  a = vec2_new(1.0f, 2.0f);
	const float b = 3.0f;
	const vec2  c = vec2_div1(a, b);
	TEST(c.x == 1.0f / 3.0f && c.y == 2.0f / 3.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul_add(vec2 a, vec2 b)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_new(5.0f, 6.0f);
    const vec2 d = vec2_mul_add(a, b, c);
	TEST(d.x == 8.0f && d.y == 14.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_mul_sub(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_new(5.0f, 6.0f);
    const vec2 d = vec2_mul_sub(a, b, c);
    TEST(d.x == 2.0f && d.y == -2.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_equal(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    TEST(!vec2_equal(a, b));
}

DEFINE_UNIT_TEST("vec2 vec2_not_equal(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    TEST(vec2_not_equal(a, b));
}

DEFINE_UNIT_TEST("vec2 vec2_sign(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, -1.0f);
    const ivec2 b = vec2_sign(a);
    TEST(b.x == 1 && b.y == -1);
}

DEFINE_UNIT_TEST("vec2 vec2_abs(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, -1.0f);
    const vec2 b = vec2_abs(a);
    TEST(b.x == 1.0f && b.y == 1.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_cos(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_cos(a);
    // This test is obviously dumb!
    TEST(b.x == cosf(a.x) && b.y == cosf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_sin(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_sin(a);
    // This test is obviously dumb!
    TEST(b.x == sinf(a.x) && b.y == sinf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_tan(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_tan(a);
    // This test is obviously dumb!
    TEST(b.x == tanf(a.x) && b.y == tanf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_cosh(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_cosh(a);
    // This test is obviously dumb!
    TEST(b.x == coshf(a.x) && b.y == coshf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_sinh(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_sinh(a);
    // This test is obviously dumb!
    TEST(b.x == sinhf(a.x) && b.y == sinhf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_tanh(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_tanh(a);
    // This test is obviously dumb!
    TEST(b.x == tanhf(a.x) && b.y == tanhf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_acos(vec2 v)")
{
    const vec2 a = vec2_new(0.0f, 1.0f);
    const vec2 b = vec2_acos(a);
    // This test is obviously dumb!
    TEST(b.x == acosf(a.x) && b.y == acosf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_asin(vec2 v)")
{
    const vec2 a = vec2_new(0.0f, 1.0f);
    const vec2 b = vec2_asin(a);
    // This test is obviously dumb!
    TEST(b.x == asinf(a.x) && b.y == asinf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_atan(vec2 v)")
{
    const vec2 a = vec2_new(0.0f, 1.0f);
    const vec2 b = vec2_atan(a);
    // This test is obviously dumb!
    TEST(b.x == atanf(a.x) && b.y == atanf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_exp(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_exp(a);
    // This test is obviously dumb!
    TEST(b.x == expf(a.x) && b.y == expf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_exp2(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_exp2(a);
    // This test is obviously dumb!
    TEST(b.x == exp2f(a.x) && b.y == exp2f(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_log(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_log(a);
    // This test is obviously dumb!
    TEST(b.x == logf(a.x) && b.y == logf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_log2(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_log2(a);
    // This test is obviously dumb!
    TEST(b.x == log2f(a.x) && b.y == log2f(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_log10(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_log10(a);
    // This test is obviously dumb!
    TEST(b.x == log10f(a.x) && b.y == log10f(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_pow(vec2 a, vec2 b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const vec2  b = vec2_new(3.0f, 4.0f);
    const vec2  c = vec2_pow(a, b);
    // This test is obviously dumb!
    TEST(c.x == powf(a.x, b.x) && c.y == powf(a.y, b.y));
}

DEFINE_UNIT_TEST("vec2 vec2_frac(vec2 v)")
{
    const vec2 a = vec2_new(1.2f, 3.4f);
    const vec2 b = vec2_frac(a);
    // This test is obviously dumb!
    TEST(b.x == float_frac(a.x) && b.y == float_frac(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_fmod(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_fmod(a, b);
    // This test is obviously dumb!
    TEST(c.x == fmodf(a.x, b.x) && c.y == fmodf(a.y, b.y));
}

DEFINE_UNIT_TEST("vec2 vec2_ceil(vec2 v)")
{
    const vec2 a = vec2_new(1.2f, 3.4f);
    const vec2 b = vec2_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == ceilf(a.x) && b.y == ceilf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_floor(vec2 v)")
{
    const vec2 a = vec2_new(1.2f, 3.4f);
    const vec2 b = vec2_floor(a);
    // This test is obviously dumb!
    TEST(b.x == floorf(a.x) && b.y == floorf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_round(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == roundf(a.x) && b.y == roundf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_trunc(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_ceil(a);
    // This test is obviously dumb!
    TEST(b.x == truncf(a.x) && b.y == truncf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_min(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_min(a, b);
    // This test is obviously dumb!
    TEST(c.x == float_min(a.x, b.x) && c.y == float_min(a.y, b.y));
}

DEFINE_UNIT_TEST("vec2 vec2_max(vec2 a, vec2 b)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_new(3.0f, 4.0f);
    const vec2 c = vec2_max(a, b);
    // This test is obviously dumb!
    TEST(c.x == float_max(a.x, b.x) && c.y == float_max(a.y, b.y));
}

DEFINE_UNIT_TEST("vec2 vec2_clamp(vec2 v, vec2 min, vec2 max)")
{
    const vec2 v        = vec2_new(1.0f, 2.0f);
    const vec2 min      = vec2_new(3.0f, 4.0f);
    const vec2 max      = vec2_new(5.0f, 6.0f);
    const vec2 clamped  = vec2_clamp(v, min, max);
    // This test is obviously dumb!
    TEST(clamped.x == float_clamp(v.x, min.x, max.x));
    TEST(clamped.y == float_clamp(v.y, min.y, max.y));
}

DEFINE_UNIT_TEST("vec2 vec2_saturate(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_saturate(a);
    // This test is obviously dumb!
    TEST(b.x == float_saturate(a.x) && b.y == float_saturate(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_lerp(vec2 a, vec2 b, vec2 t)")
{
    const vec2 a        = vec2_new(1.0f, 2.0f);
    const vec2 b        = vec2_new(3.0f, 4.0f);
    const vec2 t        = vec2_new(0.0f, 1.0f);
    const vec2 lerped   = vec2_lerp(a, b, t);
    // This test is obviously dumb!
    TEST(lerped.x == float_lerp(a.x, b.x, t.x));
    TEST(lerped.y == float_lerp(a.y, b.y, t.y));
}

DEFINE_UNIT_TEST("vec2 vec2_lerp1(vec2 a, vec2 b, float t)")
{
    const vec2  a       = vec2_new(1.0f, 2.0f);
    const vec2  b       = vec2_new(3.0f, 4.0f);
    const float t       = 0.5f;
    const vec2  lerped  = vec2_lerp1(a, b, t);
    // This test is obviously dumb!
    TEST(lerped.x == float_lerp(a.x, b.x, t));
    TEST(lerped.y == float_lerp(a.y, b.y, t));
}

DEFINE_UNIT_TEST("vec2 vec2_smoothstep(vec2 a, vec2 b, vec2 t)")
{
    const vec2 a        = vec2_new(1.0f, 2.0f);
    const vec2 b        = vec2_new(3.0f, 4.0f);
    const vec2 t        = vec2_new(0.0f, 1.0f);
    const vec2 smoothed = vec2_smoothstep(a, b, t);
    // This test is obviously dumb!
    TEST(smoothed.x == float_smoothstep(a.x, b.x, t.x));
    TEST(smoothed.y == float_smoothstep(a.y, b.y, t.y));
}

DEFINE_UNIT_TEST("vec2 vec2_sqrt(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_sqrt(a);
    // This test is obviously dumb!
    TEST(b.x == sqrtf(a.x) && b.y == sqrtf(a.y));
}

DEFINE_UNIT_TEST("vec2 vec2_rsqrt(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_rsqrt(a);
    // This test is obviously dumb!
    TEST(b.x == float_rsqrt(a.x) && b.y == float_rsqrt(a.y));
}

DEFINE_UNIT_TEST("float vec2_dot(vec2 a, vec2 b)")
{
    const vec2  a = vec2_new(1.0f, 2.0f);
    const vec2  b = vec2_new(3.0f, 4.0f);
    const float c = vec2_dot(a, b);
    TEST(c == 11.0f);
}

DEFINE_UNIT_TEST("float vec2_lensqr(vec2 v)")
{
    const vec2  v       = vec2_new(1.0f, 2.0f);
    const float lensqr  = vec2_lensqr(v);
    TEST(lensqr == 5.0f);
}

DEFINE_UNIT_TEST("float vec2_length(vec2 v)")
{
    const vec2  v       = vec2_new(1.0f, 2.0f);
    const float length  = vec2_length(v);
    TEST(length == sqrtf(5.0f));
}

DEFINE_UNIT_TEST("float vec2_distance(vec2 a, vec2 b)")
{
    const vec2  a           = vec2_new(1.0f, 2.0f);
    const vec2  b           = vec2_new(3.0f, 4.0f);
    const float distance    = vec2_distance(a, b);
    TEST(distance == sqrtf(8.0f));
}

DEFINE_UNIT_TEST("float vec2_distsqr(vec2 a, vec2 b)")
{
    const vec2  a           = vec2_new(1.0f, 2.0f);
    const vec2  b           = vec2_new(3.0f, 4.0f);
    const float distsqr     = vec2_distsqr(a, b);
    TEST(distsqr == 8.0f);
}

DEFINE_UNIT_TEST("vec2 vec2_normalize(vec2 v)")
{
    const vec2 a = vec2_new(1.0f, 2.0f);
    const vec2 b = vec2_normalize(a);
    const vec2 c = vec2_new(0.0f, 0.0f);
    const vec2 d = vec2_normalize(c);

    TEST(float_isclose(vec2_lensqr(b), 1.0f));
    TEST(float_isclose(vec2_lensqr(c), 0.0f));
    TEST(float_isclose(vec2_lensqr(d), 0.0f));
}

DEFINE_UNIT_TEST("vec2 vec2_reflect(vec2 v, vec2 n)")
{
    // NO TEST BY NOW
}

DEFINE_UNIT_TEST("vec2 vec2_refract(vec2 v, vec2 n, float eta)")
{
    // NO TEST BY NOW
}

DEFINE_UNIT_TEST("vec2_xx(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_xx(a);
	TEST(a.x == b.x && a.x == b.y);
}

DEFINE_UNIT_TEST("vec2_yy(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yy(a);
	TEST(a.y == b.x && a.y == b.y);
}

DEFINE_UNIT_TEST("vec2_yz(vec2 v)")
{
	const vec2 a = vec2_new(1.0f, 2.0f);
	const vec2 b = vec2_yx(a);
	TEST(a.x == b.y && a.y == b.x);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
