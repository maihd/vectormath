#pragma once

#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// -------------------------------------------------------------
// Remove stupid stuffs
// -------------------------------------------------------------

#undef min      // When Windows.h was included, `min` is an macro
#undef max      // When Windows.h was included, `max` is an macro
#undef far      // When Windows.h was included, `far` is an macro
#undef near     // When Windows.h was included, `near` is an macro

// -------------------------------------------------------------
// Compiler settings
// -------------------------------------------------------------

#if !defined(_MSC_VER) && !defined(__vectorcall)
#   if defined(__GNUC__)
#       define __vectorcall  /* NO VECTORCALL SUPPORTED */
#   else
#       define __vectorcall  /* NO VECTORCALL SUPPORTED */
#   endif
#endif

#if !defined(_MSC_VER) && !defined(__forceinline)
#   if defined(__GNUC__)
#       define __forceinline    static __attribute__((always_inline))
#   elif defined(__cplusplus)
#       define __forceinline    static inline
#   else
#       define __forceinline    inline
#   endif
#endif

// constexpr is helpful
#if !defined(__cplusplus) && !defined(constexpr)
#   define constexpr static const
#endif

// -------------------------------------------------------------
// Constants
// -------------------------------------------------------------

constexpr int32_t   FLOAT_DECIMAL_DIG       = 9;                        // # of decimal digits of rounding precision
constexpr int32_t   FLOAT_DIG               = 6;                        // # of decimal digits of precision
constexpr float     FLOAT_EPSILON           = 1.192092896e-07F;         // smallest such that 1.0+FLT_EPSILON != 1.0
constexpr float     FLOAT_HAS_SUBNORM       = 1;                        // type does support subnormal numbers
constexpr float     FLOAT_GUARD             = 0;
constexpr float     FLOAT_MANT_DIG          = 24;                       // # of bits in mantissa
constexpr float     FLOAT_MAX               = 3.402823466e+38F;         // max value
constexpr float     FLOAT_MAX_10_EXP        = 38;                       // max decimal exponent
constexpr float     FLOAT_MAX_EXP           = 128;                      // max binary exponent
constexpr float     FLOAT_MIN               = 1.175494351e-38F;         // min normalized positive value
constexpr int32_t   FLOAT_MIN_10_EXP        = (-37);                    // min decimal exponent
constexpr int32_t   FLOAT_MIN_EXP           = (-125);                   // min binary exponent
constexpr int32_t   FLOAT_NORMALIZE         = 0;
constexpr int32_t   FLOAT_RADIX             = 2;                        // exponent radix
constexpr float     FLOAT_TRUE_MIN          = 1.401298464e-45F;         // min positive value

constexpr float     FLOAT_PI                = 3.141592653589f;
constexpr float     FLOAT_TWO_PI            = 3.141592653589f * 2.0f;
constexpr float     FLOAT_HALF_PI           = 3.141592653589f * 0.5f;
constexpr float     FLOAT_THREE_HALF_PI     = 3.141592653589f * 1.5f;

constexpr float     FLOAT_INV_PI            = 1.0f / (3.141592653589f * 1.0f);
constexpr float     FLOAT_INV_TWO_PI        = 1.0f / (3.141592653589f * 2.0f);
constexpr float     FLOAT_INV_HALF_PI       = 1.0f / (3.141592653589f * 0.5f);
constexpr float     FLOAT_INV_THREE_HALF_PI = 1.0f / (3.141592653589f * 1.5f);

// -------------------------------------------------------------
// int32_t Functions
// -------------------------------------------------------------

/// Compute the sign of 'x'
__forceinline int32_t int32_sign(int32_t x)
{
    const int result = (x >> 31) | (!!x);
	return result;
}

/// Get the smaller value
__forceinline int32_t int32_min(int32_t x, int32_t y)
{
    return x < y ? x : y;
}

/// Get the larger value
__forceinline int32_t int32_max(int32_t x, int32_t y)
{
    return x > y ? x : y;
}

/// Clamps the 'x' to the [min, max]
__forceinline int32_t int32_clamp(int32_t x, int32_t min, int32_t max)
{
    return x < min ? min : (x > max ? max : x);
}

// -------------------------------------------------------------
// float Functions
// -------------------------------------------------------------

/// Convert degrees to radians
__forceinline float float_rad2deg(float degrees)
{
    return degrees * FLOAT_PI / 180.0f;
}

/// Convert radians to degrees
__forceinline float float_deg2rad(float radians)
{
    return radians * 180.0f / FLOAT_PI;
}

/// Computes sign of 'x'
__forceinline int32_t float_sign(float x)
{
    union
    {
        float f;
        int   i;
    } cvt;
    cvt.f = x;
    return int32_sign(cvt.i);
}

/// Get the fractal part of floating point
__forceinline float float_frac(float x)
{
    float y;
    return modff(x, &y);
}

// Android polyfill for log2 and log2f
#if defined(__ANDROID__) && defined(__ANDROID_API__) && __ANDROID_API__ < 18
__forceinline float log2f(float x)
{
    return (logf(x) / 0.693147180559945f);
}

__forceinline double log2(double x)
{
    return (log(x) / 0.693147180559945);
}
#endif

__forceinline float float_log2(float x)
{
    return (logf(x) / 0.693147180559945f);
}

/// Get the smaller value
__forceinline float float_min(float x, float y)
{
    return x < y ? x : y;
}

/// Get the larger value
__forceinline float float_max(float x, float y)
{
    return x > y ? x : y;
}

/// Clamps the 'x' value to the [min, max].
__forceinline float float_clamp(float x, float min, float max)
{
    return x < min ? min : (x > max ? max : x);
}

/// Clamps the specified value within the range of 0 to 1
__forceinline float float_saturate(float x)
{
    return float_clamp(x, 0.0f, 1.0f);
}

/// Compares two values, returning 0 or 1 based on which value is greater.
__forceinline float float_step(float y, float x)
{
    return (float)(x >= y);
}

/// Performs a linear interpolation.
__forceinline float float_lerp(float x, float y, float s)
{
    return x + (y - x) * s;
}

/// Computes inverse square root of 'x'.
__forceinline float float_rsqrt(float x)
{
    return 1.0f / sqrtf(x);
}

/// Compute a smooth Hermite interpolation
/// @return: 0 if x <= min
///          1 if x >= max
///          (0, 1) otherwise
__forceinline float float_smoothstep(float min, float max, float x)
{
    return (float_clamp(x, min, max) - min) / (max - min);
}

/// Test is two values are closely equal
__forceinline bool float_isclose(float a, float b)
{
    return fabsf(a - b) <= FLOAT_EPSILON;
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
