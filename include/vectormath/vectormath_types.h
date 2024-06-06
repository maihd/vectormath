#pragma once

// Vector components types should be fixed-size
// We use standard fixed-size types for compat
#include <stdint.h>

// Helper for extensions
#ifndef VECTORMATH_TYPES_DEFINED
#define VECTORMATH_TYPES_DEFINED
#endif

// -------------------------------------------------------------
// Prefer language extensions if enabled
// -------------------------------------------------------------

#if defined(__clang__) && __clang__ && VECTORMATH_USE_CLANG_EXT
#define VECTORMATH_ENABLE_CLANG_EXT 1
#else
#define VECTORMATH_ENABLE_CLANG_EXT 0
#endif

#if VECTORMATH_ENABLE_CLANG_EXT
#undef  VECTORMATH_SIMD_ENABLE
#define VECTORMATH_SIMD_ENABLE 0 // Force to not use simd
#endif

// Only Visual Studio 2022 support clang vector extensions (maybe only it work well with clang)
// #if VECTORMATH_ENABLE_CLANG_EXT && defined(_MSC_VER) && _MSC_VER < 1930
// #undef  VECTORMATH_ENABLE_CLANG_EXT
// #define VECTORMATH_ENABLE_CLANG_EXT 0
// #endif

// -------------------------------------------------------------
// Data structure alignment
// -------------------------------------------------------------

#ifndef VECTORMATH_ALIGNAS
#   if defined(__cplusplus)
#       define VECTORMATH_ALIGNAS(TYPE_NAME, ALIGNMENT) alignas(ALIGNMENT) TYPE_NAME
#   elif defined(__GNUC__)
#       define VECTORMATH_ALIGNAS(TYPE_NAME, ALIGNMENT) TYPE_NAME __attribute__((aligned(ALIGNMENT)))
#   elif defined(_MSC_VER)
#       define VECTORMATH_ALIGNAS(TYPE_NAME, ALIGNMENT) __declspec(align(ALIGNMENT)) TYPE_NAME
#   else
#       error The compiler is not support alignas operator.
#   endif
#endif

#ifndef VECTORMATH_VECTORTYPE
#   if defined(_MSC_VER) && !defined(__clang__)
#       define VECTORMATH_VECTORTYPE(TYPE_NAME, ALIGNMENT) __declspec(intrin_type) VECTORMATH_ALIGNAS(TYPE_NAME, ALIGNMENT)
#   else
#       define VECTORMATH_VECTORTYPE(TYPE_NAME, ALIGNMENT) VECTORMATH_ALIGNAS(TYPE_NAME, ALIGNMENT)
#   endif
#endif

// -------------------------------------------------------------
// SIMD Supporting
// -------------------------------------------------------------

#ifndef VECTORMATH_SIMD_ENABLE
#define VECTORMATH_SIMD_ENABLE 1
#endif

// Detect neon support & enable
//#define VECTORMATH_NEON_SUPPORT 0 // No neon support now
#if (defined(__ARM_NEON) || defined(__ARM_NEON__))
#   if defined(__ARM_ARCH_7A__) && defined(__ANDROID__)
#       define VECTORMATH_NEON_SUPPORT 0 // NO SUPPORT for Android 32bit
#   else
#       define VECTORMATH_NEON_SUPPORT 1
#   endif
#else
#   define VECTORMATH_NEON_SUPPORT 0
#endif

// Detect SSE support & enable
#define VECTORMATH_SSE_SUPPORT 0

#if defined(__SSSE3__)
#   undef  VECTORMATH_SSE_SUPPORT
#   define VECTORMATH_SSE_SUPPORT 1
#endif

#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
#   undef  VECTORMATH_SSE_SUPPORT
#   define VECTORMATH_SSE_SUPPORT 1
#endif

#if defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__SSE_MATH__)
#   undef  VECTORMATH_SSE_SUPPORT
#   define VECTORMATH_SSE_SUPPORT 1
#endif

#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_IX64))
#   if defined(_M_HYBRID_X86_ARM64)
#       undef  VECTORMATH_SSE_SUPPORT
#       define VECTORMATH_SSE_SUPPORT 0
#   else
#       undef  VECTORMATH_SSE_SUPPORT
#       define VECTORMATH_SSE_SUPPORT 1
#   endif
#endif

