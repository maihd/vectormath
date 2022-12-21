#pragma once

// -------------------------------------------------------------
// Swizzle functions
// -------------------------------------------------------------

#if !defined(VECTORMATH_SWIZZLES_DISABLED)

// Make sure we have vector_math functions
#ifndef VECTORMATH_FUNCTIONS_DEFINED
#error Missing vectormath functions, make sure you include it!
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

__forceinline vec4 vec4_xxxx(vec4 v)
{
	return vec4_new(v.x, v.x, v.x, v.x);
}

__forceinline vec4 vec4_xxxy(vec4 v)
{
	return vec4_new(v.x, v.x, v.x, v.y);
}

__forceinline vec4 vec4_xxxz(vec4 v)
{
	return vec4_new(v.x, v.x, v.x, v.z);
}

__forceinline vec4 vec4_xxxw(vec4 v)
{
	return vec4_new(v.x, v.x, v.x, v.w);
}

__forceinline vec4 vec4_xxyx(vec4 v)
{
	return vec4_new(v.x, v.x, v.y, v.x);
}

__forceinline vec4 vec4_xxyy(vec4 v)
{
	return vec4_new(v.x, v.x, v.y, v.y);
}

__forceinline vec4 vec4_xxyz(vec4 v)
{
	return vec4_new(v.x, v.x, v.y, v.z);
}

__forceinline vec4 vec4_xxyw(vec4 v)
{
	return vec4_new(v.x, v.x, v.y, v.w);
}

__forceinline vec4 vec4_xxzx(vec4 v)
{
	return vec4_new(v.x, v.x, v.z, v.x);
}

__forceinline vec4 vec4_xxzy(vec4 v)
{
	return vec4_new(v.x, v.x, v.z, v.y);
}

__forceinline vec4 vec4_xxzz(vec4 v)
{
	return vec4_new(v.x, v.x, v.z, v.z);
}

__forceinline vec4 vec4_xxzw(vec4 v)
{
	return vec4_new(v.x, v.x, v.z, v.w);
}

__forceinline vec4 vec4_xyxx(vec4 v)
{
	return vec4_new(v.x, v.y, v.x, v.x);
}

__forceinline vec4 vec4_xyxy(vec4 v)
{
	return vec4_new(v.x, v.y, v.x, v.y);
}

__forceinline vec4 vec4_xyxz(vec4 v)
{
	return vec4_new(v.x, v.y, v.x, v.z);
}

__forceinline vec4 vec4_xyxw(vec4 v)
{
	return vec4_new(v.x, v.y, v.x, v.w);
}

__forceinline vec4 vec4_xyyx(vec4 v)
{
	return vec4_new(v.x, v.y, v.y, v.x);
}

__forceinline vec4 vec4_xyyz(vec4 v)
{
	return vec4_new(v.x, v.y, v.y, v.z);
}

__forceinline vec4 vec4_xyyw(vec4 v)
{
	return vec4_new(v.x, v.y, v.y, v.w);
}

__forceinline vec4 vec4_xyzx(vec4 v)
{
	return vec4_new(v.x, v.y, v.z, v.x);
}

__forceinline vec4 vec4_xyzy(vec4 v)
{
	return vec4_new(v.x, v.y, v.z, v.y);
}

__forceinline vec4 vec4_xyzz(vec4 v)
{
	return vec4_new(v.x, v.y, v.z, v.z);
}

__forceinline vec4 vec4_xzxx(vec4 v)
{
	return vec4_new(v.x, v.z, v.x, v.x);
}

__forceinline vec4 vec4_xzxy(vec4 v)
{
	return vec4_new(v.x, v.z, v.x, v.y);
}

__forceinline vec4 vec4_xzxz(vec4 v)
{
	return vec4_new(v.x, v.z, v.x, v.z);
}

__forceinline vec4 vec4_xzxw(vec4 v)
{
	return vec4_new(v.x, v.z, v.x, v.w);
}

