#pragma once

// -------------------------------------------------------------
// Compiler configuration
// -------------------------------------------------------------

#include "vectormath/scalarmath.h"
#include "vectormath/vectormath_common.h"
#if !defined(__cplusplus)
#error Required C++ for shorthand functions
#endif

#if !defined(__clang__) && __clang__
#error Require clang for GLSL-like swizzle
#endif

#if defined(__CLANG_TGMATH_H)
#error Please avoid using tgmath.h, glslmath.h solve that for you
#endif


// -------------------------------------------------------------
// Types
// -------------------------------------------------------------

// Type of glsl and vectormath is the same

// -------------------------------------------------------------
// Begin of Functions
// -------------------------------------------------------------

#include "vectormath.h"

// -------------------------------------------------------------
// int32_t Functions
// -------------------------------------------------------------


/// Compute the sign of 'x'
__forceinline int32_t sign(int32_t x)
{
    return int32_sign(x);
}


/// Get the smaller value
__forceinline int32_t min(int32_t x, int32_t y)
{
    return int32_min(x, y);
}


/// Get the larger value
__forceinline int32_t max(int32_t x, int32_t y)
{
    return int32_max(x, y);
}


/// Clamps the 'x' to the [min, max]
__forceinline int32_t clamp(int32_t x, int32_t min, int32_t max)
{
    return int32_clamp(x, min, max);
}


// -------------------------------------------------------------
// uint32_t Functions
// -------------------------------------------------------------


/// Get the smaller value
__forceinline uint32_t min(uint32_t x, uint32_t y)
{
    return uint32_min(x, y);
}


/// Get the larger value
__forceinline uint32_t max(uint32_t x, uint32_t y)
{
    return uint32_max(x, y);
}


/// Clamps the 'x' to the [min, max]
__forceinline uint32_t clamp(uint32_t x, uint32_t min, uint32_t max)
{
    return uint32_clamp(x, min, max);
}


// -------------------------------------------------------------
// float Functions
// -------------------------------------------------------------


/// Convert degrees to radians
__forceinline float radians(float degrees)
{
    return float_deg2rad(degrees);
}


/// Convert radians to degrees
__forceinline float degrees(float radians)
{
    return float_rad2deg(radians);
}


/// Computes sign of 'x'
__forceinline int32_t sign(float x)
{
    return float_sign(x);
}


/// Computes absolute value
// __forceinline float abs(float x)
// {
//     return float_abs(x);
// }


/// Computes cosine
// __forceinline float cos(float x)
// {
//     return float_cos(x);
// }


/// Computes sine
// __forceinline float sin(float x)
// {
//     return float_sin(x);
// }


/// Computes tangent
// __forceinline float tan(float x)
// {
//     return float_tan(x);
// }


/// Computes hyperbolic cosine
// __forceinline float cosh(float x)
// {
//     return float_cosh(x);
// }


/// Computes hyperbolic sine
// __forceinline float sinh(float x)
// {
//     return float_sinh(x);
// }


/// Computes hyperbolic tangent
// __forceinline float tanh(float x)
// {
//     return float_tanh(x);
// }


/// Computes inverse cosine
// __forceinline float acos(float x)
// {
//     return float_acos(x);
// }


/// Computes inverse sine
// __forceinline float asin(float x)
// {
//     return float_asin(x);
// }


/// Computes inverse tangent
// __forceinline float atan(float x)
// {
//     return float_atan(x);
// }


/// Computes inverse tangent with 2 args
// __forceinline float atan2(float x, float y)
// {
//     return float_atan2(x, y);
// }


/// Computes Euler number raised to the power 'x'
// __forceinline float exp(float x)
// {
//     return float_exp(x);
// }


/// Computes 2 raised to the power 'x'
// __forceinline float exp2(float x)
// {
//     return float_exp2(x);
// }


/// Computes the base Euler number logarithm
// __forceinline float log(float x)
// {
//     return float_log(x);
// }


/// Computes the base 2 logarithm
// __forceinline float log2(float x)
// {
//     return float_log2(x);
// }


/// Computes the base 10 logarithm
// __forceinline float log10(float x)
// {
//     return float_log10(x);
// }


/// Computes the value of base raised to the power exponent
// __forceinline float pow(float x, float y)
// {
//     return float_pow(x, y);
// }


