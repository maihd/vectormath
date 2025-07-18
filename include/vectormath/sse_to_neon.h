#pragma once

// Require CPU support neon
#if !defined(VECTORMATH_NEON_SUPPORT) || !VECTORMATH_NEON_SUPPORT
#error Your platform is not supporting Neon instructions set
#endif

#include <stdint.h>
#include <arm_neon.h>

// -------------------------------------------------------------
// SSE2NEON
// -------------------------------------------------------------

// Provides a simple API translation layer
// between SSE intrinsics to their corresponding ARM NEON versions
//
// Based on project:
//	https://github.com/jratcliff63367/sse2neon
//

/*******************************************************/
/* MACRO for shuffle parameter for _mm_shuffle_ps().   */
/* Argument fp3 is a digit[0123] that represents the fp*/
/* from argument "b" of mm_shuffle_ps that will be     */
/* placed in fp3 of result. fp2 is the same for fp2 in */
/* result. fp1 is a digit[0123] that represents the fp */
/* from argument "a" of mm_shuffle_ps that will be     */
/* places in fp1 of result. fp0 is the same for fp0 of */
/* result                                              */
/*******************************************************/
#define _MM_SHUFFLE(fp3,fp2,fp1,fp0) \
	(((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | ((fp0)))

/* indicate immediate constant argument in a given range */
#define __constrange(a,b) \
	const

// Use __forceinline for shorthand functions
#if !defined(_MSC_VER) && !defined(__forceinline)
#   if defined(__GNUC__)
#       define __forceinline    static __attribute__((always_inline))
#   elif defined(__cplusplus)
#       define __forceinline    static inline
#   else
#       define __forceinline    inline
#   endif
#endif

typedef float32x2_t __m64;
typedef float32x4_t __m128;
typedef int32x4_t   __m128i;
typedef uint32x4_t  __m128u;

// ******************************************
// type-safe casting between types
// ******************************************

#define vreinterpretq_m128_f16(x) \
	vreinterpretq_f32_f16(x)

#define vreinterpretq_m128_f32(x) \
	(x)

#define vreinterpretq_m128_f64(x) \
	vreinterpretq_f32_f64(x)


#define vreinterpretq_m128_u8(x) \
	vreinterpretq_f32_u8(x)

#define vreinterpretq_m128_u16(x) \
	vreinterpretq_f32_u16(x)

#define vreinterpretq_m128_u32(x) \
	vreinterpretq_f32_u32(x)

#define vreinterpretq_m128_u64(x) \
	vreinterpretq_f32_u64(x)


#define vreinterpretq_m128_s8(x) \
	vreinterpretq_f32_s8(x)

#define vreinterpretq_m128_s16(x) \
	vreinterpretq_f32_s16(x)

#define vreinterpretq_m128_s32(x) \
	vreinterpretq_f32_s32(x)

#define vreinterpretq_m128_s64(x) \
	vreinterpretq_f32_s64(x)


#define vreinterpretq_f16_m128(x) \
	vreinterpretq_f16_f32(x)

#define vreinterpretq_f32_m128(x) \
	(x)

#define vreinterpretq_f64_m128(x) \
	vreinterpretq_f64_f32(x)


#define vreinterpretq_u8_m128(x) \
	vreinterpretq_u8_f32(x)

#define vreinterpretq_u16_m128(x) \
	vreinterpretq_u16_f32(x)

#define vreinterpretq_u32_m128(x) \
	vreinterpretq_u32_f32(x)

#define vreinterpretq_u64_m128(x) \
	vreinterpretq_u64_f32(x)


#define vreinterpretq_s8_m128(x) \
	vreinterpretq_s8_f32(x)

#define vreinterpretq_s16_m128(x) \
	vreinterpretq_s16_f32(x)

#define vreinterpretq_s32_m128(x) \
	vreinterpretq_s32_f32(x)

#define vreinterpretq_s64_m128(x) \
	vreinterpretq_s64_f32(x)


#define vreinterpretq_m128i_s8(x) \
	vreinterpretq_s32_s8(x)

#define vreinterpretq_m128i_s16(x) \
	vreinterpretq_s32_s16(x)

#define vreinterpretq_m128i_s32(x) \
	(x)

#define vreinterpretq_m128i_s64(x) \
	vreinterpretq_s32_s64(x)


#define vreinterpretq_m128i_u8(x) \
	vreinterpretq_s32_u8(x)

#define vreinterpretq_m128i_u16(x) \
	vreinterpretq_s32_u16(x)

#define vreinterpretq_m128i_u32(x) \
	vreinterpretq_s32_u32(x)

#define vreinterpretq_m128i_u64(x) \
	vreinterpretq_s32_u64(x)


#define vreinterpretq_s8_m128i(x) \
	vreinterpretq_s8_s32(x)

#define vreinterpretq_s16_m128i(x) \
	vreinterpretq_s16_s32(x)

#define vreinterpretq_s32_m128i(x) \
	(x)

#define vreinterpretq_s64_m128i(x) \
	vreinterpretq_s64_s32(x)


#define vreinterpretq_u8_m128i(x) \
	vreinterpretq_u8_s32(x)

#define vreinterpretq_u16_m128i(x) \
	vreinterpretq_u16_s32(x)

#define vreinterpretq_u32_m128i(x) \
	vreinterpretq_u32_s32(x)

#define vreinterpretq_u64_m128i(x) \
	vreinterpretq_u64_s32(x)

/// union intended to allow direct access to an __m128 variable using the names that the MSVC
/// compiler provides.  This union should really only be used when trying to access the members
/// of the vector as integer values.  GCC/clang allow native access to the float members through
/// a simple array access operator (in C since 4.6, in C++ since 4.8).
///
/// Ideally direct accesses to SIMD vectors should not be used since it can cause a performance
/// hit.  If it really is needed however, the original __m128 variable can be aliased with a
/// pointer to this union and used to access individual components.  The use of this union should
/// be hidden behind a macro that is used throughout the codebase to access the members instead
/// of always declaring this type of variable.
typedef union __attribute__((aligned(16))) SIMDVec
{
    float       m128_f32[4];    // as floats - do not to use this.  Added for convenience.
    int8_t      m128_i8[16];    // as signed 8-bit integers.
    int16_t     m128_i16[8];    // as signed 16-bit integers.
    int32_t     m128_i32[4];    // as signed 32-bit integers.
    int64_t     m128_i64[2];    // as signed 64-bit integers.
    uint8_t     m128_u8[16];    // as unsigned 8-bit integers.
    uint16_t    m128_u16[8];    // as unsigned 16-bit integers.
    uint32_t    m128_u32[4];    // as unsigned 32-bit integers.
    uint64_t    m128_u64[2];    // as unsigned 64-bit integers.
} SIMDVec;


// -------------------------------------------------------------
// Set/get methods
// -------------------------------------------------------------

/// extracts the lower order floating point value from the parameter.
/// https://msdn.microsoft.com/en-us/library/bb514059%28v=vs.120%29.aspx?f=255&MSPPError=-2147217396
__forceinline float _mm_cvtss_f32(__m128 a)
{
    return vgetq_lane_f32(vreinterpretq_f32_m128(a), 0);
}

/// Sets the 128-bit value to zero.
/// https://msdn.microsoft.com/en-us/library/vstudio/ys7dw0kh(v=vs.100).aspx
__forceinline __m128i _mm_setzero_si128()
{
    return vreinterpretq_m128i_s32(vdupq_n_s32(0));
}

/// Clears the four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/vstudio/tk1t2tbz(v=vs.100).aspx
__forceinline __m128 _mm_setzero_ps(void)
{
    return vreinterpretq_m128_f32(vdupq_n_f32(0));
}

/// Copy single-precision (32-bit) floating-point element a to the lower element of dst, and zero the upper 3 elements.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_set_ss&expand=4901,4895,4901
__forceinline __m128 _mm_set_ss(float a)
{
    float __attribute__((aligned(16))) data[4] = { a, 0, 0, 0 };
    return vreinterpretq_m128_f32(vld1q_f32(data));
}

// Sets the four single-precision, floating-point values to w. https://msdn.microsoft.com/en-us/library/vstudio/2x1se8ha(v=vs.100).aspx
__forceinline __m128 _mm_set1_ps(float _w)
{
    return vreinterpretq_m128_f32(vdupq_n_f32(_w));
}

// Sets the four single-precision, floating-point values to w. https://msdn.microsoft.com/en-us/library/vstudio/2x1se8ha(v=vs.100).aspx
__forceinline __m128 _mm_set_ps1(float _w)
{
    return vreinterpretq_m128_f32(vdupq_n_f32(_w));
}

/// Sets the four single-precision, floating-point values to the four inputs.
/// https://msdn.microsoft.com/en-us/library/vstudio/afh0zf75(v=vs.100).aspx
__forceinline __m128 _mm_set_ps(float w, float z, float y, float x)
{
    float __attribute__((aligned(16))) data[4] = { x, y, z, w };
    return vreinterpretq_m128_f32(vld1q_f32(data));
}

// Sets the four single-precision, floating-point values to the four inputs in reverse order. https://msdn.microsoft.com/en-us/library/vstudio/d2172ct3(v=vs.100).aspx
__forceinline __m128 _mm_setr_ps(float w, float z , float y , float x )
{
    float __attribute__ ((aligned (16))) data[4] = { w, z, y, x };
    return vreinterpretq_m128_f32(vld1q_f32(data));
}

/// Sets the 4 signed 32-bit integer values in reverse order
/// https://technet.microsoft.com/en-us/library/security/27yb3ee5(v=vs.90).aspx
__forceinline __m128i _mm_setr_epi32(int i3, int i2, int i1, int i0)
{
    int32_t __attribute__((aligned(16))) data[4] = { i3, i2, i1, i0 };
    return vreinterpretq_m128i_s32(vld1q_s32(data));
}

/// Sets the 16 signed 8-bit integer values to b.
/// https://msdn.microsoft.com/en-us/library/6e14xhyf(v=vs.100).aspx
__forceinline __m128i _mm_set1_epi8(char w)
{
    return vreinterpretq_m128i_s8(vdupq_n_s8(w));
}

/// Sets the 8 signed 16-bit integer values to w.
/// https://msdn.microsoft.com/en-us/library/k0ya3x0e(v=vs.90).aspx
__forceinline __m128i _mm_set1_epi16(short w)
{
    return vreinterpretq_m128i_s16(vdupq_n_s16(w));
}

/// Sets the 8 signed 16-bit integer values.
/// https://msdn.microsoft.com/en-au/library/3e0fek84(v=vs.90).aspx
__forceinline __m128i _mm_set_epi16(short i7, short i6, short i5, short i4, short i3, short i2, short i1, short i0)
{
    int16_t __attribute__((aligned(16))) data[8] = { i0, i1, i2, i3, i4, i5, i6, i7 };
    return vreinterpretq_m128i_s16(vld1q_s16(data));
}


/// Sets the 4 signed 32-bit integer values to i.
/// https://msdn.microsoft.com/en-us/library/vstudio/h4xscxat(v=vs.100).aspx
__forceinline __m128i _mm_set1_epi32(int _i)
{
    return vreinterpretq_m128i_s32(vdupq_n_s32(_i));
}

/// Sets the 4 signed 32-bit integer values.
/// https://msdn.microsoft.com/en-us/library/vstudio/019beekt(v=vs.100).aspx
__forceinline __m128i _mm_set_epi32(int i3, int i2, int i1, int i0)
{
    int32_t __attribute__((aligned(16))) data[4] = { i0, i1, i2, i3 };
    return vreinterpretq_m128i_s32(vld1q_s32(data));
}

/// Stores four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/vstudio/s3h4ay6y(v=vs.100).aspx
__forceinline void _mm_store_ps(float* p, __m128 a)
{
    vst1q_f32(p, vreinterpretq_f32_m128(a));
}

/// Stores four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/44e30x22(v=vs.100).aspx
__forceinline void _mm_storeu_ps(float* p, __m128 a)
{
    vst1q_f32(p, vreinterpretq_f32_m128(a));
}

/// Stores four 32-bit integer values as (as a __m128i value) at the address p.
/// https://msdn.microsoft.com/en-us/library/vstudio/edk11s13(v=vs.100).aspx
__forceinline void _mm_store_si128(__m128i* p, __m128i a)
{
    vst1q_s32((int32_t*)p, vreinterpretq_s32_m128i(a));
}

/// Stores four 32-bit integer values as (as a __m128i value) at the address p.
/// https://msdn.microsoft.com/en-us/library/vstudio/edk11s13(v=vs.100).aspx
__forceinline void _mm_storeu_si128(__m128i* p, __m128i a)
{
    vst1q_s32((int32_t*)p, vreinterpretq_s32_m128i(a));
}

/// Stores the lower single - precision, floating - point value.
/// https://msdn.microsoft.com/en-us/library/tzz10fbx(v=vs.100).aspx
__forceinline void _mm_store_ss(float* p, __m128 a)
{
    vst1q_lane_f32(p, vreinterpretq_f32_m128(a), 0);
}

/// Reads the lower 64 bits of b and stores them into the lower 64 bits of a.
/// https://msdn.microsoft.com/en-us/library/hhwf428f%28v=vs.90%29.aspx
__forceinline void _mm_storel_epi64(__m128i* a, __m128i b)
{
    uint64x1_t hi = vget_high_u64(vreinterpretq_u64_m128i(*a));
    uint64x1_t lo = vget_low_u64(vreinterpretq_u64_m128i(b));
    *a = vreinterpretq_m128i_u64(vcombine_u64(lo, hi));
}

/// Loads a single single-precision, floating-point value, copying it into all four words
/// https://msdn.microsoft.com/en-us/library/vstudio/5cdkf716(v=vs.100).aspx
__forceinline __m128 _mm_load1_ps(const float* p)
{
    return vreinterpretq_m128_f32(vld1q_dup_f32(p));
}

/// Load 2 single-precision (32-bit) floating-point elements from memory into the lower 2 elements of dst, and copy the upper 2 elements from a to dst. 
__forceinline __m128 _mm_loadl_pi(__m128 a, __m64* p)
{
    float32x2_t lo = vld1_f32((const float*)p);
    float32x2_t hi = vget_high_f32(a);

    return vcombine_f32(lo, hi);
}

/// Load 64-bit integer from memory into the first element of dst.
__forceinline __m128 _mm_loadl_epi64(__m128i const* p) {
    return vcombine_s32(vld1_s32((int32_t const*)p), vcreate_s32(0));
}

/// Load 2 single-precision (32-bit) floating-point elements from memory into the upper 2 elements of dst, and copy the lower 2 elements from a to dst.
__forceinline __m128 _mm_loadh_pi(__m128 a, __m64* p)
{
    float32x2_t hi = vld1_f32((const float*)p);
    float32x2_t lo = vget_low_f32(a);

    return vcombine_f32(lo, hi);
}

/// Loads four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/vstudio/zzd50xxt(v=vs.100).aspx
__forceinline __m128 _mm_load_ps(const float* p)
{
    return vreinterpretq_m128_f32(vld1q_f32(p));
}

/// Loads four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/x1b16s7z%28v=vs.90%29.aspx
__forceinline __m128 _mm_loadu_ps(const float* p)
{
    // for neon, alignment doesn't matter, so _mm_load_ps and _mm_loadu_ps are equivalent for neon
    return vreinterpretq_m128_f32(vld1q_f32(p));
}

/// Loads an single - precision, floating - point value into the low word and clears the upper three words.
/// https://msdn.microsoft.com/en-us/library/548bb9h4%28v=vs.90%29.aspx
__forceinline __m128 _mm_load_ss(const float* p)
{
    return vreinterpretq_m128_f32(vsetq_lane_f32(*p, vdupq_n_f32(0), 0));
}


// -------------------------------------------------------------
// Logic/Binary operations
// -------------------------------------------------------------

/// Compares for inequality.
/// https://msdn.microsoft.com/en-us/library/sf44thbx(v=vs.100).aspx
__forceinline __m128 _mm_cmpneq_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vmvnq_u32(vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b))));
}

