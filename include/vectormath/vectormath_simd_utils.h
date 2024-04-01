#pragma once

#include "vectormath_types.h"

// Make sure m128 is enable
#if !VECTORMATH_SIMD_ENABLE && !VECTORMATH_USE_CLANG_EXT
#error The vectormath support for simd is not enable, please use vector_math_scalar.h instead
#endif

// -------------------------------------------------------------
// Helper constants
// -------------------------------------------------------------

// Small epsilon value
constexpr float SIMD_SLERP_TOL  = 0.999f;

// Common constants used to evaluate simdSinf/cosf4/tanf4
constexpr float SIMD_SINCOS_CC0 = -0.0013602249f;
constexpr float SIMD_SINCOS_CC1 =  0.0416566950f;
constexpr float SIMD_SINCOS_CC2 = -0.4999990225f;
constexpr float SIMD_SINCOS_SC0 = -0.0001950727f;
constexpr float SIMD_SINCOS_SC1 =  0.0083320758f;
constexpr float SIMD_SINCOS_SC2 = -0.1666665247f;
constexpr float SIMD_SINCOS_KC1 =  1.57079625129f;
constexpr float SIMD_SINCOS_KC2 =  7.54978995489e-8f;


// Shorthand functions to get the unit vectors as __m128
__forceinline __m128 m128_unit_1000(void) { return _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f); }
__forceinline __m128 m128_unit_0100(void) { return _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f); }
__forceinline __m128 m128_unit_0010(void) { return _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f); }
__forceinline __m128 m128_unit_0001(void) { return _mm_setr_ps(0.0f, 0.0f, 0.0f, 1.0f); }


// ========================================================
// Internal helper types and functions
// ========================================================


// These have to be macros because _MM_SHUFFLE() requires compile-time constants.
#define m128_ror(vec, i)       (((i) % 4) ? (_mm_shuffle_ps(vec, vec, _MM_SHUFFLE((uint32_t)(i + 3) % 4, (uint32_t)(i + 2) % 4, (uint32_t)(i + 1) % 4, (uint32_t)(i + 0) % 4))) : (vec))
#define m128_splat(x, e)       _mm_shuffle_ps(x, x, _MM_SHUFFLE(e, e, e, e))
#define m128_sld(vec, vec2, x) m128_ror(vec, ((x) / 4))


__forceinline __m128 m128_mul_add(__m128 a, __m128 b, __m128 c)
{
    return _mm_add_ps(c, _mm_mul_ps(a, b));
}


__forceinline __m128 m128_mul_sub(__m128 a, __m128 b, __m128 c)
{
    return _mm_sub_ps(c, _mm_mul_ps(a, b));
}


__forceinline __m128 m128_merge_hi(__m128 a, __m128 b)
{
    return _mm_unpacklo_ps(a, b);
}


__forceinline __m128 m128_merge_lo(__m128 a, __m128 b)
{
    return _mm_unpackhi_ps(a, b);
}


__forceinline __m128 m128_select(__m128 a, __m128 b, __m128 mask)
{
    return _mm_or_ps(_mm_and_ps(mask, b), _mm_andnot_ps(mask, a));
}


__forceinline __m128 m128_negatef(__m128 x)
{
    return _mm_sub_ps(_mm_setzero_ps(), x);
}


