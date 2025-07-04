## TODOs
- Make the first stable release
- Maybe add pattern solutions for common problem in game/graphics development
- Support more systems: left/right handed, vertical/horizontal field of view
- Add NEON implementation, for optimize 2D vector operations
- Turns as a replacement for degrees/radians
- Quaternion implementation as seperate modules (scalar and simd have the same implementation)
- Common module -> Vec2 module

- Performance:
    - Benchmarking
    - Fast trigonometric with simd instructions

- Examples:
    - Make an example that use full advantages of clang vector extensions
    - Add project showcases

- Docs:
    - Docgen
    - API docs and usage docs
    - Add contributing docs

- Testing:
    - iOS tests
    - Make unit tests with better values, meaning results
    - Complete empty unit tests
    - Add missing unit tests

- Bugs:
    - MacOS m128_acos

- Platforms and Development:
    - Full shorthands versions for GLSL-like
    - Raylib/sokol templates
    - Add profile, features guidelines
    - Independent from -lm (Unix math library)

- (Low priority) Remove deprecated functions

- (Low priority) Haxe examples

- (Low priority) Building:
    - Single header library
    - Features cutting
    - Implemetation cutting