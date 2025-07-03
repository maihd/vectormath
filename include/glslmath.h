#pragma once

// -------------------------------------------------------------
// Compiler configuration
// -------------------------------------------------------------

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
// Functions
// -------------------------------------------------------------

#include "vectormath.h"

__forceinline float cos(float x)
{
    return cosf(x);
}

__forceinline float sin(float x)
{
    return sinf(x);
}

//! EOF
