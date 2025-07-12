#pragma once

#include "scalarmath.h"
#include "vectormath_types.h"

// -------------------------------------------------------------
// Constructors
// -------------------------------------------------------------


/// Create a new vector 2D
__forceinline vec2 vec2_new(float x, float y)
{
    vec2 result;
    result.x = x;
    result.y = y;
    return result;
}


/// Create a new vector 2D with 2 components have same value
__forceinline vec2 vec2_new1(float s)
{
    vec2 result;
    result.x = s;
    result.y = s;
    return result;
}


/// Create a new vector 2D with 2 components are zero
__forceinline vec2 vec2_zero(void)
{
    return vec2_new(0.0f, 0.0f);
}


/// Create a new vector 2D from a vector 3D
__forceinline vec2 vec2_from_vec3(vec3 v)
{
    return v.xy;
}


/// Create a new vector 2D from a vector 3D
__forceinline vec2 vec2_from_vec4(vec4 v)
{
    return v.xy;
}


// -------------------------------------------------------------
// Operators-like functions
// -------------------------------------------------------------


/// Compute negate value of v
__forceinline vec2 vec2_neg(vec2 v)
{
    return vec2_new(-v.x, -v.y);
}


/// Add two vectors 
__forceinline vec2 vec2_add(vec2 a, vec2 b)
{
    return vec2_new(a.x + b.x, a.y + b.y);
}


/// Subtract two vectors
__forceinline vec2 vec2_sub(vec2 a, vec2 b)
{
    return vec2_new(a.x - b.x, a.y - b.y);
}


/// Multiply two vectors
__forceinline vec2 vec2_mul(vec2 a, vec2 b)
{
    return vec2_new(a.x * b.x, a.y * b.y);
}


/// Divide two vectors
__forceinline vec2 vec2_div(vec2 a, vec2 b)
{
    return vec2_new(a.x / b.x, a.y / b.y);
}


/// Add vector with scalar
__forceinline vec2 vec2_add1(vec2 a, float b)
{
    return vec2_add(a, vec2_new1(b));
}


/// Subtract vector with scalar
__forceinline vec2 vec2_sub1(vec2 a, float b)
{
    return vec2_sub(a, vec2_new1(b));
}


/// Multiply vector with scalar
__forceinline vec2 vec2_mul1(vec2 a, float b)
{
    return vec2_mul(a, vec2_new1(b));
}


/// Divide vector with scalar
__forceinline vec2 vec2_div1(vec2 a, float b)
{
    return vec2_div(a, vec2_new1(b));
}


/// Compute Mul-Add algorithm: 
///     mul_add(a, b, c) = c - a * b 
__forceinline vec2 vec2_mul_add(vec2 a, vec2 b, vec2 c)
{
    return vec2_add(c, vec2_mul(a, b));
}


/// Compute Mul-Sub algorithm:
///     mul_sub(a, b, c) = c - a * b
__forceinline vec2 vec2_mul_sub(vec2 a, vec2 b, vec2 c)
{
    return vec2_sub(c, vec2_mul(a, b));
}


/// Check if two vectors are equal
__forceinline bool vec2_equal(vec2 a, vec2 b)
{
    return a.x == b.x && a.y == b.y;
}


/// Check if two vectors are not equal (faster than !vec2_equal)
__forceinline bool vec2_not_equal(vec2 a, vec2 b)
{
    return a.x != b.x || a.y != b.y;
}


/// Check if two vectors are closely equal
__forceinline bool vec2_isclose(vec2 a, vec2 b)
{
    return float_isclose(a.x, b.x)
        && float_isclose(a.y, b.y);
}


// -------------------------------------------------------------
// Functions
// -------------------------------------------------------------


/// Computes sign of 'x'
__forceinline ivec2 vec2_sign(vec2 v)
{
    ivec2 result = { float_sign(v.x), float_sign(v.y) };
    return result;
}


/// Computes absolute value
__forceinline vec2 vec2_abs(vec2 v)
{
    return vec2_new(float_abs(v.x), float_abs(v.y));
}


/// Computes cosine
__forceinline vec2 vec2_cos(vec2 v)
{
    return vec2_new(float_cos(v.x), float_cos(v.y));
}


/// Computes sine
__forceinline vec2 vec2_sin(vec2 v)
{
    return vec2_new(float_sin(v.x), float_sin(v.y));
}


/// Computes tangent
__forceinline vec2 vec2_tan(vec2 v)
{
    return vec2_new(float_tan(v.x), float_tan(v.y));
}


