# Dicision making and explain why

## Remove operator ++/--
- Clang vector extensions does not support theses 2 operators
- SonyVectormath does not support theses 2 operators
- Theses 2 operators are not commonly used
- Theses 2 operators are not clearly showing what its does underneath

## Add handed system
- Many frameworks, game engine use different handed systems
- Make functions clearly show what its does underneath

## Use matrix row-major instead of column-major
- Commonly in game framework/engine -> wrong
- Structure layout is simple, linear -> users often donot care, they just care about performance
- Reduce cognition overhead -> wrong, based on reason 1
- No need to change code -> just because I commonly create vectormath with row-major, like vmath, hlslmath
- Findout this just a mistake by choosing wrong name
- Decided to change to column-major:
    - Commonly in game framework/engine: BGFX, The Forge, Raylib
    - Faster computing: https://www.modular.com/blog/row-major-vs-column-major-matrices-a-performance-analysis-in-mojo-and-numpy
    - Reduce cognition overhead, because its common
    - GLSL-like

## Vector constructors
- Shortname for vecx_new
- Commonly use when coding
- The purpose of functions are clear
- Support some caster between vectors easily