__forceinline vec4 vec4_xzyx(vec4 v)
{
	return vec4_new(v.x, v.z, v.y, v.x);
}

__forceinline vec4 vec4_xzyy(vec4 v)
{
	return vec4_new(v.x, v.z, v.y, v.y);
}

__forceinline vec4 vec4_xzyz(vec4 v)
{
	return vec4_new(v.x, v.z, v.y, v.z);
}

__forceinline vec4 vec4_xzyw(vec4 v)
{
	return vec4_new(v.x, v.z, v.y, v.w);
}

__forceinline vec4 vec4_xzzx(vec4 v)
{
	return vec4_new(v.x, v.z, v.z, v.x);
}

__forceinline vec4 vec4_xzzy(vec4 v)
{
	return vec4_new(v.x, v.z, v.z, v.y);
}

__forceinline vec4 vec4_xzzz(vec4 v)
{
	return vec4_new(v.x, v.z, v.z, v.z);
}

__forceinline vec4 vec4_xzzw(vec4 v)
{
	return vec4_new(v.x, v.z, v.z, v.w);
}

__forceinline vec4 vec4_xzwx(vec4 v)
{
	return vec4_new(v.x, v.z, v.w, v.x);
}

__forceinline vec4 vec4_xzwy(vec4 v)
{
	return vec4_new(v.x, v.z, v.w, v.y);
}

__forceinline vec4 vec4_xzwz(vec4 v)
{
	return vec4_new(v.x, v.z, v.w, v.z);
}

__forceinline vec4 vec4_xzww(vec4 v)
{
	return vec4_new(v.x, v.z, v.w, v.w);
}

__forceinline vec4 vec4_xwxx(vec4 v)
{
	return vec4_new(v.x, v.w, v.x, v.x);
}

__forceinline vec4 vec4_xwxy(vec4 v)
{
	return vec4_new(v.x, v.w, v.x, v.y);
}

__forceinline vec4 vec4_xwxz(vec4 v)
{
	return vec4_new(v.x, v.w, v.x, v.z);
}

__forceinline vec4 vec4_xwxw(vec4 v)
{
	return vec4_new(v.x, v.w, v.x, v.w);
}

__forceinline vec4 vec4_xwyx(vec4 v)
{
	return vec4_new(v.x, v.w, v.y, v.x);
}

__forceinline vec4 vec4_xwyz(vec4 v)
{
	return vec4_new(v.x, v.w, v.y, v.z);
}

__forceinline vec4 vec4_xwyw(vec4 v)
{
	return vec4_new(v.x, v.w, v.y, v.w);
}

__forceinline vec4 vec4_xwzx(vec4 v)
{
	return vec4_new(v.x, v.w, v.z, v.x);
}

__forceinline vec4 vec4_xwzy(vec4 v)
{
	return vec4_new(v.x, v.w, v.z, v.y);
}

__forceinline vec4 vec4_xwzz(vec4 v)
{
	return vec4_new(v.x, v.w, v.z, v.z);
}

__forceinline vec4 vec4_xwzw(vec4 v)
{
	return vec4_new(v.x, v.w, v.z, v.w);
}

__forceinline vec4 vec4_xwwx(vec4 v)
{
	return vec4_new(v.x, v.w, v.w, v.x);
}

__forceinline vec4 vec4_xwwy(vec4 v)
{
	return vec4_new(v.x, v.w, v.w, v.y);
}

__forceinline vec4 vec4_xwwz(vec4 v)
{
	return vec4_new(v.x, v.w, v.w, v.z);
}

__forceinline vec4 vec4_xwww(vec4 v)
{
	return vec4_new(v.x, v.w, v.w, v.w);
}

__forceinline vec4 vec4_yxxx(vec4 v)
{
	return vec4_new(v.y, v.x, v.x, v.x);
}

__forceinline vec4 vec4_yxxy(vec4 v)
{
	return vec4_new(v.y, v.x, v.x, v.y);
}

__forceinline vec4 vec4_yxxz(vec4 v)
{
	return vec4_new(v.y, v.x, v.x, v.z);
}

