#pragma once

#include "scalarmath.h"
#include "vectormath_types.h"
#include "vectormath_common.h"
#include "vectormath_simd_utils.h"

// Make sure m128 is enable
#if !VECTORMATH_SIMD_ENABLE
#error The vectormath support for simd is not enable, please use vector_math_scalar.h instead
#endif

// Should not use both scalar & m128 versions of vector_math together
#if defined(VECTORMATH_FUNCTIONS_DEFINED)
#error vectormath_scalar.h has been include, please remove that from your source if you attempt to use vector_math_simd.h
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
    result.m128 = _mm_setr_ps(x, y, z, 0.0f);
    return result;
}


/// Create a new vector 3D, with components have same value
__forceinline vec3 vec3_new1(float s)
{
    vec3 result;
    result.m128 = _mm_set_ps1(s);
    return result;
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


/// Create a new vector 3D from a __m128 simd
/// @note: available only on SIMD vectormath version
__forceinline vec3 vec3_from_m128(__m128 m128)
{
    vec3 result;
    result.m128 = m128;
    return result;
}


/// Create a new vector 4D
__forceinline vec4 vec4_new(float x, float y, float z, float w)
{
    vec4 result;
    result.m128 = _mm_setr_ps(x, y, z, w);
    return result;
}


/// Create a new vector 4D, with components have same value
__forceinline vec4 vec4_new1(float s)
{
    vec4 result;
    result.m128 = _mm_set_ps1(s);
    return result;
}


/// Create a new vector 4D with 4 components are zero
__forceinline vec4 vec4_zero(void)
{
    return vec4_new(0.0f, 0.0f, 0.0f, 0.0f);
}


/// Create a new vector 4D from a __m128 simd
/// @note: available only on SIMD vectormath version
__forceinline vec4 vec4_from_m128(__m128 m128)
{
    vec4 result;
    result.m128 = m128;
    return result;
}


/// Create a new vector 3D, with components' values load from a scalars array
/// @note: this functions is not pointer-safe
__forceinline vec3 vec3_load(const float ptr[])
{
    vec3 result;
    result.m128 = _mm_load_ps(ptr);
    return result;
}


/// Create a new vector 4D, with components' values load from an scalars array
/// @note: this functions is not pointer-safe
__forceinline vec4 vec4_load(const float ptr[])
{
    vec4 result;
    result.m128 = _mm_load_ps(ptr);
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


// Create a new matrix 4x4, specify the components with 16 scalars
__deprecated("mat4_new_16f")
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
    return vec3_from_m128(_mm_sub_ps(_mm_setzero_ps(), v.m128));
}


__forceinline vec3 vec3_add(vec3 a, vec3 b)
{
    return vec3_from_m128(_mm_add_ps(a.m128, b.m128));
}


__forceinline vec3 vec3_sub(vec3 a, vec3 b)
{
    return vec3_from_m128(_mm_sub_ps(a.m128, b.m128));
}


__forceinline vec3 vec3_mul(vec3 a, vec3 b)
{
    return vec3_from_m128(_mm_mul_ps(a.m128, b.m128));
}


__forceinline vec3 vec3_div(vec3 a, vec3 b)
{
    return vec3_from_m128(_mm_div_ps(a.m128, b.m128));
}


__forceinline vec3 vec3_add1(vec3 a, float b)
{
    return vec3_from_m128(_mm_add_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec3 vec3_sub1(vec3 a, float b)
{
    return vec3_from_m128(_mm_sub_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec3 vec3_mul1(vec3 a, float b)
{
    return vec3_from_m128(_mm_mul_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec3 vec3_div1(vec3 a, float b)
{
    return vec3_from_m128(_mm_mul_ps(a.m128, _mm_set_ps1(1.0f / b)));
}


__forceinline vec3 vec3_mul_add(vec3 a, vec3 b, vec3 c)
{
    return vec3_from_m128(m128_mul_add(a.m128, b.m128, c.m128));
}


__forceinline vec3 vec3_mul_sub(vec3 a, vec3 b, vec3 c)
{
    return vec3_from_m128(m128_mul_sub(a.m128, b.m128, c.m128));
}


__forceinline bool vec3_equal(vec3 a, vec3 b)
{
    return (_mm_movemask_ps(_mm_cmpeq_ps(a.m128, b.m128)) & 0x7) == 0x7;
}


__forceinline bool vec3_not_equal(vec3 a, vec3 b)
{
    return (_mm_movemask_ps(_mm_cmpeq_ps(a.m128, b.m128)) & 0x7) != 0x7;
}


__forceinline bool vec3_isclose(vec3 a, vec3 b)
{
    const __m128 sub_abs = m128_fabsf(_mm_sub_ps(a.m128, b.m128));
    return (_mm_movemask_ps(_mm_cmplt_ps(sub_abs, _mm_set_ps1(FLOAT_EPSILON))) & 0x7) == 0x7;
}


__forceinline vec4 vec4_neg(vec4 v)
{
    return vec4_from_m128(_mm_sub_ps(_mm_setzero_ps(), v.m128));
}


__forceinline vec4 vec4_add(vec4 a, vec4 b)
{
    return vec4_from_m128(_mm_add_ps(a.m128, b.m128));
}


__forceinline vec4 vec4_sub(vec4 a, vec4 b)
{
    return vec4_from_m128(_mm_sub_ps(a.m128, b.m128));
}


__forceinline vec4 vec4_mul(vec4 a, vec4 b)
{
    return vec4_from_m128(_mm_mul_ps(a.m128, b.m128));
}


__forceinline vec4 vec4_div(vec4 a, vec4 b)
{
    return vec4_from_m128(_mm_div_ps(a.m128, b.m128));
}


__forceinline vec4 vec4_add1(vec4 a, float b)
{
    return vec4_from_m128(_mm_add_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec4 vec4_sub1(vec4 a, float b)
{
    return vec4_from_m128(_mm_sub_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec4 vec4_mul1(vec4 a, float b)
{
    return vec4_from_m128(_mm_mul_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec4 vec4_div1(vec4 a, float b)
{
    return vec4_from_m128(_mm_div_ps(a.m128, _mm_set_ps1(b)));
}


__forceinline vec4 vec4_mul_add(vec4 a, vec4 b, vec4 c)
{
    return vec4_from_m128(m128_mul_add(a.m128, b.m128, c.m128));
}


__forceinline vec4 vec4_mul_sub(vec4 a, vec4 b, vec4 c)
{
    return vec4_from_m128(m128_mul_sub(a.m128, b.m128, c.m128));
}


__forceinline bool vec4_equal(vec4 a, vec4 b)
{
    return _mm_movemask_ps(_mm_cmpeq_ps(a.m128, b.m128)) == 0x16;
}


__forceinline bool vec4_not_equal(vec4 a, vec4 b)
{
    return _mm_movemask_ps(_mm_cmpeq_ps(a.m128, b.m128)) != 0x16;
}


__forceinline bool vec4_isclose(vec4 a, vec4 b)
{
    const __m128 sub_abs = m128_fabsf(_mm_sub_ps(a.m128, b.m128));
    return _mm_movemask_ps(_mm_cmplt_ps(sub_abs, _mm_set_ps1(FLOAT_EPSILON))) == 0x16;
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
    //__m128i iv = _mm_castps_si128(v.m128);
    //int32_t* c = (int32_t*)&iv;
    //
    //ivec3 result;
    //result.m128i = _mm_or_si128(_mm_srli_epi32(iv, 31), _mm_set_epi32(!!c[3], !!c[2], !!c[1], !!c[0]));
    //return result;
    ivec3 result;
    result.x = float_sign(v.x);
    result.y = float_sign(v.y);
    result.z = float_sign(v.z);
    return result;
}


/// Computes absolute value
__forceinline vec3 vec3_abs(vec3 v)
{
    return vec3_from_m128(m128_fabsf(v.m128));
}


/// Computes cosine
__forceinline vec3 vec3_cos(vec3 v)
{
    return vec3_from_m128(m128_cosf(v.m128));
}


/// Computes sine
__forceinline vec3 vec3_sin(vec3 v)
{
    return vec3_from_m128(m128_sinf(v.m128));
}


/// Computes tangent
__forceinline vec3 vec3_tan(vec3 v)
{
    return vec3_new(tanf(v.x), tanf(v.y), tanf(v.z));
    //return vec3_from_m128(m128_tanf(v.m128));
}


/// Computes hyperbolic cosine
__forceinline vec3 vec3_cosh(vec3 v)
{
    return vec3_new(coshf(v.x), coshf(v.y), coshf(v.z));
}


/// Computes hyperbolic sine
__forceinline vec3 vec3_sinh(vec3 v)
{
    return vec3_new(sinhf(v.x), sinhf(v.y), sinhf(v.z));
}


/// Computes hyperbolic tangent
__forceinline vec3 vec3_tanh(vec3 v)
{
    return vec3_new(tanhf(v.x), tanhf(v.y), tanhf(v.z));
}


/// Computes inverse cosine
__forceinline vec3 vec3_acos(vec3 v)
{
    return vec3_from_m128(m128_acosf(v.m128));
}


/// Computes inverse sine
__forceinline vec3 vec3_asin(vec3 v)
{
    return vec3_new(asinf(v.x), asinf(v.y), asinf(v.z));
}


/// Computes inverse tangent
__forceinline vec3 vec3_atan(vec3 v)
{
    return vec3_new(atanf(v.x), atanf(v.y), atanf(v.z));
}


/// Computes inverse tangent with 2 args
__forceinline vec3 vec3_atan2(vec3 a, vec3 b)
{
    return vec3_new(atan2f(a.x, b.x), atan2f(a.y, b.y), atan2f(a.z, b.z));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec3 vec3_exp(vec3 v)
{
    return vec3_new(expf(v.x), expf(v.y), expf(v.z));
}


/// Computes 2 raised to the power 'x'
__forceinline vec3 vec3_exp2(vec3 v)
{
    return vec3_new(exp2f(v.x), exp2f(v.y), exp2f(v.z));
}


/// Computes the base Euler number logarithm
__forceinline vec3 vec3_log(vec3 v)
{
    return vec3_new(logf(v.x), logf(v.y), logf(v.z));
}


/// Computes the base 2 logarithm
__forceinline vec3 vec3_log2(vec3 v)
{
    return vec3_new(log2f(v.x), log2f(v.y), log2f(v.z));
}


/// Computes the base 10 logarithm
__forceinline vec3 vec3_log10(vec3 v)
{
    return vec3_new(log10f(v.x), log10f(v.y), log10f(v.z));
}


/// Computes the value of base raised to the power exponent
__forceinline vec3 vec3_pow(vec3 a, vec3 b)
{
    return vec3_new(powf(a.x, b.x), powf(a.y, b.y), powf(a.z, b.z));
}


/// Get the fractal part of floating point
__forceinline vec3 vec3_frac(vec3 v)
{
    return vec3_new(float_frac(v.x), float_frac(v.y), float_frac(v.z));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec3 vec3_fmod(vec3 a, vec3 b)
{
    return vec3_new(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec3 vec3_ceil(vec3 v)
{
    return vec3_new(ceilf(v.x), ceilf(v.y), ceilf(v.z));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec3 vec3_floor(vec3 v)
{
    return vec3_new(floorf(v.x), floorf(v.y), floorf(v.z));
}


/// Computes the nearest integer value
__forceinline vec3 vec3_round(vec3 v)
{
    return vec3_new(roundf(v.x), roundf(v.y), roundf(v.z));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec3 vec3_trunc(vec3 v)
{
    return vec3_new(truncf(v.x), truncf(v.y), truncf(v.z));
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
    return vec3_new(float_clamp(v.x, min.x, max.x), float_clamp(v.y, min.y, max.y), float_clamp(v.z, min.z, max.z));
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
    return vec3_new(float_smoothstep(a.x, b.x, t.x), float_smoothstep(a.y, b.y, t.y), float_smoothstep(a.z, b.z, t.z));
}


/// Computes square root of 'x'.
__forceinline vec3 vec3_sqrt(vec3 v)
{
    return vec3_new(sqrtf(v.x), sqrtf(v.y), sqrtf(v.z));
}


/// Computes inverse square root of 'x'.
__forceinline vec3 vec3_rsqrt(vec3 v)
{
    return vec3_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z));
}


/// Compute cross product of two vectors
__forceinline vec3 vec3_cross(vec3 a, vec3 b)
{
    const __m128 tmp0   = _mm_shuffle_ps(a.m128, a.m128, _MM_SHUFFLE(3, 0, 2, 1));
    const __m128 tmp1   = _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(3, 1, 0, 2));
    const __m128 tmp2   = _mm_shuffle_ps(a.m128, a.m128, _MM_SHUFFLE(3, 1, 0, 2));
    const __m128 tmp3   = _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(3, 0, 2, 1));
          __m128 result = _mm_mul_ps(tmp0, tmp1);
                 result = m128_mul_sub(tmp2, tmp3, result);
    return vec3_from_m128(result);
}


/// Compute dot product of two vectors
__forceinline float vec3_dot(vec3 a, vec3 b)
{
    const vec3 c = vec3_mul(a, b);
    return c.x + c.y + c.z;
}


/// Compute squared length of vector
__forceinline float vec3_lensqr(vec3 v)
{
    return vec3_dot(v, v);
}


/// Compute length of vector
__forceinline float vec3_length(vec3 v)
{
    return sqrtf(vec3_lensqr(v));
}


/// Compute distance from 'a' to b
__forceinline float vec3_distance(vec3 a, vec3 b)
{
    return vec3_length(vec3_sub(a, b));
}


/// Compute squared distance from 'a' to b
__forceinline float vec3_distsqr(vec3 a, vec3 b)
{
    return vec3_lensqr(vec3_sub(a, b));
}


/// Compute normalized vector
__forceinline vec3 vec3_normalize(vec3 v)
{
#ifndef VECTORMATH_USE_EXACT_PRECISION
    return vec3_mul1(v, float_fast_rsqrt(vec3_lensqr(v)));
#else
    const float lsqr = vec3_lensqr(v);
    if (lsqr > 0.0f)
    {
        const float f = float_rsqrt(lsqr);
        return vec3_mul1(v, f);
    }
    else
    {
        return v;
    }
#endif
}


/// Compute reflection vector
__forceinline vec3 vec3_reflect(vec3 v, vec3 n)
{
    return vec3_sub(v, vec3_mul1(n, 2.0f * vec3_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec3 vec3_refract(vec3 v, vec3 n, float eta)
{
    const float k = 1.0f - eta * eta * (1.0f - vec3_dot(v, n) * vec3_dot(v, n));
    return k < 0.0f
        ? vec3_new1(0.0f)
        : vec3_sub(vec3_mul1(v, eta), vec3_mul1(n, (eta * vec3_dot(v, n) + sqrtf(k))));
}


/// Compute faceforward vector
__forceinline vec3 vec3_faceforward(vec3 n, vec3 i, vec3 nref)
{
    return vec3_dot(i, nref) < 0.0f ? n : vec3_neg(n);
}


/// Computes sign of 'x'
__forceinline ivec4 vec4_sign(vec4 v)
{
    //__m128i iv = _mm_castps_si128(v.m128);
    //__m128i im = _mm_set1_epi32(31);
    //
    //int32_t* c = (int32_t*)&iv;
    //
    //ivec4 result;
    //result.m128i = _mm_or_si128(iv, _mm_set_epi32(!!c[3], !!c[2], !!c[1], !!c[0]));
    //return result;
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
    return vec4_from_m128(m128_fabsf(v.m128));
}


/// Computes cosine
__forceinline vec4 vec4_cos(vec4 v)
{
    return vec4_from_m128(m128_cosf(v.m128));
}


/// Computes sine
__forceinline vec4 vec4_sin(vec4 v)
{
    return vec4_from_m128(m128_sinf(v.m128));
}


/// Computes tangent
__forceinline vec4 vec4_tan(vec4 v)
{
    return vec4_new(tanf(v.x), tanf(v.y), tanf(v.z), tanf(v.w));
    //return vec4_from_m128(m128_tanf(v.m128));
}


/// Computes hyperbolic cosine
__forceinline vec4 vec4_cosh(vec4 v)
{
    return vec4_new(coshf(v.x), coshf(v.y), coshf(v.z), coshf(v.w));
}


/// Computes hyperbolic sine
__forceinline vec4 vec4_sinh(vec4 v)
{
    return vec4_new(sinhf(v.x), sinhf(v.y), sinhf(v.z), sinhf(v.w));
}


/// Computes hyperbolic tangent
__forceinline vec4 vec4_tanh(vec4 v)
{
    return vec4_new(tanhf(v.x), tanhf(v.y), tanhf(v.z), tanhf(v.w));
}


/// Computes inverse cosine
__forceinline vec4 vec4_acos(vec4 v)
{
    return vec4_from_m128(m128_acosf(v.m128));
}


/// Computes inverse sine
__forceinline vec4 vec4_asin(vec4 v)
{
    return vec4_new(asinf(v.x), asinf(v.y), asinf(v.z), asinf(v.w));
}


/// Computes inverse tangent
__forceinline vec4 vec4_atan(vec4 v)
{
    return vec4_new(atanf(v.x), atanf(v.y), atanf(v.z), atanf(v.w));
}


/// Computes inverse tangent with 2 args
__forceinline vec4 vec4_atan2(vec4 a, vec4 b)
{
    return vec4_new(atan2f(a.x, b.x), atan2f(a.y, b.y), atan2f(a.z, b.z), atan2f(a.w, b.w));
}


/// Computes Euler number raised to the power 'x'
__forceinline vec4 vec4_exp(vec4 v)
{
    return vec4_new(expf(v.x), expf(v.y), expf(v.z), expf(v.w));
}


/// Computes 2 raised to the power 'x'
__forceinline vec4 vec4_exp2(vec4 v)
{
    return vec4_new(exp2f(v.x), exp2f(v.y), exp2f(v.z), exp2f(v.w));
}


/// Computes the base Euler number logarithm
__forceinline vec4 vec4_log(vec4 v)
{
    return vec4_new(logf(v.x), logf(v.y), logf(v.z), logf(v.w));
}


/// Computes the base 2 logarithm
__forceinline vec4 vec4_log2(vec4 v)
{
    return vec4_new(log2f(v.x), log2f(v.y), log2f(v.z), log2f(v.w));
}


/// Computes the base 10 logarithm
__forceinline vec4 vec4_log10(vec4 v)
{
    return vec4_new(log10f(v.x), log10f(v.y), log10f(v.z), log10f(v.w));
}


/// Computes the value of base raised to the power exponent
__forceinline vec4 vec4_pow(vec4 a, vec4 b)
{
    return vec4_new(powf(a.x, b.x), powf(a.y, b.y), powf(a.z, b.z), powf(a.w, b.w));
}


/// Get the fractal part of floating point
__forceinline vec4 vec4_frac(vec4 v)
{
    return vec4_new(float_frac(v.x), float_frac(v.y), float_frac(v.z), float_frac(v.w));
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline vec4 vec4_fmod(vec4 a, vec4 b)
{
    return vec4_new(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z), fmodf(a.w, b.w));
}


/// Computes the smallest integer value not less than 'x'
__forceinline vec4 vec4_ceil(vec4 v)
{
    return vec4_new(ceilf(v.x), ceilf(v.y), ceilf(v.z), ceilf(v.w));
}


/// Computes the largest integer value not greater than 'x'
__forceinline vec4 vec4_floor(vec4 v)
{
    return vec4_new(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
}


/// Computes the nearest integer value
__forceinline vec4 vec4_round(vec4 v)
{
    return vec4_new(roundf(v.x), roundf(v.y), roundf(v.z), roundf(v.w));
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline vec4 vec4_trunc(vec4 v)
{
    return vec4_new(truncf(v.x), truncf(v.y), truncf(v.z), truncf(v.w));
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
    return vec4_new(sqrtf(v.x), sqrtf(v.y), sqrtf(v.z), sqrtf(v.w));
}


/// Computes inverse square root of 'x'.
__forceinline vec4 vec4_rsqrt(vec4 v)
{
    return vec4_new(float_rsqrt(v.x), float_rsqrt(v.y), float_rsqrt(v.z), float_rsqrt(v.w));
}


/// Compute dot product of two vectors
__forceinline float vec4_dot(vec4 a, vec4 b)
{
    const vec4 c = vec4_mul(a, b);
    return c.x + c.y + c.z + c.w;
}


/// Compute squared length of vector
__forceinline float vec4_lensqr(vec4 v)
{
    return vec4_dot(v, v);
}


/// Compute length of vector
__forceinline float vec4_length(vec4 v)
{
    return sqrtf(vec4_lensqr(v));
}


/// Compute distance from 'a' to 'b'
__forceinline float vec4_distance(vec4 a, vec4 b)
{
    return vec4_length(vec4_sub(a, b));
}


/// Compute squared distance from 'a' to 'b'
__forceinline float vec4_distsqr(vec4 a, vec4 b)
{
    return vec4_lensqr(vec4_sub(a, b));
}


/// Compute normalized vector
__forceinline vec4 vec4_normalize(vec4 v)
{
#ifndef VECTORMATH_USE_EXACT_PRECISION
    return vec4_mul1(v, float_fast_rsqrt(vec4_lensqr(v)));
#else
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
#endif
}


/// Compute reflection vector
__forceinline vec4 vec4_reflect(vec4 v, vec4 n)
{
    return vec4_sub(v, vec4_mul1(n, 2.0f * vec4_dot(v, n)));
}


/// Compute refraction vector
__forceinline vec4 vec4_refract(vec4 v, vec4 n, float eta)
{
    const float k = 1.0f - eta * eta * (1.0f - vec4_dot(v, n) * vec4_dot(v, n));
    return k < 0.0f
        ? vec4_new1(0.0f)
        : vec4_sub(vec4_mul1(v, eta), vec4_mul1(n, eta * vec4_dot(v, n) + sqrtf(k)));
}


/// Compute faceforward vector
__forceinline vec4 vec4_faceforward(vec4 n, vec4 i, vec4 nref)
{
    return vec4_dot(i, nref) < 0.0f ? n : vec4_neg(n);
}


/// Quaternion multiplication
__forceinline vec4 quat_mul(vec4 a, vec4 b)
{
    const vec3  a3  = vec3_new(a.x, a.y, a.z);
    const vec3  b3  = vec3_new(b.x, b.y, b.z);

    const vec3  xyz = vec3_add(vec3_add(vec3_mul1(a3, b.w), vec3_mul1(b3, a.w)), vec3_cross(a3, b3));
    const float w   = a.w * b.w - vec3_dot(a3, b3);
        
    return vec4_new(xyz.x, xyz.y, xyz.z, w);
}


/// Quaternion inversion
__forceinline vec4 quat_inverse(vec4 q)
{
    return vec4_new(q.x, q.y, q.z, -q.w);
}


/// Quaternion conjugate
__forceinline vec4 quat_conj(vec4 q)
{
    return vec4_new(-q.x, -q.y, -q.z, q.w);
}


/// Create quaternion from axes and angle
__forceinline vec4 quat_from_axis_angle(vec3 axis, float angle)
{
    if (vec3_lensqr(axis) == 0.0f)
    {
        return vec4_new(0, 0, 0, 1);
    }
    
    const vec3 normalized = vec3_mul1(vec3_normalize(axis), sinf(angle * 0.5f));
    return vec4_new(normalized.x, normalized.y, normalized.z, cosf(angle * 0.5f));
}


/// Convert quaternion from axes and angle
__forceinline vec4 quat_to_axis_angle(vec4 quat)
{
    vec4 c = quat;
    if (c.w != 0.0f)
    {
        c = vec4_normalize(quat);
    }

    const float den = sqrtf(1.0f - c.w * c.w);
    const vec3 axis = (den > 0.0001f)
        ? vec3_div1(vec3_new(c.x, c.y, c.z), den)
        : vec3_new(1.0f, 0.0f, 0.0f);

    const float angle = 2.0f * cosf(c.w);
    return vec4_new(axis.x, axis.y, axis.z, angle);
}


/// Convert quaternion from axes and angle, pass-by-ref
__forceinline void quat_to_axis_angle_ref(vec4 quat, vec3* axis, float* angle)
{
    vec4 axisAngle = quat_to_axis_angle(quat);
    if (axis) *axis = vec3_from_m128(axisAngle.m128);
    if (angle) *angle = axisAngle.w;
}


/// Create quaternion from euler
__forceinline vec4 quat_from_euler(float x, float y, float z)
{
    float r;
    float p;

    r = z * 0.5f;
    p = x * 0.5f;
    y = y * 0.5f; // Now y mean yaw

    const float c1 = cosf(y);
    const float c2 = cosf(p);
    const float c3 = cosf(r);
    const float s1 = sinf(y);
    const float s2 = sinf(p);
    const float s3 = sinf(r);

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


__forceinline vec4 mat4_mul_vec4(mat4 a, vec4 b)
{
    return vec4_from_m128(
        _mm_add_ps(
            _mm_add_ps(
                _mm_mul_ps(a.col0.m128, _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(0, 0, 0, 0))), 
                _mm_mul_ps(a.col1.m128, _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(1, 1, 1, 1)))
            ),
            _mm_add_ps(
                _mm_mul_ps(a.col2.m128, _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(2, 2, 2, 2))),
                _mm_mul_ps(a.col3.m128, _mm_shuffle_ps(b.m128, b.m128, _MM_SHUFFLE(3, 3, 3, 3)))
            )
        )
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
    __m128 tmp0, tmp1, tmp2, tmp3, res0, res1, res2, res3;
    tmp0 = m128_merge_hi(m.col0.m128, m.col2.m128);
    tmp1 = m128_merge_hi(m.col1.m128, m.col3.m128);
    tmp2 = m128_merge_lo(m.col0.m128, m.col2.m128);
    tmp3 = m128_merge_lo(m.col1.m128, m.col3.m128);
    res0 = m128_merge_hi(tmp0, tmp1);
    res1 = m128_merge_lo(tmp0, tmp1);
    res2 = m128_merge_hi(tmp2, tmp3);
    res3 = m128_merge_lo(tmp2, tmp3);
    return mat4_new(vec4_from_m128(res0), vec4_from_m128(res1), vec4_from_m128(res2), vec4_from_m128(res3));
}


__forceinline mat4 mat4_inverse(mat4 m)
{
    VECTORMATH_ALIGNAS(unsigned int PNPN[4], 16) = { 0x00000000, 0x80000000, 0x00000000, 0x80000000 };
    VECTORMATH_ALIGNAS(unsigned int NPNP[4], 16) = { 0x80000000, 0x00000000, 0x80000000, 0x00000000 };
    VECTORMATH_ALIGNAS(float X1_YZ0_W1[4]  , 16) = { 1.0f, 0.0f, 0.0f, 1.0f };

    __m128 Va, Vb, Vc;
    __m128 r1, r2, r3, tt, tt2;
    __m128 sum, Det, RDet;
    __m128 trns0, trns1, trns2, trns3;

    __m128 _L1 = m.col0.m128;
    __m128 _L2 = m.col1.m128;
    __m128 _L3 = m.col2.m128;
    __m128 _L4 = m.col3.m128;
    // Calculating the minterms for the first line.

    // simdRor is just a macro using _mm_shuffle_ps().
    tt = _L4;
    tt2 = m128_ror(_L3, 1);
    Vc = _mm_mul_ps(tt2, m128_ror(tt, 0)); // V3'�V4
    Va = _mm_mul_ps(tt2, m128_ror(tt, 2)); // V3'�V4"
    Vb = _mm_mul_ps(tt2, m128_ror(tt, 3)); // V3'�V4^

    r1 = _mm_sub_ps(m128_ror(Va, 1), m128_ror(Vc, 2)); // V3"�V4^ - V3^�V4"
    r2 = _mm_sub_ps(m128_ror(Vb, 2), m128_ror(Vb, 0)); // V3^�V4' - V3'�V4^
    r3 = _mm_sub_ps(m128_ror(Va, 0), m128_ror(Vc, 1)); // V3'�V4" - V3"�V4'

    tt = _L2;
    Va = m128_ror(tt, 1);
    sum = _mm_mul_ps(Va, r1);
    Vb = m128_ror(tt, 2);
    sum = _mm_add_ps(sum, _mm_mul_ps(Vb, r2));
    Vc = m128_ror(tt, 3);
    sum = _mm_add_ps(sum, _mm_mul_ps(Vc, r3));

    // Calculating the determinant.
    Det = _mm_mul_ps(sum, _L1);
    Det = _mm_add_ps(Det, _mm_movehl_ps(Det, Det));

    const __m128 Sign_PNPN = _mm_load_ps((float *)PNPN);
    const __m128 Sign_NPNP = _mm_load_ps((float *)NPNP);

    __m128 mtL1 = _mm_xor_ps(sum, Sign_PNPN);

    // Calculating the minterms of the second line (using previous results).
    tt = m128_ror(_L1, 1);
    sum = _mm_mul_ps(tt, r1);
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r2));
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r3));
    __m128 mtL2 = _mm_xor_ps(sum, Sign_NPNP);

    // Testing the determinant.
    Det = _mm_sub_ss(Det, _mm_shuffle_ps(Det, Det, 1));

    // Calculating the minterms of the third line.
    tt = m128_ror(_L1, 1);
    Va = _mm_mul_ps(tt, Vb);  // V1'�V2"
    Vb = _mm_mul_ps(tt, Vc);  // V1'�V2^
    Vc = _mm_mul_ps(tt, _L2); // V1'�V2

    r1 = _mm_sub_ps(m128_ror(Va, 1), m128_ror(Vc, 2)); // V1"�V2^ - V1^�V2"
    r2 = _mm_sub_ps(m128_ror(Vb, 2), m128_ror(Vb, 0)); // V1^�V2' - V1'�V2^
    r3 = _mm_sub_ps(m128_ror(Va, 0), m128_ror(Vc, 1)); // V1'�V2" - V1"�V2'

    tt = m128_ror(_L4, 1);
    sum = _mm_mul_ps(tt, r1);
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r2));
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r3));
    __m128 mtL3 = _mm_xor_ps(sum, Sign_PNPN);

    // Dividing is FASTER than rcp_nr! (Because rcp_nr causes many register-memory RWs).
    RDet = _mm_div_ss(_mm_load_ss((float *)&X1_YZ0_W1), Det);
    RDet = _mm_shuffle_ps(RDet, RDet, 0x00);

    // Devide the first 12 minterms with the determinant.
    mtL1 = _mm_mul_ps(mtL1, RDet);
    mtL2 = _mm_mul_ps(mtL2, RDet);
    mtL3 = _mm_mul_ps(mtL3, RDet);

    // Calculate the minterms of the forth line and devide by the determinant.
    tt = m128_ror(_L3, 1);
    sum = _mm_mul_ps(tt, r1);
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r2));
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r3));
    __m128 mtL4 = _mm_xor_ps(sum, Sign_NPNP);
    mtL4 = _mm_mul_ps(mtL4, RDet);

    // Now we just have to transpose the minterms matrix.
    trns0 = _mm_unpacklo_ps(mtL1, mtL2);
    trns1 = _mm_unpacklo_ps(mtL3, mtL4);
    trns2 = _mm_unpackhi_ps(mtL1, mtL2);
    trns3 = _mm_unpackhi_ps(mtL3, mtL4);
    _L1 = _mm_movelh_ps(trns0, trns1);
    _L2 = _mm_movehl_ps(trns1, trns0);
    _L3 = _mm_movelh_ps(trns2, trns3);
    _L4 = _mm_movehl_ps(trns3, trns2);

    return mat4_new(vec4_from_m128(_L1), vec4_from_m128(_L2), vec4_from_m128(_L3), vec4_from_m128(_L4));
}


__forceinline float mat4_determinant(mat4 mat)
{
    __m128 Va, Vb, Vc;
    __m128 r1, r2, r3, tt, tt2;
    __m128 sum, det;

    __m128 _L1 = mat.col0.m128;
    __m128 _L2 = mat.col1.m128;
    __m128 _L3 = mat.col2.m128;
    __m128 _L4 = mat.col3.m128;
    // Calculating the minterms for the first line.

    // sseRor is just a macro using _mm_shuffle_ps().
    tt = _L4;
    tt2 = m128_ror(_L3, 1);
    Vc = _mm_mul_ps(tt2, m128_ror(tt, 0)); // V3'�V4
    Va = _mm_mul_ps(tt2, m128_ror(tt, 2)); // V3'�V4"
    Vb = _mm_mul_ps(tt2, m128_ror(tt, 3)); // V3'�V4^

    r1 = _mm_sub_ps(m128_ror(Va, 1), m128_ror(Vc, 2)); // V3"�V4^ - V3^�V4"
    r2 = _mm_sub_ps(m128_ror(Vb, 2), m128_ror(Vb, 0)); // V3^�V4' - V3'�V4^
    r3 = _mm_sub_ps(m128_ror(Va, 0), m128_ror(Vc, 1)); // V3'�V4" - V3"�V4'

    tt = _L2;
    Va = m128_ror(tt, 1);
    sum = _mm_mul_ps(Va, r1);
    Vb = m128_ror(tt, 2);
    sum = _mm_add_ps(sum, _mm_mul_ps(Vb, r2));
    Vc = m128_ror(tt, 3);
    sum = _mm_add_ps(sum, _mm_mul_ps(Vc, r3));

    // Calculating the determinant.
    det = _mm_mul_ps(sum, _L1);
    det = _mm_add_ps(det, _mm_movehl_ps(det, det));

    // Calculating the minterms of the second line (using previous results).
    tt = m128_ror(_L1, 1);
    sum = _mm_mul_ps(tt, r1);
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r2));
    tt = m128_ror(tt, 1);
    sum = _mm_add_ps(sum, _mm_mul_ps(tt, r3));

    // Testing the determinant.
    det = _mm_sub_ss(det, _mm_shuffle_ps(det, det, 1));
    return vec4_from_m128(det).x;
}


__forceinline mat4 mat4_identity(void)
{
    return mat4_new(
        vec4_new(1, 0, 0, 0),
        vec4_new(0, 1, 0, 0),
        vec4_new(0, 0, 1, 0),
        vec4_new(0, 0, 0, 1)
    );
}


__forceinline mat4 mat4_ortho_rh(float left, float right, float bottom, float top, float z_near, float z_far)
{
    const __m128 zero           = _mm_set_ps1(0.0f);
    const __m128 l              = _mm_set_ps1(left);
    const __m128 f              = _mm_set_ps1(z_far);
    const __m128 r              = _mm_set_ps1(right);
    const __m128 n              = _mm_set_ps1(z_near);
    const __m128 b              = _mm_set_ps1(bottom);
    const __m128 t              = _mm_set_ps1(top);
    const __m128 lbn            = m128_merge_hi(m128_merge_hi(l, n), b);
    const __m128 rtf            = m128_merge_hi(m128_merge_hi(r, f), t);
    const __m128 diff           = _mm_sub_ps(rtf, lbn);
    const __m128 inv_diff       = _mm_rcp_ps(diff);
    const __m128 neg_inv_diff   = m128_negatef(inv_diff);
    
    const __m128 select_x       = _mm_castsi128_ps(_mm_setr_epi32(0xFFFFFFFF, 0, 0, 0));
    const __m128 select_y       = _mm_castsi128_ps(_mm_setr_epi32(0, 0xFFFFFFFF, 0, 0));
    const __m128 select_z       = _mm_castsi128_ps(_mm_setr_epi32(0, 0, 0xFFFFFFFF, 0));
    const __m128 select_w       = _mm_castsi128_ps(_mm_setr_epi32(0, 0, 0, 0xFFFFFFFF));

    const __m128 sum            = _mm_add_ps(rtf, m128_select(lbn, _mm_sub_ps(n, f), select_z));
    const __m128 diagonal       = _mm_add_ps(inv_diff, m128_select(inv_diff, zero, select_z));
    const __m128 column         = _mm_mul_ps(sum, neg_inv_diff);

    return mat4_new(
        vec4_from_m128(m128_select(zero, diagonal, select_x)),
        vec4_from_m128(m128_select(zero, diagonal, select_y)),
        vec4_from_m128(m128_select(zero, diagonal, select_z)),
        vec4_from_m128(m128_select(column, _mm_set1_ps(1.0f), select_w))
    );
}


__deprecated("mat4_frustum_rh")
__forceinline mat4 mat4_ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
    return mat4_ortho_rh(left, right, bottom, top, z_near, z_far);
}


__forceinline mat4 mat4_frustum_rh(float left, float right, float bottom, float top, float z_near, float z_far)
{
    const __m128 zero       = _mm_setzero_ps();

    const __m128 l          = _mm_set_ps(left, 0.0f, 0.0f, 0.0f);
    const __m128 f          = _mm_set_ps(z_far, 0.0f, 0.0f, 0.0f);
    const __m128 r          = _mm_set_ps(right, 0.0f, 0.0f, 0.0f);
    const __m128 n          = _mm_set_ps(z_near, 0.0f, 0.0f, 0.0f);
    const __m128 b          = _mm_set_ps(bottom, 0.0f, 0.0f, 0.0f);
    const __m128 t          = _mm_set_ps(top, 0.0f, 0.0f, 0.0f);

    const __m128 lbf        = m128_merge_hi(m128_merge_hi(l, f), b);
    const __m128 rtn        = m128_merge_hi(m128_merge_hi(r, n), t);
    const __m128 diff       = _mm_sub_ps(rtn, lbf);
    const __m128 sum        = _mm_add_ps(rtn, lbf);
    const __m128 inv_diff   = _mm_rcp_ps(diff);
    const __m128 near2      = _mm_add_ps(m128_splat(n, 0), m128_splat(n, 0));
    const __m128 diagonal   = _mm_mul_ps(near2, inv_diff);
    const __m128 column     = _mm_mul_ps(sum, inv_diff);

    const __m128 select_x   = _mm_castsi128_ps(_mm_setr_epi32(0xFFFFFFFF, 0, 0, 0));
    const __m128 select_y   = _mm_castsi128_ps(_mm_setr_epi32(0, 0xFFFFFFFF, 0, 0));
    const __m128 select_z   = _mm_castsi128_ps(_mm_setr_epi32(0, 0, 0xFFFFFFFF, 0));
    const __m128 select_w   = _mm_castsi128_ps(_mm_setr_epi32(0, 0, 0, 0xFFFFFFFF));

    return mat4_new(
        vec4_from_m128(m128_select(zero, diagonal, select_x)),
        vec4_from_m128(m128_select(zero, diagonal, select_y)),
        vec4_from_m128(m128_select(column, _mm_set1_ps(-1.0f), select_w)),
        vec4_from_m128(m128_select(zero, _mm_mul_ps(diagonal, m128_splat(f, 0)), select_z))
    );
}


__deprecated("mat4_frustum_rh")
__forceinline mat4 mat4_frustum(float left, float right, float bottom, float top, float z_near, float z_far)
{
    return mat4_frustum_rh(left, right, bottom, top, z_near, z_far);
}


__forceinline mat4 mat4_perspective_rh(float fov_radians, float aspect, float z_near, float z_far)
{
    const float zoom_x = 1.0f / tanf(fov_radians * 0.5f);
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


__deprecated("mat4_perspective_rh")
__forceinline mat4 mat4_perspective(float fov_radians, float aspect, float z_near, float z_far)
{
    return mat4_perspective_rh(fov_radians, aspect, z_near, z_far);
}


__forceinline mat4 mat4_lookat_rh(vec3 eye, vec3 target, vec3 up)
{
    const vec3 z = vec3_normalize(vec3_sub(eye, target));
    const vec3 x = vec3_normalize(vec3_cross(up, z));
    const vec3 y = vec3_normalize(vec3_cross(z, x));

    mat4 result;
    result.col0 = vec4_new(              x.x,               y.x,               z.x, 0.0f);
    result.col1 = vec4_new(              x.y,               y.y,               z.y, 0.0f);
    result.col2 = vec4_new(              x.z,               y.z,               z.z, 0.0f);
    result.col3 = vec4_new(-vec3_dot(x, eye), -vec3_dot(y, eye), -vec3_dot(z, eye), 1.0f);
    return result;
}


__deprecated("mat4_lookat_rh")
__forceinline mat4 mat4_lookat(vec3 eye, vec3 target, vec3 up)
{
    return mat4_lookat_rh(eye, target, up);
}


__forceinline mat4 mat4_scalation(float x, float y, float z)
{
    return mat4_new(
        vec4_new(x, 0, 0, 0),
        vec4_new(0, y, 0, 0),
        vec4_new(0, 0, z, 0),
        vec4_new(0, 0, 0, 1)
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
    return mat4_new(
        vec4_new(1, 0, 0, 0),
        vec4_new(0, 1, 0, 0),
        vec4_new(0, 0, 1, 0),
        vec4_new(x, y, z, 1)
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


__forceinline mat4 mat4_rotation(float x, float y, float z, float angle)
{
    const float c = cosf(-angle);
    const float s = sinf(-angle);
    const float t = 1.0f - c;

    mat4 result;
    /* Col 1 */
    result.col0 = vec4_new(
        t * x * x + c,
        t * x * y - s * z,
        t * x * z + s * y,
        0.0f);

    /* Col 2 */
    result.col1 = vec4_new(
        t * x * y + s * z,
        t * y * y + c,
        t * y * z - s * x,
        0.0f);

    /* Col 3 */
    result.col2 = vec4_new(
        t * x * z - s * y,
        t * y * z + s * x,
        t * z * z + c,
        0.0f);

    /* Col 4 */
    result.col3 = vec4_new(0, 0, 0, 1.0f);
    return result;
}


__forceinline mat4 mat4_rotation_axis_angle(vec3 axis, float angle)
{
    return mat4_rotation(axis.x, axis.y, axis.z, angle);
}


__forceinline mat4 mat4_rotation_x(float angle)
{
    const float s = sinf(angle);
    const float c = cosf(angle);

    return mat4_new(
        vec4_new(1,  0, 0, 0),
        vec4_new(0,  c, s, 0),
        vec4_new(0, -s, c, 0),
        vec4_new(0,  0, 0, 1)
    );
}


__forceinline mat4 mat4_rotation_y(float angle)
{
    const float s = sinf(angle);
    const float c = cosf(angle);

    return mat4_new(
        vec4_new( c, 0, s, 0),
        vec4_new( 0, 1, 0, 0),
        vec4_new(-s, 0, c, 0),
        vec4_new( 0, 0, 0, 1)
    );
}


__forceinline mat4 mat4_rotation_z(float angle)
{
    const float s = sinf(angle);
    const float c = cosf(angle);

    return mat4_new(
        vec4_new( c, s, 0, 0),
        vec4_new(-s, c, 0, 0),
        vec4_new( 0, 0, 1, 0),
        vec4_new( 0, 0, 0, 1)
    );
}


__forceinline mat4 mat4_rotation_quat(vec4 quaternion)
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
__forceinline mat4 mat4_transform3(vec3 position, vec4 quat, vec3 scale)
{
    const mat4 translation  = mat4_translation_vec3(position);
    const mat4 rotation     = mat4_rotation_quat(quat);
    const mat4 scalation    = mat4_scalation_vec3(scale);
    return mat4_mul(mat4_mul(translation, rotation), scalation);
}


__forceinline void mat4_decompose(mat4 m, vec3* scalation, vec4* quaternion, vec3* translation)
{
    if (translation)
    {
        *translation = vec3_from_m128(m.col3.m128);
    }

    if (!scalation && !quaternion)
    {
        return;
    }

    vec3 xaxis = vec3_from_m128(m.col0.m128);
    vec3 yaxis = vec3_from_m128(m.col1.m128);
    vec3 zaxis = vec3_from_m128(m.col2.m128);

    const float n11 = m.m00, n12 = m.m10, n13 = m.m20, n14 = m.m30;
    const float n21 = m.m01, n22 = m.m11, n23 = m.m21, n24 = m.m31;
    const float n31 = m.m02, n32 = m.m12, n33 = m.m22, n34 = m.m32;
    const float n41 = m.m03, n42 = m.m13, n43 = m.m23, n44 = m.m33;

    const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
    const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
    const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
    const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

    const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;

    const float scale_x = vec3_length(xaxis);
    const float scale_y = vec3_length(yaxis);
    const float scale_z = float_sign(det) * vec3_length(zaxis);

    if (scalation)
    {
        *scalation = vec3_new(scale_x, scale_y, scale_z);
    }

    if (!quaternion)
    {
        return;
    }

    // Factor the scale out of the matrix axes.
    xaxis = vec3_mul1(xaxis, 1.0f / scale_x);
    yaxis = vec3_mul1(yaxis, 1.0f / scale_y);
    zaxis = vec3_mul1(zaxis, 1.0f / scale_z);

    // Now calculate the rotation from the resulting matrix (axes).
    const float trace = xaxis.x + yaxis.y + zaxis.z + 1.0f;
    if (trace > 0.0001f)
    {
        const float s = 0.5f / sqrtf(trace);
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
            const float s = 0.5f / sqrtf(1.0f + xaxis.x - yaxis.y - zaxis.z);
            quaternion->w = (yaxis.z - zaxis.y) * s;
            quaternion->x = 0.25f / s;
            quaternion->y = (yaxis.x + xaxis.y) * s;
            quaternion->z = (zaxis.x + xaxis.z) * s;
        }
        else if (yaxis.y > zaxis.z)
        {
            const float s = 0.5f / sqrtf(1.0f + yaxis.y - xaxis.x - zaxis.z);
            quaternion->w = (zaxis.x - xaxis.z) * s;
            quaternion->x = (yaxis.x + xaxis.y) * s;
            quaternion->y = 0.25f / s;
            quaternion->z = (zaxis.y + yaxis.z) * s;
        }
        else
        {
            const float s = 0.5f / sqrtf(1.0f + zaxis.z - xaxis.x - yaxis.y);
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
        vec4 quat;
        mat4_decompose(m, scalation, &quat, translation);

        quat_to_axis_angle_ref(quat, axis, angle);
    }
    else
    {
        mat4_decompose(m, scalation, (vec4*)0, translation);
    }
}


//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
