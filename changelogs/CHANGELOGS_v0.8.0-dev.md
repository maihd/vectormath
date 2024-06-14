# VectorMath changelogs v0.8.0-dev
- Add constructors: quat, mat4
- Add quat as a alias type of vec4
- Constructors: add error message when using if compiler does not support
- Constructors: overloading like GLSL
- Avoid .m128 usage simd, that cause unportable code on clang extensions
- Merge simd and clang implementation into one, remove vectormath_clang.h file
- Add docs: CONTRIBUTING.md, SECURITY.md, PULL_REQUEST_TEMPLATE.md
- Operators: temporary hide vec2 * mat4, mat4 * vec2, vec3 * mat4, mat4 * vec3. Maybe add a config later.