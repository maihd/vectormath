#pragma once

// -------------------------------------------------------------
// Compiler configuration
// -------------------------------------------------------------

#include "vectormath/scalarmath.h"
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

//! EOF
