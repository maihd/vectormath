#pragma once

// -------------------------------------------------------------
// Operators overloading, only support on C++
// -------------------------------------------------------------

#if !defined(VECTORMATH_OPERATORS_DISABLED) && defined(__cplusplus) && !VECTORMATH_ENABLE_CLANG_EXT

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


__forceinline mat4 operator-(mat4 m)
{
    mat4 result;
    result.v0 = -m.v0;
    result.v1 = -m.v1;
    result.v2 = -m.v2;
    result.v3 = -m.v3;
    return result;
}


__forceinline mat4 operator+(mat4 m)
{
    return m;
}


__forceinline mat4 operator+(mat4 a, mat4 b)
{
    return mat4_new(
        a.v0 + b.v0,
        a.v1 + b.v1,
        a.v2 + b.v2,
        a.v3 + b.v3
    );
}


__forceinline mat4 operator+(mat4 a, float b)
{
    return mat4_new(
        a.v0 + b,
        a.v1 + b,
        a.v2 + b,
        a.v3 + b
    );
}


__forceinline mat4 operator+(float a, mat4 b)
{
    return mat4_new(
        a + b.v0,
        a + b.v1,
        a + b.v2,
        a + b.v3
    );
}


__forceinline mat4 operator-(mat4 a, mat4 b)
{
    return mat4_new(
        a.v0 - b.v0,
        a.v1 - b.v1,
        a.v2 - b.v2,
        a.v3 - b.v3
    );
}


__forceinline mat4 operator-(mat4 a, float b)
{
    return mat4_new(
        a.v0 - b,
        a.v1 - b,
        a.v2 - b,
        a.v3 - b
    );
}


__forceinline mat4 operator-(float a, mat4 b)
{
    return mat4_new(
        a - b.v0,
        a - b.v1,
        a - b.v2,
        a - b.v3
    );
}


__forceinline mat4 operator*(mat4 a, mat4 b)
{
    return mat4_mul(a, b);
}


__forceinline vec2 operator*(mat4 a, vec2 b)
{
    return mat4_mul_vec2(a, b);
}


__forceinline vec3 operator*(mat4 a, vec3 b)
{
    return mat4_mul_vec3(a, b);
}


__forceinline vec4 operator*(mat4 a, vec4 b)
{
    return mat4_mul_vec4(a, b);
}


__forceinline mat4 operator*(mat4 a, float b)
{
    return mat4_mul1(a, b);
}


__forceinline mat4 operator*(float a, mat4 b)
{
    return mat4_mul1(b, a);
}


__forceinline mat4 operator/(mat4 a, mat4 b)
{
    return mat4_new(
        a.v0 / b.v0,
        a.v1 / b.v1,
        a.v2 / b.v2,
        a.v3 / b.v3
    );
}


__forceinline mat4 operator/(mat4 a, float b)
{
    return mat4_new(
        a.v0 / b,
        a.v1 / b,
        a.v2 / b,
        a.v3 / b
    );
}


__forceinline mat4 operator/(float a, mat4 b)
{
    return mat4_new(
        a / b.v0,
        a / b.v1,
        a / b.v2,
        a / b.v3
    );
}


__forceinline mat4& operator+=(mat4& a, mat4 b)
{
    return (a = a + b);
}


__forceinline mat4& operator+=(mat4& a, float b)
{
    return (a = a + b);
}


__forceinline mat4& operator-=(mat4& a, mat4 b)
{
    return (a = a - b);
}


__forceinline mat4& operator-=(mat4& a, float b)
{
    return (a = a - b);
}


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


__forceinline bool operator==(mat4 a, mat4 b)
{
    return mat4_equal(a, b);
}


__forceinline bool operator!=(mat4 a, mat4 b)
{
    return mat4_not_equal(a, b);
}


#endif //! VECTORMATH_OPERATORS

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
