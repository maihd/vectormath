return {
    includedirs = function (directory)
        files {
            --path.join(ROOT_DIR, "unit_tests/test_run_all.cpp"),
            path.join(directory, "include/sse_to_neon.h"),
            path.join(directory, "include/stdmath_extensions.h"),
    
            path.join(directory, "include/vectormath_types.h"),
            path.join(directory, "include/vectormath_types.natvis"),
    
            path.join(directory, "include/vectormath_scalar.h"),
            path.join(directory, "include/vectormath_simd.h"),
            path.join(directory, "include/vectormath_operators.h"),
    
            path.join(directory, "include/vectormath.h"),
        }
    end
}