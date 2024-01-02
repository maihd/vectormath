// This code is auto-generated, please avoid editting!
// Date: Tue, 02 Jan 2024 03:53:35 GMT

package vectormath;

#if cxx
import cxx.num.Int32;
import cxx.num.UInt32;
import cxx.num.Float32;
#elseif cpp
import cpp.Int32;
import cpp.UInt32;
import cpp.Float32;
#end

@:valueType
@:structAccess
@:include("vectormath.h")
@:include("vectormath/vectormath_generics.h")
@:native("mat4")
extern class Mat4Data
{
    public var m00: Float32;
    public var m01: Float32;
    public var m02: Float32;
    public var m03: Float32;

    public var m10: Float32;
    public var m11: Float32;
    public var m12: Float32;
    public var m13: Float32;

    public var m20: Float32;
    public var m21: Float32;
    public var m22: Float32;
    public var m23: Float32;

    public var m30: Float32;
    public var m31: Float32;
    public var m32: Float32;
    public var m33: Float32;
}

@:forward
extern abstract Mat4(Mat4Data)
{
    //
    // Constructors
    //

    @:native("mat4_new")
    @:overload(function (): Mat4 {})
    @:overload(function (s: Float32): Mat4 {})
    public function new(m00: Float32, m01: Float32, m02: Float32, m03: Float32, m10: Float32, m11: Float32, m12: Float32, m13: Float32, m20: Float32, m21: Float32, m22: Float32, m23: Float32, m30: Float32, m31: Float32, m32: Float32, m33: Float32);

    //
    // Functions
    //

    @:native("mat4_neg")
    public extern static function neg(m: Mat4) : Mat4;

    @:native("mat4_add")
    public extern static function add(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_sub")
    public extern static function sub(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_equal")
    public extern static function equal(a: Mat4, b: Mat4) : Bool;

    @:native("mat4_not_equal")
    public extern static function notEqual(a: Mat4, b: Mat4) : Bool;

    @:native("mat4_abs")
    public extern static function abs(m: Mat4) : Mat4;

    @:native("mat4_cos")
    public extern static function cos(m: Mat4) : Mat4;

    @:native("mat4_sin")
    public extern static function sin(m: Mat4) : Mat4;

    @:native("mat4_tan")
    public extern static function tan(m: Mat4) : Mat4;

    @:native("mat4_cosh")
    public extern static function cosh(m: Mat4) : Mat4;

    @:native("mat4_sinh")
    public extern static function sinh(m: Mat4) : Mat4;

    @:native("mat4_tanh")
    public extern static function tanh(m: Mat4) : Mat4;

    @:native("mat4_acos")
    public extern static function acos(m: Mat4) : Mat4;

    @:native("mat4_asin")
    public extern static function asin(m: Mat4) : Mat4;

    @:native("mat4_atan")
    public extern static function atan(m: Mat4) : Mat4;

    @:native("mat4_atan2")
    public extern static function atan2(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_exp")
    public extern static function exp(m: Mat4) : Mat4;

    @:native("mat4_exp2")
    public extern static function exp2(m: Mat4) : Mat4;

    @:native("mat4_log")
    public extern static function log(m: Mat4) : Mat4;

    @:native("mat4_log2")
    public extern static function log2(m: Mat4) : Mat4;

    @:native("mat4_log10")
    public extern static function log10(m: Mat4) : Mat4;

    @:native("mat4_pow")
    public extern static function pow(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_frac")
    public extern static function frac(m: Mat4) : Mat4;

    @:native("mat4_fmod")
    public extern static function fmod(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_ceil")
    public extern static function ceil(m: Mat4) : Mat4;

    @:native("mat4_floor")
    public extern static function floor(m: Mat4) : Mat4;

    @:native("mat4_round")
    public extern static function round(m: Mat4) : Mat4;

    @:native("mat4_trunc")
    public extern static function trunc(m: Mat4) : Mat4;

    @:native("mat4_min")
    public extern static function min(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_max")
    public extern static function max(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_clamp")
    public extern static function clamp(v: Mat4, min: Mat4, max: Mat4) : Mat4;

    @:native("mat4_saturate")
    public extern static function saturate(m: Mat4) : Mat4;

    @:native("mat4_step")
    public extern static function step(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_lerp")
    public extern static function lerp(a: Mat4, b: Mat4, t: Mat4) : Mat4;

    @:native("mat4_lerp1")
    public extern static function lerp1(a: Mat4, b: Mat4, t: Float32) : Mat4;

    @:native("mat4_smoothstep")
    public extern static function smoothstep(a: Mat4, b: Mat4, t: Mat4) : Mat4;

    @:native("mat4_sqrt")
    public extern static function sqrt(m: Mat4) : Mat4;

    @:native("mat4_rsqrt")
    public extern static function rsqrt(m: Mat4) : Mat4;

    @:native("mat4_mul_vec4")
    public extern static function mulVec4(m: Mat4, v: Vec4) : Vec4;

    @:native("mat4_mul_vec3")
    public extern static function mulVec3(a: Mat4, b: Vec3) : Vec3;

    @:native("mat4_mul_vec2")
    public extern static function mulVec2(a: Mat4, b: Vec2) : Vec2;

    @:native("mat4_mul")
    public extern static function mul(a: Mat4, b: Mat4) : Mat4;

    @:native("mat4_mul1")
    public extern static function mul1(a: Mat4, b: Float32) : Mat4;

    @:native("mat4_transpose")
    public extern static function transpose(m: Mat4) : Mat4;

    @:native("mat4_inverse")
    public extern static function inverse(m: Mat4) : Mat4;

    @:native("mat4_identity")
    public extern static function identity() : Mat4;

    @:native("mat4_ortho")
    public extern static function ortho(left: Float32, right: Float32, bottom: Float32, top: Float32, zNear: Float32, zFar: Float32) : Mat4;

    @:native("mat4_frustum")
    public extern static function frustum(l: Float32, r: Float32, b: Float32, t: Float32, n: Float32, f: Float32) : Mat4;

    @:native("mat4_perspective")
    public extern static function perspective(fovRadians: Float32, aspect: Float32, znear: Float32, zfar: Float32) : Mat4;

    @:native("mat4_lookat")
    public extern static function lookat(eye: Vec3, target: Vec3, up: Vec3) : Mat4;

    @:native("mat4_scalation")
    public extern static function scalation(x: Float32, y: Float32, z: Float32) : Mat4;

    @:native("mat4_scalation1")
    public extern static function scalation1(s: Float32) : Mat4;

    @:native("mat4_scalation_vec2")
    public extern static function scalationVec2(v: Vec2) : Mat4;

    @:native("mat4_scalation_vec3")
    public extern static function scalationVec3(v: Vec3) : Mat4;

    @:native("mat4_translation")
    public extern static function translation(x: Float32, y: Float32, z: Float32) : Mat4;

    @:native("mat4_translation_vec2")
    public extern static function translationVec2(v: Vec2) : Mat4;

    @:native("mat4_translation_vec3")
    public extern static function translationVec3(v: Vec3) : Mat4;

    @:native("mat4_rotation")
    public extern static function rotation(x: Float32, y: Float32, z: Float32, radians: Float32) : Mat4;

    @:native("mat4_rotation_axis_angle")
    public extern static function rotationAxisAngle(axis: Vec3, angle: Float32) : Mat4;

    @:native("mat4_rotation_x")
    public extern static function rotationX(angle: Float32) : Mat4;

    @:native("mat4_rotation_y")
    public extern static function rotationY(angle: Float32) : Mat4;

    @:native("mat4_rotation_z")
    public extern static function rotationZ(radians: Float32) : Mat4;

    @:native("mat4_rotation_quat")
    public extern static function rotationQuat(quaternion: Vec4) : Mat4;

    @:native("mat4_transform2")
    public extern static function transform2(position: Vec2, angle: Float32, scale: Vec2) : Mat4;

    @:native("mat4_transform3")
    public extern static function transform3(position: Vec3, quat: Vec4, scale: Vec3) : Mat4;

    // End
}