__forceinline vec4 vec4_yxxw(vec4 v)
{
	return vec4_new(v.y, v.x, v.x, v.w);
}

__forceinline vec4 vec4_yxyx(vec4 v)
{
	return vec4_new(v.y, v.x, v.y, v.x);
}

__forceinline vec4 vec4_yxyy(vec4 v)
{
	return vec4_new(v.y, v.x, v.y, v.y);
}

__forceinline vec4 vec4_yxyz(vec4 v)
{
	return vec4_new(v.y, v.x, v.y, v.z);
}

__forceinline vec4 vec4_yxyw(vec4 v)
{
	return vec4_new(v.y, v.x, v.y, v.w);
}

__forceinline vec4 vec4_yxzx(vec4 v)
{
	return vec4_new(v.y, v.x, v.z, v.x);
}

__forceinline vec4 vec4_yxzy(vec4 v)
{
	return vec4_new(v.y, v.x, v.z, v.y);
}

__forceinline vec4 vec4_yxzz(vec4 v)
{
	return vec4_new(v.y, v.x, v.z, v.z);
}

__forceinline vec4 vec4_yxzw(vec4 v)
{
	return vec4_new(v.y, v.x, v.z, v.w);
}

__forceinline vec4 vec4_yxwx(vec4 v)
{
	return vec4_new(v.y, v.x, v.w, v.x);
}

__forceinline vec4 vec4_yxwy(vec4 v)
{
	return vec4_new(v.y, v.x, v.w, v.y);
}

__forceinline vec4 vec4_yxwz(vec4 v)
{
	return vec4_new(v.y, v.x, v.w, v.z);
}

__forceinline vec4 vec4_yxww(vec4 v)
{
	return vec4_new(v.y, v.x, v.w, v.w);
}

__forceinline vec4 vec4_yyxx(vec4 v)
{
	return vec4_new(v.y, v.y, v.x, v.x);
}

__forceinline vec4 vec4_yyxy(vec4 v)
{
	return vec4_new(v.y, v.y, v.x, v.y);
}

__forceinline vec4 vec4_yyxz(vec4 v)
{
	return vec4_new(v.y, v.y, v.x, v.z);
}

__forceinline vec4 vec4_yyxw(vec4 v)
{
	return vec4_new(v.y, v.y, v.x, v.w);
}

__forceinline vec4 vec4_yyyz(vec4 v)
{
	return vec4_new(v.y, v.y, v.y, v.z);
}

__forceinline vec4 vec4_yyyw(vec4 v)
{
	return vec4_new(v.y, v.y, v.y, v.w);
}

__forceinline vec4 vec4_yywx(vec4 v)
{
	return vec4_new(v.y, v.y, v.w, v.x);
}

__forceinline vec4 vec4_yywy(vec4 v)
{
	return vec4_new(v.y, v.y, v.w, v.y);
}

__forceinline vec4 vec4_yywz(vec4 v)
{
	return vec4_new(v.y, v.y, v.w, v.z);
}

__forceinline vec4 vec4_yyww(vec4 v)
{
	return vec4_new(v.y, v.y, v.w, v.w);
}

__forceinline vec4 vec4_yzxx(vec4 v)
{
	return vec4_new(v.y, v.z, v.x, v.x);
}

__forceinline vec4 vec4_yzxy(vec4 v)
{
	return vec4_new(v.y, v.z, v.x, v.y);
}

__forceinline vec4 vec4_yzxz(vec4 v)
{
	return vec4_new(v.y, v.z, v.x, v.z);
}

__forceinline vec4 vec4_yzxw(vec4 v)
{
	return vec4_new(v.y, v.z, v.x, v.w);
}

__forceinline vec4 vec4_yzyx(vec4 v)
{
	return vec4_new(v.y, v.z, v.y, v.x);
}

__forceinline vec4 vec4_yzyy(vec4 v)
{
	return vec4_new(v.y, v.z, v.y, v.y);
}

