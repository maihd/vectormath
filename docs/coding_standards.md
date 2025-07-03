Coding standards for this library
---------------------------------


Naming convention
-----------------
- Typenames should like glsl for familiar: `vec2`, `ivec2`, `mat4`, ...
- SIMD should be `__m<size>` follow the SSE for all platforms, we have `sse_to_neon.h` as a wrapper for ARM target machine.
- Variable names should be `snake_case`
- Function names should be `snake_case` with module name (normally are typenames): `vec2_new`, `mat4_mul`, ...
- Function names should be describing what they do, add params type names for multi version: `vec3_add_vec2`, `mat4_mul_vec3`, ...
- Preprocessor names are `ALL_UPPER_CASES`, specially are `constexpr` and `__forceinline`
- File names are `snake_case`, because each file is a module
- Special case is standard math library extensions, which should be follow the standard style
- Testing no need to follow the rules.


Function naming semantics
-------------------------
- This section explain function naming semantics in more details than above sections
- Function names should be `snake_case` with module name (normally are typenames): `vec2_new`, `mat4_mul`, ...
- Function names should be describing what they do, add params type names for multi version: `vec3_add_vec2`, `mat4_mul_vec3`, ...
- Use function names postfix for describe overloading functions.
- Postfix should be describing type. Ex: `vec3_from_vec2` mean create new `vec3` from 1 `vec2`
- Postfix should be describing number of parameters of that type. Ex: `mat4_new_16f32` mean create new `mat4` with 16 single-precision floating-point number (f32), `mat4_new_16f` is acceptable because `mat4` have been known the components precision (single-precision floating-point number).


Function implementation philosophy
----------------------------------
- Avoid branching!
- Please avoid std version of floating-point math. Use scalarmath.h instead. (By now, there no implement for floating-point math functions. So we need std version, but its just a backend.)
- Donot add more SIMD implementation module, instead add a wrapper, like sse_to_neon.h do!
- Support both C and C++. But avoid C++ function overloading.
- Only add basic operator overloading (+, -, *, /), with SIMD meaning (component-wise).
- Prefer fast with simple implementations over fastest with complex implementations.
- Based on the above rule, implement scalar version first, test it work, simd version later.
- The special cases will have their docs to describe the design decision of each implementations.
- Parameters are immutable.
- This is fixed-size vector and matrix library for graphics programming, so do not add pointer parameters to keep it simple and ease to use. There will be special case, otherwise. But now, we only have one for return multi values: `mat4_decompose`.


Compiler and Language Standards
-------------------------------
- Use C99 and C++0x. C89 and >=C++11 should works. 
- Treat warnings as errors.
- Does not recommending use C89, because pass-by-value may cause performance problems.
- Does not force to use C99 in examples, maybe using C++ is better purposing, show the code to the end-users. 
- C11 only require when use constructors in C


Physically architecture for source files
----------------------------------------
- Avoid introdue new include files without reasons.
- Minimal include files.
- Seperate data types and functions.
- One file that include all for fast prototype.
- Make sure fast compile, fast iteration.
