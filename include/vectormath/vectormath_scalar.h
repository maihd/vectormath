#pragma once

#include "scalarmath.h"
#include "vectormath_types.h"
#include "vectormath_common.h"

// Should not use both scalar & m128 versions of vector_math together
#if defined(VECTORMATH_FUNCTIONS_DEFINED)
#error vectormath_simd.h has been include, please remove this from your source if you attempt to use scalar version of vector_math_simd.h
#endif

// Helper for extensions
#define VECTORMATH_FUNCTIONS_DEFINED

// -------------------------------------------------------------
// Constructors
// -------------------------------------------------------------


/// Create a new vector 3D
__forceinline vec3 vec3_new(float x, float y, float z)
{
    vec3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}


/// Create a new vector 3D with 3 components have same value
__forceinline vec3 vec3_new1(float s)
{
    vec3 result;
    result.x = s;
    result.y = s;
    result.z = s;
    return result;
}


/// Create a new vector 3D, with vec2 and z component
__forceinline vec3 vec3_new_vec2(vec2 v, float z)
{
    return vec3_new(v.x, v.y, z);
}


/// Create a new vector 3D with 3 components are zero
__forceinline vec3 vec3_zero(void)
{
    return vec3_new(0.0f, 0.0f, 0.0f);
}


/// Create a new vector 3D from a vector 2D
__forceinline vec3 vec3_from_vec2(vec2 v)
{
    vec3 result;
    result.x = v.x;
    result.y = v.y;
    result.z = 0.0f;
    return result;
}


/// Create a new vector 3D from a vector 4D
__forceinline vec3 vec3_from_vec4(vec4 v)
{
    vec3 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    return result;
}


/// Create a new vector 4D
__forceinline vec4 vec4_new(float x, float y, float z, float w)
{
    vec4 result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}


/// Create a new vector 4D with 4 components have same value
__forceinline vec4 vec4_new1(float s)
{
    vec4 result;
    result.x = s;
    result.y = s;
    result.z = s;
    result.w = s;
    return result;
}


/// Create a new vector 4D
__forceinline vec4 vec4_new_vec2(vec2 v, float z, float w)
{
    vec4 result;
    result.x = v.x;
    result.y = v.y;
    result.z = z;
    result.w = w;
    return result;
}


/// Create a new vector 4D
__forceinline vec4 vec4_new_vec3(vec3 v, float w)
{
    vec4 result;
    result.x = v.x;
    result.y = v.y;
    result.z = v.z;
    result.w = w;
    return result;
}


/// Create a new vector 4D with 4 components are zero
__forceinline vec4 vec4_zero(void)
{
    return vec4_new(0.0f, 0.0f, 0.0f, 0.0f);
}


/// Create a new vector 3D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe 
__forceinline vec3 vec3_load(const float ptr[])
{
    vec3 result;
    result.x = ptr[0];
    result.y = ptr[1];
    result.z = ptr[2];
    return result;
}


/// Create a new vector 4D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe
__forceinline vec4 vec4_load(const float ptr[])
{
    vec4 result;
    result.x = ptr[0];
    result.y = ptr[1];
    result.z = ptr[2];
    result.w = ptr[3];
    return result;
}


// Create a new matrix 4x4
__forceinline mat4 mat4_new(vec4 col0, vec4 col1, vec4 col2, vec4 col3)
{
    mat4 result;
    result.col0 = col0;
    result.col1 = col1;
    result.col2 = col2;
    result.col3 = col3;
    return result;
}


// Create a new matrix 4x4, specify the components with 16 scalars
__forceinline mat4 mat4_new_16f(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
    mat4 result;
    result.col0 = vec4_new(m00, m01, m02, m03);
    result.col1 = vec4_new(m10, m11, m12, m13);
    result.col2 = vec4_new(m20, m21, m22, m23);
    result.col3 = vec4_new(m30, m31, m32, m33);
    return result;
}


// Create a new diagonal matrix 4x4
__forceinline mat4 mat4_new_1f(float s)
{
    mat4 result;
    result.col0 = vec4_new(s, 0, 0, 0);
    result.col1 = vec4_new(0, s, 0, 0);
    result.col2 = vec4_new(0, 0, s, 0);
    result.col3 = vec4_new(0, 0, 0, s);
    return result;
}


// Create a new matrix 4x4, specify the components with 16 scalars
VECTORMATH_DEPRECATED("mat4_new_16f")
__forceinline mat4 mat4_new_f16(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
    mat4 result;
    result.col0 = vec4_new(m00, m01, m02, m03);
    result.col1 = vec4_new(m10, m11, m12, m13);
    result.col2 = vec4_new(m20, m21, m22, m23);
    result.col3 = vec4_new(m30, m31, m32, m33);
    return result;
}


/// Create a new vector 4D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe
__forceinline mat4 mat4_load(const float ptr[])
{
    mat4 result;
    result.col0 = vec4_load(ptr + 0);
    result.col1 = vec4_load(ptr + 4);
    result.col2 = vec4_load(ptr + 8);
    result.col3 = vec4_load(ptr + 12);
    return result;
}


// -------------------------------------------------------------
// Operators-like functions
// -------------------------------------------------------------


__forceinline vec3 vec3_neg(vec3 v)
{
    return vec3_new(-v.x, -v.y, -v.z);
}


__forceinline vec3 vec3_add(vec3 a, vec3 b)
{
    return vec3_new(a.x + b.x, a.y + b.y, a.z + b.z);
}


__forceinline vec3 vec3_sub(vec3 a, vec3 b)
{
    return vec3_new(a.x - b.x, a.y - b.y, a.z - b.z);
}


__forceinline vec3 vec3_mul(vec3 a, vec3 b)
{
    return vec3_new(a.x * b.x, a.y * b.y, a.z * b.z);
}


__forceinline vec3 vec3_div(vec3 a, vec3 b)
{
    return vec3_new(a.x / b.x, a.y / b.y, a.z / b.z);
}


__forceinline vec3 vec3_add1(vec3 a, float b)
{
    return vec3_add(a, vec3_new1(b));
}


__forceinline vec3 vec3_sub1(vec3 a, float b)
{
    return vec3_sub(a, vec3_new1(b));
}


__forceinline vec3 vec3_mul1(vec3 a, float b)
{
    return vec3_mul(a, vec3_new1(b));
}


__forceinline vec3 vec3_div1(vec3 a, float b)
{
    return vec3_mul(a, vec3_new1(1.0f / b));
}


__forceinline vec3 vec3_mul_add(vec3 a, vec3 b, vec3 c)
{
    return vec3_add(c, vec3_mul(a, b));
}


__forceinline vec3 vec3_mul_sub(vec3 a, vec3 b, vec3 c)
{
    return vec3_sub(c, vec3_mul(a, b));
}


__forceinline bool vec3_equal(vec3 a, vec3 b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}


__forceinline bool vec3_not_equal(vec3 a, vec3 b)
{
    return a.x != b.x || a.y != b.y || a.z != b.z;
}


__forceinline bool vec3_isclose(vec3 a, vec3 b)
{
    return float_isclose(a.x, b.x)
        && float_isclose(a.y, b.y)
        && float_isclose(a.z, b.z);
}


__forceinline vec4 vec4_neg(vec4 v)
{
    return vec4_new(-v.x, -v.y, -v.z, -v.w);
}


