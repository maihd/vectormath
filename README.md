# Vector Math library based on Sony's Math library (Write new, not mod, cause different from origin version)

## Contents
- [Features and Design philosophy](#features)
- [Import/include instructions](#include-instructions)
- [Build instructions](#build-instructions)
- [Small taste](#small-taste)
- [Showcase examples](#showcase-examples)
- [Language bindings](#language-bindings)
- [FAQs](#faqs)
- [Meta](#meta)

## Features and Design philosophy <a name="features" />
- Scalar math for graphics/game: `int32_t`, `uint32_t`, `float`
- Vector math for graphics/game: `vec2`, `vec3`, `vec4`, `ivec2`, `ivec3`, `ivec4`, `uvec2`, `uvec3`, `uvec4`, `quat`, `mat2`, `mat3`, `mat4`
- Row-major matrix
- Same API for both C and C++
- Data structure is plain-old-data, no copy constructor costs
- Parameter pass-by-value, return as value (only few functions use pass-by-pointer for multi-return purpose)
- Swizzle-like functions (easier to implement vs C++ properties)
- C++ operators overloading
- Data constructor with same name as data type (for cleaner code, GLSL-like, implementation avoid abstraction costs)
- (Only clang) vector-extensions, swizzle properties, operators overloading
- Component-wise computing, specific computing for graphics math, only functions
- Seperate data types and functions in headers, support better compile speed, only include what needed
- Find out more in `docs/coding_standards.md`


## Import/include instructions <a name="include-instructions" />
- This library is headers only, you can easily import to your projects
- Use scripts/vectormath.genie.lua (WIP) to import to projects that support GENie
- Use scripts/vectormath.premake5.lua to import to projects that support premake5


## Build instructions (examples and tests projects) <a name="build-instructions" />
- Run premake5 or GENie (WIP) to generate projects
- Build with your chosen build system
- (WIP) Planning to add cmake


## Small taste
```C
vec3 position = vec3_new(100.0f, 200.0f, 10.0f);    // equals to vec3(100.0f, 200.0f, 10.0f)
vec4 rotation = quat_from_euler(0.0f, 0.0f, 0.0f);
vec3 scale    = vec3_new1(1.0f);                    // equals to vec3(1.0f)
mat4 model    = mat4_mul(mat4_mul(mat4_translation_vec3(position),
                                  mat4_rotation_quat(rotation)),
                         mat4_scalation_vec3(scale));

// Perspective matrix with 45 degrees field-of-view, right handed, row-major
mat4 proj = mat4_perspective_rh(float_deg2rad(45), WIDTH / HEIGHT, 0.0f, 100.0f);

// ... apply matrix to render, should convert to other systems (handed, row/column major) ...
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

- I want to use it with Raylib? 
    - Solution 1: replace struct definition of VectorX with typedef and it will work, Matrix must be do more work.
    - Solution 2: create some helper functions to convert between two types, fear not about performance penalty, compiler will do the work for you. This work for other framework too. Recommended.

- More about performance? Not the fastest, but enough to use with small project.

- Is it stable yet? No. This library need to make some big decisions, some decisions are mistaked in beginning.


## Meta
- Version: v0.7.0-dev
- License: UNLICENSED
- Copyright: MaiHD @ 2022 - 2024