#pragma once

// -------------------------------------------------------------
// Operators overloading, only support on C++
// -------------------------------------------------------------

#if !defined(VECTORMATH_OPERATORS_DISABLED) && defined(__cplusplus)

// Make sure we have vector_math types
#ifndef VECTORMATH_TYPES_DEFINED
#error Missing vectormath types, make sure you include it!
#endif

// Make sure we have vector_math functions
#ifndef VECTORMATH_FUNCTIONS_DEFINED
#error Missing vectormath functions, make sure you include it!
#endif

// Helper for extensions
#ifndef VECTORMATH_OPERATORS_DEFINED
#define VECTORMATH_OPERATORS_DEFINED
#endif

#if !VECTORMATH_ENABLE_CLANG_EXT

__forceinline vec2 operator-(vec2 v)
{
    return vec2_neg(v);
}


__forceinline vec2 operator+(vec2 v)
{
    return v;
}


__forceinline vec2 operator+(vec2 a, vec2 b)
{
    return vec2_add(a, b);
}


__forceinline vec2 operator-(vec2 a, vec2 b)
{
    return vec2_sub(a, b);
}


__forceinline vec2 operator*(vec2 a, vec2 b)
{
    return vec2_mul(a, b);
}


__forceinline vec2 operator/(vec2 a, vec2 b)
{
    return vec2_div(a, b);
}


__forceinline vec2 operator+(vec2 a, float b)
{
    return a + vec2_new1(b);
}


__forceinline vec2 operator-(vec2 a, float b)
{
    return a - vec2_new1(b);
}


__forceinline vec2 operator*(vec2 a, float b)
{
    return a * vec2_new1(b);
}


__forceinline vec2 operator/(vec2 a, float b)
{
    return a / vec2_new1(b);
}


__forceinline vec2 operator+(float a, vec2 b)
{
    return vec2_new1(a) + b;
}


__forceinline vec2 operator-(float a, vec2 b)
{
    return vec2_new1(a) - b;
}


__forceinline vec2 operator*(float a, vec2 b)
{
    return vec2_new1(a) * b;
}


__forceinline vec2 operator/(float a, vec2 b)
{
    return vec2_new1(a) / b;
}


__forceinline vec2& operator+=(vec2& a, vec2 b)
{
    return (a = a + b);
}


__forceinline vec2& operator+=(vec2& a, float b)
{
    return (a = a + b);
}


__forceinline vec2& operator-=(vec2& a, vec2 b)
{
    return (a = a - b);
}


__forceinline vec2& operator-=(vec2& a, float b)
{
    return (a = a - b);
}


__forceinline vec2& operator*=(vec2& a, vec2 b)
{
    return (a = a * b);
}


__forceinline vec2& operator*=(vec2& a, float b)
{
    return (a = a * b);
}


__forceinline vec2& operator/=(vec2& a, vec2 b)
{
    return (a = a / b);
}


__forceinline vec2& operator/=(vec2& a, float b)
{
    return (a = a + b);
}


__forceinline bool operator==(vec2 a, vec2 b)
{
    return a.x == b.x && a.y == b.y;
}


__forceinline bool operator!=(vec2 a, vec2 b)
{
    return a.x != b.x || a.y != b.y;
}


__forceinline vec3 operator-(vec3 v)
{
    return vec3_neg(v);
}


__forceinline vec3 operator+(vec3 v)
{
    return v;
}


__forceinline vec3 operator+(vec3 a, vec3 b)
{
    return vec3_add(a, b);
}


__forceinline vec3 operator-(vec3 a, vec3 b)
{
    return vec3_sub(a, b);
}


__forceinline vec3 operator*(vec3 a, vec3 b)
{
    return vec3_mul(a, b);
}


__forceinline vec3 operator/(vec3 a, vec3 b)
{
    return vec3_div(a, b);
}


__forceinline vec3 operator+(vec3 a, float b)
{
    return a + vec3_new1(b);
}


