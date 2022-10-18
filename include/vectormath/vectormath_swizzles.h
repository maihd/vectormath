#pragma once

// -------------------------------------------------------------
// Swizzle functions
// -------------------------------------------------------------

#if !defined(VECTORMATH_SWIZZLES_DISABLED) && defined(__cplusplus)

// Make sure we have vector_math functions
#ifndef VECTORMATH_FUNCTIONS_DEFINED
#error Missing vector_math functions, make sure you include it!
#endif

// Helper for extensions
#ifndef VECTORMATH_SWIZZLES_DEFINED
#define VECTORMATH_SWIZZLES_DEFINED
#endif

__forceinline vec2 vec2_xx(vec2 v)
{
	return vec2_new(v.x, v.x);
}

__forceinline vec2 vec2_yy(vec2 v)
{
	return vec2_new(v.y, v.y);
}

__forceinline vec2 vec2_yx(vec2 v)
{
	return vec2_new(v.y, v.x);
}

__forceinline vec3 vec3_xxx(vec3 v)
{
	return vec3_new(v.x, v.x, v.x);
}

__forceinline vec3 vec3_xxy(vec3 v)
{
	return vec3_new(v.x, v.x, v.y);
}

__forceinline vec3 vec3_xxz(vec3 v)
{
	return vec3_new(v.x, v.x, v.z);
}

__forceinline vec3 vec3_xyx(vec3 v)
{
	return vec3_new(v.x, v.y, v.x);
}

__forceinline vec3 vec3_xyy(vec3 v)
{
	return vec3_new(v.x, v.y, v.y);
}

__forceinline vec3 vec3_xzx(vec3 v)
{
	return vec3_new(v.x, v.z, v.x);
}

__forceinline vec3 vec3_xzy(vec3 v)
{
	return vec3_new(v.x, v.z, v.y);
}

__forceinline vec3 vec3_xzz(vec3 v)
{
	return vec3_new(v.x, v.z, v.z);
}

__forceinline vec3 vec3_yyy(vec3 v)
{
	return vec3_new(v.y, v.y, v.y);
}

__forceinline vec3 vec3_yyx(vec3 v)
{
	return vec3_new(v.y, v.y, v.x);
}

__forceinline vec3 vec3_yyz(vec3 v)
{
	return vec3_new(v.y, v.y, v.z);
}

__forceinline vec3 vec3_yxx(vec3 v)
{
	return vec3_new(v.y, v.x, v.x);
}

__forceinline vec3 vec3_yxy(vec3 v)
{
	return vec3_new(v.y, v.x, v.y);
}

__forceinline vec3 vec3_yxz(vec3 v)
{
	return vec3_new(v.y, v.x, v.z);
}

__forceinline vec3 vec3_yzx(vec3 v)
{
	return vec3_new(v.y, v.z, v.x);
}

__forceinline vec3 vec3_yzy(vec3 v)
{
	return vec3_new(v.y, v.z, v.y);
}

__forceinline vec3 vec3_yzz(vec3 v)
{
	return vec3_new(v.y, v.z, v.z);
}

__forceinline vec3 vec3_zzz(vec3 v)
{
	return vec3_new(v.z, v.z, v.z);
}

__forceinline vec3 vec3_zzx(vec3 v)
{
	return vec3_new(v.z, v.z, v.x);
}

__forceinline vec3 vec3_zzy(vec3 v)
{
	return vec3_new(v.z, v.z, v.y);
}

__forceinline vec3 vec3_zxx(vec3 v)
{
	return vec3_new(v.z, v.x, v.x);
}

__forceinline vec3 vec3_zxy(vec3 v)
{
	return vec3_new(v.z, v.x, v.y);
}

__forceinline vec3 vec3_zxz(vec3 v)
{
	return vec3_new(v.z, v.x, v.z);
}

__forceinline vec3 vec3_zyx(vec3 v)
{
	return vec3_new(v.z, v.y, v.x);
}

__forceinline vec3 vec3_zyy(vec3 v)
{
	return vec3_new(v.z, v.y, v.y);
}

__forceinline vec3 vec3_zyz(vec3 v)
{
	return vec3_new(v.z, v.y, v.z);
}

#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
