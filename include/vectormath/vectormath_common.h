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
    return vec2_new(fabsf(v.x), fabsf(v.y));
}


/// Computes cosine
__forceinline vec2 vec2_cos(vec2 v)
{
    return vec2_new(cosf(v.x), cosf(v.y));
}


/// Computes sine
__forceinline vec2 vec2_sin(vec2 v)
{
    return vec2_new(sinf(v.x), sinf(v.y));
}


/// Computes tangent
__forceinline vec2 vec2_tan(vec2 v)
{
    return vec2_new(tanf(v.x), tanf(v.y));
}


/// Computes hyperbolic cosine
__forceinline vec2 vec2_cosh(vec2 v)
{
    return vec2_new(coshf(v.x), coshf(v.y));
}


/// Computes hyperbolic sine
__forceinline vec2 vec2_sinh(vec2 v)
{
    return vec2_new(sinhf(v.x), sinhf(v.y));
}


/// Computes hyperbolic tangent
__forceinline vec2 vec2_tanh(vec2 v)
{
    return vec2_new(tanhf(v.x), tanhf(v.y));
}


/// Computes inverse cosine
__forceinline vec2 vec2_acos(vec2 v)
{
    return vec2_new(acosf(v.x), acosf(v.y));
}


/// Computes inverse sine
__forceinline vec2 vec2_asin(vec2 v)
{
    return vec2_new(asinf(v.x), asinf(v.y));
}


/// Computes inverse tangent
__forceinline vec2 vec2_atan(vec2 v)
{
    return vec2_new(atanf(v.x), atanf(v.y));
}


/// Computes inverse tangent with 2 args
__forceinline vec2 vec2_atan2(vec2 a, vec2 b)
{
    return vec2_new(atan2f(a.x, b.x), atan2f(a.y, b.y));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec2 vec2_exp(vec2 v)
{
    return vec2_new(expf(v.x), expf(v.y));
}


/// Computes 2 raised to the power 'x'
__forceinline vec2 vec2_exp2(vec2 v)
{
    return vec2_new(exp2f(v.x), exp2f(v.y));
}


/// Computes the base Euler number logarithm
__forceinline vec2 vec2_log(vec2 v)
{
    return vec2_new(logf(v.x), logf(v.y));
}


/// Computes the base 2 logarithm
__forceinline vec2 vec2_log2(vec2 v)
{
    return vec2_new(log2f(v.x), log2f(v.y));
}


/// Computes the base 10 logarithm
__forceinline vec2 vec2_log10(vec2 v)
{
    return vec2_new(log10f(v.x), log10f(v.y));
}


/// Computes the value of base raised to the power exponent
__forceinline vec2 vec2_pow(vec2 a, vec2 b)
{
    return vec2_new(powf(a.x, b.x), powf(a.y, b.y));
}


/// Get the fractal part of floating point
__forceinline vec2 vec2_frac(vec2 v)
{
    return vec2_new(float_frac(v.x), float_frac(v.y));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec2 vec2_fmod(vec2 a, vec2 b)
{
    return vec2_new(fmodf(a.x, b.x), fmodf(a.y, b.y));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec2 vec2_ceil(vec2 v)
{
    return vec2_new(ceilf(v.x), ceilf(v.y));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec2 vec2_floor(vec2 v)
{
    return vec2_new(floorf(v.x), floorf(v.y));
}


/// Computes the nearest integer value
__forceinline vec2 vec2_round(vec2 v)
{
    return vec2_new(roundf(v.x), roundf(v.y));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec2 vec2_trunc(vec2 v)
{
    return vec2_new(truncf(v.x), truncf(v.y));
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


/// Computes square root of 'x'.
__forceinline vec2 vec2_sqrt(vec2 v)
{
    return vec2_new(sqrtf(v.x), sqrtf(v.y));
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
__forceinline float vec2_length(vec2 v)
{
    return sqrtf(vec2_lensqr(v));
}


/// Compute distance from 'a' to b
__forceinline float vec2_distance(vec2 a, vec2 b)
{
    return vec2_length(vec2_sub(a, b));
}


/// Compute squared distance from 'a' to b
__forceinline float vec2_distsqr(vec2 a, vec2 b)
{
    return vec2_lensqr(vec2_sub(a, b));
}


/// Compute normalized vector
__forceinline vec2 vec2_normalize(vec2 v)
{
    const float lsqr = vec2_lensqr(v);
    if (lsqr > 0.0f)
    {
        const float f = 1.0f / sqrtf(lsqr);
        return vec2_new(v.x * f, v.y * f);
    }
    else
    {
        return v;
    }
}


/// Compute reflection vector
__forceinline vec2 vec2_reflect(vec2 v, vec2 n)
{
    return vec2_sub(v, vec2_mul1(n, 2.0f * vec2_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec2 vec2_refract(vec2 v, vec2 n, float eta)
{
    const float k = 1.0f - eta * eta * (1.0f - vec2_dot(v, n) * vec2_dot(v, n));
    return k < 0.0f
        ? vec2_new1(0.0f)
        : vec2_sub(vec2_mul1(v, eta), vec2_mul1(v, (eta * vec2_dot(v, n) + sqrtf(k))));
}


/// Compute faceforward vector
__forceinline vec2 vec2_faceforward(vec2 n, vec2 i, vec2 nref)
{
    return vec2_dot(i, nref) < 0.0f ? n : vec2_neg(n);
}


/// Compute angle vector
__forceinline float vec2_angle(vec2 v)
{
    return atan2f(v.y, v.x);
}


/// Compute angle vector in degrees
__forceinline float vec2_angle_deg(vec2 v)
{
    return float_rad2deg(vec2_angle(v));
}


/// Create new vector with angle and length
__forceinline vec2 vec2_from_angle(float angle, float length)
{
    return vec2_new(cosf(angle) * length, sinf(angle) * length);
}


/// Create new vector with angle in degrees, and length
__forceinline vec2 vec2_from_angle_deg(float angle, float length)
{
    return vec2_from_angle(float_rad2deg(angle), length);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++

