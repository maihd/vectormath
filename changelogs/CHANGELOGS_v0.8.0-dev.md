# VectorMath changelogs v0.8.0-dev
- Add constructors: quat, mat4
- Add quat as a alias type of vec4
- Avoid .m128 usage simd, that cause unportable code on clang extensions
- Merge simd and clang implementation into one, remove vectormath_clang.h file