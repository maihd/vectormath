return {
    includedirs = function (directory)
        includedirs {
            path.join(directory, "include")
        }

        files {
            path.join(directory, "vectormath_types.natvis"),
        }
    end,

    files = function (directory)
        files {
            path.join(directory, "include/vectormath/sse_to_neon.h"),
            path.join(directory, "include/vectormath/stdmath_extensions.h"),
    
            path.join(directory, "include/vectormath/vectormath_types.h"),
    
            path.join(directory, "include/vectormath/vectormath_scalar.h"),
            path.join(directory, "include/vectormath/vectormath_simd.h"),
            path.join(directory, "include/vectormath/vectormath_operators.h"),
    
            path.join(directory, "include/vectormath.h"),
        }
    end
}