#pragma once

#include "VectorTypes.h"

#if VECTORMATH_SIMD_ENABLE && 0
#   if VECTORMATH_NEON_SUPPORT
#       include "SSE2Neon.h"
#   endif
#   include "VectorMathSimd.h"
#else
#   include "VectorMathScalar.h"
#endif
