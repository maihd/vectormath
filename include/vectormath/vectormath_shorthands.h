#pragma once

#if !defined(__cplusplus)
#error Required C++ for shorthand functions
#endif

#ifdef _WIN32
#undef min      // When Windows.h was included, `min` is an macro
#undef max      // When Windows.h was included, `max` is an macro
#undef far      // When Windows.h was included, `far` is an macro
#undef near     // When Windows.h was included, `near` is an macro
#endif


// -------------------------------------------------------------
// Types
// -------------------------------------------------------------

// Type of glsl and vectormath is the same

// -------------------------------------------------------------
// Begin of Functions
// -------------------------------------------------------------

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
    return vec3_sign(v);
}


/// Computes absolute value
__forceinline vec3 abs(vec3 v)
{
    return vec3_abs(v);
}


/// Computes cosine
__forceinline vec3 cos(vec3 v)
{
    return vec3_cos(v);
}


/// Computes sine
__forceinline vec3 sin(vec3 v)
{
    return vec3_sin(v);
}


/// Computes tangent
__forceinline vec3 tan(vec3 v)
{
    return vec3_tan(v);
}


/// Computes hyperbolic cosine
__forceinline vec3 cosh(vec3 v)
{
    return vec3_cosh(v);
}


/// Computes hyperbolic sine
__forceinline vec3 sinh(vec3 v)
{
    return vec3_sinh(v);
}


/// Computes hyperbolic tangent
__forceinline vec3 tanh(vec3 v)
{
    return vec3_tanh(v);
}


/// Computes inverse cosine
__forceinline vec3 acos(vec3 v)
{
    return vec3_acos(v);
}


/// Computes inverse sine
__forceinline vec3 asin(vec3 v)
{
    return vec3_asin(v);
}


/// Computes inverse tangent
__forceinline vec3 atan(vec3 v)
{
    return vec3_atan(v);
}


/// Computes inverse tangent with 2 args
__forceinline vec3 atan2(vec3 a, vec3 b)
{
    return vec3_atan2(a, b);
}


/// Computes Euler number raised to the power 'x'
__forceinline vec3 exp(vec3 v)
{
    return vec3_exp(v);
}


/// Computes 2 raised to the power 'x'
__forceinline vec3 exp2(vec3 v)
{
    return vec3_exp2(v);
}


/// Computes the base Euler number logarithm
__forceinline vec3 log(vec3 v)
{
    return vec3_log(v);
}


/// Computes the base 2 logarithm
__forceinline vec3 log2(vec3 v)
{
    return vec3_log2(v);
}


/// Computes the base 10 logarithm
__forceinline vec3 log10(vec3 v)
{
    return vec3_log10(v);
}


