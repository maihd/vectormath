#pragma once

//
// Function overloading to implement constructor in C++
//

#ifdef __cplusplus

__forceinline vec2 vec2_new(void)
{
    return vec2_zero();
}


__forceinline vec3 vec3_new(void)
{
    return vec3_zero();
}


__forceinline vec4 vec4_new(void)
{
    return vec4_zero();
}


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

#endif

//
// Short-name constructors
//

#ifdef __cplusplus
#define vec2(...) vec2_new(__VA_ARGS__)
#define vec3(...) vec3_new(__VA_ARGS__)
#define vec4(...) vec4_new(__VA_ARGS__)
#else


/// mark as no argument for macro expansion
/// @note: donot use directly
struct __vectormath_no_arg { int _; };


/// vec2 ctor implementation
/// @note: donot use directly
#define __vec2_ctor(args, x, y, ...)                        \
    _Generic((x)                                            \
        , struct __vectormath_no_arg: vec2_zero             \
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
///     - vec2():           2D vector with 2 components as zero
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
        , struct __vectormath_no_arg: vec3_zero             \
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
///     - vec3():           3D vector with 3 components as zero
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
        , struct __vectormath_no_arg: vec4_zero             \
        , vec4: __vec4_copy                                 \
        , default:                                          \
            _Generic((y)                                    \
                , struct __vectormath_no_arg: vec4_new1     \
                , default: vec4_new                         \
            )                                               \
    ) args

/// Create new 4D vector
/// Overloading:
///     - vec4():           4D vector with 4 components as zero
///     - vec4(float s):    4D vector with 4 components equals to 's'
///     - vec4(float x, float y, float z, float w)
///     - vec4(vec4):       dummy cast
#define vec4(...) __vec4_ctor((__VA_ARGS__), ##__VA_ARGS__, (struct __vectormath_no_arg){0}, (struct __vectormath_no_arg){0}, ~)


#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