__forceinline vec4 vec4_yzyz(vec4 v)
{
	return vec4_new(v.y, v.z, v.y, v.z);
}

__forceinline vec4 vec4_yzyw(vec4 v)
{
	return vec4_new(v.y, v.z, v.y, v.w);
}

__forceinline vec4 vec4_yzzx(vec4 v)
{
	return vec4_new(v.y, v.z, v.z, v.x);
}

__forceinline vec4 vec4_yzzy(vec4 v)
{
	return vec4_new(v.y, v.z, v.z, v.y);
}

__forceinline vec4 vec4_yzzz(vec4 v)
{
	return vec4_new(v.y, v.z, v.z, v.z);
}

__forceinline vec4 vec4_yzzw(vec4 v)
{
	return vec4_new(v.y, v.z, v.z, v.w);
}

__forceinline vec4 vec4_yzwx(vec4 v)
{
	return vec4_new(v.y, v.z, v.w, v.x);
}

__forceinline vec4 vec4_yzwy(vec4 v)
{
	return vec4_new(v.y, v.z, v.w, v.y);
}

__forceinline vec4 vec4_yzwz(vec4 v)
{
	return vec4_new(v.y, v.z, v.w, v.z);
}

__forceinline vec4 vec4_yzww(vec4 v)
{
	return vec4_new(v.y, v.z, v.w, v.w);
}

__forceinline vec4 vec4_ywxx(vec4 v)
{
	return vec4_new(v.y, v.w, v.x, v.x);
}

__forceinline vec4 vec4_ywxy(vec4 v)
{
	return vec4_new(v.y, v.w, v.x, v.y);
}

__forceinline vec4 vec4_ywxz(vec4 v)
{
	return vec4_new(v.y, v.w, v.x, v.z);
}

__forceinline vec4 vec4_ywxw(vec4 v)
{
	return vec4_new(v.y, v.w, v.x, v.w);
}

__forceinline vec4 vec4_ywyz(vec4 v)
{
	return vec4_new(v.y, v.w, v.y, v.z);
}

__forceinline vec4 vec4_ywyw(vec4 v)
{
	return vec4_new(v.y, v.w, v.y, v.w);
}

__forceinline vec4 vec4_ywzx(vec4 v)
{
	return vec4_new(v.y, v.w, v.z, v.x);
}

__forceinline vec4 vec4_ywzy(vec4 v)
{
	return vec4_new(v.y, v.w, v.z, v.y);
}

__forceinline vec4 vec4_ywzz(vec4 v)
{
	return vec4_new(v.y, v.w, v.z, v.z);
}

__forceinline vec4 vec4_ywwx(vec4 v)
{
	return vec4_new(v.y, v.w, v.w, v.x);
}

__forceinline vec4 vec4_ywwy(vec4 v)
{
	return vec4_new(v.y, v.w, v.w, v.y);
}

__forceinline vec4 vec4_ywwz(vec4 v)
{
	return vec4_new(v.y, v.w, v.w, v.z);
}

__forceinline vec4 vec4_ywww(vec4 v)
{
	return vec4_new(v.y, v.w, v.w, v.w);
}

__forceinline vec4 vec4_zxxx(vec4 v)
{
	return vec4_new(v.z, v.x, v.x, v.x);
}

__forceinline vec4 vec4_zxxy(vec4 v)
{
	return vec4_new(v.z, v.x, v.x, v.y);
}

__forceinline vec4 vec4_zxxz(vec4 v)
{
	return vec4_new(v.z, v.x, v.x, v.z);
}

__forceinline vec4 vec4_zxxw(vec4 v)
{
	return vec4_new(v.z, v.x, v.x, v.w);
}

__forceinline vec4 vec4_zxyx(vec4 v)
{
	return vec4_new(v.z, v.x, v.y, v.x);
}

__forceinline vec4 vec4_zxyy(vec4 v)
{
	return vec4_new(v.z, v.x, v.y, v.y);
}

