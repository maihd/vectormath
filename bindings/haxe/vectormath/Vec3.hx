// This code is auto-generated, please avoid editting!
// Date: Mon, 03 Jun 2024 08:15:28 GMT

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
@:native("vec3")
extern class Vec3Data
{
    public var x: Float32;
    public var y: Float32;
    public var z: Float32;
}

@:forward
@:build(vectormath.Swizzle.generateFields(3))
extern abstract Vec3(Vec3Data)
{
    //
    // Constructors
    //

    @:native("vec3_new")
    @:overload(function (): Vec3 {})
    @:overload(function (s: Float32): Vec3 {})
    public function new(x: Float32, y: Float32, z: Float32);

    //
    // Operators
    //

    @:op(-A)
    @:native("vec3_neg")
    public extern static function neg(v: Vec3) : Vec3;

    @:op(A + B)
    @:native("vec3_add")
    public extern static function add(a: Vec3, b: Vec3) : Vec3;

    @:op(A - B)
    @:native("vec3_sub")
    public extern static function sub(a: Vec3, b: Vec3) : Vec3;

    @:op(A * B)
    @:native("vec3_mul")
    public extern static function mul(a: Vec3, b: Vec3) : Vec3;

    @:op(A / B)
    @:native("vec3_div")
    public extern static function div(a: Vec3, b: Vec3) : Vec3;

    @:op(A + B)
    @:commutative
    @:native("vec3_add1")
    public extern static function add1(a: Vec3, b: Float32) : Vec3;

    @:op(A - B)
    @:commutative
    @:native("vec3_sub1")
    public extern static function sub1(a: Vec3, b: Float32) : Vec3;

    @:op(A * B)
    @:commutative
    @:native("vec3_mul1")
    public extern static function mul1(a: Vec3, b: Float32) : Vec3;

    @:op(A / B)
    @:native("vec3_div1")
    public extern static function div1(a: Vec3, b: Float32) : Vec3;

    @:op(A == B)
    @:native("vec3_equal")
    public extern static function equal(a: Vec3, b: Vec3) : Vec3;

    @:op(A != B)
    @:native("vec3_not_equal")
    public extern static function notEqual(a: Vec3, b: Vec3) : Vec3;

    //
    // Functions
    //

    @:native("vec3_from_vec2")
    public extern static function fromVec2(v: Vec2) : Vec3;

    @:native("vec3_from_vec4")
    public extern static function fromVec4(v: Vec4) : Vec3;

    @:native("vec3_mul_add")
    public extern static function mulAdd(a: Vec3, b: Vec3, c: Vec3) : Vec3;

    @:native("vec3_mul_sub")
    public extern static function mulSub(a: Vec3, b: Vec3, c: Vec3) : Vec3;

    @:native("vec3_isclose")
    public extern static function isClose(a: Vec3, b: Vec3) : Bool;

    @:native("vec3_sign")
    public extern static function sign(v: Vec3) : IVec3;

    @:native("vec3_abs")
    public extern static function abs(v: Vec3) : Vec3;

    @:native("vec3_cos")
    public extern static function cos(v: Vec3) : Vec3;

    @:native("vec3_sin")
    public extern static function sin(v: Vec3) : Vec3;

    @:native("vec3_tan")
    public extern static function tan(v: Vec3) : Vec3;

    @:native("vec3_cosh")
    public extern static function cosh(v: Vec3) : Vec3;

    @:native("vec3_sinh")
    public extern static function sinh(v: Vec3) : Vec3;

    @:native("vec3_tanh")
    public extern static function tanh(v: Vec3) : Vec3;

    @:native("vec3_acos")
    public extern static function acos(v: Vec3) : Vec3;

    @:native("vec3_asin")
    public extern static function asin(v: Vec3) : Vec3;

    @:native("vec3_atan")
    public extern static function atan(v: Vec3) : Vec3;

    @:native("vec3_atan2")
    public extern static function atan2(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_exp")
    public extern static function exp(v: Vec3) : Vec3;

    @:native("vec3_exp2")
    public extern static function exp2(v: Vec3) : Vec3;

    @:native("vec3_log")
    public extern static function log(v: Vec3) : Vec3;

    @:native("vec3_log2")
    public extern static function log2(v: Vec3) : Vec3;

    @:native("vec3_log10")
    public extern static function log10(v: Vec3) : Vec3;

    @:native("vec3_pow")
    public extern static function pow(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_frac")
    public extern static function frac(v: Vec3) : Vec3;

    @:native("vec3_fmod")
    public extern static function fmod(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_ceil")
    public extern static function ceil(v: Vec3) : Vec3;

    @:native("vec3_floor")
    public extern static function floor(v: Vec3) : Vec3;

    @:native("vec3_round")
    public extern static function round(v: Vec3) : Vec3;

    @:native("vec3_trunc")
    public extern static function trunc(v: Vec3) : Vec3;

    @:native("vec3_min")
    public extern static function min(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_max")
    public extern static function max(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_clamp")
    public extern static function clamp(v: Vec3, min: Vec3, max: Vec3) : Vec3;

    @:native("vec3_saturate")
    public extern static function saturate(v: Vec3) : Vec3;

    @:native("vec3_step")
    public extern static function step(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_lerp")
    public extern static function lerp(a: Vec3, b: Vec3, t: Vec3) : Vec3;

    @:native("vec3_lerp1")
    public extern static function lerp1(a: Vec3, b: Vec3, t: Float32) : Vec3;

    @:native("vec3_smoothstep")
    public extern static function smoothstep(a: Vec3, b: Vec3, t: Vec3) : Vec3;

    @:native("vec3_sqrt")
    public extern static function sqrt(v: Vec3) : Vec3;

    @:native("vec3_rsqrt")
    public extern static function rsqrt(v: Vec3) : Vec3;

    @:native("vec3_cross")
    public extern static function cross(a: Vec3, b: Vec3) : Vec3;

    @:native("vec3_dot")
    public extern static function dot(a: Vec3, b: Vec3) : Float32;

    @:native("vec3_lensqr")
    public extern static function lengthSqr(v: Vec3) : Float32;

    @:native("vec3_length")
    public extern static function length(v: Vec3) : Float32;

    @:native("vec3_distance")
    public extern static function distance(a: Vec3, b: Vec3) : Float32;

    @:native("vec3_distsqr")
    public extern static function distanceSqr(a: Vec3, b: Vec3) : Float32;

    @:native("vec3_normalize")
    public extern static function normalize(v: Vec3) : Vec3;

    @:native("vec3_reflect")
    public extern static function reflect(v: Vec3, n: Vec3) : Vec3;

    @:native("vec3_refract")
    public extern static function refract(v: Vec3, n: Vec3, eta: Float32) : Vec3;

    @:native("vec3_faceforward")
    public extern static function faceforward(n: Vec3, i: Vec3, nref: Vec3) : Vec3;

    @:native("vec3_mul_mat4")
    public extern static function mulMat4(a: Vec3, b: Mat4) : Vec3;

    // End
}
