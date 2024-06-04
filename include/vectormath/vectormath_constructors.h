#pragma once

//
// Function overloading
//

#ifdef __cplusplus

/// For Haxe bindings
__forceinline vec2 vec2_new(void)
{
    return vec2_new(0.0f, 0.0f);
}


/// For Haxe bindings
__forceinline vec3 vec3_new(void)
{
    return vec3_new(0.0f, 0.0f, 0.0f);
}


/// For Haxe bindings
__forceinline vec4 vec4_new(void)
{
    return vec4_new(0.0f, 0.0f, 0.0f, 0.0f);
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

#else

__forceinline vec2 vec2_zero(void)
{
    return vec2_new(0.0f, 0.0f);
}


__forceinline vec3 vec3_zero(void)
{
    return vec3_new(0.0f, 0.0f, 0.0f);
}


__forceinline vec4 vec4_zero(void)
{
    return vec4_new(0.0f, 0.0f, 0.0f, 0.0f);
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

/// vec2 ctor implementation
/// @note: donot use directly
#define __vec2_ctor(args, x, y, ...)        \
    _Generic((x)                            \
        , vec2: vec2_zero                   \
        , vec3: vec2_from_vec3              \
        , vec4: vec2_from_vec4              \
        , default:                          \
            _Generic((y)                    \
                , vec2: vec2_new1           \
                , default: vec2_new         \
            )                               \
    ) args

#define vec2(...) __vec2_ctor((__VA_ARGS__), ##__VA_ARGS__, (vec2){0}, (vec2){0}, ~)


/// vec3 ctor implementation
/// @note: donot use directly
#define __vec3_ctor(args, x, y, ...)        \
    _Generic((x)                            \
        , vec3: vec3_zero                   \
        , vec2: vec3_from_vec2              \
        , vec4: vec3_from_vec4              \
        , default:                          \
            _Generic((y)                    \
                , vec3: vec3_new1           \
                , default: vec3_new         \
            )                               \
    ) args

#define vec3(...) __vec3_ctor((__VA_ARGS__), ##__VA_ARGS__, (vec3){0}, (vec3){0}, ~)


/// vec4 ctor implementation
/// @note: donot use directly
#define __vec4_ctor(args, x, y, ...)        \
    _Generic((x)                            \
        , vec4: vec4_zero                   \
        , default:                          \
            _Generic((y)                    \
                , vec4: vec4_new1           \
                , default: vec4_new         \
            )                               \
    ) args

#define vec4(...) __vec4_ctor((__VA_ARGS__), ##__VA_ARGS__, (vec4){0}, (vec4){0}, ~)

#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