__forceinline vec4 vec4_zxyz(vec4 v)
{
	return vec4_new(v.z, v.x, v.y, v.z);
}

__forceinline vec4 vec4_zxyw(vec4 v)
{
	return vec4_new(v.z, v.x, v.y, v.w);
}

__forceinline vec4 vec4_zxzx(vec4 v)
{
	return vec4_new(v.z, v.x, v.z, v.x);
}

__forceinline vec4 vec4_zxzy(vec4 v)
{
	return vec4_new(v.z, v.x, v.z, v.y);
}

__forceinline vec4 vec4_zxzz(vec4 v)
{
	return vec4_new(v.z, v.x, v.z, v.z);
}

__forceinline vec4 vec4_zxzw(vec4 v)
{
	return vec4_new(v.z, v.x, v.z, v.w);
}

__forceinline vec4 vec4_zxwx(vec4 v)
{
	return vec4_new(v.z, v.x, v.w, v.x);
}

__forceinline vec4 vec4_zxwy(vec4 v)
{
	return vec4_new(v.z, v.x, v.w, v.y);
}

__forceinline vec4 vec4_zxwz(vec4 v)
{
	return vec4_new(v.z, v.x, v.w, v.z);
}

__forceinline vec4 vec4_zxww(vec4 v)
{
	return vec4_new(v.z, v.x, v.w, v.w);
}

__forceinline vec4 vec4_zyxx(vec4 v)
{
	return vec4_new(v.z, v.y, v.x, v.x);
}

__forceinline vec4 vec4_zyxy(vec4 v)
{
	return vec4_new(v.z, v.y, v.x, v.y);
}

__forceinline vec4 vec4_zyxz(vec4 v)
{
	return vec4_new(v.z, v.y, v.x, v.z);
}

__forceinline vec4 vec4_zyxw(vec4 v)
{
	return vec4_new(v.z, v.y, v.x, v.w);
}

__forceinline vec4 vec4_zyyz(vec4 v)
{
	return vec4_new(v.z, v.y, v.y, v.z);
}

__forceinline vec4 vec4_zyyw(vec4 v)
{
	return vec4_new(v.z, v.y, v.y, v.w);
}

__forceinline vec4 vec4_zyzx(vec4 v)
{
	return vec4_new(v.z, v.y, v.z, v.x);
}

__forceinline vec4 vec4_zyzy(vec4 v)
{
	return vec4_new(v.z, v.y, v.z, v.y);
}

__forceinline vec4 vec4_zyzz(vec4 v)
{
	return vec4_new(v.z, v.y, v.z, v.z);
}

__forceinline vec4 vec4_zyzw(vec4 v)
{
	return vec4_new(v.z, v.y, v.z, v.w);
}

__forceinline vec4 vec4_zywx(vec4 v)
{
	return vec4_new(v.z, v.y, v.w, v.x);
}

__forceinline vec4 vec4_zywy(vec4 v)
{
	return vec4_new(v.z, v.y, v.w, v.y);
}

__forceinline vec4 vec4_zywz(vec4 v)
{
	return vec4_new(v.z, v.y, v.w, v.z);
}

__forceinline vec4 vec4_zyww(vec4 v)
{
	return vec4_new(v.z, v.y, v.w, v.w);
}

__forceinline vec4 vec4_zzxx(vec4 v)
{
	return vec4_new(v.z, v.z, v.x, v.x);
}

__forceinline vec4 vec4_zzxy(vec4 v)
{
	return vec4_new(v.z, v.z, v.x, v.y);
}

__forceinline vec4 vec4_zzxz(vec4 v)
{
	return vec4_new(v.z, v.z, v.x, v.z);
}

__forceinline vec4 vec4_zzxw(vec4 v)
{
	return vec4_new(v.z, v.z, v.x, v.w);
}

__forceinline vec4 vec4_zzyx(vec4 v)
{
	return vec4_new(v.z, v.z, v.y, v.x);
}

