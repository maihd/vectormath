#pragma once

#include "stdmath_extensions.h"
#include "vectormath_types.h"

// Should not use both scalar & m128 versions of vector_math together
//#if (defined(__has_include) && __has_include("vector_math_simd.h"))
//#error vector_math_simd.h has been include, please remove this from your source if you attempt to use scalar version of vector_math_simd.h
//#endif

// Helper for extensions
#ifndef VECTORMATH_FUNCTIONS_DEFINED
#define VECTORMATH_FUNCTIONS_DEFINED
#endif

// -------------------------------------------------------------
// Constructors
// -------------------------------------------------------------

/// Create a new vector 2D
__forceinline vec2 vec2_new(float x, float y)
{
    vec2 result = { x, y };
    return result;
}

/// Create a new vector 2D with 2 components have same value
__forceinline vec2 vec2_new1(float s)
{
    vec2 result = { s, s };
    return result;
}

/// Create a new vector 2D from a vector 3D
__forceinline vec2 vec2_from_vec3(vec3 v)
{
    return v.xy;
}

/// Create a new vector 3D
__forceinline vec3 vec3_new(float x, float y, float z)
{
    vec3 result;
    result.m128 = _mm_setr_ps(x, y, z, 0.0f);
    return result;
}

/// Create a new vector 3D with 3 components have same value
__forceinline vec3 vec3_new1(float s)
{
    vec3 result;
    result.m128 = _mm_set_ps1(s);
    return result;
}

/// Create a new vector 3D from a vector 2D
__forceinline vec3 vec3_from_vec2(vec2 v)
{
    vec3 result;
    result.m128 = _mm_setr_ps(v.x, v.y, 0.0f, 0.0f);
    return result;
}

/// Create a new vector 3D from a vector 4D
__forceinline vec3 vec3_from_vec4(vec4 v)
{
    vec3 result;
    result.m128 = v.m128;
    return result;
}

/// Create a new vector 4D
__forceinline vec4 vec4_new(float x, float y, float z, float w)
{
    vec4 result;
    result.m128 = _mm_setr_ps(x, y, z, w);
    return result;
}

/// Create a new vector 4D with 4 components have same value
__forceinline vec4 vec4_new1(float s)
{
    vec4 result;
    result.m128 = _mm_set_ps1(s);
    return result;
}

/// Create a new vector 3D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe 
__forceinline vec3 vec3_load(const float[] ptr)
{
    vec3 result = { ptr[0], ptr[1], ptr[2] };
    return result;
}

/// Create a new vector 4D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe
__forceinline vec4 vec4_load(const float* ptr)
{
    vec4 result = { ptr[0], ptr[1], ptr[2], ptr[3] };
    return result;
}

// Create a new matrix 4x4
__forceinline mat4 mat4_new(vec4 row0, vec4 row1, vec4 row2, vec4 row3)
{
    mat4 result;
    result.row0 = row0;
    result.row1 = row1;
    result.row2 = row2;
    result.row3 = row3;
    return result;
}

// Create a new matrix 4x4, specify the components with 16 scalars
__forceinline mat4 mat4_new_f16(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
    mat4 result;
    result.row0 = vec4_new(m00, m01, m02, m03);
    result.row1 = vec4_new(m10, m11, m12, m13);
    result.row2 = vec4_new(m20, m21, m22, m23);
    result.row3 = vec4_new(m30, m31, m32, m33);
    return result;
}

/// Create a new vector 4D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe
__forceinline mat4 mat4_load(const float* ptr)
{
    mat4 result;
    result.row0 = vec4_load(ptr + 0);
    result.row1 = vec4_load(ptr + 4);
    result.row2 = vec4_load(ptr + 8);
    result.row3 = vec4_load(ptr + 12);
    return result;
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
