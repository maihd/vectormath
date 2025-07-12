#pragma once

// -------------------------------------------------------------
// Compiler configuration
// -------------------------------------------------------------

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
#include "vectormath/vectormath_shorthands.h"


/// Get the fractal part of floating point
__forceinline float fract(float x)
{
    return float_fract(x);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline float mod(float x, float y)
{
    return float_mod(x, y);
}


/// Performs x linear interpolation.
__forceinline float mix(float x, float y, float s)
{
    return float_lerp(x, y, s);
}


/// Computes inverse square root of 'x', using FastInvSqrt algorithm.
__forceinline float inversesqrt(float x)
{
    return float_fast_rsqrt(x);
}


/// Get the fractal part of floating point
__forceinline vec2 fract(vec2 v)
{
    return vec2_fract(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec2 mod(vec2 a, vec2 b)
{
    return vec2_mod(a, b);
}


/// Performs a linear interpolation.
__forceinline vec2 mix(vec2 a, vec2 b, vec2 t)
{
    return vec2_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline vec2 mix(vec2 a, vec2 b, float t)
{
    return vec2_lerp1(a, b, t);
}


/// Computes inverse square root of 'x'.
__forceinline vec2 inversesqrt(vec2 v)
{
    return vec2_rsqrt(v);
}


/// Get the fractal part of floating point
__forceinline vec3 fract(vec3 v)
{
    return vec3_frac(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec3 mod(vec3 a, vec3 b)
{
    return vec3_fmod(a, b);
}


/// Performs a linear interpolation.
__forceinline vec3 mix(vec3 a, vec3 b, vec3 t)
{
    return vec3_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline vec3 mix(vec3 a, vec3 b, float t)
{
    return vec3_lerp1(a, b, t);
}


/// Computes inverse square root of 'x'.
__forceinline vec3 inversesqrt(vec3 v)
{
    return vec3_rsqrt(v);
}


/// Get the fractal part of floating point
__forceinline vec4 fract(vec4 v)
{
    return vec4_frac(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec4 mod(vec4 a, vec4 b)
{
    return vec4_fmod(a, b);
}


/// Performs a linear interpolation.
__forceinline vec4 mix(vec4 a, vec4 b, vec4 t)
{
    return vec4_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline vec4 mix(vec4 a, vec4 b, float t)
{
    return vec4_lerp1(a, b, t);
}


/// Computes inverse square root of 'x'.
__forceinline vec4 inversesqrt(vec4 v)
{
    return vec4_rsqrt(v);
}


/// Get the fractal part of floating point
__forceinline mat4 fract(mat4 m)
{
    return mat4_frac(m);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline mat4 mod(mat4 a, mat4 b)
{
    return mat4_fmod(a, b);
}


/// Performs a linear interpolation.
__forceinline mat4 mix(mat4 a, mat4 b, mat4 t)
{
    return mat4_lerp(a, b, t);
}


/// Performs a linear interpolation.
__forceinline mat4 mix(mat4 a, mat4 b, float t)
{
    return mat4_lerp1(a, b, t);
}


/// Computes inverse square root of 'x'.
__forceinline mat4 inversesqrt(mat4 m)
{
    return mat4_rsqrt(m);
}


//! EOF