__forceinline vec4 vec4_zzyy(vec4 v)
{
	return vec4_new(v.z, v.z, v.y, v.y);
}

__forceinline vec4 vec4_zzyz(vec4 v)
{
	return vec4_new(v.z, v.z, v.y, v.z);
}

__forceinline vec4 vec4_zzyw(vec4 v)
{
	return vec4_new(v.z, v.z, v.y, v.w);
}

__forceinline vec4 vec4_zzzx(vec4 v)
{
	return vec4_new(v.z, v.z, v.z, v.x);
}

__forceinline vec4 vec4_zzzy(vec4 v)
{
	return vec4_new(v.z, v.z, v.z, v.y);
}

__forceinline vec4 vec4_zzzz(vec4 v)
{
	return vec4_new(v.z, v.z, v.z, v.z);
}

__forceinline vec4 vec4_zzzw(vec4 v)
{
	return vec4_new(v.z, v.z, v.z, v.w);
}

__forceinline vec4 vec4_zzwx(vec4 v)
{
	return vec4_new(v.z, v.z, v.w, v.x);
}

__forceinline vec4 vec4_zzwy(vec4 v)
{
	return vec4_new(v.z, v.z, v.w, v.y);
}

__forceinline vec4 vec4_zzwz(vec4 v)
{
	return vec4_new(v.z, v.z, v.w, v.z);
}

__forceinline vec4 vec4_zzww(vec4 v)
{
	return vec4_new(v.z, v.z, v.w, v.w);
}

__forceinline vec4 vec4_zwxx(vec4 v)
{
	return vec4_new(v.z, v.w, v.x, v.x);
}

__forceinline vec4 vec4_zwxy(vec4 v)
{
	return vec4_new(v.z, v.w, v.x, v.y);
}

__forceinline vec4 vec4_zwxz(vec4 v)
{
	return vec4_new(v.z, v.w, v.x, v.z);
}

__forceinline vec4 vec4_zwxw(vec4 v)
{
	return vec4_new(v.z, v.w, v.x, v.w);
}

__forceinline vec4 vec4_zwyx(vec4 v)
{
	return vec4_new(v.z, v.w, v.y, v.x);
}

__forceinline vec4 vec4_zwyy(vec4 v)
{
	return vec4_new(v.z, v.w, v.y, v.y);
}

__forceinline vec4 vec4_zwyz(vec4 v)
{
	return vec4_new(v.z, v.w, v.y, v.z);
}

__forceinline vec4 vec4_zwyw(vec4 v)
{
	return vec4_new(v.z, v.w, v.y, v.w);
}

__forceinline vec4 vec4_zwzx(vec4 v)
{
	return vec4_new(v.z, v.w, v.z, v.x);
}

__forceinline vec4 vec4_zwzy(vec4 v)
{
	return vec4_new(v.z, v.w, v.z, v.y);
}

__forceinline vec4 vec4_zwzz(vec4 v)
{
	return vec4_new(v.z, v.w, v.z, v.z);
}

__forceinline vec4 vec4_zwzw(vec4 v)
{
	return vec4_new(v.z, v.w, v.z, v.w);
}

__forceinline vec4 vec4_zwwx(vec4 v)
{
	return vec4_new(v.z, v.w, v.w, v.x);
}

__forceinline vec4 vec4_zwwy(vec4 v)
{
	return vec4_new(v.z, v.w, v.w, v.y);
}

__forceinline vec4 vec4_zwwz(vec4 v)
{
	return vec4_new(v.z, v.w, v.w, v.z);
}

__forceinline vec4 vec4_zwww(vec4 v)
{
	return vec4_new(v.z, v.w, v.w, v.w);
}

__forceinline vec4 vec4_wxxx(vec4 v)
{
	return vec4_new(v.w, v.x, v.x, v.x);
}

__forceinline vec4 vec4_wxxy(vec4 v)
{
	return vec4_new(v.w, v.x, v.x, v.y);
}

__forceinline vec4 vec4_wxxz(vec4 v)
{
	return vec4_new(v.w, v.x, v.x, v.z);
}

