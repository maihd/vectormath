#pragma once

#include "vector_types.h"

#if VECTORMATH_SIMD_ENABLE && 0
#   if VECTORMATH_NEON_SUPPORT
#       include "sse_to_neon.h"
#   endif
#   include "vector_math_simd.h"
#else
#   include "vector_math_scalar.h"
#endif
