# Build flags and config details
- `VECTORMATH_ENABLE_CLANG_EXT`:
    - Compiler options: `-DVECTORMATH_ENABLE_CLANG_EXT`
    - Use clang vector extensions, only work with clang compiler.
    - Clang vector extensions support swizzle syntaxes.

- `VECTORMATH_SIMD_ENABLE`:
    - Compiler options: `-DVECTORMATH_SIMD_ENABLE`
    - Prefer to use SIMD if available, autoconfig to use SSE or NEON based on target platform.

- `VECTORMATH_USE_EXACT_PRECISION`:
    - Compiler options: `-DVECTORMATH_USE_EXACT_PRECISION`
    - Prefer good precision over fast math (currently use idSoftware FastInvSqrt)
    - Planning to do some fast trigonometric with simd instructions