__forceinline __m128 m128_fabsf(__m128 x)
{
    return _mm_and_ps(x, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
    //return _mm_andnot_ps(x, _mm_castsi128_ps(_mm_set1_epi32(0x80000000)));
}


__forceinline __m128 m128_acosf(__m128 x)
{
    const __m128 xabs   = m128_fabsf(x);
    const __m128 select = _mm_cmplt_ps(x, _mm_setzero_ps());
    const __m128 t1     = _mm_sqrt_ps(_mm_sub_ps(_mm_set1_ps(1.0f), xabs));

    /* Instruction counts can be reduced if the polynomial was
     * computed entirely from nested (dependent) fma's. However,
     * to reduce the number of pipeline stalls, the polygon is evaluated
     * in two halves (hi and lo).
     */
    const __m128 xabs2 = _mm_mul_ps(xabs, xabs);
    const __m128 xabs4 = _mm_mul_ps(xabs2, xabs2);

    const __m128 hi = m128_mul_add(m128_mul_add(m128_mul_add(_mm_set1_ps(-0.0012624911f),
        xabs, _mm_set1_ps( 0.0066700901f)),
        xabs, _mm_set1_ps(-0.0170881256f)),
        xabs, _mm_set1_ps( 0.0308918810f));

    const __m128 lo = m128_mul_add(m128_mul_add(m128_mul_add(_mm_set1_ps(-0.0501743046f),
        xabs, _mm_set1_ps( 0.0889789874f)),
        xabs, _mm_set1_ps(-0.2145988016f)),
        xabs, _mm_set1_ps( 1.5707963050f));

    const __m128 result = m128_mul_add(hi, xabs4, lo);

    // Adjust the result if x is negative.
    return m128_select(
        _mm_mul_ps(t1, result),                                     // Positive
        m128_mul_sub(t1, result, _mm_set1_ps(3.1415926535898f)),    // Negative
        select
    );
}


/// Compute cosf for SIMD 128
__forceinline __m128 m128_cosf(__m128 x)
{
    // Range reduction
    // Find the quadrant the angle falls in
    // Algo:
    //      xl = angle * TwoOverPi; 
    //      q = (int32_t)(ceil(abs(xl)) * sign(xl))
    const __m128i q = _mm_cvtps_epi32(_mm_mul_ps(x, _mm_set1_ps(0.63661977236f)));

    // Compute the offset based on the quadrant that the angle falls in.
    // Add 1 to the offset for the cosine.
    const __m128i offset_sin = _mm_and_si128(q, _mm_set1_epi32(0x3));
    const __m128i offset_cos = _mm_add_epi32(_mm_set1_epi32(1), offset_sin);

    // Remainder in range [-pi/4..pi/4]
    const __m128 qf = _mm_cvtepi32_ps(q);
    const __m128 xl = m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC2), m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC1), x));

    // Compute x^2 and x^3
    const __m128 xl2 = _mm_mul_ps(xl, xl);
    const __m128 xl3 = _mm_mul_ps(xl2, xl);

    // Compute both the sin and cos of the angles
    // using a polynomial expression:
    //      cx = 1.0f + xl2 * ((C0 * xl2 + C1) * xl2 + C2)
    //      sx =   xl + xl3 * ((S0 * xl2 + S1) * xl2 + S2)
    const __m128 cx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_CC0), xl2, _mm_set1_ps(SIMD_SINCOS_CC1)), xl2, _mm_set1_ps(SIMD_SINCOS_CC2)),
            xl2, _mm_set1_ps(1.0f));

    const __m128 sx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_SC0), xl2, _mm_set1_ps(SIMD_SINCOS_SC1)), xl2, _mm_set1_ps(SIMD_SINCOS_SC2)),
            xl3, xl);

    // Use the cosine when the offset is odd and the sin
    // when the offset is even
    __m128 cos_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_cos, _mm_set1_epi32(0x1)), _mm_setzero_si128()));

    __m128 cos = m128_select(cx, sx, cos_mask);

    // Flip the sign of the result when (offset mod 4) = 1 or 2
    cos_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_cos, _mm_set1_epi32(0x2)), _mm_setzero_si128()));

    // Write the result
    return m128_select(_mm_xor_ps(_mm_castsi128_ps(_mm_set1_epi32(0x80000000)), cos), cos, cos_mask);    
}


/// Compute sinf for SIMD 128
__forceinline __m128 m128_sinf(__m128 x)
{
    // Range reduction
    // Find the quadrant the angle falls in
    // Algo:
    //      xl = angle * TwoOverPi; 
    //      q = (int32_t)(ceil(abs(xl)) * sign(xl))
    const __m128i q = _mm_cvtps_epi32(_mm_mul_ps(x, _mm_set1_ps(0.63661977236f)));

    // Compute the offset based on the quadrant that the angle falls in.
    // Add 1 to the offset for the cosine.
    const __m128i offset_sin = _mm_and_si128(q, _mm_set1_epi32(0x3));

    // Remainder in range [-pi/4..pi/4]
    const __m128 qf = _mm_cvtepi32_ps(q);
    const __m128 xl = m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC2), m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC1), x));

    // Compute x^2 and x^3
    const __m128 xl2 = _mm_mul_ps(xl, xl);
    const __m128 xl3 = _mm_mul_ps(xl2, xl);

    // Compute both the sin and cos of the angles
    // using a polynomial expression:
    //      cx = 1.0f + xl2 * ((C0 * xl2 + C1) * xl2 + C2)
    //      sx =   xl + xl3 * ((S0 * xl2 + S1) * xl2 + S2)
    const __m128 cx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_CC0), xl2, _mm_set1_ps(SIMD_SINCOS_CC1)), xl2, _mm_set1_ps(SIMD_SINCOS_CC2)),
            xl2, _mm_set1_ps(1.0f));

    const __m128 sx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_SC0), xl2, _mm_set1_ps(SIMD_SINCOS_SC1)), xl2, _mm_set1_ps(SIMD_SINCOS_SC2)),
            xl3, xl);

    // Use the cosine when the offset is odd and the sin
    // when the offset is even
    __m128 sin_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_sin, _mm_set1_epi32(0x1)), _mm_setzero_si128()));

    __m128 sin = m128_select(cx, sx, sin_mask);

    // Flip the sign of the result when (offset mod 4) = 1 or 2
    sin_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_sin, _mm_set1_epi32(0x2)), _mm_setzero_si128()));

    // Write the result
    return m128_select(_mm_xor_ps(_mm_castsi128_ps(_mm_set1_epi32(0x80000000)), sin), sin, sin_mask);
}


