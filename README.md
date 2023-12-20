# Vector Math library based on Sony's Math library (Write new, not mod)

## Features and Design philosophy
- Scalar math for graphics/game: int32, uint32, float
- Vector math for graphics/game: vec2, vec3, vec4, ivec2, ivec3, ivec4, uvec2, uvec3, uvec4, quat, mat2, mat3, mat4
- Data structure is PODs only (no constructors)
- Parameter pass-by-value, return as value (only few functions use pass-by-pointer for multi-return purpose)
- Swizzle-like functions (easier to implement vs C++ properties)
- C++ operators overloading
- (Only clang) vector-extensions, swizzle properties, operators overloading
- Component-wise computing, specific computing for graphics math, only functions
- Find more in docs/coding_style.md

## Import/include instructions
- This library is headers only, you can easily import to your projects
- Use scripts/vectormath.genie.lua (WIP) to import to projects that support GENie
- Use scripts/vectormath.premake5.lua to import to projects that support premake5

## Build instructions (examples and tests projects)
- Run premake5 or GENie (WIP) to generate projects
- Build with your chosen build system
- (WIP) Planning to add cmake

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
- More examples on some popular renderers (bgfx, The-Forge)? Learning.
- Is it stable yet? No.

## Meta
- Version: v0.1.4-dev
- License: UNLICENSED
- Copyright: MaiHD @ 2022 - 2023