__forceinline vec3 operator-(vec3 a, float b)
{
    return a - vec3_new1(b);
}


__forceinline vec3 operator*(vec3 a, float b)
{
    return a * vec3_new1(b);
}


__forceinline vec3 operator/(vec3 a, float b)
{
    return a * vec3_new1(1.0f / b);
}


__forceinline vec3 operator+(float a, vec3 b)
{
    return vec3_new1(a) + b;
}


__forceinline vec3 operator-(float a, vec3 b)
{
    return vec3_new1(a) - b;
}


__forceinline vec3 operator*(float a, vec3 b)
{
    return vec3_new1(a) * b;
}


__forceinline vec3 operator/(float a, vec3 b)
{
    return vec3_new1(a) / b;
}


__forceinline vec3& operator+=(vec3& a, vec3 b)
{
    return (a = a + b);
}


__forceinline vec3& operator+=(vec3& a, float b)
{
    return (a = a + b);
}


__forceinline vec3& operator-=(vec3& a, vec3 b)
{
    return (a = a - b);
}


__forceinline vec3& operator-=(vec3& a, float b)
{
    return (a = a - b);
}


__forceinline vec3& operator*=(vec3& a, vec3 b)
{
    return (a = a * b);
}


__forceinline vec3& operator*=(vec3& a, float b)
{
    return (a = a * b);
}


__forceinline vec3& operator/=(vec3& a, vec3 b)
{
    return (a = a / b);
}


__forceinline vec3& operator/=(vec3& a, float b)
{
    return (a = a + b);
}


__forceinline bool operator==(vec3 a, vec3 b)
{
    return vec3_equal(a, b);
}


__forceinline bool operator!=(vec3 a, vec3 b)
{
    return vec3_equal(a, b);
}


__forceinline vec4 operator-(vec4 v)
{
    return vec4_neg(v);
}


__forceinline vec4 operator+(vec4 v)
{
    return v;
}


__forceinline vec4 operator+(vec4 a, vec4 b)
{
    return vec4_add(a, b);
}


__forceinline vec4 operator-(vec4 a, vec4 b)
{
    return vec4_sub(a, b);
}


__forceinline vec4 operator*(vec4 a, vec4 b)
{
    return vec4_mul(a, b);
}


__forceinline vec4 operator/(vec4 a, vec4 b)
{
    return vec4_div(a, b);
}


__forceinline vec4 operator+(vec4 a, float b)
{
    return a + vec4_new1(b);
}


__forceinline vec4 operator-(vec4 a, float b)
{
    return a - vec4_new1(b);
}


__forceinline vec4 operator*(vec4 a, float b)
{
    return a * vec4_new1(b);
}


__forceinline vec4 operator/(vec4 a, float b)
{
    return a / vec4_new1(b);
}


__forceinline vec4 operator+(float a, vec4 b)
{
    return vec4_new1(a) + b;
}


__forceinline vec4 operator-(float a, vec4 b)
{
    return vec4_new1(a) - b;
}


__forceinline vec4 operator*(float a, vec4 b)
{
    return vec4_new1(a) * b;
}


__forceinline vec4 operator/(float a, vec4 b)
{
    return vec4_new1(a) / b;
}


__forceinline vec4& operator+=(vec4& a, vec4 b)
{
    return (a = a + b);
}


__forceinline vec4& operator+=(vec4& a, float b)
{
    return (a = a + b);
}


__forceinline vec4& operator-=(vec4& a, vec4 b)
{
    return (a = a - b);
}


__forceinline vec4& operator-=(vec4& a, float b)
{
    return (a = a - b);
}


__forceinline vec4& operator*=(vec4& a, vec4 b)
{
    return (a = a * b);
}


__forceinline vec4& operator*=(vec4& a, float b)
{
    return (a = a * b);
}


__forceinline vec4& operator/=(vec4& a, vec4 b)
{
    return (a = a / b);
}


__forceinline vec4& operator/=(vec4& a, float b)
{
    return (a = a + b);
}


