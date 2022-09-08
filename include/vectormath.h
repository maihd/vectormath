#pragma once

#include "vectormath_types.h"

#if VECTORMATH_SIMD_ENABLE
#   if VECTORMATH_NEON_SUPPORT
#       include "sse_to_neon.h"
#   endif
#   include "vectormath_simd.h"
#else
#   include "vectormath_scalar.h"
#endif

#include "vectormath_operators.h"

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