/// Get the fractal part of floating point
__forceinline float fract(float x)
{
    return float_frac(x);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline float mod(float x, float y)
{
    return float_fmod(x, y);
}


/// Computes the floating-point remainder of the division operation x/y
// __forceinline float modf(float x, float* y)
// {
//     return modff(x, y);
// }


/// Computes the smallest integer value not less than 'x'
// __forceinline float ceil(float x)
// {
//     return float_ceil(x);
// }


/// Computes the largest integer value not greater than 'x'
// __forceinline float floor(float x)
// {
//     return float_floor(x);
// }


/// Computes the nearest integer value
// __forceinline float round(float x)
// {
//     return float_round(x);
// }


/// Computes the nearest integer not greater in magnitude than 'x'
// __forceinline float trunc(float x)
// {
//     return float_trunc(x);
// }


/// Get the smaller value
__forceinline float min(float x, float y)
{
    return float_min(x, y);
}


/// Get the larger value
__forceinline float max(float x, float y)
{
    return float_max(x, y);
}


/// Clamps the 'x' value to the [min, max].
__forceinline float clamp(float x, float min, float max)
{
    return float_clamp(x, min, max);
}


/// Clamps the specified value within the range of 0 to 1
__forceinline float saturate(float x)
{
    return float_clamp(x, 0.0f, 1.0f);
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline float step(float y, float x)
{
    return float_step(x, y);
}


/// Performs x linear interpolation.
__forceinline float lerp(float x, float y, float s)
{
    return float_lerp(x, y, s);
}


/// Compute x smooth Hermite interpolation
/// @return: 0 if x <= min
///          1 if x >= max
///          (0, 1) otherwise
__forceinline float smoothstep(float min, float max, float x)
{
    return float_smoothstep(min, max, x);
}


/// Computes square root of 'x'.
// __forceinline float sqrt(float x)
// {
//     return float_sqrt(x);
// }


/// Computes inverse square root of 'x'.
// __forceinline float inversesqrt(float x)
// {
//     return 1.0f / sqrtf(x);
// }


/// Computes inverse square root of 'x', using FastInvSqrt algorithm.
__forceinline float inversesqrt(float x)
{
    return float_fast_rsqrt(x);
}


// -------------------------------------------------------------
// Functions
// -------------------------------------------------------------


/// Check if two vectors are closely equal
__forceinline bool isclose(vec2 a, vec2 b)
{
    return vec2_isclose(a, b);
}


/// Computes sign of 'x'
__forceinline ivec2 sign(vec2 v)
{
    return vec2_sign(v);
}


/// Computes absolute value
__forceinline vec2 abs(vec2 v)
{
    return vec2_abs(v);
}


/// Computes cosine
__forceinline vec2 cos(vec2 v)
{
    return vec2_cos(v);
}


/// Computes sine
__forceinline vec2 sin(vec2 v)
{
    return vec2_sin(v);
}


/// Computes tangent
__forceinline vec2 tan(vec2 v)
{
    return vec2_tan(v);
}


/// Computes hyperbolic cosine
__forceinline vec2 cosh(vec2 v)
{
    return vec2_cosh(v);
}


/// Computes hyperbolic sine
__forceinline vec2 sinh(vec2 v)
{
    return vec2_sinh(v);
}


/// Computes hyperbolic tangent
__forceinline vec2 tanh(vec2 v)
{
    return vec2_new(tanhf(v.x), tanhf(v.y));
}


/// Computes inverse cosine
__forceinline vec2 acos(vec2 v)
{
    return vec2_new(acosf(v.x), acosf(v.y));
}


/// Computes inverse sine
__forceinline vec2 asin(vec2 v)
{
    return vec2_new(asinf(v.x), asinf(v.y));
}


/// Computes inverse tangent
__forceinline vec2 atan(vec2 v)
{
    return vec2_new(atanf(v.x), atanf(v.y));
}


/// Computes inverse tangent with 2 args
__forceinline vec2 atan2(vec2 a, vec2 b)
{
    return vec2_new(atan2f(a.x, b.x), atan2f(a.y, b.y));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec2 exp(vec2 v)
{
    return vec2_new(expf(v.x), expf(v.y));
}


/// Computes 2 raised to the power 'x'
__forceinline vec2 exp2(vec2 v)
{
    return vec2_new(exp2f(v.x), exp2f(v.y));
}


/// Computes the base Euler number logarithm
__forceinline vec2 log(vec2 v)
{
    return vec2_new(logf(v.x), logf(v.y));
}


/// Computes the base 2 logarithm
__forceinline vec2 log2(vec2 v)
{
    return vec2_new(log2f(v.x), log2f(v.y));
}


/// Computes the base 10 logarithm
__forceinline vec2 log10(vec2 v)
{
    return vec2_new(log10f(v.x), log10f(v.y));
}


/// Computes the value of base raised to the power exponent
__forceinline vec2 pow(vec2 a, vec2 b)
{
    return vec2_new(powf(a.x, b.x), powf(a.y, b.y));
}


/// Get the fractal part of floating point
__forceinline vec2 fract(vec2 v)
{
    return vec2_new(float_frac(v.x), float_frac(v.y));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec2 mod(vec2 a, vec2 b)
{
    return vec2_new(fmodf(a.x, b.x), fmodf(a.y, b.y));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec2 ceil(vec2 v)
{
    return vec2_new(ceilf(v.x), ceilf(v.y));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec2 floor(vec2 v)
{
    return vec2_new(floorf(v.x), floorf(v.y));
}


/// Computes the nearest integer value
__forceinline vec2 round(vec2 v)
{
    return vec2_new(roundf(v.x), roundf(v.y));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec2 trunc(vec2 v)
{
    return vec2_new(truncf(v.x), truncf(v.y));
}


/// Get the smaller value
__forceinline vec2 min(vec2 a, vec2 b)
{
    return vec2_new(float_min(a.x, b.x), float_min(a.y, b.y));
}


/// Get the larger value
__forceinline vec2 max(vec2 a, vec2 b)
{
    return vec2_new(float_max(a.x, b.x), float_max(a.y, b.y));
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec2 clamp(vec2 v, vec2 min, vec2 max)
{
    return vec2_new(float_clamp(v.x, min.x, max.x), float_clamp(v.y, min.y, max.y));
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec2 saturate(vec2 v)
{
    return vec2_new(float_saturate(v.x), float_saturate(v.y));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec2 step(vec2 a, vec2 b)
{
    return vec2_new(float_step(a.x, b.x), float_step(a.y, b.y));
}


/// Performs a linear interpolation.
__forceinline vec2 lerp(vec2 a, vec2 b, vec2 t)
{
    return vec2_new(float_lerp(a.x, b.x, t.x), float_lerp(a.y, b.y, t.y));
}


/// Performs a linear interpolation.
__forceinline vec2 lerp(vec2 a, vec2 b, float t)
{
    return vec2_lerp1(a, b, t);
}


/// Compute a smooth Hermite interpolation
__forceinline vec2 smoothstep(vec2 a, vec2 b, vec2 t)
{
    return vec2_smoothstep(a, b, t);
}


/// Computes square root of 'x'.
__forceinline vec2 sqrt(vec2 v)
{
    return vec2_sqrt(v);
}


/// Computes inverse square root of 'x'.
__forceinline vec2 inversesqrt(vec2 v)
{
    return vec2_rsqrt(v);
}


/// Compute dot product of two vectors
__forceinline float dot(vec2 a, vec2 b)
{
    return vec2_dot(a, b);
}


/// Compute squared length of vector
__forceinline float lengthSqr(vec2 v)
{
    return vec2_lensqr(v);
}


/// Compute length of vector
__forceinline float length(vec2 v)
{
    return vec2_length(v);
}


/// Compute distance from 'a' to b
__forceinline float distance(vec2 a, vec2 b)
{
    return vec2_distance(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float distanceSqr(vec2 a, vec2 b)
{
    return vec2_distsqr(a, b);
}


/// Compute normalized vector
__forceinline vec2 normalize(vec2 v)
{
    return vec2_normalize(v);
}


/// Compute reflection vector
__forceinline vec2 reflect(vec2 v, vec2 n)
{
    return vec2_reflect(v, n);
}


/// Compute refraction vector
__forceinline vec2 refract(vec2 v, vec2 n, float eta)
{
    return vec2_refract(v, n, eta);
}


/// Compute faceforward vector
__forceinline vec2 faceforward(vec2 n, vec2 i, vec2 nref)
{
    return vec2_faceforward(n, i, nref);
}


/// Computes sign of 'x'
__forceinline ivec3 sign(vec3 v)
{
    ivec3 result;
    result.x = float_sign(v.x);
    result.y = float_sign(v.y);
    result.z = float_sign(v.z);
    return result;
}


/// Computes absolute value
__forceinline vec3 abs(vec3 v)
{
    return vec3_new(fabsf(v.x), fabsf(v.y), fabsf(v.z));
}


/// Computes cosine
__forceinline vec3 cos(vec3 v)
{
    return vec3_new(cosf(v.x), cosf(v.y), cosf(v.z));
}


/// Computes sine
__forceinline vec3 sin(vec3 v)
{
    return vec3_new(sinf(v.x), sinf(v.y), sinf(v.z));
}


/// Computes tangent
__forceinline vec3 tan(vec3 v)
{
    return vec3_new(tanf(v.x), tanf(v.y), tanf(v.z));
}


/// Computes hyperbolic cosine
__forceinline vec3 cosh(vec3 v)
{
    return vec3_new(coshf(v.x), coshf(v.y), coshf(v.z));
}


/// Computes hyperbolic sine
__forceinline vec3 sinh(vec3 v)
{
    return vec3_new(sinhf(v.x), sinhf(v.y), sinhf(v.z));
}


/// Computes hyperbolic tangent
__forceinline vec3 tanh(vec3 v)
{
    return vec3_new(tanhf(v.x), tanhf(v.y), tanhf(v.z));
}


/// Computes inverse cosine
__forceinline vec3 acos(vec3 v)
{
    return vec3_new(acosf(v.x), acosf(v.y), acosf(v.z));
}


/// Computes inverse sine
__forceinline vec3 asin(vec3 v)
{
    return vec3_new(asinf(v.x), asinf(v.y), asinf(v.z));
}


/// Computes inverse tangent
__forceinline vec3 atan(vec3 v)
{
    return vec3_new(atanf(v.x), atanf(v.y), atanf(v.z));
}


/// Computes inverse tangent with 2 args
__forceinline vec3 atan2(vec3 a, vec3 b)
{
    return vec3_new(atan2f(a.x, b.x), atan2f(a.y, b.y), atan2f(a.z, b.z));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec3 exp(vec3 v)
{
    return vec3_new(expf(v.x), expf(v.y), expf(v.z));
}


/// Computes 2 raised to the power 'x'
__forceinline vec3 exp2(vec3 v)
{
    return vec3_new(exp2f(v.x), exp2f(v.y), exp2f(v.z));
}


/// Computes the base Euler number logarithm
__forceinline vec3 log(vec3 v)
{
    return vec3_new(logf(v.x), logf(v.y), logf(v.z));
}


/// Computes the base 2 logarithm
__forceinline vec3 log2(vec3 v)
{
    return vec3_new(log2f(v.x), log2f(v.y), log2f(v.z));
}


/// Computes the base 10 logarithm
__forceinline vec3 log10(vec3 v)
{
    return vec3_new(log10f(v.x), log10f(v.y), log10f(v.z));
}


/// Computes the value of base raised to the power exponent
__forceinline vec3 pow(vec3 a, vec3 b)
{
    return vec3_new(powf(a.x, b.x), powf(a.y, b.y), powf(a.z, b.z));
}


/// Get the fractal part of floating point
__forceinline vec3 fract(vec3 v)
{
    return vec3_new(float_frac(v.x), float_frac(v.y), float_frac(v.z));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec3 mod(vec3 a, vec3 b)
{
    return vec3_new(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec3 ceil(vec3 v)
{
    return vec3_new(ceilf(v.x), ceilf(v.y), ceilf(v.z));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec3 floor(vec3 v)
{
    return vec3_new(floorf(v.x), floorf(v.y), floorf(v.z));
}


/// Computes the nearest integer value
__forceinline vec3 round(vec3 v)
{
    return vec3_new(roundf(v.x), roundf(v.y), roundf(v.z));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec3 trunc(vec3 v)
{
    return vec3_new(truncf(v.x), truncf(v.y), truncf(v.z));
}


/// Get the smaller value
__forceinline vec3 min(vec3 a, vec3 b)
{
    return vec3_new(float_min(a.x, b.x), float_min(a.y, b.y), float_min(a.z, b.z));
}


/// Get the larger value
__forceinline vec3 max(vec3 a, vec3 b)
{
    return vec3_new(float_max(a.x, b.x), float_max(a.y, b.y), float_max(a.z, b.z));
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec3 clamp(vec3 v, vec3 min, vec3 max)
{
    return vec3_new(float_clamp(v.x, min.x, max.x), float_clamp(v.y, min.y, max.y), float_clamp(v.z, min.z, max.z));
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec3 saturate(vec3 v)
{
    return vec3_new(float_saturate(v.x), float_saturate(v.y), float_saturate(v.z));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec3 step(vec3 a, vec3 b)
{
    return vec3_new(float_step(a.x, b.x), float_step(a.y, b.y), float_step(a.z, b.z));
}


/// Performs a linear interpolation.
__forceinline vec3 lerp(vec3 a, vec3 b, vec3 t)
{
    return vec3_new(float_lerp(a.x, b.x, t.x), float_lerp(a.y, b.y, t.y), float_lerp(a.z, b.z, t.z));
}


/// Performs a linear interpolation.
__forceinline vec3 lerp(vec3 a, vec3 b, float t)
{
    return vec3_new(float_lerp(a.x, b.x, t), float_lerp(a.y, b.y, t), float_lerp(a.z, b.z, t));
}


// Compute a smooth Hermite interpolation
__forceinline vec3 smoothstep(vec3 a, vec3 b, vec3 t)
{
    return vec3_new(float_smoothstep(a.x, b.x, t.x), float_smoothstep(a.y, b.y, t.y), float_smoothstep(a.z, b.z, t.z));
}


/// Computes square root of 'x'.
__forceinline vec3 sqrt(vec3 v)
{
    return vec3_new(sqrtf(v.x), sqrtf(v.y), sqrtf(v.z));
}


/// Computes inverse square root of 'x'.
__forceinline vec3 inversesqrt(vec3 v)
{
    return vec3_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z));
}


/// Compute cross product of two vectors
__forceinline vec3 cross(vec3 a, vec3 b)
{
    return vec3_new(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}


/// Compute dot product of two vectors
__forceinline float dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


/// Compute squared length of vector
__forceinline float lengthSqr(vec3 v)
{
    return vec3_dot(v, v);
}


/// Compute length of vector
__forceinline float length(vec3 v)
{
    return sqrtf(vec3_lensqr(v));
}


/// Compute distance from 'a' to b
__forceinline float distance(vec3 a, vec3 b)
{
    return vec3_length(vec3_sub(a, b));
}


/// Compute squared distance from 'a' to b
__forceinline float distanceSqr(vec3 a, vec3 b)
{
    return vec3_lensqr(vec3_sub(a, b));
}


/// Compute normalized vector
__forceinline vec3 normalize(vec3 v)
{
    const float lsqr = vec3_lensqr(v);
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec3_new(v.x * f, v.y * f, v.z * f);
    }
    else
    {
        return v;
    }
}


/// Compute reflection vector
__forceinline vec3 reflect(vec3 v, vec3 n)
{
    return vec3_sub(v, vec3_mul1(n, 2.0f * vec3_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec3 refract(vec3 v, vec3 n, float eta)
{
    const float k = 1.0f - eta * eta * (1.0f - vec3_dot(v, n) * vec3_dot(v, n));
    return k < 0.0f
        ? vec3_new1(0.0f)
        : vec3_sub(vec3_mul1(v, eta), vec3_mul1(n, eta * vec3_dot(v, n) + sqrtf(k)));
}


/// Compute faceforward vector
__forceinline vec3 faceforward(vec3 n, vec3 i, vec3 nref)
{
    return vec3_dot(i, nref) < 0.0f ? n : vec3_neg(n);
}


/// Computes sign of 'x'
__forceinline ivec4 sign(vec4 v)
{
    ivec4 result;
    result.x = float_sign(v.x);
    result.y = float_sign(v.y);
    result.z = float_sign(v.z);
    result.w = float_sign(v.w);
    return result;
}


/// Computes absolute value
__forceinline vec4 abs(vec4 v)
{
    return vec4_new(fabsf(v.x), fabsf(v.y), fabsf(v.z), fabsf(v.w));
}


/// Computes cosine
__forceinline vec4 cos(vec4 v)
{
    return vec4_new(cosf(v.x), cosf(v.y), cosf(v.z), cosf(v.w));
}


/// Computes sine
__forceinline vec4 sin(vec4 v)
{
    return vec4_new(sinf(v.x), sinf(v.y), sinf(v.z), sinf(v.w));
}


/// Computes tangent
__forceinline vec4 tan(vec4 v)
{
    return vec4_new(tanf(v.x), tanf(v.y), tanf(v.z), tanf(v.w));
}


/// Computes hyperbolic cosine
__forceinline vec4 cosh(vec4 v)
{
    return vec4_new(coshf(v.x), coshf(v.y), coshf(v.z), coshf(v.w));
}


/// Computes hyperbolic sine
__forceinline vec4 sinh(vec4 v)
{
    return vec4_new(sinhf(v.x), sinhf(v.y), sinhf(v.z), sinhf(v.w));
}


/// Computes hyperbolic tangent
__forceinline vec4 tanh(vec4 v)
{
    return vec4_new(tanhf(v.x), tanhf(v.y), tanhf(v.z), tanhf(v.w));
}


/// Computes inverse cosine
__forceinline vec4 acos(vec4 v)
{
    return vec4_new(acosf(v.x), acosf(v.y), acosf(v.z), acosf(v.w));
}


/// Computes inverse sine
__forceinline vec4 asin(vec4 v)
{
    return vec4_new(asinf(v.x), asinf(v.y), asinf(v.z), asinf(v.w));
}


/// Computes inverse tangent
__forceinline vec4 atan(vec4 v)
{
    return vec4_new(atanf(v.x), atanf(v.y), atanf(v.z), atanf(v.w));
}


/// Computes inverse tangent with 2 args
__forceinline vec4 atan2(vec4 a, vec4 b)
{
    return vec4_new(atan2f(a.x, b.x), atan2f(a.y, b.y), atan2f(a.z, b.z), atan2f(a.w, b.w));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec4 exp(vec4 v)
{
    return vec4_new(expf(v.x), expf(v.y), expf(v.z), expf(v.w));
}


/// Computes 2 raised to the power 'x'
__forceinline vec4 exp2(vec4 v)
{
    return vec4_new(exp2f(v.x), exp2f(v.y), exp2f(v.z), exp2f(v.w));
}


/// Computes the base Euler number logarithm
__forceinline vec4 log(vec4 v)
{
    return vec4_new(logf(v.x), logf(v.y), logf(v.z), logf(v.w));
}


/// Computes the base 2 logarithm
__forceinline vec4 log2(vec4 v)
{
    return vec4_new(log2f(v.x), log2f(v.y), log2f(v.z), log2f(v.w));
}


/// Computes the base 10 logarithm
__forceinline vec4 log10(vec4 v)
{
    return vec4_new(log10f(v.x), log10f(v.y), log10f(v.z), log10f(v.w));
}


/// Computes the value of base raised to the power exponent
__forceinline vec4 pow(vec4 a, vec4 b)
{
    return vec4_new(powf(a.x, b.x), powf(a.y, b.y), powf(a.z, b.z), powf(a.w, b.w));
}


/// Get the fractal part of floating point
__forceinline vec4 fract(vec4 v)
{
    return vec4_new(float_frac(v.x), float_frac(v.y), float_frac(v.z), float_frac(v.w));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec4 fmod(vec4 a, vec4 b)
{
    return vec4_new(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z), fmodf(a.w, b.w));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec4 ceil(vec4 v)
{
    return vec4_new(ceilf(v.x), ceilf(v.y), ceilf(v.z), ceilf(v.w));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec4 floor(vec4 v)
{
    return vec4_new(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
}


/// Computes the nearest integer value
__forceinline vec4 round(vec4 v)
{
    return vec4_new(roundf(v.x), roundf(v.y), roundf(v.z), roundf(v.w));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec4 trunc(vec4 v)
{
    return vec4_new(truncf(v.x), truncf(v.y), truncf(v.z), truncf(v.w));
}


/// Get the smaller value
__forceinline vec4 min(vec4 a, vec4 b)
{
    return vec4_new(
        float_min(a.x, b.x),
        float_min(a.y, b.y),
        float_min(a.z, b.z),
        float_min(a.w, b.w)
    );
}


/// Get the larger value
__forceinline vec4 max(vec4 a, vec4 b)
{
    return vec4_new(
        float_max(a.x, b.x), 
        float_max(a.y, b.y),
        float_max(a.z, b.z),
        float_max(a.w, b.w)
    );
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec4 clamp(vec4 v, vec4 min, vec4 max)
{
    return vec4_new(
        float_clamp(v.x, min.x, max.x), 
        float_clamp(v.y, min.y, max.y), 
        float_clamp(v.z, min.z, max.z), 
        float_clamp(v.w, min.w, max.w)
    );
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec4 saturate(vec4 v)
{
    return vec4_new(float_saturate(v.x), float_saturate(v.y), float_saturate(v.z), float_saturate(v.w));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec4 step(vec4 a, vec4 b)
{
    return vec4_new(
        float_step(a.x, b.x),
        float_step(a.y, b.y),
        float_step(a.z, b.z),
        float_step(a.w, b.w)
    );
}


/// Performs a linear interpolation.
__forceinline vec4 lerp(vec4 a, vec4 b, vec4 t)
{
    return vec4_new(
        float_lerp(a.x, b.x, t.x),
        float_lerp(a.y, b.y, t.y),
        float_lerp(a.z, b.z, t.z),
        float_lerp(a.w, b.w, t.w)
    );
}


/// Performs a linear interpolation.
__forceinline vec4 lerp(vec4 a, vec4 b, float t)
{
    return vec4_lerp1(a, b, t);
}


/// Compute a smooth Hermite interpolation
__forceinline vec4 smoothstep(vec4 a, vec4 b, vec4 t)
{
    return vec4_smoothstep(a, b, t);
}


/// Computes square root of 'x'.
__forceinline vec4 sqrt(vec4 v)
{
    return vec4_new(sqrtf(v.x), sqrtf(v.y), sqrtf(v.z), sqrtf(v.w));
}


/// Computes inverse square root of 'x'.
__forceinline vec4 inversesqrt(vec4 v)
{
    return vec4_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z), float_rsqrt(v.w));
}


/// Compute dot product of two vectors
__forceinline float dot(vec4 a, vec4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


/// Compute squared length of vector
__forceinline float lengthSqr(vec4 v)
{
    return vec4_dot(v, v);
}


/// Compute length of vector
__forceinline float length(vec4 v)
{
    return sqrtf(vec4_lensqr(v));
}


/// Compute distance from 'a' to b
__forceinline float distance(vec4 a, vec4 b)
{
    return vec4_length(vec4_sub(a, b));
}


/// Compute squared distance from 'a' to b
__forceinline float distanceSqr(vec4 a, vec4 b)
{
    return vec4_lensqr(vec4_sub(a, b));
}


/// Compute normalized vector
__forceinline vec4 normalize(vec4 v)
{
    const float lsqr = vec4_lensqr(v);
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec4_new(v.x * f, v.y * f, v.z * f, v.w * f);
    }
    else
    {
        return v;
    }
}


/// Compute reflection vector
__forceinline vec4 reflect(vec4 v, vec4 n)
{
    return vec4_sub(v, vec4_mul1(n, 2.0f * vec4_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec4 refract(vec4 v, vec4 n, float eta)
{
    const float d = vec4_dot(v, n);
    const float k = 1.0f - eta * eta * (1.0f - d * d);
    return k < 0.0f
        ? vec4_new1(0.0f)
        : vec4_sub(vec4_mul1(v, eta), vec4_mul1(n, eta * d + sqrtf(k)));
}


/// Compute faceforward vector
__forceinline vec4 faceforward(vec4 n, vec4 i, vec4 nref)
{
    return vec4_dot(i, nref) < 0.0f ? n : vec4_neg(n);
}


/// Computes absolute value
__forceinline mat4 abs(mat4 m)
{
    return mat4_new(vec4_abs(m.col0), vec4_abs(m.col1), vec4_abs(m.col2), vec4_abs(m.col3));
}


/// Computes cosine
__forceinline mat4 cos(mat4 m)
{
    return mat4_new(
        vec4_cos(m.col0),
        vec4_cos(m.col1),
        vec4_cos(m.col2),
        vec4_cos(m.col3)
    );
}


/// Computes sine
__forceinline mat4 sin(mat4 m)
{
    return mat4_new(
        vec4_sin(m.col0),
        vec4_sin(m.col1),
        vec4_sin(m.col2),
        vec4_sin(m.col3)
    );
}


/// Computes tangent
__forceinline mat4 tan(mat4 m)
{
    return mat4_new(
        vec4_tan(m.col0),
        vec4_tan(m.col1),
        vec4_tan(m.col2),
        vec4_tan(m.col3)
    );
}


/// Computes hyperbolic cosine
__forceinline mat4 cosh(mat4 m)
{
    return mat4_new(
        vec4_cosh(m.col0),
        vec4_cosh(m.col1),
        vec4_cosh(m.col2),
        vec4_cosh(m.col3)
    );
}


/// Computes hyperbolic sine
__forceinline mat4 sinh(mat4 m)
{
    return mat4_new(
        vec4_sinh(m.col0),
        vec4_sinh(m.col1),
        vec4_sinh(m.col2),
        vec4_sinh(m.col3)
    );
}


/// Computes hyperbolic tangent
__forceinline mat4 tanh(mat4 m)
{
    return mat4_new(
        vec4_tanh(m.col0),
        vec4_tanh(m.col1),
        vec4_tanh(m.col2),
        vec4_tanh(m.col3)
    );
}


/// Computes inverse cosine
__forceinline mat4 acos(mat4 m)
{
    return mat4_new(
        vec4_acos(m.col0),
        vec4_acos(m.col1),
        vec4_acos(m.col2),
        vec4_acos(m.col3)
    );
}


/// Computes inverse sine
__forceinline mat4 asin(mat4 m)
{
    return mat4_new(
        vec4_asin(m.col0),
        vec4_asin(m.col1),
        vec4_asin(m.col2),
        vec4_asin(m.col3)
    );
}


/// Computes inverse tangent
__forceinline mat4 atan(mat4 m)
{
    return mat4_new(
        vec4_atan(m.col0),
        vec4_atan(m.col1),
        vec4_atan(m.col2),
        vec4_atan(m.col3)
    );
}


/// Computes inverse tangent with 2 args
__forceinline mat4 atan2(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_atan2(a.col0, b.col0),
        vec4_atan2(a.col1, b.col1),
        vec4_atan2(a.col2, b.col2),
        vec4_atan2(a.col3, b.col3)
    );
}


/// Computes Euler number raised to the power 'x'
__forceinline mat4 exp(mat4 m)
{
    return mat4_new(
        vec4_exp(m.col0),
        vec4_exp(m.col1),
        vec4_exp(m.col2),
        vec4_exp(m.col3)
    );
}


/// Computes 2 raised to the power 'x'
__forceinline mat4 exp2(mat4 m)
{
    return mat4_new(
        vec4_exp2(m.col0),
        vec4_exp2(m.col1),
        vec4_exp2(m.col2),
        vec4_exp2(m.col3)
    );
}


/// Computes the base Euler number logarithm
__forceinline mat4 log(mat4 m)
{
    return mat4_new(
        vec4_log(m.col0),
        vec4_log(m.col1),
        vec4_log(m.col2),
        vec4_log(m.col3)
    );
}


/// Computes the base 2 logarithm
__forceinline mat4 log2(mat4 m)
{
    return mat4_new(
        vec4_log2(m.col0),
        vec4_log2(m.col1),
        vec4_log2(m.col2),
        vec4_log2(m.col3)
    );
}


/// Computes the base 10 logarithm
__forceinline mat4 log10(mat4 m)
{
    return mat4_new(
        vec4_log10(m.col0),
        vec4_log10(m.col1),
        vec4_log10(m.col2),
        vec4_log10(m.col3)
    );
}


/// Computes the value of base raised to the power exponent
__forceinline mat4 pow(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_pow(a.col0, b.col0),
        vec4_pow(a.col1, b.col1),
        vec4_pow(a.col2, b.col2),
        vec4_pow(a.col3, b.col3)
    );
}


/// Get the fractal part of floating point
__forceinline mat4 fract(mat4 m)
{
    return mat4_new(
        vec4_frac(m.col0),
        vec4_frac(m.col1),
        vec4_frac(m.col2),
        vec4_frac(m.col3)
    );
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline mat4 fmod(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_fmod(a.col0, b.col0),
        vec4_fmod(a.col1, b.col1),
        vec4_fmod(a.col2, b.col2),
        vec4_fmod(a.col3, b.col3)
    );
}


/// Computes the smallest integer value not less than 'x'
__forceinline mat4 ceil(mat4 m)
{
    return mat4_new(
        vec4_ceil(m.col0),
        vec4_ceil(m.col1),
        vec4_ceil(m.col2),
        vec4_ceil(m.col3)
    );
}


/// Computes the largest integer value not greater than 'x'
__forceinline mat4 floor(mat4 m)
{
    return mat4_new(
        vec4_floor(m.col0),
        vec4_floor(m.col1),
        vec4_floor(m.col2),
        vec4_floor(m.col3)
    );
}


/// Computes the nearest integer value
__forceinline mat4 round(mat4 m)
{
    return mat4_new(
        vec4_round(m.col0),
        vec4_round(m.col1),
        vec4_round(m.col2),
        vec4_round(m.col3)
    );
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline mat4 trunc(mat4 m)
{
    return mat4_new(
        vec4_trunc(m.col0),
        vec4_trunc(m.col1),
        vec4_trunc(m.col2),
        vec4_trunc(m.col3)
    );
}


/// Get the smaller value
__forceinline mat4 min(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_min(a.col0, b.col0),
        vec4_min(a.col1, b.col1),
        vec4_min(a.col2, b.col2),
        vec4_min(a.col3, b.col3)
    );
}


/// Get the larger value
__forceinline mat4 max(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_max(a.col0, b.col0),
        vec4_max(a.col1, b.col1),
        vec4_max(a.col2, b.col2),
        vec4_max(a.col3, b.col3)
    );
}


/// Clamps the 'x' value to the [min, max].
__forceinline mat4 clamp(mat4 v, mat4 min, mat4 max)
{
    return mat4_new(
        vec4_clamp(v.col0, min.col0, max.col0),
        vec4_clamp(v.col1, min.col1, max.col1),
        vec4_clamp(v.col2, min.col2, max.col2),
        vec4_clamp(v.col3, min.col3, max.col3)
    );
}


/// Clamps the specified value within the range of 0 to 1
__forceinline mat4 saturate(mat4 m)
{
    return mat4_new(
        vec4_saturate(m.col0),
        vec4_saturate(m.col1),
        vec4_saturate(m.col2),
        vec4_saturate(m.col3)
    );
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline mat4 step(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_step(a.col0, b.col0),
        vec4_step(a.col1, b.col1),
        vec4_step(a.col2, b.col2),
        vec4_step(a.col3, b.col3)
    );
}


/// Performs a linear interpolation.
__forceinline mat4 lerp(mat4 a, mat4 b, mat4 t)
{
    return mat4_new(
        vec4_lerp(a.col0, b.col0, t.col0),
        vec4_lerp(a.col1, b.col1, t.col1),
        vec4_lerp(a.col2, b.col2, t.col2),
        vec4_lerp(a.col3, b.col3, t.col3)
    );
}


/// Performs a linear interpolation.
__forceinline mat4 lerp(mat4 a, mat4 b, float t)
{
    return mat4_new(
        vec4_lerp(a.col0, b.col0, vec4_new1(t)),
        vec4_lerp(a.col1, b.col1, vec4_new1(t)),
        vec4_lerp(a.col2, b.col2, vec4_new1(t)),
        vec4_lerp(a.col3, b.col3, vec4_new1(t))
    );
}


/// Compute a smooth Hermite interpolation
__forceinline mat4 smoothstep(mat4 a, mat4 b, mat4 t)
{
    return mat4_new(
        vec4_smoothstep(a.col0, b.col0, t.col0),
        vec4_smoothstep(a.col1, b.col1, t.col1),
        vec4_smoothstep(a.col2, b.col2, t.col2),
        vec4_smoothstep(a.col3, b.col3, t.col3)
    );
}


/// Computes square root of 'x'.
__forceinline mat4 sqrt(mat4 m)
{
    return mat4_new(vec4_sqrt(m.col0), vec4_sqrt(m.col1), vec4_sqrt(m.col2), vec4_sqrt(m.col3));
}


/// Computes inverse square root of 'x'.
__forceinline mat4 inversesqrt(mat4 m)
{
    return mat4_new(vec4_rsqrt(m.col0), vec4_rsqrt(m.col1), vec4_rsqrt(m.col2), vec4_rsqrt(m.col3));
}


//! EOF
