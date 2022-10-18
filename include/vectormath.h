#pragma once

#include "vectormath/vectormath_types.h"

#if VECTORMATH_SIMD_ENABLE
#   if VECTORMATH_NEON_SUPPORT
#       include "vectormath/sse_to_neon.h"
#   endif
#   include "vectormath/vectormath_simd.h"
#else
#   include "vectormath/vectormath_scalar.h"
#endif

#include "vectormath/vectormath_operators.h"
#include "vectormath/vectormath_swizzles.h"

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