/// Computes the bitwise AND-NOT of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/68h7wd02(v=vs.100).aspx
__forceinline __m128 _mm_andnot_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_s32(vbicq_s32(vreinterpretq_s32_m128(b), vreinterpretq_s32_m128(a))); // *NOTE* argument swap
}

/// Computes the bitwise AND of the 128-bit value in b and the bitwise NOT of the 128-bit value in a.
/// https://msdn.microsoft.com/en-us/library/vstudio/1beaceh8(v=vs.100).aspx
__forceinline __m128i _mm_andnot_si128(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vbicq_s32(vreinterpretq_s32_m128i(b), vreinterpretq_s32_m128i(a))); // *NOTE* argument swap
}

/// Computes the bitwise AND of the 128-bit value in a and the 128-bit value in b.
/// https://msdn.microsoft.com/en-us/library/vstudio/6d1txsa8(v=vs.100).aspx
__forceinline __m128i _mm_and_si128(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vandq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Computes the bitwise AND of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/73ck1xc5(v=vs.100).aspx
__forceinline __m128 _mm_and_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_s32(vandq_s32(vreinterpretq_s32_m128(a), vreinterpretq_s32_m128(b)));
}

/// Computes the bitwise OR of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/7ctdsyy0(v=vs.100).aspx
__forceinline __m128 _mm_or_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_s32(vorrq_s32(vreinterpretq_s32_m128(a), vreinterpretq_s32_m128(b)));
}

/// Computes bitwise EXOR (exclusive-or) of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/ss6k3wk8(v=vs.100).aspx
__forceinline __m128 _mm_xor_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_s32(veorq_s32(vreinterpretq_s32_m128(a), vreinterpretq_s32_m128(b)));
}

/// Computes the bitwise OR of the 128-bit value in a and the 128-bit value in b.
/// https://msdn.microsoft.com/en-us/library/vstudio/ew8ty0db(v=vs.100).aspx
__forceinline __m128i _mm_or_si128(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vorrq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Computes the bitwise XOR of the 128-bit value in a and the 128-bit value in b.
/// https://msdn.microsoft.com/en-us/library/fzt08www(v=vs.100).aspx
__forceinline __m128i _mm_xor_si128(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(veorq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// NEON does not provide this method
/// Creates a 4-bit mask from the most significant bits of the four single-precision, floating-point values.
/// https://msdn.microsoft.com/en-us/library/vstudio/4490ys29(v=vs.100).aspx
__forceinline int _mm_movemask_ps(__m128 a)
{
#if ENABLE_CPP_VERSION // I am not yet convinced that the NEON version is faster than the C version of this
    uint32x4_t& ia = *(uint32x4_t*)&a;
    return (ia.row0 >> 31) | ((ia.row1 >> 30) & 2) | ((ia.row2 >> 29) & 4) | ((ia.row3 >> 28) & 8);
#else
    static const uint32x4_t movemask = { 1, 2, 4, 8 };
    static const uint32x4_t highbit = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
    uint32x4_t t0 = vreinterpretq_u32_m128(a);
    uint32x4_t t1 = vtstq_u32(t0, highbit);
    uint32x4_t t2 = vandq_u32(t1, movemask);
    uint32x2_t t3 = vorr_u32(vget_low_u32(t2), vget_high_u32(t2));
    return vget_lane_u32(t3, 0) | vget_lane_u32(t3, 1);
#endif
}

//// Takes the upper 64 bits of a and places it in the low end of the result
//// Takes the lower 64 bits of b and places it into the high end of the result.
__forceinline __m128 _mm_shuffle_ps_1032(__m128 a, __m128 b)
{
    float32x2_t a32 = vget_high_f32(vreinterpretq_f32_m128(a));
    float32x2_t b10 = vget_low_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(a32, b10));
}

//// takes the lower two 32-bit values from a and swaps them and places in high end of result
//// takes the higher two 32 bit values from b and swaps them and places in low end of result.
__forceinline __m128 _mm_shuffle_ps_2301(__m128 a, __m128 b)
{
    float32x2_t a01 = vrev64_f32(vget_low_f32(vreinterpretq_f32_m128(a)));
    float32x2_t b23 = vrev64_f32(vget_high_f32(vreinterpretq_f32_m128(b)));
    return vreinterpretq_m128_f32(vcombine_f32(a01, b23));
}

__forceinline __m128 _mm_shuffle_ps_0321(__m128 a, __m128 b)
{
    float32x2_t a21 = vget_high_f32(vextq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a), 3));
    float32x2_t b03 = vget_low_f32(vextq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b), 3));
    return vreinterpretq_m128_f32(vcombine_f32(a21, b03));
}

__forceinline __m128 _mm_shuffle_ps_2103(__m128 a, __m128 b)
{
    float32x2_t a03 = vget_low_f32(vextq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a), 3));
    float32x2_t b21 = vget_high_f32(vextq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b), 3));
    return vreinterpretq_m128_f32(vcombine_f32(a03, b21));
}

__forceinline __m128 _mm_shuffle_ps_1010(__m128 a, __m128 b)
{
    float32x2_t a10 = vget_low_f32(vreinterpretq_f32_m128(a));
    float32x2_t b10 = vget_low_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(a10, b10));
}

__forceinline __m128 _mm_shuffle_ps_1001(__m128 a, __m128 b)
{
    float32x2_t a01 = vrev64_f32(vget_low_f32(vreinterpretq_f32_m128(a)));
    float32x2_t b10 = vget_low_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(a01, b10));
}

__forceinline __m128 _mm_shuffle_ps_0101(__m128 a, __m128 b)
{
    float32x2_t a01 = vrev64_f32(vget_low_f32(vreinterpretq_f32_m128(a)));
    float32x2_t b01 = vrev64_f32(vget_low_f32(vreinterpretq_f32_m128(b)));
    return vreinterpretq_m128_f32(vcombine_f32(a01, b01));
}