/// Computes hyperbolic cosine
__forceinline vec2 vec2_cosh(vec2 v)
{
    return vec2_new(float_cosh(v.x), float_cosh(v.y));
}


/// Computes hyperbolic sine
__forceinline vec2 vec2_sinh(vec2 v)
{
    return vec2_new(float_sinh(v.x), float_sinh(v.y));
}


/// Computes hyperbolic tangent
__forceinline vec2 vec2_tanh(vec2 v)
{
    return vec2_new(float_tanh(v.x), float_tanh(v.y));
}


/// Computes inverse cosine
__forceinline vec2 vec2_acos(vec2 v)
{
    return vec2_new(float_acos(v.x), float_acos(v.y));
}


/// Computes inverse sine
__forceinline vec2 vec2_asin(vec2 v)
{
    return vec2_new(float_asin(v.x), float_asin(v.y));
}


/// Computes inverse tangent
__forceinline vec2 vec2_atan(vec2 v)
{
    return vec2_new(float_atan(v.x), float_atan(v.y));
}


/// Computes inverse tangent with 2 args
__forceinline vec2 vec2_atan2(vec2 a, vec2 b)
{
    return vec2_new(float_atan2(a.x, b.x), float_atan2(a.y, b.y));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec2 vec2_exp(vec2 v)
{
    return vec2_new(float_exp(v.x), float_exp(v.y));
}


/// Computes 2 raised to the power 'x'
__forceinline vec2 vec2_exp2(vec2 v)
{
    return vec2_new(float_exp2(v.x), float_exp2(v.y));
}


/// Computes the base Euler number logarithm
__forceinline vec2 vec2_log(vec2 v)
{
    return vec2_new(float_log(v.x), float_log(v.y));
}


/// Computes the base 2 logarithm
__forceinline vec2 vec2_log2(vec2 v)
{
    return vec2_new(float_log2(v.x), float_log2(v.y));
}


/// Computes the base 10 logarithm
__forceinline vec2 vec2_log10(vec2 v)
{
    return vec2_new(float_log10(v.x), float_log10(v.y));
}


/// Computes the value of base raised to the power exponent
__forceinline vec2 vec2_pow(vec2 a, vec2 b)
{
    return vec2_new(float_pow(a.x, b.x), float_pow(a.y, b.y));
}


/// Get the fractal part of floating point
__forceinline vec2 vec2_fract(vec2 v)
{
    return vec2_new(float_fract(v.x), float_fract(v.y));
}


/// Get the fractal part of floating point
VECTORMATH_DEPRECATED("vec2_fract")
__forceinline vec2 vec2_frac(vec2 v)
{
    return vec2_fract(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec2 vec2_mod(vec2 a, vec2 b)
{
    return vec2_new(float_mod(a.x, b.x), float_mod(a.y, b.y));
}


/// Computes the floating-point remainder of the division operation x/y
VECTORMATH_DEPRECATED("vec2_mod")
__forceinline vec2 vec2_fmod(vec2 a, vec2 b)
{
    return vec2_mod(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec2 vec2_ceil(vec2 v)
{
    return vec2_new(float_ceil(v.x), float_ceil(v.y));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec2 vec2_floor(vec2 v)
{
    return vec2_new(float_floor(v.x), float_floor(v.y));
}


/// Computes the nearest integer value
__forceinline vec2 vec2_round(vec2 v)
{
    return vec2_new(float_round(v.x), float_round(v.y));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec2 vec2_trunc(vec2 v)
{
    return vec2_new(float_trunc(v.x), float_trunc(v.y));
}


/// Get the smaller value
__forceinline vec2 vec2_min(vec2 a, vec2 b)
{
    return vec2_new(float_min(a.x, b.x), float_min(a.y, b.y));
}


/// Get the larger value
__forceinline vec2 vec2_max(vec2 a, vec2 b)
{
    return vec2_new(float_max(a.x, b.x), float_max(a.y, b.y));
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec2 vec2_clamp(vec2 v, vec2 min, vec2 max)
{
    return vec2_new(float_clamp(v.x, min.x, max.x), float_clamp(v.y, min.y, max.y));
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec2 vec2_saturate(vec2 v)
{
    return vec2_new(float_saturate(v.x), float_saturate(v.y));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec2 vec2_step(vec2 a, vec2 b)
{
    return vec2_new(float_step(a.x, b.x), float_step(a.y, b.y));
}


/// Performs a linear interpolation.
__forceinline vec2 vec2_lerp(vec2 a, vec2 b, vec2 t)
{
    return vec2_new(float_lerp(a.x, b.x, t.x), float_lerp(a.y, b.y, t.y));
}


/// Performs a linear interpolation.
__forceinline vec2 vec2_lerp1(vec2 a, vec2 b, float t)
{
    return vec2_new(float_lerp(a.x, b.x, t), float_lerp(a.y, b.y, t));
}


/// Compute a smooth Hermite interpolation
__forceinline vec2 vec2_smoothstep(vec2 a, vec2 b, vec2 t)
{
    return vec2_new(float_smoothstep(a.x, b.x, t.x), float_smoothstep(a.y, b.y, t.y));
}


/// Compute a smooth Hermite interpolation
__forceinline vec2 vec2_smoothstep1(vec2 a, vec2 b, float t)
{
    return vec2_smoothstep(a, b, vec2_new1(t));
}


/// Computes square root of 'x'.
__forceinline vec2 vec2_sqrt(vec2 v)
{
    return vec2_new(float_sqrt(v.x), float_sqrt(v.y));
}


/// Computes inverse square root of 'x'.
__forceinline vec2 vec2_rsqrt(vec2 v)
{
    return vec2_new(float_rsqrt(v.x), float_rsqrt(v.y));
}


/// Compute dot product of two vectors
__forceinline float vec2_dot(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}


/// Compute squared length of vector
__forceinline float vec2_lensqr(vec2 v)
{
    return vec2_dot(v, v);
}


/// Compute length of vector
__forceinline float vec2_len(vec2 v)
{
#if VECTORMATH_USE_EXACT_PRECISION
    return float_sqrt(vec2_lensqr(v));
#else
    const float lensqr = vec2_lensqr(v);
    return lensqr * float_fast_rsqrt(lensqr);
#endif
}


/// Compute length of vector
VECTORMATH_DEPRECATED("vec2_len")
__forceinline float vec2_length(vec2 v)
{
    return vec2_len(v);
}


/// Compute distance from 'a' to b
__forceinline float vec2_dist(vec2 a, vec2 b)
{
    return vec2_len(vec2_sub(a, b));
}


/// Compute distance from 'a' to b
VECTORMATH_DEPRECATED("vec2_dist")
__forceinline float vec2_distance(vec2 a, vec2 b)
{
    return vec2_dist(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float vec2_distsqr(vec2 a, vec2 b)
{
    return vec2_lensqr(vec2_sub(a, b));
}


/// Compute normalized vector
__forceinline vec2 vec2_norm(vec2 v)
{
    const float lsqr = vec2_lensqr(v);
#if VECTORMATH_USE_EXACT_PRECISION
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec2_new(v.x * f, v.y * f);
    }
    else
    {
        return v;
    }
#else
    return vec2_mul1(v, float_fast_rsqrt(lsqr));
#endif
}


/// Compute normalized vector
VECTORMATH_DEPRECATED("vec2_norm")
__forceinline vec2 vec2_normalize(vec2 v)
{
    return vec2_norm(v);
}


/// Compute reflection vector
__forceinline vec2 vec2_reflect(vec2 v, vec2 n)
{
    return vec2_sub(v, vec2_mul1(n, 2.0f * vec2_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec2 vec2_refract(vec2 v, vec2 n, float eta)
{
    // @todos(maihd): use branchless for this algorithm
    const float k = 1.0f - eta * eta * (1.0f - vec2_dot(v, n) * vec2_dot(v, n));
    return k < 0.0f
        ? vec2_new1(0.0f)
        : vec2_sub(vec2_mul1(v, eta), vec2_mul1(v, (eta * vec2_dot(v, n) + float_sqrt(k))));
}


/// Compute faceforward vector
__forceinline vec2 vec2_faceforward(vec2 n, vec2 i, vec2 nref)
{
    return vec2_dot(i, nref) < 0.0f ? n : vec2_neg(n);
}


/// Compute angle vector
__forceinline float vec2_angle(vec2 v)
{
    return float_atan2(v.y, v.x);
}


/// Compute angle vector in degrees
__forceinline float vec2_angle_deg(vec2 v)
{
    return float_rad2deg(vec2_angle(v));
}


/// Create new vector with angle and length
__forceinline vec2 vec2_from_angle(float angle, float length)
{
    return vec2_new(float_cos(angle) * length, float_sin(angle) * length);
}


/// Create new vector with angle in degrees, and length
__forceinline vec2 vec2_from_angle_deg(float angle, float length)
{
    return vec2_from_angle(float_rad2deg(angle), length);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++

