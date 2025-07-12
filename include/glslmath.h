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


//! EOF