#if (defined(__AVX__) || defined(__AVX2__) || defined(_M_AMD64) || defined(_M_X64) || (_M_IX86_FP == 1) || (_M_IX86_FP == 2))
#   undef  VECTORMATH_SSE_SUPPORT
#   define VECTORMATH_SSE_SUPPORT 1
#endif

// Disable SIMD on unsupported CPU
#if !VECTORMATH_SSE_SUPPORT && !VECTORMATH_NEON_SUPPORT
#   undef  VECTORMATH_SIMD_ENABLE
#   define VECTORMATH_SIMD_ENABLE 0
#endif

// Define __m128
#if VECTORMATH_SSE_SUPPORT
#   include <emmintrin.h>
    typedef __m128i		__m128u;
#elif VECTORMATH_NEON_SUPPORT
#   include "sse_to_neon.h"
#elif !VECTORMATH_ENABLE_CLANG_EXT
    typedef struct      __m64   { float      data[2]; } __m64;
    typedef struct      __m128  { float      data[4]; } __m128;
    typedef struct      __m128i { int32_t    data[4]; } __m128i;
    typedef struct      __m128u { uint32_t   data[4]; } __m128u;
#endif

// -------------------------------------------------------------
// Types
// -------------------------------------------------------------

#if VECTORMATH_ENABLE_CLANG_EXT
/// vec2
/// 2D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y]
typedef float vec2 __attribute__((ext_vector_type(2), aligned(4)));


/// vec3
/// 3D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y][float z][float __unused]
typedef float vec3 __attribute__((ext_vector_type(3), aligned(16)));


/// vec4
/// 4D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y][float z][float w]
typedef float vec4 __attribute__((ext_vector_type(4), aligned(16)));


/// ivec2
/// 2D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y]
typedef int32_t ivec2 __attribute__((ext_vector_type(2), aligned(4)));


/// ivec3
/// 3D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y][int32_t z][int32_t __unused]
typedef int32_t ivec3 __attribute__((ext_vector_type(3), aligned(16)));


/// ivec4
/// 4D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y][int32_t z][int32_t w]
typedef int32_t ivec4 __attribute__((ext_vector_type(4), aligned(16)));


/// uvec2
/// 2D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y]
typedef uint32_t uvec2 __attribute__((ext_vector_type(2), aligned(4)));


/// uvec3
/// 3D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y][uint32_t z][uint32_t __unused]
typedef uint32_t uvec3 __attribute__((ext_vector_type(3), aligned(16)));


/// uvec4
/// 4D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y][uint32_t z][uint32_t w]
typedef uint32_t uvec4 __attribute__((ext_vector_type(4), aligned(16)));
#else
/// vec2
/// 2D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y]
typedef struct VECTORMATH_ALIGNAS(vec2, 4)
{
    float                       x;
    float                       y;
} vec2;


/// vec3
/// 3D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y][float z][float __unused]
typedef union VECTORMATH_VECTORTYPE(vec3, 16)
{
    struct
    {
        float                   x;
		
		union
		{
			struct
			{
				float           y;
				float           z;
			};
			vec2				yz;
		};
    };
    vec2                        xy;

    // Internal
    __m128                      m128;
    float                       data[4];
} vec3;


/// vec4
/// 4D floating-point vector
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: [float x][float y][float z][float w]
typedef union VECTORMATH_VECTORTYPE(vec4, 16)
{
    struct
    {
        float                   x;

		union
		{
			struct
			{
				float           y;
				float           z;
			};
			vec2				yz;
		};

        union
        {

            float               w;
            float               angle;
        };
    };

    struct
    {
        vec2                    xy;
        vec2                    zw;
    };

    vec3                        xyz;
    vec3                        axis;

    // Internal
    __m128                      m128;
    //float                       data[4];
} vec4;


/// ivec2
/// 2D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y]
typedef struct VECTORMATH_ALIGNAS(ivec2, 4)
{
    int32_t                     x, y;
} ivec2;


