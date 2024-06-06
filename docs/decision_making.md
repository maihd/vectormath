# Dicision making and explain why

## Remove operator ++/--
- Clang vector extensions does not support theses 2 operators
- SonyVectormath does not support theses 2 operators
- Theses 2 operators are not commonly used
- Theses 2 operators are not clearly showing what its does underneath

## Add handed system
- Many frameworks, game engine use different handed systems
- Make functions clearly show what its does underneath

## Use matrix row-major instead of column major
- Commonly in game framework/engine
- Structure layout is simple, linear
- Reduce cognition overhead
- No need to change code

## Vector constructors
- Shortname for vecx_new
- Commonly use when coding
- The purpose of functions are clear
- Support some caster between vectors easily