__forceinline vec4 vec4_wxxw(vec4 v)
{
	return vec4_new(v.w, v.x, v.x, v.w);
}

__forceinline vec4 vec4_wxyx(vec4 v)
{
	return vec4_new(v.w, v.x, v.y, v.x);
}

__forceinline vec4 vec4_wxyy(vec4 v)
{
	return vec4_new(v.w, v.x, v.y, v.y);
}

__forceinline vec4 vec4_wxyz(vec4 v)
{
	return vec4_new(v.w, v.x, v.y, v.z);
}

__forceinline vec4 vec4_wxyw(vec4 v)
{
	return vec4_new(v.w, v.x, v.y, v.w);
}

__forceinline vec4 vec4_wxzx(vec4 v)
{
	return vec4_new(v.w, v.x, v.z, v.x);
}

__forceinline vec4 vec4_wxzy(vec4 v)
{
	return vec4_new(v.w, v.x, v.z, v.y);
}

__forceinline vec4 vec4_wxzz(vec4 v)
{
	return vec4_new(v.w, v.x, v.z, v.z);
}

__forceinline vec4 vec4_wxzw(vec4 v)
{
	return vec4_new(v.w, v.x, v.z, v.w);
}

__forceinline vec4 vec4_wxwx(vec4 v)
{
	return vec4_new(v.w, v.x, v.w, v.x);
}

__forceinline vec4 vec4_wxwy(vec4 v)
{
	return vec4_new(v.w, v.x, v.w, v.y);
}

__forceinline vec4 vec4_wxwz(vec4 v)
{
	return vec4_new(v.w, v.x, v.w, v.z);
}

__forceinline vec4 vec4_wxww(vec4 v)
{
	return vec4_new(v.w, v.x, v.w, v.w);
}

__forceinline vec4 vec4_wyxx(vec4 v)
{
	return vec4_new(v.w, v.y, v.x, v.x);
}

__forceinline vec4 vec4_wyxy(vec4 v)
{
	return vec4_new(v.w, v.y, v.x, v.y);
}

__forceinline vec4 vec4_wyxz(vec4 v)
{
	return vec4_new(v.w, v.y, v.x, v.z);
}

__forceinline vec4 vec4_wyxw(vec4 v)
{
	return vec4_new(v.w, v.y, v.x, v.w);
}

__forceinline vec4 vec4_wyyx(vec4 v)
{
	return vec4_new(v.w, v.y, v.y, v.x);
}

__forceinline vec4 vec4_wyyy(vec4 v)
{
	return vec4_new(v.w, v.y, v.y, v.y);
}

__forceinline vec4 vec4_wyyz(vec4 v)
{
	return vec4_new(v.w, v.y, v.y, v.z);
}

__forceinline vec4 vec4_wyyw(vec4 v)
{
	return vec4_new(v.w, v.y, v.y, v.w);
}

__forceinline vec4 vec4_wyzx(vec4 v)
{
	return vec4_new(v.w, v.y, v.z, v.x);
}

__forceinline vec4 vec4_wywx(vec4 v)
{
	return vec4_new(v.w, v.y, v.w, v.x);
}

__forceinline vec4 vec4_wywy(vec4 v)
{
	return vec4_new(v.w, v.y, v.w, v.y);
}

__forceinline vec4 vec4_wywz(vec4 v)
{
	return vec4_new(v.w, v.y, v.w, v.z);
}

__forceinline vec4 vec4_wyww(vec4 v)
{
	return vec4_new(v.w, v.y, v.w, v.w);
}

__forceinline vec4 vec4_wzxx(vec4 v)
{
	return vec4_new(v.w, v.z, v.x, v.x);
}

__forceinline vec4 vec4_wzxy(vec4 v)
{
	return vec4_new(v.w, v.z, v.x, v.y);
}

__forceinline vec4 vec4_wzxz(vec4 v)
{
	return vec4_new(v.w, v.z, v.x, v.z);
}

