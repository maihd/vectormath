# VectorMath library based on Sony's Math library (Write new, not mod, cause different from origin version)
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/maihd)

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
- Column-major matrix
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


## Contributing
All pull requests are welcome:
- Add more examples
- Reporting and fixing bugs
- Unit tests
- Add functions implementations: NEON (other simd intrinsics), handedness, reverse z-order, turns
- Add docs, fixing typo
- Find contributing guides as CONTRIBUING.md


## Small taste
```C
// C

vec3 position = vec3_new(100.0f, 200.0f, 10.0f);    // equals to vec3(100.0f, 200.0f, 10.0f)
quat rotation = quat_from_euler(0.0f, 0.0f, 0.0f);
vec3 scale    = vec3_new1(1.0f);                    // equals to vec3(1.0f)
mat4 model    = mat4_mul(mat4_mul(mat4_translation_vec3(position),
                                  mat4_rotation_quat(rotation)),
                         mat4_scalation_vec3(scale));

// Perspective matrix with 45 degrees field-of-view, right handed, row-major
mat4 proj = mat4_perspective_rh(float_deg2rad(45), WIDTH / HEIGHT, 0.0f, 100.0f);

// ... apply matrix to render, should convert to other systems (handed, row/column major) ...
```

```C++
// C++

vec3 position = vec3(100.0f, 200.0f, 10.0f);
quat rotation = quat_from_euler(0.0f, 0.0f, 0.0f); // no quat(0.0f, 0.0f, 0.0f) because this is hidden what it does behind the scene
vec3 scale    = vec3(1.0f);
mat4 model    = mat4_translation_vec3(position) * mat4_rotation_quat(rotation) * mat4_scalation_vec3(scale);
             // maybe some function overloading: mat4_translation(position) * mat4_rotation(quat) * mat4_scalation(scale) is appreciated

// Perspective matrix with 45 degrees field-of-view, right handed, row-major
mat4 proj = mat4_perspective_rh(float_deg2rad(45), WIDTH / HEIGHT, 0.0f, 100.0f);

// ... apply matrix to render, should convert to other systems (handed, row/column major) ...
```


```C
// GLSL-like (require Clang with vector extensions support)
// Exactly it's OpenCL C's vector types, does not .uv
// Doesnot support in other compilers, use with care

vec2 position;
vec2 texcoord;

vec4 vert2d;
vert2d.xy = position;
vert2d.zw = texcoord;

vec4 red_color;
color.r = 1.0f;
color.g = 0.0f;
color.b = 0.0f;
color.a = 1.0f;

vec3 red_color_3f = red_color.rgb;
```

## Showcase examples
- Please check folder `examples` to exploring
- [Pixel Adventure, Mai clone of that game](https://github.com/maihd/pixel_adventure)


## Language bindings
Language bindings only prefer transpiling language like Haxe (maybe only), that use C++ code to compile, which may using the advantages of inlining optimization. Other languages may need FFI, C ABI to call functions (not inlining),
so other languages you should use the libraries written specifily for thoses languages. (Like Zig have zmath, Odin have native support for vector/matrix types)
- Haxe Reflaxe.CPP (bindgen with nodejs script)
- Carbon was said that can include C++ header without changing the source code. No experiment yet.

## FAQs
- Why another math library? I'm a big fan of The-Forge renderer, when I read the source, discovered Sony's Math library. But the Sony's Math was support C++ only, then I write a port to support both C and C++ for learning purposes.

- Why Unlicense? Mostly source codes were re-written from The-Forge's VectorMath library, so I don't own the code. (I found the code with the same design with this library, but older: https://github.com/zauonlok/renderer/blob/master/renderer/core/maths.h)

- Where the functions docs, and tutorials? WIP.

- Advance usages, configs, build flags docs? Find out in [build_flags](docs/build_flags.md).

- More examples on some popular renderers (bgfx, The-Forge)? Learning.

- I want to use it with Raylib? 
    - Solution 1: replace struct definition of VectorX with typedef and it will work. Matrix should be converted.
    - Solution 2: create some helper functions to convert between two types, fear not about performance penalty, compiler will do the work for you. This work for other framework too. Recommended.

- More about performance? Not the fastest, but enough to use with small project.

- Is it stable yet? No. But the API will stable soon (which is still missing needed features).


## Meta
- Version: v0.8.0-dev (nearly stable)
- License: UNLICENSED
- Copyright: MaiHD @ 2022 - 2024