/// keeps the low 64 bits of b in the low and puts the high 64 bits of a in the high
__forceinline __m128 _mm_shuffle_ps_3210(__m128 a, __m128 b)
{
    float32x2_t a10 = vget_low_f32(vreinterpretq_f32_m128(a));
    float32x2_t b32 = vget_high_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(a10, b32));
}

__forceinline __m128 _mm_shuffle_ps_0011(__m128 a, __m128 b)
{
    float32x2_t a11 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(a)), 1);
    float32x2_t b00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 0);
    return vreinterpretq_m128_f32(vcombine_f32(a11, b00));
}

__forceinline __m128 _mm_shuffle_ps_0022(__m128 a, __m128 b)
{
    float32x2_t a22 = vdup_lane_f32(vget_high_f32(vreinterpretq_f32_m128(a)), 0);
    float32x2_t b00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 0);
    return vreinterpretq_m128_f32(vcombine_f32(a22, b00));
}

__forceinline __m128 _mm_shuffle_ps_2200(__m128 a, __m128 b)
{
    float32x2_t a00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(a)), 0);
    float32x2_t b22 = vdup_lane_f32(vget_high_f32(vreinterpretq_f32_m128(b)), 0);
    return vreinterpretq_m128_f32(vcombine_f32(a00, b22));
}

__forceinline __m128 _mm_shuffle_ps_3202(__m128 a, __m128 b)
{
    float32_t a0 = vgetq_lane_f32(vreinterpretq_f32_m128(a), 0);
    float32x2_t a22 = vdup_lane_f32(vget_high_f32(vreinterpretq_f32_m128(a)), 0);
    float32x2_t a02 = vset_lane_f32(a0, a22, 1); /* apoty: TODO: use vzip ?*/
    float32x2_t b32 = vget_high_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(a02, b32));
}

__forceinline __m128 _mm_shuffle_ps_1133(__m128 a, __m128 b)
{
    float32x2_t a33 = vdup_lane_f32(vget_high_f32(vreinterpretq_f32_m128(a)), 1);
    float32x2_t b11 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 1);
    return vreinterpretq_m128_f32(vcombine_f32(a33, b11));
}

__forceinline __m128 _mm_shuffle_ps_2010(__m128 a, __m128 b)
{
    float32x2_t a10 = vget_low_f32(vreinterpretq_f32_m128(a));
    float32_t b2 = vgetq_lane_f32(vreinterpretq_f32_m128(b), 2);
    float32x2_t b00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 0);
    float32x2_t b20 = vset_lane_f32(b2, b00, 1);
    return vreinterpretq_m128_f32(vcombine_f32(a10, b20));
}

__forceinline __m128 _mm_shuffle_ps_2001(__m128 a, __m128 b)
{
    float32x2_t a01 = vrev64_f32(vget_low_f32(vreinterpretq_f32_m128(a)));
    float32_t b2 = vgetq_lane_f32(b, 2);
    float32x2_t b00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 0);
    float32x2_t b20 = vset_lane_f32(b2, b00, 1);
    return vreinterpretq_m128_f32(vcombine_f32(a01, b20));
}

__forceinline __m128 _mm_shuffle_ps_2032(__m128 a, __m128 b)
{
    float32x2_t a32 = vget_high_f32(vreinterpretq_f32_m128(a));
    float32_t b2 = vgetq_lane_f32(b, 2);
    float32x2_t b00 = vdup_lane_f32(vget_low_f32(vreinterpretq_f32_m128(b)), 0);
    float32x2_t b20 = vset_lane_f32(b2, b00, 1);
    return vreinterpretq_m128_f32(vcombine_f32(a32, b20));
}

//// NEON does not support a general purpose permute intrinsic
//// Currently I am not sure whether the C implementation is faster or slower than the NEON version.
//// Note, this has to be expanded as a template because the shuffle value must be an immediate value.
//// The same is true on SSE as well.
//// Selects four specific single-precision, floating-point values from a and b, based on the mask i. https://msdn.microsoft.com/en-us/library/vstudio/5f0858x0(v=vs.100).aspx
#if ENABLE_CPP_VERSION // I am not convinced that the NEON version is faster than the C version yet.
__forceinline __m128 _mm_shuffle_ps_default(__m128 a, __m128 b, __constrange(0, 255) int imm)
{
    __m128 ret;
    ret[0] = a[imm & 0x3];
    ret[1] = a[(imm >> 2) & 0x3];
    ret[2] = b[(imm >> 4) & 0x03];
    ret[3] = b[(imm >> 6) & 0x03];
    return ret;
}
#else
#define _mm_shuffle_ps_default(a, b, imm) \
({ \
	float32x4_t ret; \
	ret = vmovq_n_f32(vgetq_lane_f32(vreinterpretq_f32_m128(a), (imm) & 0x3)); \
	ret = vsetq_lane_f32(vgetq_lane_f32(vreinterpretq_f32_m128(a), ((imm) >> 2) & 0x3), ret, 1); \
	ret = vsetq_lane_f32(vgetq_lane_f32(vreinterpretq_f32_m128(b), ((imm) >> 4) & 0x3), ret, 2); \
	ret = vsetq_lane_f32(vgetq_lane_f32(vreinterpretq_f32_m128(b), ((imm) >> 6) & 0x3), ret, 3); \
	vreinterpretq_m128_f32(ret); \
})
#endif

//__forceinline __m128 _mm_shuffle_ps(__m128 a, __m128 b, __constrange(0,255) int imm)
#define _mm_shuffle_ps(a, b, imm) \
({ \
	__m128 ret; \
	switch (imm) \
	{ \
		case _MM_SHUFFLE(1, 0, 3, 2): ret = _mm_shuffle_ps_1032((a), (b)); break; \
		case _MM_SHUFFLE(2, 3, 0, 1): ret = _mm_shuffle_ps_2301((a), (b)); break; \
		case _MM_SHUFFLE(0, 3, 2, 1): ret = _mm_shuffle_ps_0321((a), (b)); break; \
		case _MM_SHUFFLE(2, 1, 0, 3): ret = _mm_shuffle_ps_2103((a), (b)); break; \
		case _MM_SHUFFLE(1, 0, 1, 0): ret = _mm_shuffle_ps_1010((a), (b)); break; \
		case _MM_SHUFFLE(1, 0, 0, 1): ret = _mm_shuffle_ps_1001((a), (b)); break; \
		case _MM_SHUFFLE(0, 1, 0, 1): ret = _mm_shuffle_ps_0101((a), (b)); break; \
		case _MM_SHUFFLE(3, 2, 1, 0): ret = _mm_shuffle_ps_3210((a), (b)); break; \
		case _MM_SHUFFLE(0, 0, 1, 1): ret = _mm_shuffle_ps_0011((a), (b)); break; \
		case _MM_SHUFFLE(0, 0, 2, 2): ret = _mm_shuffle_ps_0022((a), (b)); break; \
		case _MM_SHUFFLE(2, 2, 0, 0): ret = _mm_shuffle_ps_2200((a), (b)); break; \
		case _MM_SHUFFLE(3, 2, 0, 2): ret = _mm_shuffle_ps_3202((a), (b)); break; \
		case _MM_SHUFFLE(1, 1, 3, 3): ret = _mm_shuffle_ps_1133((a), (b)); break; \
		case _MM_SHUFFLE(2, 0, 1, 0): ret = _mm_shuffle_ps_2010((a), (b)); break; \
		case _MM_SHUFFLE(2, 0, 0, 1): ret = _mm_shuffle_ps_2001((a), (b)); break; \
		case _MM_SHUFFLE(2, 0, 3, 2): ret = _mm_shuffle_ps_2032((a), (b)); break; \
		default: ret = _mm_shuffle_ps_default((a), (b), (imm)); break; \
	} \
	ret; \
})

/// Takes the upper 64 bits of a and places it in the low end of the result
/// Takes the lower 64 bits of a and places it into the high end of the result.
__forceinline __m128i _mm_shuffle_epi_1032(__m128i a)
{
    int32x2_t a32 = vget_high_s32(vreinterpretq_s32_m128i(a));
    int32x2_t a10 = vget_low_s32(vreinterpretq_s32_m128i(a));
    return vreinterpretq_m128i_s32(vcombine_s32(a32, a10));
}

/// Takes the lower two 32-bit values from a and swaps them and places in low end of result
/// Takes the higher two 32 bit values from a and swaps them and places in high end of result.
__forceinline __m128i _mm_shuffle_epi_2301(__m128i a)
{
    int32x2_t a01 = vrev64_s32(vget_low_s32(vreinterpretq_s32_m128i(a)));
    int32x2_t a23 = vrev64_s32(vget_high_s32(vreinterpretq_s32_m128i(a)));
    return vreinterpretq_m128i_s32(vcombine_s32(a01, a23));
}

/// Rotates the least significant 32 bits into the most signficant 32 bits, and shifts the rest down
__forceinline __m128i _mm_shuffle_epi_0321(__m128i a)
{
    return vreinterpretq_m128i_s32(vextq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(a), 1));
}

/// Rotates the most significant 32 bits into the least signficant 32 bits, and shifts the rest up
__forceinline __m128i _mm_shuffle_epi_2103(__m128i a)
{
    return vreinterpretq_m128i_s32(vextq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(a), 3));
}

/// Gets the lower 64 bits of a, and places it in the upper 64 bits
/// Gets the lower 64 bits of a and places it in the lower 64 bits
__forceinline __m128i _mm_shuffle_epi_1010(__m128i a)
{
    int32x2_t a10 = vget_low_s32(vreinterpretq_s32_m128i(a));
    return vreinterpretq_m128i_s32(vcombine_s32(a10, a10));
}

/// Gets the lower 64 bits of a, swaps the 0 and 1 elements, and places it in the lower 64 bits
/// Gets the lower 64 bits of a, and places it in the upper 64 bits
__forceinline __m128i _mm_shuffle_epi_1001(__m128i a)
{
    int32x2_t a01 = vrev64_s32(vget_low_s32(vreinterpretq_s32_m128i(a)));
    int32x2_t a10 = vget_low_s32(vreinterpretq_s32_m128i(a));
    return vreinterpretq_m128i_s32(vcombine_s32(a01, a10));
}

/// Gets the lower 64 bits of a, swaps the 0 and 1 elements and places it in the upper 64 bits
/// Gets the lower 64 bits of a, swaps the 0 and 1 elements, and places it in the lower 64 bits
__forceinline __m128i _mm_shuffle_epi_0101(__m128i a)
{
    int32x2_t a01 = vrev64_s32(vget_low_s32(vreinterpretq_s32_m128i(a)));
    return vreinterpretq_m128i_s32(vcombine_s32(a01, a01));
}

__forceinline __m128i _mm_shuffle_epi_2211(__m128i a)
{
    int32x2_t a11 = vdup_lane_s32(vget_low_s32(vreinterpretq_s32_m128i(a)), 1);
    int32x2_t a22 = vdup_lane_s32(vget_high_s32(vreinterpretq_s32_m128i(a)), 0);
    return vreinterpretq_m128i_s32(vcombine_s32(a11, a22));
}

