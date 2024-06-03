#pragma once

#include "vectormath/vectormath_types.h"

#if VECTORMATH_ENABLE_CLANG_EXT
#   include "vectormath/vectormath_clang.h"
#elif VECTORMATH_SIMD_ENABLE
// #if VECTORMATH_SIMD_ENABLE
#   include "vectormath/vectormath_simd.h"
#else
#   include "vectormath/vectormath_scalar.h"
#endif

#include "vectormath/vectormath_operators.h"
#include "vectormath/vectormath_swizzles.h"
#include "vectormath/vectormath_constructors.h"

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
