#pragma once

// This file is created for use with Haxe bindings (Haxe need generics functions for overloading)

// Currently only support C++
#ifndef __cplusplus
#error VectorMath generic functions currently only support C++ (a.k.a function overloading)
#endif

//
// Constructors
//

__forceinline vec2 vec2_new(void)
{
    return vec2_new(0.0f, 0.0f);
}

__forceinline vec3 vec3_new(void)
{
    return vec3_new(0.0f, 0.0f, 0.0f);
}

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

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
