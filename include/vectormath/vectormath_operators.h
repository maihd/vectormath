#pragma once

// -------------------------------------------------------------
// Operators overloading, only support on C++
// -------------------------------------------------------------

#if !defined(VECTORMATH_OPERATORS_DISABLED) && defined(__cplusplus)

// Make sure we have vector_math functions
#ifndef VECTORMATH_FUNCTIONS_DEFINED
#error Missing vector_math functions, make sure you include it!
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

__forceinline vec2& operator--(vec2& v)
{
    --v.x;
    --v.y;
    return v;
}

__forceinline vec2& operator++(vec2& v)
{
    ++v.x;
    ++v.y;
    return v;
}

__forceinline vec2 operator--(vec2& v, int)
{
    const vec2 result = v;

    v.x--;
    v.y--;

    return result;
}

__forceinline vec2 operator++(vec2& v, int)
{
    const vec2 result = v;

    v.x++;
    v.y++;

    return result;
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

__forceinline vec3& operator--(vec3& v)
{
#if VECTORMATH_SIMD_ENABLE
    v.m128 = _mm_sub_ps(v.m128, _mm_set_ps1(1.0f));
#else
    v.x--;
    v.y--;
    v.z--;
#endif
    return v;
}

__forceinline vec3& operator++(vec3& v)
{
#if VECTORMATH_SIMD_ENABLE
    v.m128 = _mm_add_ps(v.m128, _mm_set_ps1(1.0f));
#else
    v.x++;
    v.y++;
    v.z++;
#endif
    return v;
}

__forceinline vec3 operator--(vec3& v, int)
{
    const vec3 result = v;

    --v;

    return result;
}

__forceinline vec3 operator++(vec3& v, int)
{
    const vec3 result = v;

    ++v;

    return result;
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

__forceinline vec4& operator--(vec4& v)
{
#if VECTORMATH_SIMD_ENABLE
    v.m128 = _mm_sub_ps(v.m128, _mm_set_ps1(1.0f));
#else
    v.x--;
    v.y--;
    v.z--;
    v.w--;
#endif
    return v;
}

__forceinline vec4& operator++(vec4& v)
{
#if VECTORMATH_SIMD_ENABLE
    v.m128 = _mm_add_ps(v.m128, _mm_set_ps1(1.0f));
#else
    v.x--;
    v.y--;
    v.z--;
    v.w--;
#endif
    return v;
}

__forceinline vec4 operator--(vec4& v, int)
{
    const vec4 result = v;

    --v;

    return result;
}

__forceinline vec4 operator++(vec4& v, int)
{
    const vec4 result = v;

    ++v;

    return result;
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
    result.row0 = -m.row0;
    result.row1 = -m.row1;
    result.row2 = -m.row2;
    result.row3 = -m.row3;
    return result;
}

__forceinline mat4 operator+(mat4 m)
{
    return m;
}

__forceinline mat4& operator--(mat4& m)
{
    --m.row0;
    --m.row1;
    --m.row2;
    --m.row3;
    return m;
}

__forceinline mat4& operator++(mat4& m)
{
    ++m.row0;
    ++m.row1;
    ++m.row2;
    ++m.row3;
    return m;
}

__forceinline mat4 operator--(mat4& m, int)
{
    m.row0--;
    m.row1--;
    m.row2--;
    m.row3--;
    return m;
}

__forceinline mat4 operator++(mat4& m, int)
{
    m.row0++;
    m.row1++;
    m.row2++;
    m.row3++;
    return m;
}

__forceinline mat4 operator+(mat4 a, mat4 b)
{
    return mat4_new(
        a.row0 + b.row0,
        a.row1 + b.row1,
        a.row2 + b.row2,
        a.row3 + b.row3
    );
}

__forceinline mat4 operator+(mat4 a, float b)
{
    return mat4_new(
        a.row0 + b,
        a.row1 + b,
        a.row2 + b,
        a.row3 + b
    );
}

__forceinline mat4 operator+(float a, mat4 b)
{
    return mat4_new(
        a + b.row0,
        a + b.row1,
        a + b.row2,
        a + b.row3
    );
}

__forceinline mat4 operator-(mat4 a, mat4 b)
{
    return mat4_new(
        a.row0 - b.row0,
        a.row1 - b.row1,
        a.row2 - b.row2,
        a.row3 - b.row3
    );
}

__forceinline mat4 operator-(mat4 a, float b)
{
    return mat4_new(
        a.row0 - b,
        a.row1 - b,
        a.row2 - b,
        a.row3 - b
    );
}

__forceinline mat4 operator-(float a, mat4 b)
{
    return mat4_new(
        a - b.row0,
        a - b.row1,
        a - b.row2,
        a - b.row3
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
        a.row0 / b.row0,
        a.row1 / b.row1,
        a.row2 / b.row2,
        a.row3 / b.row3
    );
}

__forceinline mat4 operator/(mat4 a, float b)
{
    return mat4_new(
        a.row0 / b,
        a.row1 / b,
        a.row2 / b,
        a.row3 / b
    );
}

__forceinline mat4 operator/(float a, mat4 b)
{
    return mat4_new(
        a / b.row0,
        a / b.row1,
        a / b.row2,
        a / b.row3
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

#endif //! OPERATORS

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