/// ivec3
/// 3D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y][int32_t z][int32_t __unused]
typedef union VECTORMATH_VECTORTYPE(ivec3, 16)
{
    struct
    {
        int32_t                 x, y, z;
    };

    // Internal
    __m128i                     m128i;
    int32_t                     data[4];
} ivec3;


/// ivec4
/// 4D integer vector
/// Components are 32 bit fixed-size signed integer
/// Struct Layout: [int32_t x][int32_t y][int32_t z][int32_t w]
typedef union VECTORMATH_VECTORTYPE(ivec4, 16)
{
    struct
    {
        int32_t                 x, y, z, w;
    };

    // Internal
    __m128i                     m128i;
    int32_t                     data[4];
} ivec4;


/// ivec2
/// 2D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y]
typedef struct VECTORMATH_ALIGNAS(uvec2, 4)
{
    uint32_t                    x, y;
} uvec2;


/// ivec3
/// 3D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y][uint32_t z][uint32_t __unused]
typedef union VECTORMATH_VECTORTYPE(uvec3, 16)
{
    struct
    {
        uint32_t                x, y, z;
    };

    // Internal
    __m128u                     m128u;
    uint32_t                    data[4];
} uvec3;


/// ivec4
/// 4D integer vector
/// Components are 32 bit fixed-size unsigned integer
/// Struct Layout: [uint32_t x][uint32_t y][uint32_t z][uint32_t w]
typedef union VECTORMATH_VECTORTYPE(uvec4, 16)
{
    struct
    {
        uint32_t                x, y, z, w;
    };

    // Internal
    __m128u                     m128u;
    uint32_t                    data[4];
} uvec4;
#endif // VECTORMATH_USE_CLANG_EXT


/// mat2
/// 2x2 floating-point matrix (default col-major, row-major is supported)
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: 
///		[float m00][float m01]
///		[float m10][float m11]
typedef union VECTORMATH_VECTORTYPE(mat2, 16)
{
    struct
    {
        vec2                    v0;
        vec2                    v1;
    };

    struct
    {
        vec2                    row0;
        vec2                    row1;
    };

    struct
    {
        vec2                    col0;
        vec2                    col1;
    };

    struct
    {
        float                   m00, m01;
        float                   m10, m11;
    };

    vec2                        vecs[2];            // Matrix rows array
    vec2                        rows[2];            // Matrix rows array
    vec2                        cols[2];            // Matrix cols array

    // Internal
    __m128                      m128;
    float                       data[4];
} mat2;


/// mat3
/// 3x3 floating-point matrix (default col-major, row-major is supported)
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: 
///		[float m00][float m01][float m02][float _m03]
///		[float m10][float m11][float m12][float _m13]
///		[float m20][float m21][float m22][float _m23]
typedef union VECTORMATH_VECTORTYPE(mat3, 16)
{
    struct
    {
        vec3                    v0;
        vec3                    v1;
        vec3                    v2;
    };

    struct
    {
        vec3                    row0;
        vec3                    row1;
        vec3                    row2;
    };

    struct
    {
        vec3                    col0;
        vec3                    col1;
        vec3                    col2;
    };

    struct
    {
        float                   m00, m01, m02, _m03;
        float                   m10, m11, m12, _m13;
        float                   m20, m21, m22, _m23;
    };

    vec3                        vecs[3];            // Matrix vecs array
    vec3                        rows[3];            // Matrix rows array
    vec3                        cols[3];            // Matrix cols array
    
    // Internal
    float                       data[12];
} mat3;


