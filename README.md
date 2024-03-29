# Vector Math library based on Sony's Math library (Write new, not mod)

## Features and Design philosophy
- Scalar math for graphics/game: `int32_t`, `uint32_t`, `float32_t` (typedef of `float` for *common* computers)
- Vector math for graphics/game: `vec2`, `vec3`, `vec4`, `ivec2`, `ivec3`, `ivec4`, `uvec2`, `uvec3`, `uvec4`, `quat`, `mat2`, `mat3`, `mat4`
- Data structure is PODs only (no constructors)
- Parameter pass-by-value, return as value (only few functions use pass-by-pointer for multi-return purpose)
- Swizzle-like functions (easier to implement vs C++ properties)
- C++ operators overloading
- (Only clang) vector-extensions, swizzle properties, operators overloading
- Component-wise computing, specific computing for graphics math, only functions
- Seperate data types and functions in headers, support better compile speed, only include what needed
- Find more in `docs/coding_standards.md`

## TODOs
- Make all code use `float32_t` instead of `float`, for clearer size of floating-point number type
- Add project showcases
- API docs and usage docs
- Full clang extensions without deps on `__m128` for portable (on clang implementation)
- Make an example that use full advantages of clang vector extensions
- Benchmarking
- Maybe pattern solution for common problem in game/graphics development
- Make the first stable release
- Support more systems: left/right handed, vertical/horizontal field of view
- Choose namespace for primitives between: `int32`, `i32`, `int` (same with uint32, float32)
    - `int32`: Same name with type `int32_t`, but too long
    - `i32`: Short enough, not common in C, but maybe familiar for someones
    - `int`: Short enough, common in C, but have no size

## Import/include instructions
- This library is headers only, you can easily import to your projects
- Use scripts/vectormath.genie.lua (WIP) to import to projects that support GENie
- Use scripts/vectormath.premake5.lua to import to projects that support premake5

## Build instructions (examples and tests projects)
- Run premake5 or GENie (WIP) to generate projects
- Build with your chosen build system
- (WIP) Planning to add cmake

## Small taste
```C
vec3 position = vec3_new(100.0f, 200.0f, 10.0f);
vec4 rotation = quat_from_euler(0.0f, 0.0f, 0.0f);
vec3 scale    = vec3_new1(1.0f);
mat4 model    = mat4_mul(mat4_mul(mat4_translation_vec3(position),
                                  mat4_rotation_quat(rotation)),
                         mat4_scalation_vec3(scale));

// Perspective matrix with 45 degrees field-of-view
mat4 proj = mat4_perspective(float32_deg2rad(45), WIDTH / HEIGHT, 0.0f, 100.0f);

... apply matrix to render ...
```

## Showcase examples
- Please check folder `examples` to exploring

## Language bindings
Language bindings only prefer transpiling language like Haxe (maybe only), that use C++ code to compile, which may using the advantages of inlining optimization. Other languages may need FFI, C ABI to call functions (not inlining),
so other languages you should use the libraries written specifily for thoses languages. (Like Zig have zmath, Odin have native support for vector/matrix types)
- Haxe Reflaxe.CPP (bindgen with nodejs script)

## FAQs
- Why another math library? I'm a big fan of The-Forge renderer, when I read the source, discovered Sony's Math library. But the Sony's Math was support C++ only, then I write a port to support both C and C++ for learning purposes.

- Why Unlicense? Mostly source codes were re-written from The-Forge's VectorMath library, so I don't own the code. (I found the code with the same design with this library, but older: https://github.com/zauonlok/renderer/blob/master/renderer/core/maths.h)
- Where the functions docs, and tutorials? WIP.
- Advance usages, configs, build flags docs? Find out in [build_flags](docs/build_flags.md).
- More examples on some popular renderers (bgfx, The-Forge)? Learning.
- I want to use it with Raylib? replace struct definition of VectorX with typedef and it will work, Matrix must be do more work.
- More about performance? Not the fastest, but enough to use with small project.
- Is it stable yet? No.

## Meta
- Version: v0.2.0-dev
- License: UNLICENSED
- Copyright: MaiHD @ 2022 - 2024
