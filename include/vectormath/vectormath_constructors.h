#pragma once

//
// Function overloading to implement constructor in C++
//

#ifdef __cplusplus


__forceinline vec2 vec2_new(float s)
{
    return vec2_new(s, s);
}


__forceinline vec3 vec3_new(float s)
{
    return vec3_new(s, s, s);
}


__forceinline vec4 vec4_new(float s)
{
    return vec4_new(s, s, s, s);
}


__forceinline vec2 vec2_new(vec2 v)
{
    return v;
}


__forceinline vec2 vec2_new(vec3 v3)
{
    return vec2_from_vec3(v3);
}


__forceinline vec2 vec2_new(vec4 v4)
{
    return vec2_from_vec4(v4);
}


__forceinline vec3 vec3_new(vec2 v2)
{
    return vec3_from_vec2(v2);
}


__forceinline vec3 vec3_new(vec3 v)
{
    return v;
}


__forceinline vec3 vec3_new(vec4 v4)
{
    return vec3_from_vec4(v4);
}


__forceinline vec4 vec4_new(vec4 v)
{
    return v;
}


__forceinline mat4 mat4_new(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
    return mat4_new_16f(
        m00, m01, m02, m03,
        m10, m11, m12, m13,
        m20, m21, m22, m23,
        m30, m31, m32, m33
    );
}


__forceinline mat4 mat4_new(float s)
{
    return mat4_new_1f(s);
}


#else


/// @note: donot use directly
__forceinline vec2 __vec2_copy(vec2 v)
{
    return v;
}


/// @note: not need to use directly
__forceinline vec3 __vec3_copy(vec3 v)
{
    return v;
}


/// @note: not need to use directly
__forceinline vec4 __vec4_copy(vec4 v)
{
    return v;
}


/// @note: not need to use directly
__forceinline mat4 __mat4_copy(mat4 m)
{
    return m;
}

#endif

//
// Short-name constructors
//

#ifdef __cplusplus
/// Create new 2D vector
/// Overloading:
///     - vec2(float s):    2D vector with 2 components equals to 's'
///     - vec2(float x, float y, float z)
///     - vec2(vec2):       dummy cast
///     - vec2(vec3):       cast vec3 to vec2
///     - vec2(vec4):       cast vec4 to vec2
#define vec2(...) vec2_new(__VA_ARGS__)


/// Create new 3D vector
/// Overloading:
///     - vec3(float s):    3D vector with 3 components equals to 's'
///     - vec3(float x, float y, float z)
///     - vec3(vec3):       dummy cast
///     - vec3(vec2):       cast vec2 to vec3
///     - vec3(vec4):       cast vec4 to vec3
#define vec3(...) vec3_new(__VA_ARGS__)


/// Create new 4D vector
/// Overloading:
///     - vec4(float s):    4D vector with 4 components equals to 's'
///     - vec4(float x, float y, float z, float w)
///     - vec4(vec4):       dummy cast
#define vec4(...) vec4_new(__VA_ARGS__)


/// Create new quaternion
/// Overloading:
///     - quat(float s):    quaternion with 4 components equals to 's'
///     - quat(float x, float y, float z, float w)
///     - quat(vec4):       dummy cast
///     - quat(quat):       dummy cast
#define quat(...) vec4_new(__VA_ARGS__)


/// Create new matrix 4x4
/// Overloading:
///     - mat4(float s):    4D vector with 4 components equals to 's'
///     - mat4(float m00 .. m33)
///     - mat4(vec4 col0, vec4 col1, vec4 col2, vec4 col3)
///     - mat4(mat4):       dummy cast
#define mat4(...) mat4_new(__VA_ARGS__)


#else


/// mark as no argument for macro expansion
/// @note: donot use directly
struct __vectormath_no_arg { int _; };


/// vec2 ctor implementation
/// @note: donot use directly
#define __vec2_ctor(args, x, y, ...)                        \
    _Generic((x)                                            \
        , vec2: __vec2_copy                                 \
        , vec3: vec2_from_vec3                              \
        , vec4: vec2_from_vec4                              \
        , default:                                          \
            _Generic((y)                                    \
                , struct __vectormath_no_arg: vec2_new1     \
                , default: vec2_new                         \
            )                                               \
    ) args

/// Create new 2D vector
/// Overloading:
///     - vec2(float s):    2D vector with 2 components equals to 's'
///     - vec2(float x, float y, float z)
///     - vec2(vec2):       dummy cast
///     - vec2(vec3):       cast vec3 to vec2
///     - vec2(vec4):       cast vec4 to vec2
#define vec2(...) __vec2_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)


/// vec3 ctor implementation
/// @note: donot use directly
#define __vec3_ctor(args, x, y, ...)                        \
    _Generic((x)                                            \
        , vec3: __vec3_copy                                 \
        , vec2: vec3_from_vec2                              \
        , vec4: vec3_from_vec4                              \
        , default:                                          \
            _Generic((y)                                    \
                , struct __vectormath_no_arg: vec3_new1     \
                , default: vec3_new                         \
            )                                               \
    ) args

/// Create new 3D vector
/// Overloading:
///     - vec3(float s):    3D vector with 3 components equals to 's'
///     - vec3(float x, float y, float z)
///     - vec3(vec3):       dummy cast
///     - vec3(vec2):       cast vec2 to vec3
///     - vec3(vec4):       cast vec4 to vec3
#define vec3(...) __vec3_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)


/// vec4 ctor implementation
/// @note: donot use directly
#define __vec4_ctor(args, x, y, ...)                        \
    _Generic((x)                                            \
        , vec4: __vec4_copy                                 \
        , default:                                          \
            _Generic((y)                                    \
                , struct __vectormath_no_arg: vec4_new1     \
                , default: vec4_new                         \
            )                                               \
    ) args

/// Create new 4D vector
/// Overloading:
///     - vec4(float s):    4D vector with 4 components equals to 's'
///     - vec4(float x, float y, float z, float w)
///     - vec4(vec4):       dummy cast
#define vec4(...) __vec4_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)

/// Create new quaternion
/// Overloading:
///     - quat(float s):    quaternion with 4 components equals to 's'
///     - quat(float x, float y, float z, float w)
///     - quat(vec4):       dummy cast
///     - quat(quat):       dummy cast
#define quat(...) __vec4_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)


/// mat4 ctor implementation
/// @note: donot use directly
#define __mat4_ctor(args, x, y, ...)                        \
    _Generic((x)                                            \
        , vec4: mat4_new                                    \
        , mat4: __mat4_copy                                 \
        , default:                                          \
            _Generic((y)                                    \
                , struct __vectormath_no_arg: mat4_new_1f   \
                , default: mat4_new_16f                     \
            )                                               \
    ) args

/// Create new matrix 4x4
/// Overloading:
///     - mat4(float s):    4D vector with 4 components equals to 's'
///     - mat4(float m00 .. m33)
///     - mat4(vec4 col0, vec4 col1, vec4 col2, vec4 col3)
///     - mat4(mat4):       dummy cast
#define mat4(...) __mat4_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)


#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