__forceinline __m128i _mm_shuffle_epi_0122(__m128i a)
{
    int32x2_t a22 = vdup_lane_s32(vget_high_s32(vreinterpretq_s32_m128i(a)), 0);
    int32x2_t a01 = vrev64_s32(vget_low_s32(vreinterpretq_s32_m128i(a)));
    return vreinterpretq_m128i_s32(vcombine_s32(a22, a01));
}

__forceinline __m128i _mm_shuffle_epi_3332(__m128i a)
{
    int32x2_t a32 = vget_high_s32(vreinterpretq_s32_m128i(a));
    int32x2_t a33 = vdup_lane_s32(vget_high_s32(vreinterpretq_s32_m128i(a)), 1);
    return vreinterpretq_m128i_s32(vcombine_s32(a32, a33));
}

//__forceinline __m128i _mm_shuffle_epi32_default(__m128i a, __constrange(0,255) int imm)
#if ENABLE_CPP_VERSION
__forceinline __m128i _mm_shuffle_epi32_default(__m128i a, __constrange(0, 255) int imm)
{
    __m128i ret;
    ret[0] = a[imm & 0x3];
    ret[1] = a[(imm >> 2) & 0x3];
    ret[2] = a[(imm >> 4) & 0x03];
    ret[3] = a[(imm >> 6) & 0x03];
    return ret;
}
#else
#define _mm_shuffle_epi32_default(a, imm) \
({ \
	int32x4_t ret; \
	ret = vmovq_n_s32(vgetq_lane_s32(vreinterpretq_s32_m128i(a), (imm) & 0x3)); \
	ret = vsetq_lane_s32(vgetq_lane_s32(vreinterpretq_s32_m128i(a), ((imm) >> 2) & 0x3), ret, 1); \
	ret = vsetq_lane_s32(vgetq_lane_s32(vreinterpretq_s32_m128i(a), ((imm) >> 4) & 0x3), ret, 2); \
	ret = vsetq_lane_s32(vgetq_lane_s32(vreinterpretq_s32_m128i(a), ((imm) >> 6) & 0x3), ret, 3); \
	vreinterpretq_m128i_s32(ret); \
})
#endif

//__forceinline __m128i _mm_shuffle_epi32_splat(__m128i a, __constrange(0,255) int imm)
#if defined(__aarch64__)
#define _mm_shuffle_epi32_splat(a, imm) \
({ \
	vreinterpretq_m128i_s32(vdupq_laneq_s32(vreinterpretq_s32_m128i(a), (imm))); \
})
#else
#define _mm_shuffle_epi32_splat(a, imm) \
({ \
	vreinterpretq_m128i_s32(vdupq_n_s32(vgetq_lane_s32(vreinterpretq_s32_m128i(a), (imm)))); \
})
#endif

/// Shuffles the 4 signed or unsigned 32-bit integers in a as specified by imm.
/// https://msdn.microsoft.com/en-us/library/56f67xbk%28v=vs.90%29.aspx
//__forceinline __m128i _mm_shuffle_epi32(__m128i a, __constrange(0,255) int imm)
#define _mm_shuffle_epi32(a, imm) \
({ \
	__m128i ret; \
	switch (imm) \
	{ \
		case _MM_SHUFFLE(1, 0, 3, 2): ret = _mm_shuffle_epi_1032((a)); break; \
		case _MM_SHUFFLE(2, 3, 0, 1): ret = _mm_shuffle_epi_2301((a)); break; \
		case _MM_SHUFFLE(0, 3, 2, 1): ret = _mm_shuffle_epi_0321((a)); break; \
		case _MM_SHUFFLE(2, 1, 0, 3): ret = _mm_shuffle_epi_2103((a)); break; \
		case _MM_SHUFFLE(1, 0, 1, 0): ret = _mm_shuffle_epi_1010((a)); break; \
		case _MM_SHUFFLE(1, 0, 0, 1): ret = _mm_shuffle_epi_1001((a)); break; \
		case _MM_SHUFFLE(0, 1, 0, 1): ret = _mm_shuffle_epi_0101((a)); break; \
		case _MM_SHUFFLE(2, 2, 1, 1): ret = _mm_shuffle_epi_2211((a)); break; \
		case _MM_SHUFFLE(0, 1, 2, 2): ret = _mm_shuffle_epi_0122((a)); break; \
		case _MM_SHUFFLE(3, 3, 3, 2): ret = _mm_shuffle_epi_3332((a)); break; \
		case _MM_SHUFFLE(0, 0, 0, 0): ret = _mm_shuffle_epi32_splat((a),0); break; \
		case _MM_SHUFFLE(1, 1, 1, 1): ret = _mm_shuffle_epi32_splat((a),1); break; \
		case _MM_SHUFFLE(2, 2, 2, 2): ret = _mm_shuffle_epi32_splat((a),2); break; \
		case _MM_SHUFFLE(3, 3, 3, 3): ret = _mm_shuffle_epi32_splat((a),3); break; \
		default: ret = _mm_shuffle_epi32_default((a), (imm)); break; \
	} \
	ret; \
})

/// Shuffles the upper 4 signed or unsigned 16 - bit integers in a as specified by imm.
/// https://msdn.microsoft.com/en-us/library/13ywktbs(v=vs.100).aspx
//__forceinline __m128i _mm_shufflehi_epi16_function(__m128i a, __constrange(0,255) int imm)
#define _mm_shufflehi_epi16_function(a, imm) \
({ \
	int16x8_t ret = vreinterpretq_s16_s32(a); \
	int16x4_t highBits = vget_high_s16(ret); \
	ret = vsetq_lane_s16(vget_lane_s16(highBits, (imm) & 0x3), ret, 4); \
	ret = vsetq_lane_s16(vget_lane_s16(highBits, ((imm) >> 2) & 0x3), ret, 5); \
	ret = vsetq_lane_s16(vget_lane_s16(highBits, ((imm) >> 4) & 0x3), ret, 6); \
	ret = vsetq_lane_s16(vget_lane_s16(highBits, ((imm) >> 6) & 0x3), ret, 7); \
	vreinterpretq_s32_s16(ret); \
})

//__forceinline __m128i _mm_shufflehi_epi16(__m128i a, __constrange(0,255) int imm)
#define _mm_shufflehi_epi16(a, imm) \
	_mm_shufflehi_epi16_function((a), (imm))


/// Shifts the 8 signed or unsigned 16-bit integers in a left by count bits while shifting in zeros.
/// https://msdn.microsoft.com/en-us/library/es73bcsy(v=vs.90).aspx
#define _mm_slli_epi16(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) {\
		ret = a; \
	} \
	else if ((imm) > 31) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_s16(vshlq_n_s16(vreinterpretq_s16_m128i(a), (imm))); \
	} \
	ret; \
})

/// Shifts the 4 signed or unsigned 32-bit integers in a left by count bits while shifting in zeros.
/// https://msdn.microsoft.com/en-us/library/z2k3bbtb%28v=vs.90%29.aspx
//__forceinline __m128i _mm_slli_epi32(__m128i a, __constrange(0,255) int imm)
#define _mm_slli_epi32(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) {\
		ret = a; \
	} \
	else if ((imm) > 31) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_s32(vshlq_n_s32(vreinterpretq_s32_m128i(a), (imm))); \
	} \
	ret; \
})

/// Shifts the 8 signed or unsigned 16-bit integers in a right by count bits while shifting in zeros.
/// https://msdn.microsoft.com/en-us/library/6tcwd38t(v=vs.90).aspx
#define _mm_srli_epi16(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) { \
		ret = a; \
	} \
	else if ((imm)> 31) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_u16(vshrq_n_u16(vreinterpretq_u16_m128i(a), (imm))); \
	} \
	ret; \
})

/// Shifts the 4 signed or unsigned 32-bit integers in a right by count bits while shifting in zeros.
/// https://msdn.microsoft.com/en-us/library/w486zcfa(v=vs.100).aspx
//__forceinline __m128i _mm_srli_epi32(__m128i a, __constrange(0,255) int imm)
#define _mm_srli_epi32(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) { \
		ret = a; \
	} \
	else if ((imm)> 31) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_u32(vshrq_n_u32(vreinterpretq_u32_m128i(a), (imm))); \
	} \
	ret; \
})

/// Shifts the 4 signed 32 - bit integers in a right by count bits while shifting in the sign bit.
/// https://msdn.microsoft.com/en-us/library/z1939387(v=vs.100).aspx
//__forceinline __m128i _mm_srai_epi32(__m128i a, __constrange(0,255) int imm)
#define _mm_srai_epi32(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) { \
		ret = a; \
	} \
	else if ((imm) > 31) { \
		ret = vreinterpretq_m128i_s32(vshrq_n_s32(vreinterpretq_s32_m128i(a), 16)); \
		ret = vreinterpretq_m128i_s32(vshrq_n_s32(vreinterpretq_s32_m128i(ret), 16)); \
	} \
	else { \
		ret = vreinterpretq_m128i_s32(vshrq_n_s32(vreinterpretq_s32_m128i(a), (imm))); \
	} \
	ret; \
})

/// Shifts the 128 - bit value in a right by imm bytes while shifting in zeros.imm must be an immediate.
/// https://msdn.microsoft.com/en-us/library/305w28yz(v=vs.100).aspx
//__forceinline _mm_srli_si128(__m128i a, __constrange(0,255) int imm)
#define _mm_srli_si128(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) { \
		ret = a; \
	} \
	else if ((imm) > 15) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_s8(vextq_s8(vreinterpretq_s8_m128i(a), vdupq_n_s8(0), (imm))); \
	} \
	ret; \
})

/// Shifts the 128-bit value in a left by imm bytes while shifting in zeros. imm must be an immediate.
/// https://msdn.microsoft.com/en-us/library/34d3k2kt(v=vs.100).aspx
//__forceinline __m128i _mm_slli_si128(__m128i a, __constrange(0,255) int imm)
#define _mm_slli_si128(a, imm) \
({ \
	__m128i ret; \
	if ((imm) <= 0) { \
		ret = a; \
	} \
	else if ((imm) > 15) { \
		ret = _mm_setzero_si128(); \
	} \
	else { \
		ret = vreinterpretq_m128i_s8(vextq_s8(vdupq_n_s8(0), vreinterpretq_s8_m128i(a), 16 - (imm))); \
	} \
	ret; \
})

