## Vector Math library based on Sony's Math library (Write new, not mod)

## Further reading
- [HLSL data types](https://docs.microsoft.com/en-us/windows/win32/direct3dhlsl/dx-graphics-hlsl-data-types)
- [HLSL Math functions (intrinsics)](https://docs.microsoft.com/en-us/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)
- [Inline functions FQA](https://yosefk.com/c++fqa/inline.html)
> FQA: To summarize: the compiler has the right to inline or not inline any function, whether it's declared inline in any of the several ways or not.<br/>
> => I decise to remove hard-to-read HLSLMATH_INLINE and HLSLMATH_CONSTEXPR macros. Use simple 'inline' keyword, just to hint the compilers. Sony's Math library do the same.
- [Operator overloading FQA](https://yosefk.com/c++fqa/operator.html)
- [TDD and Math library](https://gamesfromwithin.com/when-is-it-ok-not-to-tdd)
> On the other hand, I would argue that using TDD on a math library is a bad idea. It’s essential to write good unit tests for a math library, but probably not to design it through TDD. Are you really going to implement a cross product differently just because you wrote tests before? The emphasis there has to be on correctness and performance, not on creating the interface or implementation through tests.<br/>
> => Write unit tests, benchmarks after design the API
- [Sony's open sourced VectorMath library overview](https://github.com/glampert/vectormath/blob/master/docs/VectorMath-Library-Overview.pdf)
> Features<br/>
>   The Vector Math library mainly provides functions used in 3-D graphics for 3-D and 4-D vector operations, matrix operations, and quaternion operations. APIs for both the C and C++ programming languages are provided, along with three formats according to the data layout:<br/>
>       - The AoS (Array of Structures) SIMD format, which can easily and quickly be adapted to handle different situations<br/>
>       - The SoA (Structure of Arrays) SIMD format, which allows for maximum throughput<br/>
>       - The scalar format, which is useful for porting and testing<br/>
>   All three formats provide implementations for the PPU and SPU.
> => Sony's VectorMath was design for their PPU and SPU, we need an update version that work well on modern cpu.