/// mat4
/// 4x4 floating-point matrix (default col-major, row-major is supported)
/// Components are 32 bit fixed-size floating-point number
/// Struct Layout: 
///		[float m00][float m01][float m02][float m03]
///		[float m10][float m11][float m12][float m13]
///		[float m20][float m21][float m22][float m23]
///		[float m30][float m31][float m32][float m33]
typedef union VECTORMATH_VECTORTYPE(mat4, 16)
{
    struct
    {
        vec4                    v0;               // Matrix first vec  (4 components)
        vec4                    v1;               // Matrix second vec (4 components)
        vec4                    v2;               // Matrix third vec  (4 components)
        vec4                    v3;               // Matrix fourth vec (4 components)
    };
    
    struct
    {
        vec4                    row0;               // Matrix first row  (4 components)
        vec4                    row1;               // Matrix second row (4 components)
        vec4                    row2;               // Matrix third row  (4 components)
        vec4                    row3;               // Matrix fourth row (4 components)
    };

    struct
    {
        vec4                    col0;               // Matrix first col  (4 components)
        vec4                    col1;               // Matrix second col (4 components)
        vec4                    col2;               // Matrix third col  (4 components)
        vec4                    col3;               // Matrix fourth col (4 components)
    };

    struct
    {
        float                   m00, m01, m02, m03; // Matrix first col  (4 components)
        float                   m10, m11, m12, m13; // Matrix second col (4 components)
        float                   m20, m21, m22, m23; // Matrix third col  (4 components)
        float                   m30, m31, m32, m33; // Matrix fourth col (4 components)
    };

    vec4                        vecs[4];            // Matrix vecs array
    vec4                        rows[4];            // Matrix rows array
    vec4                        cols[4];            // Matrix cols array

    // Internal
    float                       data[16];
} mat4;


// -------------------------------------------------------------
// Type size and align verification
// -------------------------------------------------------------

#if !defined(__cplusplus) && !defined(static_assert)
#   if __STDC_VERSION__ >= 201112L
#       define static_assert _Static_assert             
#   else
#       define __static_assert_2(cond, msg, x)  static const int __static_assert_##x[(cond) ? 1 : -1] = { 0 }
#       define __static_assert_1(cond, msg, x)  __static_assert_2(cond, msg, x)
#       define static_assert(cond, msg)         __static_assert_1(cond, msg, __LINE__)
#   endif
#endif

static_assert(sizeof(vec2)  ==  8, "sizeof(vec2) must be 8 bytes");
static_assert(sizeof(vec3)  == 16, "sizeof(vec3) must be 16 bytes");
static_assert(sizeof(vec4)  == 16, "sizeof(vec4) must be 16 bytes");

static_assert(sizeof(ivec2) ==  8, "sizeof(ivec2) must be 8 bytes");
static_assert(sizeof(ivec3) == 16, "sizeof(ivec3) must be 16 bytes");
static_assert(sizeof(ivec4) == 16, "sizeof(ivec4) must be 16 bytes");

static_assert(sizeof(uvec2) ==  8, "sizeof(uvec2) must be 8 bytes");
static_assert(sizeof(uvec3) == 16, "sizeof(uvec3) must be 16 bytes");
static_assert(sizeof(uvec4) == 16, "sizeof(uvec4) must be 16 bytes");

static_assert(sizeof(mat2)  == 16, "sizeof(mat2) must be 16 bytes");
static_assert(sizeof(mat3)  == 48, "sizeof(mat3) must be 48 bytes");
static_assert(sizeof(mat4)  == 64, "sizeof(mat4) must be 64 bytes");

#if !defined(__cplusplus) && !defined(alignof)
#if defined(_MSC_VER)
#define alignof __alignof
#else
#define alignof __alignof__
#endif
#endif

static_assert(alignof(vec2)  ==  4, "alignof(vec2) must be 4 bytes");
static_assert(alignof(vec3)  == 16, "alignof(vec3) must be 16 bytes");
static_assert(alignof(vec4)  == 16, "alignof(vec4) must be 16 bytes");

static_assert(alignof(ivec2) ==  4, "alignof(ivec2) must be 4 bytes");
static_assert(alignof(ivec3) == 16, "alignof(ivec3) must be 16 bytes");
static_assert(alignof(ivec4) == 16, "alignof(ivec4) must be 16 bytes");

static_assert(alignof(uvec2) ==  4, "alignof(uvec2) must be 4 bytes");
static_assert(alignof(uvec3) == 16, "alignof(uvec3) must be 16 bytes");
static_assert(alignof(uvec4) == 16, "alignof(uvec4) must be 16 bytes");

static_assert(alignof(mat2)  == 16, "alignof(mat2) must be 16 bytes");
static_assert(alignof(mat3)  == 16, "alignof(mat3) must be 16 bytes");
static_assert(alignof(mat4)  == 16, "alignof(mat4) must be 16 bytes");

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
