#pragma once

#include "vector_types.h"

#if VECTORMATH_SIMD_ENABLE
#   if VECTORMATH_NEON_SUPPORT
#       include "sse_to_neon.h"
#   endif
#   include "vector_math_simd.h"
#else
#   include "vector_math_scalar.h"
#endif

#include "vector_math_operators.h"

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
