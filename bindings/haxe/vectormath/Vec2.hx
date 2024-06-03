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
@:native("vec2")
extern class Vec2Data
{
    public var x: Float32;
    public var y: Float32;
}

@:forward
@:build(vectormath.Swizzle.generateFields(2))
extern abstract Vec2(Vec2Data)
{
    //
    // Constructors
    //

    @:native("vec2_new")
    @:overload(function (): Vec2 {})
    @:overload(function (s: Float32): Vec2 {})
    public function new(x: Float32, y: Float32);

    //
    // Operators
    //

    @:op(-A)
    @:native("vec2_neg")
    public extern static function neg(v: Vec2) : Vec2;

    @:op(A + B)
    @:native("vec2_add")
    public extern static function add(a: Vec2, b: Vec2) : Vec2;

    @:op(A - B)
    @:native("vec2_sub")
    public extern static function sub(a: Vec2, b: Vec2) : Vec2;

    @:op(A * B)
    @:native("vec2_mul")
    public extern static function mul(a: Vec2, b: Vec2) : Vec2;

    @:op(A / B)
    @:native("vec2_div")
    public extern static function div(a: Vec2, b: Vec2) : Vec2;

    @:op(A + B)
    @:commutative
    @:native("vec2_add1")
    public extern static function add1(a: Vec2, b: Float32) : Vec2;

    @:op(A - B)
    @:commutative
    @:native("vec2_sub1")
    public extern static function sub1(a: Vec2, b: Float32) : Vec2;

    @:op(A * B)
    @:commutative
    @:native("vec2_mul1")
    public extern static function mul1(a: Vec2, b: Float32) : Vec2;

    @:op(A / B)
    @:native("vec2_div1")
    public extern static function div1(a: Vec2, b: Float32) : Vec2;

    @:op(A == B)
    @:native("vec2_equal")
    public extern static function equal(a: Vec2, b: Vec2) : Vec2;

    @:op(A != B)
    @:native("vec2_not_equal")
    public extern static function notEqual(a: Vec2, b: Vec2) : Vec2;

    //
    // Functions
    //

    @:native("vec2_from_vec3")
    public extern static function fromVec3(v: Vec3) : Vec2;

    @:native("vec2_mul_add")
    public extern static function mulAdd(a: Vec2, b: Vec2, c: Vec2) : Vec2;

    @:native("vec2_mul_sub")
    public extern static function mulSub(a: Vec2, b: Vec2, c: Vec2) : Vec2;

    @:native("vec2_isclose")
    public extern static function isClose(a: Vec2, b: Vec2) : Bool;

    @:native("vec2_sign")
    public extern static function sign(v: Vec2) : IVec2;

    @:native("vec2_abs")
    public extern static function abs(v: Vec2) : Vec2;

    @:native("vec2_cos")
    public extern static function cos(v: Vec2) : Vec2;

    @:native("vec2_sin")
    public extern static function sin(v: Vec2) : Vec2;

    @:native("vec2_tan")
    public extern static function tan(v: Vec2) : Vec2;

    @:native("vec2_cosh")
    public extern static function cosh(v: Vec2) : Vec2;

    @:native("vec2_sinh")
    public extern static function sinh(v: Vec2) : Vec2;

    @:native("vec2_tanh")
    public extern static function tanh(v: Vec2) : Vec2;

    @:native("vec2_acos")
    public extern static function acos(v: Vec2) : Vec2;

    @:native("vec2_asin")
    public extern static function asin(v: Vec2) : Vec2;

    @:native("vec2_atan")
    public extern static function atan(v: Vec2) : Vec2;

    @:native("vec2_atan2")
    public extern static function atan2(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_exp")
    public extern static function exp(v: Vec2) : Vec2;

    @:native("vec2_exp2")
    public extern static function exp2(v: Vec2) : Vec2;

    @:native("vec2_log")
    public extern static function log(v: Vec2) : Vec2;

    @:native("vec2_log2")
    public extern static function log2(v: Vec2) : Vec2;

    @:native("vec2_log10")
    public extern static function log10(v: Vec2) : Vec2;

    @:native("vec2_pow")
    public extern static function pow(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_frac")
    public extern static function frac(v: Vec2) : Vec2;

    @:native("vec2_fmod")
    public extern static function fmod(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_ceil")
    public extern static function ceil(v: Vec2) : Vec2;

    @:native("vec2_floor")
    public extern static function floor(v: Vec2) : Vec2;

    @:native("vec2_round")
    public extern static function round(v: Vec2) : Vec2;

    @:native("vec2_trunc")
    public extern static function trunc(v: Vec2) : Vec2;

    @:native("vec2_min")
    public extern static function min(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_max")
    public extern static function max(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_clamp")
    public extern static function clamp(v: Vec2, min: Vec2, max: Vec2) : Vec2;

    @:native("vec2_saturate")
    public extern static function saturate(v: Vec2) : Vec2;

    @:native("vec2_step")
    public extern static function step(a: Vec2, b: Vec2) : Vec2;

    @:native("vec2_lerp")
    public extern static function lerp(a: Vec2, b: Vec2, t: Vec2) : Vec2;

    @:native("vec2_lerp1")
    public extern static function lerp1(a: Vec2, b: Vec2, t: Float32) : Vec2;

    @:native("vec2_smoothstep")
    public extern static function smoothstep(a: Vec2, b: Vec2, t: Vec2) : Vec2;

    @:native("vec2_sqrt")
    public extern static function sqrt(v: Vec2) : Vec2;

    @:native("vec2_rsqrt")
    public extern static function rsqrt(v: Vec2) : Vec2;

    @:native("vec2_dot")
    public extern static function dot(a: Vec2, b: Vec2) : Float32;

    @:native("vec2_lensqr")
    public extern static function lengthSqr(v: Vec2) : Float32;

    @:native("vec2_length")
    public extern static function length(v: Vec2) : Float32;

    @:native("vec2_distance")
    public extern static function distance(a: Vec2, b: Vec2) : Float32;

    @:native("vec2_distsqr")
    public extern static function distanceSqr(a: Vec2, b: Vec2) : Float32;

    @:native("vec2_normalize")
    public extern static function normalize(v: Vec2) : Vec2;

    @:native("vec2_reflect")
    public extern static function reflect(v: Vec2, n: Vec2) : Vec2;

    @:native("vec2_refract")
    public extern static function refract(v: Vec2, n: Vec2, eta: Float32) : Vec2;

    @:native("vec2_faceforward")
    public extern static function faceforward(n: Vec2, i: Vec2, nref: Vec2) : Vec2;

    @:native("vec2_angle")
    public extern static function angle(v: Vec2) : Float32;

    @:native("vec2_angle_deg")
    public extern static function angleDeg(v: Vec2) : Float32;

    @:native("vec2_from_angle")
    public extern static function fromAngle(angle: Float32, length: Float32) : Vec2;

    @:native("vec2_from_angle_deg")
    public extern static function fromAngleDeg(angle: Float32, length: Float32) : Vec2;

    // End
}