/// NEON does not provide a version of this function, here is an article about some ways to repro the results.
/// http://stackoverflow.com/questions/11870910/sse-mm-movemask-epi8-equivalent-method-for-arm-neon
/// Creates a 16-bit mask from the most significant bits of the 16 signed or unsigned 8-bit integers in a and zero extends the upper bits. https://msdn.microsoft.com/en-us/library/vstudio/s090c8fk(v=vs.100).aspx
__forceinline int _mm_movemask_epi8(__m128i _a)
{
    uint8x16_t input = vreinterpretq_u8_m128i(_a);
    static const int8_t __attribute__((aligned(16))) xr[8] = { -7, -6, -5, -4, -3, -2, -1, 0 };
    uint8x8_t mask_and = vdup_n_u8(0x80);
    int8x8_t mask_shift = vld1_s8(xr);

    uint8x8_t lo = vget_low_u8(input);
    uint8x8_t hi = vget_high_u8(input);

    lo = vand_u8(lo, mask_and);
    lo = vshl_u8(lo, mask_shift);

    hi = vand_u8(hi, mask_and);
    hi = vshl_u8(hi, mask_shift);

    lo = vpadd_u8(lo, lo);
    lo = vpadd_u8(lo, lo);
    lo = vpadd_u8(lo, lo);

    hi = vpadd_u8(hi, hi);
    hi = vpadd_u8(hi, hi);
    hi = vpadd_u8(hi, hi);

    return ((hi[0] << 8) | (lo[0] & 0xFF));
}


// -------------------------------------------------------------
// Math operations
// -------------------------------------------------------------

/// Subtracts the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/1zad2k61(v=vs.100).aspx
__forceinline __m128 _mm_sub_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_f32(vsubq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// Subtract the lower single-precision (32-bit) floating-point element in b from the lower single-precision (32-bit) floating-point element in a,
/// store the result in the lower element of dst, and copy the upper 3 packed elements from a to the upper elements of dst.
__forceinline __m128 _mm_sub_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_sub_ps(a, b), 0), a, 0);
}

/// Subtracts the 4 signed or unsigned 32-bit integers of b from the 4 signed or unsigned 32-bit integers of a.
/// https://msdn.microsoft.com/en-us/library/vstudio/fhh866h0(v=vs.100).aspx
__forceinline __m128i _mm_sub_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128_f32(vsubq_s32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

__forceinline __m128i _mm_sub_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vsubq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

__forceinline __m128i _mm_sub_epi8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s8(vsubq_s8(vreinterpretq_s8_m128i(a), vreinterpretq_s8_m128i(b)));
}

/// Subtracts the 8 unsigned 16-bit integers of bfrom the 8 unsigned 16-bit integers of a and saturates.
/// https://technet.microsoft.com/en-us/subscriptions/index/f44y0s19(v=vs.90).aspx
__forceinline __m128i _mm_subs_epu16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u16(vqsubq_u16(vreinterpretq_u16_m128i(a), vreinterpretq_u16_m128i(b)));
}

/// Subtracts the 16 unsigned 8-bit integers of b from the 16 unsigned 8-bit integers of a and saturates.
/// https://technet.microsoft.com/en-us/subscriptions/yadkxc18(v=vs.90)
__forceinline __m128i _mm_subs_epu8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vqsubq_u8(vreinterpretq_u8_m128i(a), vreinterpretq_u8_m128i(b)));
}

/// Adds the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/c9848chc(v=vs.100).aspx
__forceinline __m128 _mm_add_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_f32(vaddq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// adds the scalar single-precision floating point values of a and b.
/// https://msdn.microsoft.com/en-us/library/be94x2y6(v=vs.100).aspx
__forceinline __m128 _mm_add_ss(__m128 a, __m128 b)
{
    float32_t b0 = vgetq_lane_f32(vreinterpretq_f32_m128(b), 0);
    float32x4_t value = vsetq_lane_f32(b0, vdupq_n_f32(0), 0);
    //the upper values in the result must be the remnants of <a>.
    return vreinterpretq_m128_f32(vaddq_f32(a, value));
}

/// Adds the 4 signed or unsigned 32-bit integers in a to the 4 signed or unsigned 32-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/vstudio/09xs4fkk(v=vs.100).aspx
__forceinline __m128i _mm_add_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vaddq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Adds the 8 signed or unsigned 16-bit integers in a to the 8 signed or unsigned 16-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/fceha5k4(v=vs.100).aspx
__forceinline __m128i _mm_add_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vaddq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

/// Adds the 16 signed or unsigned 8-bit integers in a to the 16 signed or unsigned 8-bit integers in b.
/// https://technet.microsoft.com/en-us/subscriptions/yc7tcyzs(v=vs.90)
__forceinline __m128i _mm_add_epi8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s8(vaddq_s8(vreinterpretq_s8_m128i(a), vreinterpretq_s8_m128i(b)));
}

/// Adds the 8 signed 16-bit integers in a to the 8 signed 16-bit integers in b and saturates.
/// https://msdn.microsoft.com/en-us/library/1a306ef8(v=vs.100).aspx
__forceinline __m128i _mm_adds_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vqaddq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

/// Adds the 16 unsigned 8-bit integers in a to the 16 unsigned 8-bit integers in b and saturates.
/// https://msdn.microsoft.com/en-us/library/9hahyddy(v=vs.100).aspx
__forceinline __m128i _mm_adds_epu8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vqaddq_u8(vreinterpretq_u8_m128i(a), vreinterpretq_u8_m128i(b)));
}


/// Multiplies the 8 signed or unsigned 16-bit integers from a by the 8 signed or unsigned 16-bit integers from b.
/// https://msdn.microsoft.com/en-us/library/vstudio/9ks1472s(v=vs.100).aspx
__forceinline __m128i _mm_mullo_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vmulq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

/// Multiplies the 4 signed or unsigned 32-bit integers from a by the 4 signed or unsigned 32-bit integers from b.
/// https://msdn.microsoft.com/en-us/library/vstudio/bb531409(v=vs.100).aspx
__forceinline __m128i _mm_mullo_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vmulq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Multiplies the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/22kbk6t9(v=vs.100).aspx
__forceinline __m128 _mm_mul_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_f32(vmulq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// Multiply the lower single-precision (32-bit) floating-point element in a and b, store the result in the lower element of dst, and copy the upper 3 packed elements from a to the upper elements of dst
__forceinline __m128 _mm_mul_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_mul_ps(a, b), 0), a, 0);
}

/// This version does additional iterations to improve accuracy.  Between 1 and 4 recommended.
/// Computes the approximations of reciprocals of the four single-precision, floating-point values of a.
/// Xn+1 = Xn * (2 - IN * Xn)
/// https://msdn.microsoft.com/en-us/library/vstudio/796k1tty(v=vs.100).aspx
__forceinline __m128 recipq_newton(__m128 in, int n)
{
    int i;
    float32x4_t recip = vrecpeq_f32(vreinterpretq_f32_m128(in));
    for (i = 0; i < n; ++i)
    {
        recip = vmulq_f32(recip, vrecpsq_f32(recip, vreinterpretq_f32_m128(in)));
    }
    return vreinterpretq_m128_f32(recip);
}

/// Xn+1 = Xn * (3 - IN * Xn2)/2
__forceinline __m128 rsqrtq_newton(__m128 in, int n)
{
    int i;
    float32x4_t recip = vrsqrteq_f32(in);
    for (i = 0; i < n; ++i)
    {
        float32x4_t recip2 = vmulq_f32(recip, recip);

        recip = vmulq_f32(recip, vrsqrtsq_f32(recip2, in));
    }
    return recip;
}

/// Divides the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/edaw8147(v=vs.100).aspx
__forceinline __m128 _mm_div_ps(__m128 a, __m128 b)
{
    // 2 step to pass ToQuaternion() unit test
    return vmulq_f32(a, recipq_newton(b, 3));
}

/// Divides the scalar single-precision floating point value of a by b.
/// https://msdn.microsoft.com/en-us/library/4y73xa49(v=vs.100).aspx
__forceinline __m128 _mm_div_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_div_ps(a, b), 0), a, 0);
}

/// Computes the approximations of reciprocals of the four single-precision, floating-point values of a.x
/// The maximum relative error for this approximation is less than 1.5*2^-12.
/// https://msdn.microsoft.com/en-us/library/vstudio/796k1tty(v=vs.100).aspx
__forceinline __m128 _mm_rcp_ps(__m128 in)
{
    return recipq_newton(in, 1);
}

/// Compute the approximate reciprocal of the lower single-precision (32-bit) floating-point element in a, store the result in the lower element of dst, and copy the upper 3 packed elements from a to the upper elements of dst.
/// The maximum relative error for this approximation is less than 1.5*2^-12.
__forceinline __m128 _mm_rcp_ss(__m128 in)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_rcp_ps(in), 0), in, 0);
}

/// Computes the approximations of the reciprocal square roots of the four single-precision floating point values of in.
/// https://msdn.microsoft.com/en-us/library/22hfsh53(v=vs.100).aspx
__forceinline __m128 _mm_rsqrt_ps(__m128 in)
{
    return rsqrtq_newton(in, 1);
}

/// Compute the approximate reciprocal square root of the lower single-precision (32-bit) floating-point element in a, store the result in the lower element of dst, and copy the upper 3 packed elements from a to the upper elements of dst.
__forceinline __m128 _mm_rsqrt_ss(__m128 in)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_rsqrt_ps(in), 0), in, 0);
}

/// Computes the approximations of square roots of the four single-precision, floating-point values of a. First computes reciprocal square roots and then reciprocals of the four values.
/// https://msdn.microsoft.com/en-us/library/vstudio/8z67bwwk(v=vs.100).aspx
__forceinline __m128 _mm_sqrt_ps(__m128 in)
{
    // single step is not enough to pass unit-tests
    return recipq_newton(rsqrtq_newton(in, 3), 2);
}

/// Computes the approximation of the square root of the scalar single-precision floating point value of in.
/// https://msdn.microsoft.com/en-us/library/ahfsc22d(v=vs.100).aspx
__forceinline __m128 _mm_sqrt_ss(__m128 in)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_sqrt_ps(in), 0), in, 0);
}

/// Computes the maximums of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/ff5d607a(v=vs.100).aspx
__forceinline __m128 _mm_max_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_f32(vmaxq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// Computes the minima of the four single-precision, floating-point values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/wh13kadz(v=vs.100).aspx
__forceinline __m128 _mm_min_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_f32(vminq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// Computes the maximum of the two lower scalar single-precision floating point values of a and b.
/// https://msdn.microsoft.com/en-us/library/s6db5esz(v=vs.100).aspx
__forceinline __m128 _mm_max_ss(__m128 a, __m128 b)
{
    float32_t value = vgetq_lane_f32(vmaxq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    return vreinterpretq_m128_f32(vsetq_lane_f32(value, vreinterpretq_f32_m128(a), 0));
}

/// Computes the minimum of the two lower scalar single-precision floating point values of a and b.
/// https://msdn.microsoft.com/en-us/library/0a9y7xaa(v=vs.100).aspx
__forceinline __m128 _mm_min_ss(__m128 a, __m128 b)
{
    float32_t value = vgetq_lane_f32(vminq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    return vreinterpretq_m128_f32(vsetq_lane_f32(value, vreinterpretq_f32_m128(a), 0));
}

/// Computes the pairwise maxima of the 16 unsigned 8-bit integers from a and the 16 unsigned 8-bit integers from b.
/// https://msdn.microsoft.com/en-us/library/st6634za(v=vs.100).aspx
__forceinline __m128i _mm_max_epu8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vmaxq_u8(vreinterpretq_u8_m128i(a), vreinterpretq_u8_m128i(b)));
}

/// Computes the pairwise minima of the 16 unsigned 8-bit integers from a and the 16 unsigned 8-bit integers from b.
/// https://msdn.microsoft.com/ko-kr/library/17k8cf58(v=vs.100).aspxx
__forceinline __m128i _mm_min_epu8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vminq_u8(vreinterpretq_u8_m128i(a), vreinterpretq_u8_m128i(b)));
}