__forceinline vec4 vec4_wzxw(vec4 v)
{
	return vec4_new(v.w, v.z, v.x, v.w);
}

__forceinline vec4 vec4_wzyx(vec4 v)
{
	return vec4_new(v.w, v.z, v.y, v.x);
}

__forceinline vec4 vec4_wzyy(vec4 v)
{
	return vec4_new(v.w, v.z, v.y, v.y);
}

__forceinline vec4 vec4_wzyz(vec4 v)
{
	return vec4_new(v.w, v.z, v.y, v.z);
}

__forceinline vec4 vec4_wzyw(vec4 v)
{
	return vec4_new(v.w, v.z, v.y, v.w);
}

__forceinline vec4 vec4_wzzx(vec4 v)
{
	return vec4_new(v.w, v.z, v.z, v.x);
}

__forceinline vec4 vec4_wzzy(vec4 v)
{
	return vec4_new(v.w, v.z, v.z, v.y);
}

__forceinline vec4 vec4_wzzz(vec4 v)
{
	return vec4_new(v.w, v.z, v.z, v.z);
}

__forceinline vec4 vec4_wzzw(vec4 v)
{
	return vec4_new(v.w, v.z, v.z, v.w);
}

__forceinline vec4 vec4_wzwx(vec4 v)
{
	return vec4_new(v.w, v.z, v.w, v.x);
}

__forceinline vec4 vec4_wzwy(vec4 v)
{
	return vec4_new(v.w, v.z, v.w, v.y);
}

__forceinline vec4 vec4_wzwz(vec4 v)
{
	return vec4_new(v.w, v.z, v.w, v.z);
}

__forceinline vec4 vec4_wzww(vec4 v)
{
	return vec4_new(v.w, v.z, v.w, v.w);
}

__forceinline vec4 vec4_wwxx(vec4 v)
{
	return vec4_new(v.w, v.w, v.x, v.x);
}

__forceinline vec4 vec4_wwxy(vec4 v)
{
	return vec4_new(v.w, v.w, v.x, v.y);
}

__forceinline vec4 vec4_wwxz(vec4 v)
{
	return vec4_new(v.w, v.w, v.x, v.z);
}

__forceinline vec4 vec4_wwxw(vec4 v)
{
	return vec4_new(v.w, v.w, v.x, v.w);
}

__forceinline vec4 vec4_wwyx(vec4 v)
{
	return vec4_new(v.w, v.w, v.y, v.x);
}

__forceinline vec4 vec4_wwyy(vec4 v)
{
	return vec4_new(v.w, v.w, v.y, v.y);
}

__forceinline vec4 vec4_wwyz(vec4 v)
{
	return vec4_new(v.w, v.w, v.y, v.z);
}

__forceinline vec4 vec4_wwyw(vec4 v)
{
	return vec4_new(v.w, v.w, v.y, v.w);
}

__forceinline vec4 vec4_wwzx(vec4 v)
{
	return vec4_new(v.w, v.w, v.z, v.x);
}

__forceinline vec4 vec4_wwzy(vec4 v)
{
	return vec4_new(v.w, v.w, v.z, v.y);
}

__forceinline vec4 vec4_wwzz(vec4 v)
{
	return vec4_new(v.w, v.w, v.z, v.z);
}

__forceinline vec4 vec4_wwzw(vec4 v)
{
	return vec4_new(v.w, v.w, v.z, v.w);
}

__forceinline vec4 vec4_wwwx(vec4 v)
{
	return vec4_new(v.w, v.w, v.w, v.x);
}

__forceinline vec4 vec4_wwwy(vec4 v)
{
	return vec4_new(v.w, v.w, v.w, v.y);
}

__forceinline vec4 vec4_wwwz(vec4 v)
{
	return vec4_new(v.w, v.w, v.w, v.z);
}

__forceinline vec4 vec4_wwww(vec4 v)
{
	return vec4_new(v.w, v.w, v.w, v.w);
}

#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
