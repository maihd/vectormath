# Vector Math library based on Sony's Math library (Write new, not mod)

## Features
- Scalar math for graphics/game: int32, uint32, float
- Vector math for graphics/game: vec2, vec3, vec4, ivec2, ivec3, ivec4, uvec2, uvec3, uvec4, quat, mat2, mat3, mat4

## Import instructions
- This library is headers only, you can easily import to your projects
- Use scripts/vectormath.genie.lua to import to projects that support GENie
- Use scripts/vectormath.premake5.lua to import to projects that support premake5

## Build instructions (examples and tests projects)
- Run premake5 or GENie to generate projects
- Build with your chosen build system

## FAQs
- Why another math library? I'm a big fan of The-Forge renderer, when I read the source, discovered Sony's Math library. But the Sony's Math was support C++ only, then I write a port to support both C and C++ for learning purposes.

- Why Unlicense? Mostly source codes were re-written from The-Forge's VectorMath library, so I don't own the code. (I found the code with the same design with this library, but older: https://github.com/zauonlok/renderer/blob/master/renderer/core/maths.h)
- Where the functions docs, and tutorials? WIP.

## Meta
- Version: v0.1.3-dev
- License: UNLICENSED
- Copyright: MaiHD @ 2022 - 2023