/// Computes the pairwise minima of the 8 signed 16-bit integers from a and the 8 signed 16-bit integers from b.
/// https://msdn.microsoft.com/en-us/library/vstudio/6te997ew(v=vs.100).aspx
__forceinline __m128i _mm_min_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vminq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

/// Computes the pairwise maxima of the 8 signed 16-bit integers from a and the 8 signed 16-bit integers from b.
/// https://msdn.microsoft.com/en-us/LIBRary/3x060h7c(v=vs.100).aspx
__forceinline __m128i _mm_max_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vmaxq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}


/// epi versions of min/max
/// Computes the pariwise maximums of the four signed 32-bit integer values of a and b.
/// https://msdn.microsoft.com/en-us/library/vstudio/bb514055(v=vs.100).aspx
__forceinline __m128i _mm_max_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vmaxq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Computes the pariwise minima of the four signed 32-bit integer values of a and b. 
/// https://msdn.microsoft.com/en-us/library/vstudio/bb531476(v=vs.100).aspx
__forceinline __m128i _mm_min_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s32(vminq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Multiplies the 8 signed 16-bit integers from a by the 8 signed 16-bit integers from b.
/// https://msdn.microsoft.com/en-us/library/vstudio/59hddw1d(v=vs.100).aspx
__forceinline __m128i _mm_mulhi_epi16(__m128i a, __m128i b)
{
    /* apoty: issue with large values because of result saturation */
    //int16x8_t ret = vqdmulhq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)); /* =2*a*b */
    //return vreinterpretq_m128i_s16(vshrq_n_s16(ret, 1));
    int16x4_t a3210 = vget_low_s16(vreinterpretq_s16_m128i(a));
    int16x4_t b3210 = vget_low_s16(vreinterpretq_s16_m128i(b));
    int32x4_t ab3210 = vmull_s16(a3210, b3210); /* 3333222211110000 */
    int16x4_t a7654 = vget_high_s16(vreinterpretq_s16_m128i(a));
    int16x4_t b7654 = vget_high_s16(vreinterpretq_s16_m128i(b));
    int32x4_t ab7654 = vmull_s16(a7654, b7654); /* 7777666655554444 */
    uint16x8x2_t r = vuzpq_u16(vreinterpretq_u16_s32(ab3210), vreinterpretq_u16_s32(ab7654));
    return vreinterpretq_m128i_u16(r.val[1]);
}

/// Computes pairwise add of each argument as single-precision, floating-point values a and b. 
/// https://msdn.microsoft.com/en-us/library/yd9wecaa.aspx
__forceinline __m128 _mm_hadd_ps(__m128 a, __m128 b)
{
#if defined(__aarch64__)
    return vreinterpretq_m128_f32(vpaddq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b))); //AArch64
#else
    float32x2_t a10 = vget_low_f32(vreinterpretq_f32_m128(a));
    float32x2_t a32 = vget_high_f32(vreinterpretq_f32_m128(a));
    float32x2_t b10 = vget_low_f32(vreinterpretq_f32_m128(b));
    float32x2_t b32 = vget_high_f32(vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_f32(vcombine_f32(vpadd_f32(a10, a32), vpadd_f32(b10, b32)));
#endif
}

// -------------------------------------------------------------
// Compare operations
// -------------------------------------------------------------

/// Compares for less than
/// https://msdn.microsoft.com/en-us/library/vstudio/f330yhc8(v=vs.100).aspx
__forceinline __m128 _mm_cmplt_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vcltq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

__forceinline __m128 _mm_cmplt_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_cmplt_ps(a, b), 0), vreinterpretq_f32_m128(a), 0);
}

/// Compares for greater than.
/// https://msdn.microsoft.com/en-us/library/vstudio/11dy102s(v=vs.100).aspx
__forceinline __m128 _mm_cmpgt_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vcgtq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

__forceinline __m128 _mm_cmpgt_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_cmpgt_ps(a, b), 0), vreinterpretq_f32_m128(a), 0);
}

/// Compares for greater than or equal.
/// https://msdn.microsoft.com/en-us/library/vstudio/fs813y2t(v=vs.100).aspx
__forceinline __m128 _mm_cmpge_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vcgeq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

__forceinline __m128 _mm_cmpge_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_cmpge_ps(a, b), 0), a, 0);
}


/// Compares for less than or equal.
/// https://msdn.microsoft.com/en-us/library/vstudio/1s75w83z(v=vs.100).aspx
__forceinline __m128 _mm_cmple_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vcleq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

/// Compare the lower single-precision (32-bit) floating-point elements in a and b for less-than-or-equal, store the result in the lower element of dst, and copy the upper 3 packed elements from a to the upper elements of dst.
__forceinline __m128 _mm_cmple_ss(__m128 a, __m128 b)
{
    return vsetq_lane_f32(vgetq_lane_f32(_mm_cmple_ps(a, b), 0), a, 0);
}

/// Compares for equality.
/// https://msdn.microsoft.com/en-us/library/vstudio/36aectz5(v=vs.100).aspx
__forceinline __m128 _mm_cmpeq_ps(__m128 a, __m128 b)
{
    return vreinterpretq_m128_u32(vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
}

__forceinline __m128 _mm_cmpeq_ss(__m128 a, __m128 b)
{
    float32_t value = vgetq_lane_f32(vreinterpretq_f32_m128(_mm_cmpeq_ps(a, b)), 0);
    return vreinterpretq_m128_f32(vsetq_lane_f32(value, vreinterpretq_f32_m128(a), 0));
}

/// Compares the 16 signed or unsigned 8-bit integers in a and the 16 signed or unsigned 8-bit integers in b for equality.
/// https://msdn.microsoft.com/en-us/library/windows/desktop/bz5xk21a(v=vs.90).aspx
__forceinline __m128i _mm_cmpeq_epi8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vceqq_s8(vreinterpretq_s8_m128i(a), vreinterpretq_s8_m128i(b)));
}

/// Compares the 8 signed or unsigned 16-bit integers in a and the 8 signed or unsigned 16-bit integers in b for equality. 
/// https://msdn.microsoft.com/en-us/library/2ay060te(v=vs.100).aspx
__forceinline __m128i _mm_cmpeq_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u16(vceqq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}

/// Compares the 32-bit integers in a and b for equality.
__forceinline __m128i _mm_cmpeq_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u32(vceqq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Compares the 16 signed 8-bit integers in a and the 16 signed 8-bit integers in b for lesser than.
/// https://msdn.microsoft.com/en-us/library/windows/desktop/9s46csht(v=vs.90).aspx
__forceinline __m128i _mm_cmplt_epi8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vcltq_s8(vreinterpretq_s8_m128i(a), vreinterpretq_s8_m128i(b)));
}

/// Compares the 16 signed 8-bit integers in a and the 16 signed 8-bit integers in b for greater than.
/// https://msdn.microsoft.com/zh-tw/library/wf45zt2b(v=vs.100).aspx
__forceinline __m128i _mm_cmpgt_epi8(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u8(vcgtq_s8(vreinterpretq_s8_m128i(a), vreinterpretq_s8_m128i(b)));
}

/// Compares the 8 signed 16-bit integers in a and the 8 signed 16-bit integers in b for greater than.
/// https://technet.microsoft.com/en-us/library/xd43yfsa(v=vs.100).aspx
__forceinline __m128i _mm_cmpgt_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u16(vcgtq_s16(vreinterpretq_s16_m128i(a), vreinterpretq_s16_m128i(b)));
}


/// Compares the 4 signed 32-bit integers in a and the 4 signed 32-bit integers in b for less than.
/// https://msdn.microsoft.com/en-us/library/vstudio/4ak0bf5d(v=vs.100).aspx
__forceinline __m128i _mm_cmplt_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u32(vcltq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Compares the 4 signed 32-bit integers in a and the 4 signed 32-bit integers in b for greater than.
/// https://msdn.microsoft.com/en-us/library/vstudio/1s9f2z0y(v=vs.100).aspx
__forceinline __m128i _mm_cmpgt_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_u32(vcgtq_s32(vreinterpretq_s32_m128i(a), vreinterpretq_s32_m128i(b)));
}

/// Compares the four 32-bit floats in a and b to check if any values are NaN.
/// Ordered compare between each value returns true for "orderable" and false for "not orderable" (NaN). 
/// see also:
///     https://msdn.microsoft.com/en-us/library/vstudio/0h9w00fx(v=vs.100).aspx
///     https://stackoverflow.com/questions/8627331/what-does-ordered-unordered-comparison-mean
///     https://stackoverflow.com/questions/29349621/neon-isnanval-intrinsics
__forceinline __m128 _mm_cmpord_ps(__m128 a, __m128 b)
{
    // Note: NEON does not have ordered compare builtin
    // Need to compare a eq a and b eq b to check for NaN
    // Do AND of results to get final
    uint32x4_t ceqaa = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t ceqbb = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    return vreinterpretq_m128_u32(vandq_u32(ceqaa, ceqbb));
}

/// Compares the lower single-precision floating point scalar values of a and b using a less than operation.
/// Important note!! The documentation on MSDN is incorrect! If either of the values is a NAN the docs say you will get a one, but in fact, it will return a zero!!
/// https://msdn.microsoft.com/en-us/library/2kwe606b(v=vs.90).aspx
__forceinline int _mm_comilt_ss(__m128 a, __m128 b)
{
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
    uint32x4_t a_lt_b = vcltq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b));
    return (vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_lt_b), 0) != 0) ? 1 : 0;
}

/// Compares the lower single-precision floating point scalar values of a and b using a greater than operation.
/// https://msdn.microsoft.com/en-us/library/b0738e0t(v=vs.100).aspx
__forceinline int _mm_comigt_ss(__m128 a, __m128 b)
{
    //return vgetq_lane_u32(vcgtq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
    uint32x4_t a_gt_b = vcgtq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b));
    return (vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_gt_b), 0) != 0) ? 1 : 0;
}

/// Compares the lower single-precision floating point scalar values of a and b using a less than or equal operation.
/// https://msdn.microsoft.com/en-us/library/1w4t7c57(v=vs.90).aspx
__forceinline int _mm_comile_ss(__m128 a, __m128 b)
{
    //return vgetq_lane_u32(vcleq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
    uint32x4_t a_le_b = vcleq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b));
    return (vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_le_b), 0) != 0) ? 1 : 0;
}

