#pragma once

#include "glslmath.h"

typedef uint32_t uint;

typedef vec2 float2;
typedef vec3 float3;
typedef vec4 float4;

typedef ivec2 int2;
typedef ivec3 int3;
typedef ivec4 int4;

typedef uvec2 uint2;
typedef uvec3 uint3;
typedef uvec4 uint4;

typedef mat2 float2x2;
typedef mat3 float3x3;
typedef mat4 float4x4;

#define float2(...)     vec2(##__VA_ARGS__)
#define float3(...)     vec3(##__VA_ARGS__)
#define float4(...)     vec4(##__VA_ARGS__)

#define float4x4(...)   mat4(##__VA_ARGS__)

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
