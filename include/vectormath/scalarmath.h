#pragma once

#include <math.h>
#include <stdint.h>
#include <stdbool.h>


// -------------------------------------------------------------
// Remove stupid stuffs
// -------------------------------------------------------------

#ifdef _WIN32
#undef min      // When Windows.h was included, `min` is an macro
#undef max      // When Windows.h was included, `max` is an macro
#undef far      // When Windows.h was included, `far` is an macro
#undef near     // When Windows.h was included, `near` is an macro
#endif

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
#       define __forceinline    static __attribute__((always_inline)) inline
#   elif !defined(__cplusplus)
#       define __forceinline    static inline
#   else
#       define __forceinline    inline
#   endif
#endif


// constexpr is helpful
// @note: experimental on !(defined(__clang__) || defined(__GNUC__))
#if !defined(__cplusplus) && !defined(constexpr) && __STDC_VERSION__ <= 201710L
#   define constexpr static const
#endif


// VECTORMATH_DEPRECATED is helpful
#if !defined(VECTORMATH_DEPRECATED)
#   if defined(_MSC_VER)
#      define VECTORMATH_DEPRECATED(alternative, ...) __declspec(deprecated("Please use " alternative " instead." ##__VA_ARGS__))
// #   elif defined(__APPLE__)
// #      define VECTORMATH_DEPRECATED(alternative, ...) __deprecated_msg("Please use " alternative " instead." ##__VA_ARGS__)
#   elif defined(__GNUC__)
#      define VECTORMATH_DEPRECATED(alternative, ...) __attribute__((deprecated("Please use " alternative " instead." ##__VA_ARGS__)))
#   elif defined(__cplusplus) && __cplusplus >= 201402L
#      define VECTORMATH_DEPRECATED(alternative, ...) [[deprecated("Please use " alternative " instead." ##__VA_ARGS__)]]
#   else
#      define VECTORMATH_DEPRECATED(alternative, ...)
#   endif
#endif


// -------------------------------------------------------------
// Types
// -------------------------------------------------------------

// NO TYPES NEED TO DEFINED

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
    const int32_t result = (x >> 31) | (!!x);
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
// uint32_t Functions
// -------------------------------------------------------------


/// Get the smaller value
__forceinline uint32_t uint32_min(uint32_t x, uint32_t y)
{
    return x < y ? x : y;
}


/// Get the larger value
__forceinline uint32_t uint32_max(uint32_t x, uint32_t y)
{
    return x > y ? x : y;
}


/// Clamps the 'x' to the [min, max]
__forceinline uint32_t uint32_clamp(uint32_t x, uint32_t min, uint32_t max)
{
    return x < min ? min : (x > max ? max : x);
}


// -------------------------------------------------------------
// float Functions
// -------------------------------------------------------------


/// Convert degrees to radians
__forceinline float float_deg2rad(float degrees)
{
    return degrees * FLOAT_PI / 180.0f;
}


/// Convert radians to degrees
__forceinline float float_rad2deg(float radians)
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


/// Computes absolute value
__forceinline float float_abs(float x)
{
    return fabsf(x);
}


/// Computes cosine
__forceinline float float_cos(float x)
{
    return cosf(x);
}


/// Computes sine
__forceinline float float_sin(float x)
{
    return sinf(x);
}


/// Computes tangent
__forceinline float float_tan(float x)
{
    return tanf(x);
}


/// Computes hyperbolic cosine
__forceinline float float_cosh(float x)
{
    return coshf(x);
}


/// Computes hyperbolic sine
__forceinline float float_sinh(float x)
{
    return sinhf(x);
}


/// Computes hyperbolic tangent
__forceinline float float_tanh(float x)
{
    return tanhf(x);
}


/// Computes inverse cosine
__forceinline float float_acos(float x)
{
    return acosf(x);
}


/// Computes inverse sine
__forceinline float float_asin(float x)
{
    return asinf(x);
}


/// Computes inverse tangent
__forceinline float float_atan(float x)
{
    return atanf(x);
}


/// Computes inverse tangent with 2 args
__forceinline float float_atan2(float x, float y)
{
    return atan2f(x, y);
}


/// Computes Euler number raised to the power 'x'
__forceinline float float_exp(float x)
{
    return expf(x);
}


/// Computes 2 raised to the power 'x'
__forceinline float float_exp2(float x)
{
    return exp2f(x);
}


/// Computes the base Euler number logarithm
__forceinline float float_log(float x)
{
    return logf(x);
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


/// Computes the base 2 logarithm
__forceinline float float_log2(float x)
{
    return (logf(x) / 0.693147180559945f);
}
#else
/// Computes the base 2 logarithm
__forceinline float float_log2(float x)
{
    return log2f(x);
}
#endif // Android polyfill for log2 and log2f


/// Computes the base 10 logarithm
__forceinline float float_log10(float x)
{
    return log10f(x);
}


/// Computes the value of base raised to the power exponent
__forceinline float float_pow(float x, float y)
{
    return powf(x, y);
}


/// Get the fractal part of floating point
__forceinline float float_fract(float x)
{
    float y;
    return modff(x, &y);
}


/// Get the fractal part of floating point
VECTORMATH_DEPRECATED("float_fract")
__forceinline float float_frac(float x)
{
    return float_fract(x);
}


/// Computes the floating-point remainder of the division operation x/y
__forceinline float float_mod(float x, float y)
{
    return fmodf(x, y);
}


/// Computes the floating-point remainder of the division operation x/y
VECTORMATH_DEPRECATED("float_mod")
__forceinline float float_fmod(float x, float y)
{
    return float_mod(x, y);
}


/// Computes the smallest integer value not less than 'x'
__forceinline float float_ceil(float x)
{
    return ceilf(x);
}


/// Computes the largest integer value not greater than 'x'
__forceinline float float_floor(float x)
{
    return floorf(x);
}


/// Computes the nearest integer value
__forceinline float float_round(float x)
{
    return roundf(x);
}


/// Computes the nearest integer not greater in magnitude than 'x'
__forceinline float float_trunc(float x)
{
    return truncf(x);
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


/// Performs x linear interpolation.
__forceinline float float_lerp(float x, float y, float s)
{
    return x + (y - x) * s;
}


/// Computes square root of 'x'.
__forceinline float float_sqrt(float x)
{
    return sqrtf(x);
}


/// Computes inverse square root of 'x', using FastInvSqrt algorithm.
__forceinline float float_fast_rsqrt(float x)
{
    union
    {
        float f;
        int   i;
    } cvt;
    float xhalf = 0.5f * x;
    cvt.f = x;
    cvt.i = 0x5f3759df - (cvt.i >> 1); 
    cvt.f = cvt.f * (1.5f - xhalf * cvt.f * cvt.f); // first approximation
    cvt.f = cvt.f * (1.5f - xhalf * cvt.f * cvt.f); // second approximation
    return cvt.f;
}


/// Computes inverse square root of 'x'.
__forceinline float float_rsqrt(float x)
{
#if VECTORMATH_USE_EXACT_PRECISION
    return 1.0f / float_sqrt(x);
#else
    return float_fast_rsqrt(x);
#endif
}


/// Compute x smooth Hermite interpolation
/// @return: 0 if x <= min
///          1 if x >= max
///          (0, 1) otherwise
__forceinline float float_smoothstep(float min, float max, float x)
{
    return (float_clamp(x, min, max) - min) / (max - min);
}


/// Test is two values are closely equal
__forceinline bool float_isclose(float x, float y)
{
    return float_abs(x - y) <= FLOAT_EPSILON;
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