/// Compute cosf and sinf for SIMD 128 in one function call
__forceinline void m128_sinf_cosf(__m128 x, __m128* out_sin, __m128* out_cos)
{
    // Range reduction
    // Find the quadrant the angle falls in
    // Algo:
    //      xl = angle * TwoOverPi; 
    //      q = (int32_t)(ceil(abs(xl)) * sign(xl))
    const __m128i q = _mm_cvtps_epi32(_mm_mul_ps(x, _mm_set1_ps(0.63661977236f)));

    // Compute the offset based on the quadrant that the angle falls in.
    // Add 1 to the offset for the cosine.
    const __m128i offset_sin = _mm_and_si128(q, _mm_set1_epi32(0x3));
    const __m128i offset_cos = _mm_add_epi32(_mm_set1_epi32(1), offset_sin);

    // Remainder in range [-pi/4..pi/4]
    const __m128 qf = _mm_cvtepi32_ps(q);
    const __m128 xl = m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC2), m128_mul_sub(qf, _mm_set1_ps(SIMD_SINCOS_KC1), x));

    // Compute x^2 and x^3
    const __m128 xl2 = _mm_mul_ps(xl, xl);
    const __m128 xl3 = _mm_mul_ps(xl2, xl);

    // Compute both the sin and cos of the angles
    // using a polynomial expression:
    //      cx = 1.0f + xl2 * ((C0 * xl2 + C1) * xl2 + C2)
    //      sx =   xl + xl3 * ((S0 * xl2 + S1) * xl2 + S2)
    const __m128 cx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_CC0), xl2, _mm_set1_ps(SIMD_SINCOS_CC1)), xl2, _mm_set1_ps(SIMD_SINCOS_CC2)),
            xl2, _mm_set1_ps(1.0f));

    const __m128 sx =
        m128_mul_add(
            m128_mul_add(
                m128_mul_add(_mm_set1_ps(SIMD_SINCOS_SC0), xl2, _mm_set1_ps(SIMD_SINCOS_SC1)), xl2, _mm_set1_ps(SIMD_SINCOS_SC2)),
            xl3, xl);

    // Use the cosine when the offset is odd and the sin
    // when the offset is even
    __m128 sin_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_sin, _mm_set1_epi32(0x1)), _mm_setzero_si128()));
    __m128 cos_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_cos, _mm_set1_epi32(0x1)), _mm_setzero_si128()));

    __m128 sin = m128_select(cx, sx, sin_mask);
    __m128 cos = m128_select(cx, sx, cos_mask);

    // Flip the sign of the result when (offset mod 4) = 1 or 2
    sin_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_sin, _mm_set1_epi32(0x2)), _mm_setzero_si128()));
    cos_mask = _mm_castsi128_ps(_mm_cmpeq_epi32(_mm_and_si128(offset_cos, _mm_set1_epi32(0x2)), _mm_setzero_si128()));

    // Write the result
    *out_sin = m128_select(_mm_xor_ps(_mm_castsi128_ps(_mm_set1_epi32(0x80000000)), sin), sin, sin_mask);
    *out_cos = m128_select(_mm_xor_ps(_mm_castsi128_ps(_mm_set1_epi32(0x80000000)), cos), cos, cos_mask);
}

//! EOF