/// Computes the value of base raised to the power exponent
__forceinline vec3 pow(vec3 a, vec3 b)
{
    return vec3_pow(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec3 ceil(vec3 v)
{
    return vec3_ceil(v);
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec3 floor(vec3 v)
{
    return vec3_floor(v);
}


/// Computes the nearest integer value
__forceinline vec3 round(vec3 v)
{
    return vec3_round(v);
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec3 trunc(vec3 v)
{
    return vec3_trunc(v);
}


/// Get the smaller value
__forceinline vec3 min(vec3 a, vec3 b)
{
    return vec3_min(a, b);
}


/// Get the larger value
__forceinline vec3 max(vec3 a, vec3 b)
{
    return vec3_max(a, b);
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec3 clamp(vec3 v, vec3 min, vec3 max)
{
    return vec3_clamp(v, min, max);
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec3 saturate(vec3 v)
{
    return vec3_saturate(v);
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec3 step(vec3 a, vec3 b)
{
    return vec3_step(a, b);
}


/// Performs a linear interpolation.
__forceinline vec3 lerp(vec3 a, vec3 b, vec3 t)
{
    return vec3_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline vec3 lerp(vec3 a, vec3 b, float t)
{
    return vec3_lerp1(a, b, t);
}


// Compute a smooth Hermite interpolation
__forceinline vec3 smoothstep(vec3 a, vec3 b, vec3 t)
{
    return vec3_smoothstep(a, b, t);
}


/// Computes square root of 'x'.
__forceinline vec3 sqrt(vec3 v)
{
    return vec3_sqrt(v);
}


/// Compute cross product of two vectors
__forceinline vec3 cross(vec3 a, vec3 b)
{
    return vec3_cross(a, b);
}


/// Compute dot product of two vectors
__forceinline float dot(vec3 a, vec3 b)
{
    return vec3_dot(a, b);
}


/// Compute squared length of vector
__forceinline float lengthSqr(vec3 v)
{
    return vec3_lensqr(v);
}


/// Compute length of vector
__forceinline float length(vec3 v)
{
    return vec3_length(v);
}


/// Compute distance from 'a' to b
__forceinline float distance(vec3 a, vec3 b)
{
    return vec3_distance(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float distanceSqr(vec3 a, vec3 b)
{
    return vec3_distsqr(a, b);
}


/// Compute normalized vector
__forceinline vec3 normalize(vec3 v)
{
    return vec3_normalize(v);
}


/// Compute reflection vector
__forceinline vec3 reflect(vec3 v, vec3 n)
{
    return vec3_reflect(v, n);
}


/// Compute refraction vector
__forceinline vec3 refract(vec3 v, vec3 n, float eta)
{
    return vec3_refract(v, n, eta);
}


/// Compute faceforward vector
__forceinline vec3 faceforward(vec3 n, vec3 i, vec3 nref)
{
    return vec3_faceforward(n, i, nref);
}


/// Computes sign of 'x'
__forceinline ivec4 sign(vec4 v)
{
    return vec4_sign(v);
}


/// Computes absolute value
__forceinline vec4 abs(vec4 v)
{
    return vec4_abs(v);
}


/// Computes cosine
__forceinline vec4 cos(vec4 v)
{
    return vec4_cos(v);
}


/// Computes sine
__forceinline vec4 sin(vec4 v)
{
    return vec4_sin(v);
}


/// Computes tangent
__forceinline vec4 tan(vec4 v)
{
    return vec4_tan(v);
}


/// Computes hyperbolic cosine
__forceinline vec4 cosh(vec4 v)
{
    return vec4_cosh(v);
}


/// Computes hyperbolic sine
__forceinline vec4 sinh(vec4 v)
{
    return vec4_sinh(v);
}


/// Computes hyperbolic tangent
__forceinline vec4 tanh(vec4 v)
{
    return vec4_tanh(v);
}


/// Computes inverse cosine
__forceinline vec4 acos(vec4 v)
{
    return vec4_acos(v);
}


/// Computes inverse sine
__forceinline vec4 asin(vec4 v)
{
    return vec4_asin(v);
}


/// Computes inverse tangent
__forceinline vec4 atan(vec4 v)
{
    return vec4_atan(v);
}


/// Computes inverse tangent with 2 args
__forceinline vec4 atan2(vec4 a, vec4 b)
{
    return vec4_atan2(a, b);
}


/// Computes Euler number raised to the power 'x'
__forceinline vec4 exp(vec4 v)
{
    return vec4_exp(v);
}


/// Computes 2 raised to the power 'x'
__forceinline vec4 exp2(vec4 v)
{
    return vec4_exp2(v);
}


/// Computes the base Euler number logarithm
__forceinline vec4 log(vec4 v)
{
    return vec4_log(v);
}


/// Computes the base 2 logarithm
__forceinline vec4 log2(vec4 v)
{
    return vec4_log2(v);
}


/// Computes the base 10 logarithm
__forceinline vec4 log10(vec4 v)
{
    return vec4_log10(v);
}


/// Computes the value of base raised to the power exponent
__forceinline vec4 pow(vec4 a, vec4 b)
{
    return vec4_pow(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec4 ceil(vec4 v)
{
    return vec4_ceil(v);
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec4 floor(vec4 v)
{
    return vec4_floor(v);
}


/// Computes the nearest integer value
__forceinline vec4 round(vec4 v)
{
    return vec4_round(v);
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec4 trunc(vec4 v)
{
    return vec4_trunc(v);
}


/// Get the smaller value
__forceinline vec4 min(vec4 a, vec4 b)
{
    return vec4_min(a, b);
}


/// Get the larger value
__forceinline vec4 max(vec4 a, vec4 b)
{
    return vec4_max(a, b);
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec4 clamp(vec4 v, vec4 min, vec4 max)
{
    return vec4_clamp(v, min, max);
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec4 saturate(vec4 v)
{
    return vec4_saturate(v);
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec4 step(vec4 a, vec4 b)
{
    return vec4_step(a, b);
}


/// Performs a linear interpolation.
__forceinline vec4 lerp(vec4 a, vec4 b, vec4 t)
{
    return vec4_lerp(a, b, t);
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
    return vec4_sqrt(v);
}


/// Compute dot product of two vectors
__forceinline float dot(vec4 a, vec4 b)
{
    return vec4_dot(a, b);
}


/// Compute squared length of vector
__forceinline float lengthSqr(vec4 v)
{
    return vec4_lensqr(v);
}


/// Compute length of vector
__forceinline float length(vec4 v)
{
    return vec4_length(v);
}


/// Compute distance from 'a' to b
__forceinline float distance(vec4 a, vec4 b)
{
    return vec4_distance(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float distanceSqr(vec4 a, vec4 b)
{
    return vec4_distsqr(a, b);
}


/// Compute normalized vector
__forceinline vec4 normalize(vec4 v)
{
    return vec4_normalize(v);
}


/// Compute reflection vector
__forceinline vec4 reflect(vec4 v, vec4 n)
{
    return vec4_reflect(v, n);
}


/// Compute refraction vector
__forceinline vec4 refract(vec4 v, vec4 n, float eta)
{
    return vec4_refract(v, n, eta);
}


/// Compute faceforward vector
__forceinline vec4 faceforward(vec4 n, vec4 i, vec4 nref)
{
    return vec4_faceforward(n, i, nref);
}


/// Computes absolute value
__forceinline mat4 abs(mat4 m)
{
    return mat4_abs(m);
}


/// Computes cosine
__forceinline mat4 cos(mat4 m)
{
    return mat4_cos(m);
}


/// Computes sine
__forceinline mat4 sin(mat4 m)
{
    return mat4_sin(m);
}


/// Computes tangent
__forceinline mat4 tan(mat4 m)
{
    return mat4_tan(m);
}


/// Computes hyperbolic cosine
__forceinline mat4 cosh(mat4 m)
{
    return mat4_cosh(m);
}


/// Computes hyperbolic sine
__forceinline mat4 sinh(mat4 m)
{
    return mat4_sinh(m);
}


/// Computes hyperbolic tangent
__forceinline mat4 tanh(mat4 m)
{
    return mat4_tanh(m);
}


/// Computes inverse cosine
__forceinline mat4 acos(mat4 m)
{
    return mat4_acos(m);
}


/// Computes inverse sine
__forceinline mat4 asin(mat4 m)
{
    return mat4_asin(m);
}


/// Computes inverse tangent
__forceinline mat4 atan(mat4 m)
{
    return mat4_atan(m);
}


/// Computes inverse tangent with 2 args
__forceinline mat4 atan2(mat4 a, mat4 b)
{
    return mat4_atan2(a, b);
}


/// Computes Euler number raised to the power 'x'
__forceinline mat4 exp(mat4 m)
{
    return mat4_exp(m);
}


/// Computes 2 raised to the power 'x'
__forceinline mat4 exp2(mat4 m)
{
    return mat4_exp2(m);
}


/// Computes the base Euler number logarithm
__forceinline mat4 log(mat4 m)
{
    return mat4_log(m);
}


/// Computes the base 2 logarithm
__forceinline mat4 log2(mat4 m)
{
    return mat4_log2(m);
}


/// Computes the base 10 logarithm
__forceinline mat4 log10(mat4 m)
{
    return mat4_log10(m);
}


/// Computes the value of base raised to the power exponent
__forceinline mat4 pow(mat4 a, mat4 b)
{
    return mat4_pow(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline mat4 ceil(mat4 m)
{
    return mat4_ceil(m);
}


/// Computes the largest integer value not greater than 'x'
__forceinline mat4 floor(mat4 m)
{
    return mat4_floor(m);
}


/// Computes the nearest integer value
__forceinline mat4 round(mat4 m)
{
    return mat4_round(m);
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline mat4 trunc(mat4 m)
{
    return mat4_trunc(m);
}


/// Get the smaller value
__forceinline mat4 min(mat4 a, mat4 b)
{
    return mat4_min(a, b);
}


/// Get the larger value
__forceinline mat4 max(mat4 a, mat4 b)
{
    return mat4_max(a, b);
}


/// Clamps the 'x' value to the [min, max].
__forceinline mat4 clamp(mat4 v, mat4 min, mat4 max)
{
    return mat4_clamp(v, min, max);
}


/// Clamps the specified value within the range of 0 to 1
__forceinline mat4 saturate(mat4 m)
{
    return mat4_saturate(m);
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline mat4 step(mat4 a, mat4 b)
{
    return mat4_step(a, b);
}


/// Performs a linear interpolation.
__forceinline mat4 lerp(mat4 a, mat4 b, mat4 t)
{
    return mat4_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline mat4 lerp(mat4 a, mat4 b, float t)
{
    return mat4_lerp1(a, b, t);
}


/// Compute a smooth Hermite interpolation
__forceinline mat4 smoothstep(mat4 a, mat4 b, mat4 t)
{
    return mat4_smoothstep(a, b, t);
}


/// Computes square root of 'x'.
__forceinline mat4 sqrt(mat4 m)
{
    return mat4_sqrt(m);
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++