/// Compares the lower single-precision floating point scalar values of a and b using a greater than or equal operation.
/// https://msdn.microsoft.com/en-us/library/8t80des6(v=vs.100).aspx
__forceinline int _mm_comige_ss(__m128 a, __m128 b)
{
    //return vgetq_lane_u32(vcgeq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
    uint32x4_t a_ge_b = vcgeq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b));
    return (vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_ge_b), 0) != 0) ? 1 : 0;
}

/// Compares the lower single-precision floating point scalar values of a and b using an equality operation.
/// https://msdn.microsoft.com/en-us/library/93yx2h2b(v=vs.100).aspx
__forceinline int _mm_comieq_ss(__m128 a, __m128 b)
{
    //return vgetq_lane_u32(vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
    uint32x4_t a_eq_b = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b));
    return (vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_eq_b), 0) != 0) ? 1 : 0;
}

/// Compares the lower single-precision floating point scalar values of a and b using an inequality operation.
/// https://msdn.microsoft.com/en-us/library/bafh5e0a(v=vs.90).aspx
__forceinline int _mm_comineq_ss(__m128 a, __m128 b)
{
    //return !vgetq_lane_u32(vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)), 0);
    uint32x4_t a_not_nan = vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(a));
    uint32x4_t b_not_nan = vceqq_f32(vreinterpretq_f32_m128(b), vreinterpretq_f32_m128(b));
    uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
    uint32x4_t a_neq_b = vmvnq_u32(vceqq_f32(vreinterpretq_f32_m128(a), vreinterpretq_f32_m128(b)));
    return (vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_neq_b), 0) != 0) ? 1 : 0;
}

// according to the documentation, these intrinsics behave the same as the non-'u' versions.  We'll just alias them here.
#define _mm_ucomilt_ss      _mm_comilt_ss
#define _mm_ucomile_ss      _mm_comile_ss
#define _mm_ucomigt_ss      _mm_comigt_ss
#define _mm_ucomige_ss      _mm_comige_ss
#define _mm_ucomieq_ss      _mm_comieq_ss
#define _mm_ucomineq_ss     _mm_comineq_ss

// -------------------------------------------------------------
// Conversions
// -------------------------------------------------------------

/// Converts the four single-precision, floating-point values of a to signed 32-bit integer values using truncate.
/// https://msdn.microsoft.com/en-us/library/vstudio/1h005y6x(v=vs.100).aspx
__forceinline __m128i _mm_cvttps_epi32(__m128 a)
{
    return vreinterpretq_m128i_s32(vcvtq_s32_f32(vreinterpretq_f32_m128(a)));
}

/// Converts the four signed 32-bit integer values of a to single-precision, floating-point values
/// https://msdn.microsoft.com/en-us/library/vstudio/36bwxcx5(v=vs.100).aspx
__forceinline __m128 _mm_cvtepi32_ps(__m128i a)
{
    return vreinterpretq_m128_f32(vcvtq_f32_s32(vreinterpretq_s32_m128i(a)));
}

/// Converts the four unsigned 8-bit integers in the lower 32 bits to four unsigned 32-bit integers.
/// https://msdn.microsoft.com/en-us/library/bb531467%28v=vs.100%29.aspx
__forceinline __m128i _mm_cvtepu8_epi32(__m128i a)
{
    uint8x16_t u8x16 = vreinterpretq_u8_s32(a);        /* xxxx xxxx xxxx DCBA */
    uint16x8_t u16x8 = vmovl_u8(vget_low_u8(u8x16));   /* 0x0x 0x0x 0D0C 0B0A */
    uint32x4_t u32x4 = vmovl_u16(vget_low_u16(u16x8)); /* 000D 000C 000B 000A */
    return vreinterpretq_s32_u32(u32x4);
}

/// Converts the four signed 16-bit integers in the lower 64 bits to four signed 32-bit integers.
/// https://msdn.microsoft.com/en-us/library/bb514079%28v=vs.100%29.aspx
__forceinline __m128i _mm_cvtepi16_epi32(__m128i a)
{
    return vreinterpretq_m128i_s32(vmovl_s16(vget_low_s16(vreinterpretq_s16_m128i(a))));
}

/// Converts the four single-precision, floating-point values of a to signed 32-bit integer values. 
/// *NOTE*. The default rounding mode on SSE is 'round to even', which ArmV7 does not support!  
/// It is supported on ARMv8 however.
/// https://msdn.microsoft.com/en-us/library/vstudio/xdc42k5e(v=vs.100).aspx
__forceinline __m128i _mm_cvtps_epi32(__m128 a)
{
#if defined(__aarch64__)
    return vcvtnq_s32_f32(a);
#else
    uint32x4_t signmask = vdupq_n_u32(0x80000000);
    float32x4_t half = vbslq_f32(signmask, vreinterpretq_f32_m128(a), vdupq_n_f32(0.5f)); /* +/- 0.5 */
    int32x4_t r_normal = vcvtq_s32_f32(vaddq_f32(vreinterpretq_f32_m128(a), half)); /* round to integer: [a + 0.5]*/
    int32x4_t r_trunc = vcvtq_s32_f32(vreinterpretq_f32_m128(a)); /* truncate to integer: [a] */
    int32x4_t plusone = vreinterpretq_s32_u32(vshrq_n_u32(vreinterpretq_u32_s32(vnegq_s32(r_trunc)), 31)); /* 1 or 0 */
    int32x4_t r_even = vbicq_s32(vaddq_s32(r_trunc, plusone), vdupq_n_s32(1)); /* ([a] + {0,1}) & ~1 */
    float32x4_t delta = vsubq_f32(vreinterpretq_f32_m128(a), vcvtq_f32_s32(r_trunc)); /* compute delta: delta = (a - [a]) */
    uint32x4_t is_delta_half = vceqq_f32(delta, half); /* delta == +/- 0.5 */
    return vreinterpretq_m128i_s32(vbslq_s32(is_delta_half, r_even, r_normal));
#endif
}

/// Moves the least significant 32 bits of a to a 32-bit integer.
/// https://msdn.microsoft.com/en-us/library/5z7a9642%28v=vs.90%29.aspx
__forceinline int _mm_cvtsi128_si32(__m128i a)
{
    return vgetq_lane_s32(vreinterpretq_s32_m128i(a), 0);
}

/// Moves 32-bit integer a to the least significant 32 bits of an __m128 object, zero extending the upper bits.
/// https://msdn.microsoft.com/en-us/library/ct3539ha%28v=vs.90%29.aspx
__forceinline __m128i _mm_cvtsi32_si128(int a)
{
    return vreinterpretq_m128i_s32(vsetq_lane_s32(a, vdupq_n_s32(0), 0));
}


/// Applies a type cast to reinterpret four 32-bit floating point values passed in as a 128-bit parameter as packed 32-bit integers.
/// https://msdn.microsoft.com/en-us/library/bb514099.aspx
__forceinline __m128i _mm_castps_si128(__m128 a)
{
    return vreinterpretq_m128i_s32(vreinterpretq_s32_m128(a));
}

/// Applies a type cast to reinterpret four 32-bit integers passed in as a 128-bit parameter as packed 32-bit floating point values.
/// https://msdn.microsoft.com/en-us/library/bb514029.aspx
__forceinline __m128 _mm_castsi128_ps(__m128i a)
{
    return vreinterpretq_m128_s32(vreinterpretq_s32_m128i(a));
}

/// Loads 128-bit value.
/// https://msdn.microsoft.com/en-us/library/atzzad1h(v=vs.80).aspx
__forceinline __m128i _mm_load_si128(const __m128i* p)
{
    return vreinterpretq_m128i_s32(vld1q_s32((int32_t*)p));
}

/// Loads 128-bit value.
/// https://msdn.microsoft.com/zh-cn/library/f4k12ae8(v=vs.90).aspx
__forceinline __m128i _mm_loadu_si128(const __m128i* p)
{
    return vreinterpretq_m128i_s32(vld1q_s32((int32_t*)p));
}


// -------------------------------------------------------------
// Miscellaneous Operations
// -------------------------------------------------------------

/// Packs the 16 signed 16-bit integers from a and b into 8-bit integers and saturates.
/// https://msdn.microsoft.com/en-us/library/k4y4f7w5%28v=vs.90%29.aspx
__forceinline __m128i _mm_packs_epi16(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s8(vcombine_s8(vqmovn_s16(vreinterpretq_s16_m128i(a)), vqmovn_s16(vreinterpretq_s16_m128i(b))));
}

/// Packs the 16 signed 16 - bit integers from a and b into 8 - bit unsigned integers and saturates.
/// https://msdn.microsoft.com/en-us/library/07ad1wx4(v=vs.100).aspx
__forceinline __m128i _mm_packus_epi16(const __m128i a, const __m128i b)
{
    return vreinterpretq_m128i_u8(vcombine_u8(vqmovun_s16(vreinterpretq_s16_m128i(a)), vqmovun_s16(vreinterpretq_s16_m128i(b))));
}

/// Packs the 8 signed 32-bit integers from a and b into signed 16-bit integers and saturates.
/// https://msdn.microsoft.com/en-us/library/393t56f9%28v=vs.90%29.aspx
__forceinline __m128i _mm_packs_epi32(__m128i a, __m128i b)
{
    return vreinterpretq_m128i_s16(vcombine_s16(vqmovn_s32(vreinterpretq_s32_m128i(a)), vqmovn_s32(vreinterpretq_s32_m128i(b))));
}

/// Interleaves the lower 8 signed or unsigned 8-bit integers in a with the lower 8 signed or unsigned 8-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/xf7k860c%28v=vs.90%29.aspx
__forceinline __m128i _mm_unpacklo_epi8(__m128i a, __m128i b)
{
    int8x8_t a1 = vreinterpret_s8_s16(vget_low_s16(vreinterpretq_s16_m128i(a)));
    int8x8_t b1 = vreinterpret_s8_s16(vget_low_s16(vreinterpretq_s16_m128i(b)));
    int8x8x2_t result = vzip_s8(a1, b1);
    return vreinterpretq_m128i_s8(vcombine_s8(result.val[0], result.val[1]));
}

/// Interleaves the lower 4 signed or unsigned 16-bit integers in a with the lower 4 signed or unsigned 16-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/btxb17bw%28v=vs.90%29.aspx
__forceinline __m128i _mm_unpacklo_epi16(__m128i a, __m128i b)
{
    int16x4_t a1 = vget_low_s16(vreinterpretq_s16_m128i(a));
    int16x4_t b1 = vget_low_s16(vreinterpretq_s16_m128i(b));
    int16x4x2_t result = vzip_s16(a1, b1);
    return vreinterpretq_m128i_s16(vcombine_s16(result.val[0], result.val[1]));
}

/// Interleaves the lower 2 signed or unsigned 32 - bit integers in a with the lower 2 signed or unsigned 32 - bit integers in b.
/// https://msdn.microsoft.com/en-us/library/x8atst9d(v=vs.100).aspx
__forceinline __m128i _mm_unpacklo_epi32(__m128i a, __m128i b)
{
    int32x2_t a1 = vget_low_s32(vreinterpretq_s32_m128i(a));
    int32x2_t b1 = vget_low_s32(vreinterpretq_s32_m128i(b));
    int32x2x2_t result = vzip_s32(a1, b1);
    return vreinterpretq_m128i_s32(vcombine_s32(result.val[0], result.val[1]));
}