__forceinline bool operator==(vec4 a, vec4 b)
{
    return vec4_equal(a, b);
}


__forceinline bool operator!=(vec4 a, vec4 b)
{
    return vec4_not_equal(a, b);
}
#endif // !VECTORMATH_ENABLE_CLANG_EXT


__forceinline mat4 operator-(mat4 m)
{
    mat4 result;
    result.col0 = -m.col0;
    result.col1 = -m.col1;
    result.col2 = -m.col2;
    result.col3 = -m.col3;
    return result;
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator+(mat4 m)
{
    return m;
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator+(mat4 a, mat4 b)
{
    return mat4_new(
        a.col0 + b.col0,
        a.col1 + b.col1,
        a.col2 + b.col2,
        a.col3 + b.col3
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator+(mat4 a, float b)
{
    return mat4_new(
        a.col0 + b,
        a.col1 + b,
        a.col2 + b,
        a.col3 + b
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator+(float a, mat4 b)
{
    return mat4_new(
        a + b.col0,
        a + b.col1,
        a + b.col2,
        a + b.col3
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator-(mat4 a, mat4 b)
{
    return mat4_new(
        a.col0 - b.col0,
        a.col1 - b.col1,
        a.col2 - b.col2,
        a.col3 - b.col3
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator-(mat4 a, float b)
{
    return mat4_new(
        a.col0 - b,
        a.col1 - b,
        a.col2 - b,
        a.col3 - b
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator-(float a, mat4 b)
{
    return mat4_new(
        a - b.col0,
        a - b.col1,
        a - b.col2,
        a - b.col3
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator*(mat4 a, mat4 b)
{
    return mat4_mul(a, b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
// __forceinline vec2 operator*(mat4 a, vec2 b)
// {
//     return mat4_mul_vec2(a, b);
// }


// @todo: expr to use `const mat4&` instead of `mat4`
// __forceinline vec3 operator*(mat4 a, vec3 b)
// {
//     return mat4_mul_vec3(a, b);
// }


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline vec4 operator*(mat4 a, vec4 b)
{
    return mat4_mul_vec4(a, b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
// __forceinline vec2 operator*(vec2 a, mat4 b)
// {
//     return vec2_mul_mat4(a, b);
// }


// @todo: expr to use `const mat4&` instead of `mat4`
// __forceinline vec3 operator*(vec3 a, mat4 b)
// {
//     return vec3_mul_mat4(a, b);
// }


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline vec4 operator*(vec4 a, mat4 b)
{
    return vec4_mul_mat4(a, b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator*(mat4 a, float b)
{
    return mat4_mul1(a, b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator*(float a, mat4 b)
{
    return mat4_mul1(b, a);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator/(mat4 a, float b)
{
    return mat4_new(
        a.col0 / b,
        a.col1 / b,
        a.col2 / b,
        a.col3 / b
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4 operator/(float a, mat4 b)
{
    return mat4_new(
        a / b.col0,
        a / b.col1,
        a / b.col2,
        a / b.col3
    );
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4& operator+=(mat4& a, mat4 b)
{
    return (a = a + b);
}


__forceinline mat4& operator+=(mat4& a, float b)
{
    return (a = a + b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4& operator-=(mat4& a, mat4 b)
{
    return (a = a - b);
}


__forceinline mat4& operator-=(mat4& a, float b)
{
    return (a = a - b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline mat4& operator*=(mat4& a, mat4 b)
{
    return (a = a * b);
}


__forceinline mat4& operator*=(mat4& a, float b)
{
    return (a = a * b);
}


__forceinline mat4& operator/=(mat4& a, float b)
{
    return (a = a + b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline bool operator==(mat4 a, mat4 b)
{
    return mat4_equal(a, b);
}


// @todo: expr to use `const mat4&` instead of `mat4`
__forceinline bool operator!=(mat4 a, mat4 b)
{
    return mat4_not_equal(a, b);
}


#endif //! VECTORMATH_OPERATORS

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