__forceinline vec4 vec4_add(vec4 a, vec4 b)
{
    return vec4_new(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}


__forceinline vec4 vec4_sub(vec4 a, vec4 b)
{
    return vec4_new(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}


__forceinline vec4 vec4_mul(vec4 a, vec4 b)
{
    return vec4_new(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}


__forceinline vec4 vec4_div(vec4 a, vec4 b)
{
    return vec4_new(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}


__forceinline vec4 vec4_add1(vec4 a, float b)
{
    return vec4_add(a, vec4_new1(b));
}


__forceinline vec4 vec4_sub1(vec4 a, float b)
{
    return vec4_sub(a, vec4_new1(b));
}


__forceinline vec4 vec4_mul1(vec4 a, float b)
{
    return vec4_mul(a, vec4_new1(b));
}


__forceinline vec4 vec4_div1(vec4 a, float b)
{
    return vec4_mul(a, vec4_new1(1.0f / b));
}


__forceinline vec4 vec4_mul_add(vec4 a, vec4 b, vec4 c)
{
    return vec4_mul(vec4_add(a, b), c);
}


__forceinline vec4 vec4_mul_sub(vec4 a, vec4 b, vec4 c)
{
    return vec4_mul(vec4_sub(a, b), c);
}


__forceinline bool vec4_equal(vec4 a, vec4 b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}


__forceinline bool vec4_not_equal(vec4 a, vec4 b)
{
    return a.x != b.x || a.y != b.y || a.z != b.z || a.w == b.w;
}


__forceinline bool vec4_isclose(vec4 a, vec4 b)
{
    return float_isclose(a.x, b.x)
        && float_isclose(a.y, b.y)
        && float_isclose(a.z, b.z)
        && float_isclose(a.w, b.w);
}


__forceinline mat4 mat4_neg(mat4 m)
{
    mat4 result;
    result.col0 = vec4_neg(m.col0);
    result.col1 = vec4_neg(m.col1);
    result.col2 = vec4_neg(m.col2);
    result.col3 = vec4_neg(m.col3);
    return result;
}


__forceinline mat4 mat4_add(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_add(a.col0, b.col0),
        vec4_add(a.col1, b.col1),
        vec4_add(a.col2, b.col2),
        vec4_add(a.col3, b.col3)
    );
}


__forceinline mat4 mat4_sub(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_sub(a.col0, b.col0),
        vec4_sub(a.col1, b.col1),
        vec4_sub(a.col2, b.col2),
        vec4_sub(a.col3, b.col3)
    );
}


__forceinline bool mat4_equal(mat4 a, mat4 b)
{
    return vec4_equal(a.col0, b.col0) && vec4_equal(a.col1, b.col1) && vec4_equal(a.col2, b.col2) && vec4_equal(a.col2, b.col2);
}


__forceinline bool mat4_not_equal(mat4 a, mat4 b)
{
    return vec4_not_equal(a.col0, b.col0) && vec4_not_equal(a.col1, b.col1) && vec4_not_equal(a.col2, b.col2) && vec4_not_equal(a.col2, b.col2);
}


// -------------------------------------------------------------
// Functions
// -------------------------------------------------------------


/// Computes sign of 'x'
__forceinline ivec3 vec3_sign(vec3 v)
{
    ivec3 result;
    result.x = float_sign(v.x);
    result.y = float_sign(v.y);
    result.z = float_sign(v.z);
    return result;
}


/// Computes absolute value
__forceinline vec3 vec3_abs(vec3 v)
{
    return vec3_new(float_abs(v.x), float_abs(v.y), float_abs(v.z));
}


/// Computes cosine
__forceinline vec3 vec3_cos(vec3 v)
{
    return vec3_new(float_cos(v.x), float_cos(v.y), float_cos(v.z));
}


/// Computes sine
__forceinline vec3 vec3_sin(vec3 v)
{
    return vec3_new(float_sin(v.x), float_sin(v.y), float_sin(v.z));
}


/// Computes tangent
__forceinline vec3 vec3_tan(vec3 v)
{
    return vec3_new(float_tan(v.x), float_tan(v.y), float_tan(v.z));
}


/// Computes hyperbolic cosine
__forceinline vec3 vec3_cosh(vec3 v)
{
    return vec3_new(float_cosh(v.x), float_cosh(v.y), float_cosh(v.z));
}


/// Computes hyperbolic sine
__forceinline vec3 vec3_sinh(vec3 v)
{
    return vec3_new(float_sinh(v.x), float_sinh(v.y), float_sinh(v.z));
}


/// Computes hyperbolic tangent
__forceinline vec3 vec3_tanh(vec3 v)
{
    return vec3_new(float_tanh(v.x), float_tanh(v.y), float_tanh(v.z));
}


/// Computes inverse cosine
__forceinline vec3 vec3_acos(vec3 v)
{
    return vec3_new(float_acos(v.x), float_acos(v.y), float_acos(v.z));
}


/// Computes inverse sine
__forceinline vec3 vec3_asin(vec3 v)
{
    return vec3_new(float_asin(v.x), float_asin(v.y), float_asin(v.z));
}


/// Computes inverse tangent
__forceinline vec3 vec3_atan(vec3 v)
{
    return vec3_new(float_atan(v.x), float_atan(v.y), float_atan(v.z));
}


/// Computes inverse tangent with 2 args
__forceinline vec3 vec3_atan2(vec3 a, vec3 b)
{
    return vec3_new(float_atan2(a.x, b.x), float_atan2(a.y, b.y), float_atan2(a.z, b.z));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec3 vec3_exp(vec3 v)
{
    return vec3_new(float_exp(v.x), float_exp(v.y), float_exp(v.z));
}


/// Computes 2 raised to the power 'x'
__forceinline vec3 vec3_exp2(vec3 v)
{
    return vec3_new(float_exp2(v.x), float_exp2(v.y), float_exp2(v.z));
}


/// Computes the base Euler number logarithm
__forceinline vec3 vec3_log(vec3 v)
{
    return vec3_new(float_log(v.x), float_log(v.y), float_log(v.z));
}


/// Computes the base 2 logarithm
__forceinline vec3 vec3_log2(vec3 v)
{
    return vec3_new(float_log2(v.x), float_log2(v.y), float_log2(v.z));
}


/// Computes the base 10 logarithm
__forceinline vec3 vec3_log10(vec3 v)
{
    return vec3_new(float_log10(v.x), float_log10(v.y), float_log10(v.z));
}


/// Computes the value of base raised to the power exponent
__forceinline vec3 vec3_pow(vec3 a, vec3 b)
{
    return vec3_new(float_pow(a.x, b.x), float_pow(a.y, b.y), float_pow(a.z, b.z));
}


/// Get the fractal part of floating point
__forceinline vec3 vec3_fract(vec3 v)
{
    return vec3_new(float_fract(v.x), float_fract(v.y), float_fract(v.z));
}


/// Get the fractal part of floating point
VECTORMATH_DEPRECATED("vec3_fract")
__forceinline vec3 vec3_frac(vec3 v)
{
    return vec3_fract(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec3 vec3_mod(vec3 a, vec3 b)
{
    return vec3_new(float_mod(a.x, b.x), float_mod(a.y, b.y), float_mod(a.z, b.z));
}


/// Computes the floating-point remainder of the division operation x/y
VECTORMATH_DEPRECATED("vec3_mod")
__forceinline vec3 vec3_fmod(vec3 a, vec3 b)
{
    return vec3_mod(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec3 vec3_ceil(vec3 v)
{
    return vec3_new(float_ceil(v.x), float_ceil(v.y), float_ceil(v.z));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec3 vec3_floor(vec3 v)
{
    return vec3_new(float_floor(v.x), float_floor(v.y), float_floor(v.z));
}


/// Computes the nearest integer value
__forceinline vec3 vec3_round(vec3 v)
{
    return vec3_new(float_round(v.x), float_round(v.y), float_round(v.z));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec3 vec3_trunc(vec3 v)
{
    return vec3_new(float_trunc(v.x), float_trunc(v.y), float_trunc(v.z));
}


/// Get the smaller value
__forceinline vec3 vec3_min(vec3 a, vec3 b)
{
    return vec3_new(float_min(a.x, b.x), float_min(a.y, b.y), float_min(a.z, b.z));
}


/// Get the larger value
__forceinline vec3 vec3_max(vec3 a, vec3 b)
{
    return vec3_new(float_max(a.x, b.x), float_max(a.y, b.y), float_max(a.z, b.z));
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec3 vec3_clamp(vec3 v, vec3 min, vec3 max)
{
    return vec3_new(
        float_clamp(v.x, min.x, max.x), 
        float_clamp(v.y, min.y, max.y), 
        float_clamp(v.z, min.z, max.z));
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec3 vec3_saturate(vec3 v)
{
    return vec3_new(float_saturate(v.x), float_saturate(v.y), float_saturate(v.z));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec3 vec3_step(vec3 a, vec3 b)
{
    return vec3_new(float_step(a.x, b.x), float_step(a.y, b.y), float_step(a.z, b.z));
}


/// Performs a linear interpolation.
__forceinline vec3 vec3_lerp(vec3 a, vec3 b, vec3 t)
{
    return vec3_new(float_lerp(a.x, b.x, t.x), float_lerp(a.y, b.y, t.y), float_lerp(a.z, b.z, t.z));
}


/// Performs a linear interpolation.
__forceinline vec3 vec3_lerp1(vec3 a, vec3 b, float t)
{
    return vec3_new(float_lerp(a.x, b.x, t), float_lerp(a.y, b.y, t), float_lerp(a.z, b.z, t));
}


// Compute a smooth Hermite interpolation
__forceinline vec3 vec3_smoothstep(vec3 a, vec3 b, vec3 t)
{
    return vec3_new(
        float_smoothstep(a.x, b.x, t.x), 
        float_smoothstep(a.y, b.y, t.y), 
        float_smoothstep(a.z, b.z, t.z));
}


/// Computes square root of 'x'.
__forceinline vec3 vec3_sqrt(vec3 v)
{
    return vec3_new(float_sqrt(v.x), float_sqrt(v.y), float_sqrt(v.z));
}


/// Computes inverse square root of 'x'.
__forceinline vec3 vec3_rsqrt(vec3 v)
{
    return vec3_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z));
}


/// Computes inverse square root of 'x'.
__forceinline vec3 vec3_fast_rsqrt(vec3 v)
{
    return vec3_new(float_fast_rsqrt(v.x), float_fast_rsqrt(v.y), float_fast_rsqrt(v.z));
}


/// Compute cross product of two vectors
__forceinline vec3 vec3_cross(vec3 a, vec3 b)
{
    return vec3_new(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}


/// Compute dot product of two vectors
__forceinline float vec3_dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


/// Compute squared length of vector
__forceinline float vec3_lensqr(vec3 v)
{
    return vec3_dot(v, v);
}


/// Compute length of vector
__forceinline float vec3_len(vec3 v)
{
    return float_sqrt(vec3_lensqr(v));
}


/// Compute length of vector
VECTORMATH_DEPRECATED("vec3_len")
__forceinline float vec3_length(vec3 v)
{
    return vec3_len(v);
}


/// Compute distance from 'a' to b
__forceinline float vec3_dist(vec3 a, vec3 b)
{
    return vec3_len(vec3_sub(a, b));
}


/// Compute distance from 'a' to b
VECTORMATH_DEPRECATED("vec3_dist")
__forceinline float vec3_distance(vec3 a, vec3 b)
{
    return vec3_dist(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float vec3_distsqr(vec3 a, vec3 b)
{
    return vec3_lensqr(vec3_sub(a, b));
}


/// Compute normalized vector
__forceinline vec3 vec3_norm(vec3 v)
{
    const float lsqr = vec3_lensqr(v);
#if VECTORMATH_USE_EXACT_PRECISION
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec3_new(v.x * f, v.y * f, v.z * f);
    }
    else
    {
        return v;
    }
#else
    const float f = float_fast_rsqrt(lsqr);
    return vec3_mul1(v, f);
#endif
}


/// Compute normalized vector
VECTORMATH_DEPRECATED("vec3_norm")
__forceinline vec3 vec3_normalize(vec3 v)
{
    return vec3_norm(v);
}


/// Compute reflection vector
__forceinline vec3 vec3_reflect(vec3 v, vec3 n)
{
    return vec3_sub(v, vec3_mul1(n, 2.0f * vec3_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec3 vec3_refract(vec3 v, vec3 n, float eta)
{
    const float dvn = vec3_dot(v, n); 
    const float k = 1.0f - eta * eta * (1.0f - dvn * dvn);

#if VECTORMATH_USE_EXACT_PRECISION
    return k < 0.0f
        ? vec3_new1(0.0f)
        : vec3_sub(vec3_mul1(v, eta), vec3_mul1(v, (eta * dvn + float_sqrt(k))));
#else
    const float mask = (float)(k >= 0.0f);
    const float sqrt_k = float_sqrt(float_abs(k));

    const vec3 refraction = vec3_sub(vec3_mul1(v, eta), vec3_mul1(v, (eta * dvn + sqrt_k)));
    return vec3_lerp1(vec3_new1(0.0f), refraction, mask);
#endif
}


/// Compute faceforward vector
__forceinline vec3 vec3_faceforward(vec3 n, vec3 i, vec3 nref)
{
#if VECTORMATH_USE_EXACT_PRECISION
    return vec3_dot(i, nref) < 0.0f ? n : vec3_neg(n);
#else
    const float d = vec3_dot(i, nref);
    const float s = 1.0f - 2.0f * float_sign(d);
    return vec3_mul1(n, s);
#endif
}


/// Computes sign of 'x'
__forceinline ivec4 vec4_sign(vec4 v)
{
    ivec4 result;
    result.x = float_sign(v.x);
    result.y = float_sign(v.y);
    result.z = float_sign(v.z);
    result.w = float_sign(v.w);
    return result;
}


/// Computes absolute value
__forceinline vec4 vec4_abs(vec4 v)
{
    return vec4_new(float_abs(v.x), float_abs(v.y), float_abs(v.z), float_abs(v.w));
}


/// Computes cosine
__forceinline vec4 vec4_cos(vec4 v)
{
    return vec4_new(float_cos(v.x), float_cos(v.y), float_cos(v.z), float_cos(v.w));
}


/// Computes sine
__forceinline vec4 vec4_sin(vec4 v)
{
    return vec4_new(float_sin(v.x), float_sin(v.y), float_sin(v.z), float_sin(v.w));
}


/// Computes tangent
__forceinline vec4 vec4_tan(vec4 v)
{
    return vec4_new(float_tan(v.x), float_tan(v.y), float_tan(v.z), float_tan(v.w));
}


/// Computes hyperbolic cosine
__forceinline vec4 vec4_cosh(vec4 v)
{
    return vec4_new(float_cosh(v.x), float_cosh(v.y), float_cosh(v.z), float_cosh(v.w));
}


/// Computes hyperbolic sine
__forceinline vec4 vec4_sinh(vec4 v)
{
    return vec4_new(float_sinh(v.x), float_sinh(v.y), float_sinh(v.z), float_sinh(v.w));
}


/// Computes hyperbolic tangent
__forceinline vec4 vec4_tanh(vec4 v)
{
    return vec4_new(float_tanh(v.x), float_tanh(v.y), float_tanh(v.z), float_tanh(v.w));
}


/// Computes inverse cosine
__forceinline vec4 vec4_acos(vec4 v)
{
    return vec4_new(float_acos(v.x), float_acos(v.y), float_acos(v.z), float_acos(v.w));
}


/// Computes inverse sine
__forceinline vec4 vec4_asin(vec4 v)
{
    return vec4_new(float_asin(v.x), float_asin(v.y), float_asin(v.z), float_asin(v.w));
}


/// Computes inverse tangent
__forceinline vec4 vec4_atan(vec4 v)
{
    return vec4_new(float_atan(v.x), float_atan(v.y), float_atan(v.z), float_atan(v.w));
}


/// Computes inverse tangent with 2 args
__forceinline vec4 vec4_atan2(vec4 a, vec4 b)
{
    return vec4_new(float_atan2(a.x, b.x), float_atan2(a.y, b.y), float_atan2(a.z, b.z), float_atan2(a.w, b.w));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec4 vec4_exp(vec4 v)
{
    return vec4_new(float_exp(v.x), float_exp(v.y), float_exp(v.z), float_exp(v.w));
}


/// Computes 2 raised to the power 'x'
__forceinline vec4 vec4_exp2(vec4 v)
{
    return vec4_new(float_exp2(v.x), float_exp2(v.y), float_exp2(v.z), float_exp2(v.w));
}


/// Computes the base Euler number logarithm
__forceinline vec4 vec4_log(vec4 v)
{
    return vec4_new(float_log(v.x), float_log(v.y), float_log(v.z), float_log(v.w));
}


/// Computes the base 2 logarithm
__forceinline vec4 vec4_log2(vec4 v)
{
    return vec4_new(float_log2(v.x), float_log2(v.y), float_log2(v.z), float_log2(v.w));
}


/// Computes the base 10 logarithm
__forceinline vec4 vec4_log10(vec4 v)
{
    return vec4_new(float_log10(v.x), float_log10(v.y), float_log10(v.z), float_log10(v.w));
}


/// Computes the value of base raised to the power exponent
__forceinline vec4 vec4_pow(vec4 a, vec4 b)
{
    return vec4_new(float_pow(a.x, b.x), float_pow(a.y, b.y), float_pow(a.z, b.z), float_pow(a.w, b.w));
}


/// Get the fractal part of floating point
__forceinline vec4 vec4_fract(vec4 v)
{
    return vec4_new(float_fract(v.x), float_fract(v.y), float_fract(v.z), float_fract(v.w));
}


/// Get the fractal part of floating point
__forceinline vec4 vec4_frac(vec4 v)
{
    return vec4_fract(v);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec4 vec4_mod(vec4 a, vec4 b)
{
    return vec4_new(float_mod(a.x, b.x), float_mod(a.y, b.y), float_mod(a.z, b.z), float_mod(a.w, b.w));
}


/// Computes the floating-point remainder of the division operation x/y
VECTORMATH_DEPRECATED("vec4_mod")
__forceinline vec4 vec4_fmod(vec4 a, vec4 b)
{
    return vec4_mod(a, b);
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec4 vec4_ceil(vec4 v)
{
    return vec4_new(float_ceil(v.x), float_ceil(v.y), float_ceil(v.z), float_ceil(v.w));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec4 vec4_floor(vec4 v)
{
    return vec4_new(float_floor(v.x), float_floor(v.y), float_floor(v.z), float_floor(v.w));
}


/// Computes the nearest integer value
__forceinline vec4 vec4_round(vec4 v)
{
    return vec4_new(float_round(v.x), float_round(v.y), float_round(v.z), float_round(v.w));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec4 vec4_trunc(vec4 v)
{
    return vec4_new(float_trunc(v.x), float_trunc(v.y), float_trunc(v.z), float_trunc(v.w));
}


/// Get the smaller value
__forceinline vec4 vec4_min(vec4 a, vec4 b)
{
    return vec4_new(
        float_min(a.x, b.x),
        float_min(a.y, b.y),
        float_min(a.z, b.z),
        float_min(a.w, b.w)
    );
}


/// Get the larger value
__forceinline vec4 vec4_max(vec4 a, vec4 b)
{
    return vec4_new(
        float_max(a.x, b.x), 
        float_max(a.y, b.y),
        float_max(a.z, b.z),
        float_max(a.w, b.w)
    );
}


/// Clamps the 'x' value to the [min, max].
__forceinline vec4 vec4_clamp(vec4 v, vec4 min, vec4 max)
{
    return vec4_new(
        float_clamp(v.x, min.x, max.x), 
        float_clamp(v.y, min.y, max.y), 
        float_clamp(v.z, min.z, max.z), 
        float_clamp(v.w, min.w, max.w)
    );
}


/// Clamps the specified value within the range of 0 to 1
__forceinline vec4 vec4_saturate(vec4 v)
{
    return vec4_new(float_saturate(v.x), float_saturate(v.y), float_saturate(v.z), float_saturate(v.w));
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline vec4 vec4_step(vec4 a, vec4 b)
{
    return vec4_new(
        float_step(a.x, b.x),
        float_step(a.y, b.y),
        float_step(a.z, b.z),
        float_step(a.w, b.w)
    );
}


/// Performs a linear interpolation.
__forceinline vec4 vec4_lerp(vec4 a, vec4 b, vec4 t)
{
    return vec4_new(
        float_lerp(a.x, b.x, t.x),
        float_lerp(a.y, b.y, t.y),
        float_lerp(a.z, b.z, t.z),
        float_lerp(a.w, b.w, t.w)
    );
}


/// Performs a linear interpolation.
__forceinline vec4 vec4_lerp1(vec4 a, vec4 b, float t)
{
    return vec4_new(
        float_lerp(a.x, b.x, t),
        float_lerp(a.y, b.y, t),
        float_lerp(a.z, b.z, t),
        float_lerp(a.w, b.w, t)
    );
}


/// Compute a smooth Hermite interpolation
__forceinline vec4 vec4_smoothstep(vec4 a, vec4 b, vec4 t)
{
    return vec4_new(
        float_smoothstep(a.x, b.x, t.x),
        float_smoothstep(a.y, b.y, t.y),
        float_smoothstep(a.z, b.z, t.z),
        float_smoothstep(a.w, b.w, t.w)
    );
}


/// Computes square root of 'x'.
__forceinline vec4 vec4_sqrt(vec4 v)
{
    return vec4_new(float_sqrt(v.x), float_sqrt(v.y), float_sqrt(v.z), float_sqrt(v.w));
}


/// Computes inverse square root of 'x'.
__forceinline vec4 vec4_rsqrt(vec4 v)
{
    return vec4_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z), float_rsqrt(v.w));
}


/// Computes inverse square root of 'x'.
__forceinline vec4 vec4_fast_rsqrt(vec4 v)
{
    return vec4_new(
        float_fast_rsqrt(v.x), 
        float_fast_rsqrt(v.y), 
        float_fast_rsqrt(v.z), 
        float_fast_rsqrt(v.w));
}


/// Compute dot product of two vectors
__forceinline float vec4_dot(vec4 a, vec4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


/// Compute squared length of vector
__forceinline float vec4_lensqr(vec4 v)
{
    return vec4_dot(v, v);
}


/// Compute length of vector
__forceinline float vec4_len(vec4 v)
{
    return float_sqrt(vec4_lensqr(v));
}


/// Compute length of vector
VECTORMATH_DEPRECATED("vec4_len")
__forceinline float vec4_length(vec4 v)
{
    return vec4_len(v);
}


/// Compute distance from 'a' to b
__forceinline float vec4_dist(vec4 a, vec4 b)
{
    return vec4_len(vec4_sub(a, b));
}


/// Compute distance from 'a' to b
VECTORMATH_DEPRECATED("vec4_dist")
__forceinline float vec4_distance(vec4 a, vec4 b)
{
    return vec4_dist(a, b);
}


/// Compute squared distance from 'a' to b
__forceinline float vec4_distsqr(vec4 a, vec4 b)
{
    return vec4_lensqr(vec4_sub(a, b));
}


/// Compute normalized vector
__forceinline vec4 vec4_norm(vec4 v)
{
    const float lsqr = vec4_lensqr(v);
#if VECTORMATH_USE_EXACT_PRECISION
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec4_new(v.x * f, v.y * f);
    }
    else
    {
        return v;
    }
#else
    return vec4_mul1(v, float_fast_rsqrt(lsqr));
#endif
}


/// Compute normalized vector
VECTORMATH_DEPRECATED("vec4_norm")
__forceinline vec4 vec4_normalize(vec4 v)
{
    return vec4_norm(v);
}


/// Compute reflection vector
__forceinline vec4 vec4_reflect(vec4 v, vec4 n)
{
    return vec4_sub(v, vec4_mul1(n, 2.0f * vec4_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec4 vec4_refract(vec4 v, vec4 n, float eta)
{
    const float dvn = vec4_dot(v, n); 
    const float k = 1.0f - eta * eta * (1.0f - dvn * dvn);

#if VECTORMATH_USE_EXACT_PRECISION
    return k < 0.0f
        ? vec4_new1(0.0f)
        : vec4_sub(vec4_mul1(v, eta), vec4_mul1(v, (eta * dvn + float_sqrt(k))));
#else
    const float mask = (float)(k >= 0.0f);
    const float sqrt_k = float_sqrt(float_abs(k));

    const vec4 refraction = vec4_sub(vec4_mul1(v, eta), vec4_mul1(v, (eta * dvn + sqrt_k)));
    return vec4_lerp1(vec4_new1(0.0f), refraction, mask);
#endif
}


/// Compute faceforward vector
__forceinline vec4 vec4_faceforward(vec4 n, vec4 i, vec4 nref)
{
#if VECTORMATH_USE_EXACT_PRECISION
    return vec4_dot(i, nref) < 0.0f ? n : vec4_neg(n);
#else
    const float d = vec4_dot(i, nref);
    const float s = 1.0f - 2.0f * float_sign(d);
    return vec4_mul1(n, s);
#endif
}


/// Create an identity quaternion
__forceinline quat quat_identity(void)
{
    return vec4_new(0.0f, 0.0f, 0.0f, 1.0f);
}


/// Quaternion multiplication
__forceinline quat quat_mul(quat a, quat b)
{
    const vec3  a3 = vec3_new(a.x, a.y, a.z);
    const vec3  b3 = vec3_new(b.x, b.y, b.z);

    const vec3  xyz = vec3_add(vec3_add(vec3_mul1(a3, b.w), vec3_mul1(b3, a.w)), vec3_cross(a3, b3));
    const float w = a.w * b.w - vec3_dot(a3, b3);

    return vec4_new(xyz.x, xyz.y, xyz.z, w);
}


/// Quaternion inversion
__forceinline quat quat_inverse(vec4 q)
{
    return vec4_new(q.x, q.y, q.z, -q.w);
}


/// Quaternion conjugate
__forceinline quat quat_conj(vec4 q)
{
    return vec4_new(-q.x, -q.y, -q.z, q.w);
}


__forceinline quat quat_from_axis_angle(vec3 axis, float angle)
{
    if (vec3_lensqr(axis) == 0.0f)
    {
        return vec4_new(0, 0, 0, 1);
    }

    vec4 result;
    result.xyz  = vec3_mul1(vec3_norm(axis), float_sin(angle * 0.5f));
    result.w    = float_cos(angle * 0.5f);
    return result;
}


__forceinline vec4 quat_to_axis_angle(quat quat)
{
    vec4 c = quat;
    if (c.w != 0.0f)
    {
        c = vec4_norm(quat);
    }

    const float den = float_sqrt(1.0f - c.w * c.w);
    const vec3 axis = (den > 0.0001f) 
        ? vec3_div1(vec3_new(c.x, c.y, c.z), den)
        : vec3_new(1, 0, 0);

    const float angle = 2.0f * float_cos(c.w);

    vec4 result;
    result.x = axis.x;
    result.y = axis.y;
    result.z = axis.z;
    result.w = angle;
    return result;
}


__forceinline void quat_to_axis_angle_ref(quat quat, vec3* axis, float* angle)
{
    vec4 axisAngle = quat_to_axis_angle(quat);
    if (axis) *axis = axisAngle.xyz;
    if (angle) *angle = axisAngle.w;
}


__forceinline quat quat_from_euler(float x, float y, float z)
{
    float r;
    float p;

    r = z * 0.5f;
    p = x * 0.5f;
    y = y * 0.5f; // Now y mean yaw

    const float c1 = float_cos(y);
    const float c2 = float_cos(p);
    const float c3 = float_cos(r);
    const float s1 = float_sin(y);
    const float s2 = float_sin(p);
    const float s3 = float_sin(r);

    return vec4_new(
        s1 * s2 * c3 + c1 * c2 * s3,
        s1 * c2 * c3 + c1 * s2 * s3,
        c1 * s2 * c3 - s1 * c2 * s3,
        c1 * c2 * c3 - s1 * s2 * s3
    );
}


/// Computes absolute value
__forceinline mat4 mat4_abs(mat4 m)
{
    return mat4_new(vec4_abs(m.col0), vec4_abs(m.col1), vec4_abs(m.col2), vec4_abs(m.col3));
}


/// Computes cosine
__forceinline mat4 mat4_cos(mat4 m)
{
    return mat4_new(
        vec4_cos(m.col0),
        vec4_cos(m.col1),
        vec4_cos(m.col2),
        vec4_cos(m.col3)
    );
}


/// Computes sine
__forceinline mat4 mat4_sin(mat4 m)
{
    return mat4_new(
        vec4_sin(m.col0),
        vec4_sin(m.col1),
        vec4_sin(m.col2),
        vec4_sin(m.col3)
    );
}


/// Computes tangent
__forceinline mat4 mat4_tan(mat4 m)
{
    return mat4_new(
        vec4_tan(m.col0),
        vec4_tan(m.col1),
        vec4_tan(m.col2),
        vec4_tan(m.col3)
    );
}


/// Computes hyperbolic cosine
__forceinline mat4 mat4_cosh(mat4 m)
{
    return mat4_new(
        vec4_cosh(m.col0),
        vec4_cosh(m.col1),
        vec4_cosh(m.col2),
        vec4_cosh(m.col3)
    );
}


/// Computes hyperbolic sine
__forceinline mat4 mat4_sinh(mat4 m)
{
    return mat4_new(
        vec4_sinh(m.col0),
        vec4_sinh(m.col1),
        vec4_sinh(m.col2),
        vec4_sinh(m.col3)
    );
}


/// Computes hyperbolic tangent
__forceinline mat4 mat4_tanh(mat4 m)
{
    return mat4_new(
        vec4_tanh(m.col0),
        vec4_tanh(m.col1),
        vec4_tanh(m.col2),
        vec4_tanh(m.col3)
    );
}


/// Computes inverse cosine
__forceinline mat4 mat4_acos(mat4 m)
{
    return mat4_new(
        vec4_acos(m.col0),
        vec4_acos(m.col1),
        vec4_acos(m.col2),
        vec4_acos(m.col3)
    );
}


/// Computes inverse sine
__forceinline mat4 mat4_asin(mat4 m)
{
    return mat4_new(
        vec4_asin(m.col0),
        vec4_asin(m.col1),
        vec4_asin(m.col2),
        vec4_asin(m.col3)
    );
}


/// Computes inverse tangent
__forceinline mat4 mat4_atan(mat4 m)
{
    return mat4_new(
        vec4_atan(m.col0),
        vec4_atan(m.col1),
        vec4_atan(m.col2),
        vec4_atan(m.col3)
    );
}


/// Computes inverse tangent with 2 args
__forceinline mat4 mat4_atan2(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_atan2(a.col0, b.col0),
        vec4_atan2(a.col1, b.col1),
        vec4_atan2(a.col2, b.col2),
        vec4_atan2(a.col3, b.col3)
    );
}


/// Computes Euler number raised to the power 'x'
__forceinline mat4 mat4_exp(mat4 m)
{
    return mat4_new(
        vec4_exp(m.col0),
        vec4_exp(m.col1),
        vec4_exp(m.col2),
        vec4_exp(m.col3)
    );
}


/// Computes 2 raised to the power 'x'
__forceinline mat4 mat4_exp2(mat4 m)
{
    return mat4_new(
        vec4_exp2(m.col0),
        vec4_exp2(m.col1),
        vec4_exp2(m.col2),
        vec4_exp2(m.col3)
    );
}


/// Computes the base Euler number logarithm
__forceinline mat4 mat4_log(mat4 m)
{
    return mat4_new(
        vec4_log(m.col0),
        vec4_log(m.col1),
        vec4_log(m.col2),
        vec4_log(m.col3)
    );
}


/// Computes the base 2 logarithm
__forceinline mat4 mat4_log2(mat4 m)
{
    return mat4_new(
        vec4_log2(m.col0),
        vec4_log2(m.col1),
        vec4_log2(m.col2),
        vec4_log2(m.col3)
    );
}


/// Computes the base 10 logarithm
__forceinline mat4 mat4_log10(mat4 m)
{
    return mat4_new(
        vec4_log10(m.col0),
        vec4_log10(m.col1),
        vec4_log10(m.col2),
        vec4_log10(m.col3)
    );
}


/// Computes the value of base raised to the power exponent
__forceinline mat4 mat4_pow(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_pow(a.col0, b.col0),
        vec4_pow(a.col1, b.col1),
        vec4_pow(a.col2, b.col2),
        vec4_pow(a.col3, b.col3)
    );
}


/// Get the fractal part of floating point
__forceinline mat4 mat4_frac(mat4 m)
{
    return mat4_new(
        vec4_frac(m.col0),
        vec4_frac(m.col1),
        vec4_frac(m.col2),
        vec4_frac(m.col3)
    );
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline mat4 mat4_fmod(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_fmod(a.col0, b.col0),
        vec4_fmod(a.col1, b.col1),
        vec4_fmod(a.col2, b.col2),
        vec4_fmod(a.col3, b.col3)
    );
}


/// Computes the smallest integer value not less than 'x'
__forceinline mat4 mat4_ceil(mat4 m)
{
    return mat4_new(
        vec4_ceil(m.col0),
        vec4_ceil(m.col1),
        vec4_ceil(m.col2),
        vec4_ceil(m.col3)
    );
}


/// Computes the largest integer value not greater than 'x'
__forceinline mat4 mat4_floor(mat4 m)
{
    return mat4_new(
        vec4_floor(m.col0),
        vec4_floor(m.col1),
        vec4_floor(m.col2),
        vec4_floor(m.col3)
    );
}


/// Computes the nearest integer value
__forceinline mat4 mat4_round(mat4 m)
{
    return mat4_new(
        vec4_round(m.col0),
        vec4_round(m.col1),
        vec4_round(m.col2),
        vec4_round(m.col3)
    );
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline mat4 mat4_trunc(mat4 m)
{
    return mat4_new(
        vec4_trunc(m.col0),
        vec4_trunc(m.col1),
        vec4_trunc(m.col2),
        vec4_trunc(m.col3)
    );
}


/// Get the smaller value
__forceinline mat4 mat4_min(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_min(a.col0, b.col0),
        vec4_min(a.col1, b.col1),
        vec4_min(a.col2, b.col2),
        vec4_min(a.col3, b.col3)
    );
}


/// Get the larger value
__forceinline mat4 mat4_max(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_max(a.col0, b.col0),
        vec4_max(a.col1, b.col1),
        vec4_max(a.col2, b.col2),
        vec4_max(a.col3, b.col3)
    );
}


/// Clamps the 'x' value to the [min, max].
__forceinline mat4 mat4_clamp(mat4 v, mat4 min, mat4 max)
{
    return mat4_new(
        vec4_clamp(v.col0, min.col0, max.col0),
        vec4_clamp(v.col1, min.col1, max.col1),
        vec4_clamp(v.col2, min.col2, max.col2),
        vec4_clamp(v.col3, min.col3, max.col3)
    );
}


/// Clamps the specified value within the range of 0 to 1
__forceinline mat4 mat4_saturate(mat4 m)
{
    return mat4_new(
        vec4_saturate(m.col0),
        vec4_saturate(m.col1),
        vec4_saturate(m.col2),
        vec4_saturate(m.col3)
    );
}


/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline mat4 mat4_step(mat4 a, mat4 b)
{
    return mat4_new(
        vec4_step(a.col0, b.col0),
        vec4_step(a.col1, b.col1),
        vec4_step(a.col2, b.col2),
        vec4_step(a.col3, b.col3)
    );
}


/// Performs a linear interpolation.
__forceinline mat4 mat4_lerp(mat4 a, mat4 b, mat4 t)
{
    return mat4_new(
        vec4_lerp(a.col0, b.col0, t.col0),
        vec4_lerp(a.col1, b.col1, t.col1),
        vec4_lerp(a.col2, b.col2, t.col2),
        vec4_lerp(a.col3, b.col3, t.col3)
    );
}


/// Performs a linear interpolation.
__forceinline mat4 mat4_lerp1(mat4 a, mat4 b, float t)
{
    return mat4_new(
        vec4_lerp(a.col0, b.col0, vec4_new1(t)),
        vec4_lerp(a.col1, b.col1, vec4_new1(t)),
        vec4_lerp(a.col2, b.col2, vec4_new1(t)),
        vec4_lerp(a.col3, b.col3, vec4_new1(t))
    );
}


/// Compute a smooth Hermite interpolation
__forceinline mat4 mat4_smoothstep(mat4 a, mat4 b, mat4 t)
{
    return mat4_new(
        vec4_smoothstep(a.col0, b.col0, t.col0),
        vec4_smoothstep(a.col1, b.col1, t.col1),
        vec4_smoothstep(a.col2, b.col2, t.col2),
        vec4_smoothstep(a.col3, b.col3, t.col3)
    );
}


/// Computes square root of 'x'.
__forceinline mat4 mat4_sqrt(mat4 m)
{
    return mat4_new(vec4_sqrt(m.col0), vec4_sqrt(m.col1), vec4_sqrt(m.col2), vec4_sqrt(m.col3));
}


/// Computes inverse square root of 'x'.
__forceinline mat4 mat4_rsqrt(mat4 m)
{
    return mat4_new(vec4_rsqrt(m.col0), vec4_rsqrt(m.col1), vec4_rsqrt(m.col2), vec4_rsqrt(m.col3));
}


__forceinline vec4 mat4_mul_vec4(mat4 m, vec4 v)
{
    return vec4_new(
        m.col0.x * v.x + m.col1.x * v.y + m.col2.x * v.z + m.col3.x * v.w,
        m.col0.y * v.x + m.col1.y * v.y + m.col2.y * v.z + m.col3.y * v.w,
        m.col0.z * v.x + m.col1.z * v.y + m.col2.z * v.z + m.col3.z * v.w,
        m.col0.w * v.x + m.col1.w * v.y + m.col2.w * v.z + m.col3.w * v.w
    );
}


__forceinline vec4 vec4_mul_mat4(vec4 v, mat4 m)
{
    return vec4_new(
        vec4_dot(v, m.col0),
        vec4_dot(v, m.col1),
        vec4_dot(v, m.col2),
        vec4_dot(v, m.col3)
    );
}


__forceinline vec3 mat4_mul_vec3(mat4 a, vec3 b)
{
    const vec4 b0 = vec4_new(b.x, b.y, b.z, 1.0f);
    const vec4 b1 = mat4_mul_vec4(a, b0);

    const float iw = 1.0f / b1.w;
    return vec3_new(b1.x * iw, b1.y * iw, b1.z * iw);
}


__forceinline vec2 mat4_mul_vec2(mat4 a, vec2 b)
{
    const vec4 b0 = vec4_new(b.x, b.y, 0.0f, 1.0f);
    const vec4 b1 = mat4_mul_vec4(a, b0);

    const float iw = 1.0f / b1.w;
    return vec2_new(b1.x * iw, b1.y * iw);
}


__forceinline vec3 vec3_mul_mat4(vec3 a, mat4 b)
{
    const vec4 a0 = vec4_new(a.x, a.y, a.z, 1.0f);
    const vec4 a1 = vec4_mul_mat4(a0, b);

    const float iw = 1.0f / a1.w;
    return vec3_new(a1.x * iw, a1.y * iw, a1.z * iw);
}


__forceinline mat4 mat4_mul(mat4 a, mat4 b)
{
    return mat4_new(
        mat4_mul_vec4(a, b.col0),
        mat4_mul_vec4(a, b.col1),
        mat4_mul_vec4(a, b.col2),
        mat4_mul_vec4(a, b.col3)
    );
}


__forceinline mat4 mat4_mul1(mat4 a, float b)
{
    return mat4_new(
        vec4_mul1(a.col0, b),
        vec4_mul1(a.col1, b),
        vec4_mul1(a.col2, b),
        vec4_mul1(a.col3, b)
    );
}


__forceinline mat4 mat4_transpose(mat4 m)
{
    return mat4_new_16f(
        m.m00, m.m10, m.m20, m.m30,
        m.m01, m.m11, m.m21, m.m31,
        m.m02, m.m12, m.m22, m.m32,
        m.m03, m.m13, m.m23, m.m33
    );
}


__forceinline mat4 mat4_inverse(mat4 m)
{
    const float n11 = m.m00, n12 = m.m10, n13 = m.m20, n14 = m.m30;
    const float n21 = m.m01, n22 = m.m11, n23 = m.m21, n24 = m.m31;
    const float n31 = m.m02, n32 = m.m12, n33 = m.m22, n34 = m.m32;
    const float n41 = m.m03, n42 = m.m13, n43 = m.m23, n44 = m.m33;

    const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
    const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
    const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
    const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

    const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;
    if (det < 0.0f)
    {
        mat4 result;
        result.m00 = 0.0f; result.m01 = 0.0f; result.m02 = 0.0f; result.m03 = 0.0f;
        result.m10 = 0.0f; result.m11 = 0.0f; result.m12 = 0.0f; result.m13 = 0.0f;
        result.m20 = 0.0f; result.m21 = 0.0f; result.m22 = 0.0f; result.m23 = 0.0f;
        result.m30 = 0.0f; result.m31 = 0.0f; result.m32 = 0.0f; result.m33 = 0.0f;
        return result;
    }

    const float idet = 1.0f / det;

    mat4 result;
    result.m00 = t11 * idet;
    result.m01 = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * idet;
    result.m02 = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * idet;
    result.m03 = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * idet;

    result.m10 = t12 * idet;
    result.m11 = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * idet;
    result.m12 = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * idet;
    result.m13 = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43) * idet;

    result.m20 = t13 * idet;
    result.m21 = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * idet;
    result.m22 = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * idet;
    result.m23 = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * idet;

    result.m30 = t14 * idet;
    result.m31 = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * idet;
    result.m32 = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * idet;
    result.m33 = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * idet;
    return result;
}


__forceinline mat4 mat4_identity(void)
{
    return mat4_new_16f(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}


__forceinline mat4 mat4_ortho_rh(float left, float right, float bottom, float top, float z_near, float z_far)
{
    const float sum_rl = (right + left);
    const float sum_tb = (top + bottom);
    const float sum_nf = (z_near + z_far);
    const float inv_rl = (1.0f / (right - left));
    const float inv_tb = (1.0f / (top - bottom));
    const float inv_nf = (1.0f / (z_far - z_near));

    return mat4_new_16f(
         (inv_rl + inv_rl),               0.0f,               0.0f, 0.0f,
                      0.0f,  (inv_tb + inv_tb),               0.0f, 0.0f,
                      0.0f,               0.0f,  (inv_nf + inv_nf), 0.0f,
        -(sum_rl * inv_rl), -(sum_tb * inv_tb), -(sum_nf * inv_nf), 1.0f
    );
}


VECTORMATH_DEPRECATED("mat4_ortho_rh")
__forceinline mat4 mat4_ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
    return mat4_ortho_rh(left, right, bottom, top, z_near, z_far);
}


__forceinline mat4 mat4_frustum_rh(float left, float right, float bottom, float top, float z_near, float z_far)
{
    const float x = 1.0f / (right - left);
    const float y = 1.0f / (top - bottom);
    const float z = 1.0f / (z_far - z_near);

    return mat4_new_16f(
        2.0f * x, 0, 0, 0,
        0, 2.0f * y, 0, 0,
        x * (left + right), y * (bottom + top), z * (z_near + z_far), 1.0f,
        0, 0, 2.0f * z, 0
    );
}


VECTORMATH_DEPRECATED("mat4_frustum_rh")
__forceinline mat4 mat4_frustum(float left, float right, float bottom, float top, float z_near, float z_far)
{
    return mat4_frustum_rh(left, right, bottom, top, z_near, z_far);
}


__forceinline mat4 mat4_perspective_rh(float fov_radians, float aspect, float z_near, float z_far)
{
    const float zoom_x = 1.0f / float_tan(fov_radians * 0.5f);
    const float zoom_y = zoom_x * aspect;

    const float z_clip_bias_0 = (z_near + z_far) / (z_near - z_far);
    const float z_clip_bias_1 = (2.0f * z_near * z_far) / (z_near - z_far);

    mat4 result;
    result.col0 = vec4_new(zoom_x,   0.0f,          0.0f,  0.0f);
    result.col1 = vec4_new(  0.0f, zoom_y,          0.0f,  0.0f);
    result.col2 = vec4_new(  0.0f,   0.0f, z_clip_bias_0, -1.0f);
    result.col3 = vec4_new(  0.0f,   0.0f, z_clip_bias_1,  1.0f);
    return result;
}


VECTORMATH_DEPRECATED("mat4_perspective_rh")
__forceinline mat4 mat4_perspective(float fov_radians, float aspect, float z_near, float z_far)
{
    return mat4_perspective_rh(fov_radians, aspect, z_near, z_far);
}


__forceinline mat4 mat4_lookat_rh(vec3 eye, vec3 target, vec3 up)
{
    const vec3 z = vec3_norm(vec3_sub(eye, target));
    const vec3 x = vec3_norm(vec3_cross(vec3_norm(up), z));
    const vec3 y = vec3_norm(vec3_cross(z, x));

    return mat4_new_16f(
         x.x,  y.x,  z.x, -vec3_dot(x, eye),
         x.y,  y.y,  z.y, -vec3_dot(y, eye),
         x.z,  y.z,  z.z, -vec3_dot(z, eye),
        0.0f, 0.0f, 0.0f,                   1.0f
    );
}


VECTORMATH_DEPRECATED("mat4_lookat_rh")
__forceinline mat4 mat4_lookat(vec3 eye, vec3 target, vec3 up)
{
    return mat4_lookat_rh(eye, target, up);
}


__forceinline mat4 mat4_scalation(float x, float y, float z)
{
    return mat4_new_16f(
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    );
}


__forceinline mat4 mat4_scalation1(float s)
{
    return mat4_scalation(s, s, s);
}


__forceinline mat4 mat4_scalation_vec2(vec2 v)
{
    return mat4_scalation(v.x, v.y, 1.0f);
}


__forceinline mat4 mat4_scalation_vec3(vec3 v)
{
    return mat4_scalation(v.x, v.y, v.z);
}


__forceinline mat4 mat4_translation(float x, float y, float z)
{
    return mat4_new_16f(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1
    );
}


__forceinline mat4 mat4_translation_vec2(vec2 v)
{
    return mat4_translation(v.x, v.y, 0.0f);
}


__forceinline mat4 mat4_translation_vec3(vec3 v)
{
    return mat4_translation(v.x, v.y, v.z);
}


__forceinline mat4 mat4_rotation(float x, float y, float z, float radians)
{
    const float c = float_cos(-radians);
    const float s = float_sin(-radians);
    const float t = 1.0f - c;

    return mat4_new_16f(
        /* Col 0 */
        t * x * x + c,
        t * x * y - s * z,
        t * x * z + s * y,
        0.0f,

        /* Col 1 */
        t * x * y + s * z,
        t * y * y + c,
        t * y * z - s * x,
        0.0f,

        /* Col 2 */
        t * x * z - s * y,
        t * y * z + s * x,
        t * z * z + c,
        0.0f,

        /* Col 3 */
        0, 0, 0, 1.0f
    );
}


__forceinline mat4 mat4_rotation_axis_angle(vec3 axis, float angle)
{
    return mat4_rotation(axis.x, axis.y, axis.z, angle);
}


__forceinline mat4 mat4_rotation_x(float angle)
{
    const float s = float_sin(angle);
    const float c = float_cos(angle);

    return mat4_new_16f(
        1,  0, 0, 0,
        0,  c, s, 0,
        0, -s, c, 0,
        0,  0, 0, 1
    );
}


__forceinline mat4 mat4_rotation_y(float angle)
{
    const float s = float_sin(angle);
    const float c = float_cos(angle);

    return mat4_new_16f(
         c, 0, s, 0,
         0, 1, 0, 0,
        -s, 0, c, 0,
         0, 0, 0, 1
    );
}


__forceinline mat4 mat4_rotation_z(float radians)
{
    const float s = float_sin(radians);
    const float c = float_cos(radians);

    return mat4_new_16f(
         c, s, 0, 0,
        -s, c, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1
    );
}


__forceinline mat4 mat4_rotation_quat(quat quaternion)
{
    vec4 axisangle = quat_to_axis_angle(quaternion);
    return mat4_rotation(axisangle.x, axisangle.y, axisangle.z, axisangle.w);
}


/// Create 2D transformation matrix
__forceinline mat4 mat4_transform2(vec2 position, float angle, vec2 scale)
{
    const mat4 translation  = mat4_translation_vec2(position);
    const mat4 rotation     = mat4_rotation_z(angle);
    const mat4 scalation    = mat4_scalation_vec2(scale);
    return mat4_mul(mat4_mul(translation, rotation), scalation);
}


/// Create 3D transformation matrix
__forceinline mat4 mat4_transform3(vec3 position, quat quat, vec3 scale)
{
    const mat4 translation  = mat4_translation_vec3(position);
    const mat4 rotation     = mat4_rotation_quat(quat);
    const mat4 scalation    = mat4_scalation_vec3(scale);
    return mat4_mul(mat4_mul(translation, rotation), scalation);
}


__forceinline void mat4_decompose(mat4 m, vec3* scalation, quat* quaternion, vec3* translation)
{
    if (translation)
    {
        *translation = m.col3.xyz;
    }

    if (!scalation && !quaternion)
    {
        return;
    }

    vec3 xaxis = m.col0.xyz;
    vec3 yaxis = m.col1.xyz;
    vec3 zaxis = m.col2.xyz;

    float scale_x = vec3_len(xaxis);
    float scale_y = vec3_len(yaxis);
    float scale_z = vec3_len(zaxis);

    const float n11 = m.m00, n12 = m.m10, n13 = m.m20, n14 = m.m30;
    const float n21 = m.m01, n22 = m.m11, n23 = m.m21, n24 = m.m31;
    const float n31 = m.m02, n32 = m.m12, n33 = m.m22, n34 = m.m32;
    const float n41 = m.m03, n42 = m.m13, n43 = m.m23, n44 = m.m33;

    const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
    const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
    const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
    const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

    const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;
    if (det < 0) scale_z = -scale_z;

    if (scalation)
    {
        *scalation = vec3_new(scale_x, scale_y, scale_z);
    }

    if (!quaternion)
    {
        return;
    }

    float rn;

    // Factor the scale out of the matrix axes.
    rn = 1.0f / scale_x;
    xaxis.x *= rn;
    xaxis.y *= rn;
    xaxis.z *= rn;

    rn = 1.0f / scale_y;
    yaxis.x *= rn;
    yaxis.y *= rn;
    yaxis.z *= rn;

    rn = 1.0f / scale_z;
    zaxis.x *= rn;
    zaxis.y *= rn;
    zaxis.z *= rn;

    // Now calculate the rotation from the resulting matrix (axes).
    const float trace = xaxis.x + yaxis.y + zaxis.z + 1.0f;

    if (trace > 0.0001f)
    {
        float s = 0.5f / float_sqrt(trace);
        quaternion->w = 0.25f / s;
        quaternion->x = (yaxis.z - zaxis.y) * s;
        quaternion->y = (zaxis.x - xaxis.z) * s;
        quaternion->z = (xaxis.y - yaxis.x) * s;
    }
    else
    {
        // Note: since X axis, Y axis, and Z axis are normalized, 
        // we will never divide by zero in the code below.
        if (xaxis.x > yaxis.y && xaxis.x > zaxis.z)
        {
            float s = 0.5f / float_sqrt(1.0f + xaxis.x - yaxis.y - zaxis.z);
            quaternion->w = (yaxis.z - zaxis.y) * s;
            quaternion->x = 0.25f / s;
            quaternion->y = (yaxis.x + xaxis.y) * s;
            quaternion->z = (zaxis.x + xaxis.z) * s;
        }
        else if (yaxis.y > zaxis.z)
        {
            float s = 0.5f / float_sqrt(1.0f + yaxis.y - xaxis.x - zaxis.z);
            quaternion->w = (zaxis.x - xaxis.z) * s;
            quaternion->x = (yaxis.x + xaxis.y) * s;
            quaternion->y = 0.25f / s;
            quaternion->z = (zaxis.y + yaxis.z) * s;
        }
        else
        {
            float s = 0.5f / float_sqrt(1.0f + zaxis.z - xaxis.x - yaxis.y);
            quaternion->w = (xaxis.y - yaxis.x) * s;
            quaternion->x = (zaxis.x + xaxis.z) * s;
            quaternion->y = (zaxis.y + yaxis.z) * s;
            quaternion->z = 0.25f / s;
        }
    }
}


__forceinline void mat4_decompose_axis_angle(mat4 m, vec3* scalation, vec3* axis, float* angle, vec3* translation)
{
    if (axis || angle)
    {
        quat quat;
        mat4_decompose(m, scalation, &quat, translation);

        quat_to_axis_angle_ref(quat, axis, angle);
    }
    else
    {
        mat4_decompose(m, scalation, (vec4*)0, translation);
    }
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