/// Selects and interleaves the lower two single-precision, floating-point values from a and b.
/// https://msdn.microsoft.com/en-us/library/25st103b%28v=vs.90%29.aspx
__forceinline __m128 _mm_unpacklo_ps(__m128 a, __m128 b)
{
    float32x2_t a1 = vget_low_f32(vreinterpretq_f32_m128(a));
    float32x2_t b1 = vget_low_f32(vreinterpretq_f32_m128(b));
    float32x2x2_t result = vzip_f32(a1, b1);
    return vreinterpretq_m128_f32(vcombine_f32(result.val[0], result.val[1]));
}

/// Selects and interleaves the upper two single-precision, floating-point values from a and b.
/// https://msdn.microsoft.com/en-us/library/skccxx7d%28v=vs.90%29.aspx
__forceinline __m128 _mm_unpackhi_ps(__m128 a, __m128 b)
{
    float32x2_t a1 = vget_high_f32(vreinterpretq_f32_m128(a));
    float32x2_t b1 = vget_high_f32(vreinterpretq_f32_m128(b));
    float32x2x2_t result = vzip_f32(a1, b1);
    return vreinterpretq_m128_f32(vcombine_f32(result.val[0], result.val[1]));
}

/// Interleaves the upper 8 signed or unsigned 8-bit integers in a with the upper 8 signed or unsigned 8-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/t5h7783k(v=vs.100).aspx
__forceinline __m128i _mm_unpackhi_epi8(__m128i a, __m128i b)
{
    int8x8_t a1 = vreinterpret_s8_s16(vget_high_s16(vreinterpretq_s16_m128i(a)));
    int8x8_t b1 = vreinterpret_s8_s16(vget_high_s16(vreinterpretq_s16_m128i(b)));
    int8x8x2_t result = vzip_s8(a1, b1);
    return vreinterpretq_m128i_s8(vcombine_s8(result.val[0], result.val[1]));
}

/// Interleaves the upper 4 signed or unsigned 16-bit integers in a with the upper 4 signed or unsigned 16-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/03196cz7(v=vs.100).aspx
__forceinline __m128i _mm_unpackhi_epi16(__m128i a, __m128i b)
{
    int16x4_t a1 = vget_high_s16(vreinterpretq_s16_m128i(a));
    int16x4_t b1 = vget_high_s16(vreinterpretq_s16_m128i(b));
    int16x4x2_t result = vzip_s16(a1, b1);
    return vreinterpretq_m128i_s16(vcombine_s16(result.val[0], result.val[1]));
}

/// Interleaves the upper 2 signed or unsigned 32-bit integers in a with the upper 2 signed or unsigned 32-bit integers in b.
/// https://msdn.microsoft.com/en-us/library/65sa7cbs(v=vs.100).aspx
__forceinline __m128i _mm_unpackhi_epi32(__m128i a, __m128i b)
{
    int32x2_t a1 = vget_high_s32(vreinterpretq_s32_m128i(a));
    int32x2_t b1 = vget_high_s32(vreinterpretq_s32_m128i(b));
    int32x2x2_t result = vzip_s32(a1, b1);
    return vreinterpretq_m128i_s32(vcombine_s32(result.val[0], result.val[1]));
}

/// Extracts the selected signed or unsigned 16-bit integer from a and zero extends.
/// https://msdn.microsoft.com/en-us/library/6dceta0c(v=vs.100).aspx
//__forceinline int _mm_extract_epi16(__m128i a, __constrange(0,8) int imm)
#define _mm_extract_epi16(a, imm) \
({ \
	(vgetq_lane_s16(vreinterpretq_s16_m128i(a), (imm)) & 0x0000ffffUL); \
})

/// Inserts the least significant 16 bits of b into the selected 16-bit integer of a.
/// https://msdn.microsoft.com/en-us/library/kaze8hz1%28v=vs.100%29.aspx
//__forceinline __m128i _mm_insert_epi16(__m128i a, const int b, __constrange(0,8) int imm)
#define _mm_insert_epi16(a, b, imm) \
({ \
	vreinterpretq_m128i_s16(vsetq_lane_s16((b), vreinterpretq_s16_m128i(a), (imm))); \
})

// -------------------------------------------------------------
// Streaming Extensions
// -------------------------------------------------------------

/// Guarantees that every preceding store is globally visible before any subsequent store.
/// https://msdn.microsoft.com/en-us/library/5h2w73d1%28v=vs.90%29.aspx
__forceinline void _mm_sfence(void)
{
    __sync_synchronize();
}

/// #TODO - Implement correctly
__forceinline void _mm_stream_ps(float* p, __m128 a)
{
    _mm_store_ps(p, a);
}

/// Stores the data in a to the address p without polluting the caches.
/// If the cache line containing address p is already in the cache, the cache will be updated.
/// Address p must be 16 - byte aligned.
/// https://msdn.microsoft.com/en-us/library/ba08y07y%28v=vs.90%29.aspx
__forceinline void _mm_stream_si128(__m128i* p, __m128i a)
{
    *p = a;
}

/// Cache line containing p is flushed and invalidated from all caches in the coherency domain.
/// https://msdn.microsoft.com/en-us/library/ba08y07y(v=vs.100).aspx
__forceinline void _mm_clflush(void const* p)
{
}

/// Blend packed single-precision (32-bit) floating-point elements from a and b using mask, and store the results in dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_blendv_ps&expand=5217,3606,3720,5595,3828,3847,3857,2178,450
__forceinline __m128 _mm_blendv_ps(__m128 a, __m128 b, __m128 mask)
{
    return vreinterpretq_m128_s32(vbslq_s32(vreinterpretq_s32_m128(mask), vreinterpretq_s32_m128(b), vreinterpretq_s32_m128(a)));
}

/// Conditionally multiply the packed single-precision (32-bit) floating-point elements in a and b using the high 4 bits in imm8, sum the four products, and conditionally store the sum in dst using the low 4 bits of imm8.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_dp_ps&expand=5217,3606,3720,5595,3828,3847,3857,2178
__forceinline __m128 _mm_dp_ps(__m128 a, __m128 b, const int mask)
{
    __m128 prod = vmulq_f32(a, b);
    float32x2_t v1 = vadd_f32(vget_low_f32(prod), vget_high_f32(prod));
    v1 = vpadd_f32(v1, v1);
    return vcombine_f32(v1, v1);
}

/// Move the lower 2 single-precision (32-bit) floating-point elements from b to the upper 2 elements of dst, and copy the lower 2 elements from a to the lower 2 elements of dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_movelh_ps&expand=5217,3606,3720,5595,3828,3847,3857
__forceinline __m128 _mm_movelh_ps(__m128 a, __m128 b)
{
    return vcombine_f32(vget_low_f32(a), vget_low_f32(b));
}

/// Move the upper 2 single-precision (32-bit) floating-point elements from b to the lower 2 elements of dst, and copy the upper 2 elements from a to the upper 2 elements of dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_movehl_ps&expand=5217,3606,3720,5595,3828,3847
__forceinline __m128 _mm_movehl_ps(__m128 a, __m128 b)
{
    return vcombine_f32(vget_high_f32(b), vget_high_f32(a));
}

/// Move the lower single-precision (32-bit) floating-point element from b to the lower element of dst, and copy the upper 3 elements from a to the upper elements of dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_move_ss&expand=5217,3606,3720,5595,3828
__forceinline __m128 _mm_move_ss(__m128 a, __m128 b)
{
    return __builtin_shufflevector(b, a, 0, 5, 6, 7);
}

/// Negate packed 32-bit integers in a when the corresponding signed 32-bit integer in b is negative, and store the results in dst. Element in dst are zeroed out when the corresponding element in b is zero.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sign_epi32&expand=5217
__forceinline __m128i _mm_sign_epi32(__m128i a, __m128i b)
{
    __m128i c1 = vcgtq_s32(b, _mm_setzero_si128());
    __m128i ret = vandq_s32(a, c1);
    __m128i c2 = vcltq_s32(b, _mm_setzero_si128());
    return vaddq_s32(ret, vsubq_s32(_mm_setzero_si128(), vandq_s32(a, c2)));
}

/// Compare packed unsigned 32-bit integers in a and b, and store packed maximum values in dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_max_epu32&expand=5217,3606
__forceinline __m128i _mm_max_epu32(__m128i a, __m128i b)
{
    return vmaxq_u32(a, b);
}

/// Compare packed unsigned 32-bit integers in a and b, and store packed minimum values in dst.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_max_epu32&expand=5217,3606
__forceinline __m128i _mm_min_epu32(__m128i a, __m128i b)
{
    return vminq_u32(a, b);
}

/// Store the lower single-precision (32-bit) floating-point element from a into 4 contiguous elements in memory. mem_addr must be aligned on a 16-byte boundary or a general-protection exception may be generated.
/// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store1_ps&expand=5217,3606,3720,5595
__forceinline void _mm_store1_ps(float* mem_addr, __m128 a)
{
    vst1q_lane_f32(mem_addr, a, 0);
}

#define CONST_TO_DYNAMIC32(foo) \
__forceinline __m128i foo ## _dynamic(__m128i _v, int bits) { \
	switch (bits) \
	{ \
		case 1: return foo(_v, 1); \
		case 2: return foo(_v, 2); \
		case 3: return foo(_v, 3); \
		case 4: return foo(_v, 4); \
		case 5: return foo(_v, 5); \
		case 6: return foo(_v, 6); \
		case 7: return foo(_v, 7); \
		case 8: return foo(_v, 8); \
		case 9: return foo(_v, 9); \
		case 10: return foo(_v, 10); \
		case 11: return foo(_v, 11); \
		case 12: return foo(_v, 12); \
		case 13: return foo(_v, 13); \
		case 14: return foo(_v, 14); \
		case 15: return foo(_v, 15); \
		case 16: return foo(_v, 16); \
		case 17: return foo(_v, 17); \
		case 18: return foo(_v, 18); \
		case 19: return foo(_v, 19); \
		case 20: return foo(_v, 20); \
		case 21: return foo(_v, 21); \
		case 22: return foo(_v, 22); \
		case 23: return foo(_v, 23); \
		case 24: return foo(_v, 24); \
		case 25: return foo(_v, 25); \
		case 26: return foo(_v, 26); \
		case 27: return foo(_v, 27); \
		case 28: return foo(_v, 28); \
		case 29: return foo(_v, 29); \
		case 30: return foo(_v, 30); \
		case 31: return foo(_v, 31); \
	} \
	assert(0 && "Out of constant range"); \
	return _v; \
}

#include <assert.h>
CONST_TO_DYNAMIC32(_mm_slli_epi32);
CONST_TO_DYNAMIC32(_mm_srai_epi32);
CONST_TO_DYNAMIC32(_mm_srli_epi32);

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
