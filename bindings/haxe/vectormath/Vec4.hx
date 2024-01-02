// This code is auto-generated, please avoid editting!
// Date: Tue, 02 Jan 2024 03:50:55 GMT

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
@:native("::vec4")
extern class Vec4Data
{
    public var x: Float32;
    public var y: Float32;
    public var z: Float32;
    public var w: Float32;
}

@:forward
@:build(vectormath.Swizzle.generateFields(4))
extern abstract Vec4(Vec4Data)
{
    //
    // Constructors
    //

    @:native("vec4_new")
    @:overload(function (): Vec4 {})
    @:overload(function (s: Float32): Vec4 {})
    public function new(x: Float32, y: Float32, z: Float32, w: Float32);

    //
    // Operators
    //

    @:op(-A)
    @:native("vec4_neg")
    public extern static function neg(v: Vec4) : Vec4;

    @:op(A + B)
    @:native("vec4_add")
    public extern static function add(a: Vec4, b: Vec4) : Vec4;

    @:op(A - B)
    @:native("vec4_sub")
    public extern static function sub(a: Vec4, b: Vec4) : Vec4;

    @:op(A * B)
    @:native("vec4_mul")
    public extern static function mul(a: Vec4, b: Vec4) : Vec4;

    @:op(A / B)
    @:native("vec4_div")
    public extern static function div(a: Vec4, b: Vec4) : Vec4;

    @:op(A + B)
    @:commutative
    @:native("vec4_add1")
    public extern static function add1(a: Vec4, b: Float32) : Vec4;

    @:op(A - B)
    @:commutative
    @:native("vec4_sub1")
    public extern static function sub1(a: Vec4, b: Float32) : Vec4;

    @:op(A * B)
    @:commutative
    @:native("vec4_mul1")
    public extern static function mul1(a: Vec4, b: Float32) : Vec4;

    @:op(A / B)
    @:native("vec4_div1")
    public extern static function div1(a: Vec4, b: Float32) : Vec4;

    @:op(A == B)
    @:native("vec4_equal")
    public extern static function equal(a: Vec4, b: Vec4) : Vec4;

    @:op(A != B)
    @:native("vec4_not_equal")
    public extern static function notEqual(a: Vec4, b: Vec4) : Vec4;

    //
    // Functions
    //

    @:native("vec4_mul_add")
    public extern static function mulAdd(a: Vec4, b: Vec4, c: Vec4) : Vec4;

    @:native("vec4_mul_sub")
    public extern static function mulSub(a: Vec4, b: Vec4, c: Vec4) : Vec4;

    @:native("vec4_isclose")
    public extern static function isClose(a: Vec4, b: Vec4) : Bool;

    @:native("vec4_sign")
    public extern static function sign(v: Vec4) : IVec4;

    @:native("vec4_abs")
    public extern static function abs(v: Vec4) : Vec4;

    @:native("vec4_cos")
    public extern static function cos(v: Vec4) : Vec4;

    @:native("vec4_sin")
    public extern static function sin(v: Vec4) : Vec4;

    @:native("vec4_tan")
    public extern static function tan(v: Vec4) : Vec4;

    @:native("vec4_cosh")
    public extern static function cosh(v: Vec4) : Vec4;

    @:native("vec4_sinh")
    public extern static function sinh(v: Vec4) : Vec4;

    @:native("vec4_tanh")
    public extern static function tanh(v: Vec4) : Vec4;

    @:native("vec4_acos")
    public extern static function acos(v: Vec4) : Vec4;

    @:native("vec4_asin")
    public extern static function asin(v: Vec4) : Vec4;

    @:native("vec4_atan")
    public extern static function atan(v: Vec4) : Vec4;

    @:native("vec4_atan2")
    public extern static function atan2(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_exp")
    public extern static function exp(v: Vec4) : Vec4;

    @:native("vec4_exp2")
    public extern static function exp2(v: Vec4) : Vec4;

    @:native("vec4_log")
    public extern static function log(v: Vec4) : Vec4;

    @:native("vec4_log2")
    public extern static function log2(v: Vec4) : Vec4;

    @:native("vec4_log10")
    public extern static function log10(v: Vec4) : Vec4;

    @:native("vec4_pow")
    public extern static function pow(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_frac")
    public extern static function frac(v: Vec4) : Vec4;

    @:native("vec4_fmod")
    public extern static function fmod(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_ceil")
    public extern static function ceil(v: Vec4) : Vec4;

    @:native("vec4_floor")
    public extern static function floor(v: Vec4) : Vec4;

    @:native("vec4_round")
    public extern static function round(v: Vec4) : Vec4;

    @:native("vec4_trunc")
    public extern static function trunc(v: Vec4) : Vec4;

    @:native("vec4_min")
    public extern static function min(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_max")
    public extern static function max(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_clamp")
    public extern static function clamp(v: Vec4, min: Vec4, max: Vec4) : Vec4;

    @:native("vec4_saturate")
    public extern static function saturate(v: Vec4) : Vec4;

    @:native("vec4_step")
    public extern static function step(a: Vec4, b: Vec4) : Vec4;

    @:native("vec4_lerp")
    public extern static function lerp(a: Vec4, b: Vec4, t: Vec4) : Vec4;

    @:native("vec4_lerp1")
    public extern static function lerp1(a: Vec4, b: Vec4, t: Float32) : Vec4;

    @:native("vec4_smoothstep")
    public extern static function smoothstep(a: Vec4, b: Vec4, t: Vec4) : Vec4;

    @:native("vec4_sqrt")
    public extern static function sqrt(v: Vec4) : Vec4;

    @:native("vec4_rsqrt")
    public extern static function rsqrt(v: Vec4) : Vec4;

    @:native("vec4_dot")
    public extern static function dot(a: Vec4, b: Vec4) : Float32;

    @:native("vec4_lensqr")
    public extern static function lengthSqr(v: Vec4) : Float32;

    @:native("vec4_length")
    public extern static function length(v: Vec4) : Float32;

    @:native("vec4_distsqr")
    public extern static function distanceSqr(a: Vec4, b: Vec4) : Float32;

    @:native("vec4_normalize")
    public extern static function normalize(v: Vec4) : Vec4;

    @:native("vec4_reflect")
    public extern static function reflect(v: Vec4, n: Vec4) : Vec4;

    @:native("vec4_refract")
    public extern static function refract(v: Vec4, n: Vec4, eta: Float32) : Vec4;

    @:native("vec4_faceforward")
    public extern static function faceforward(n: Vec4, i: Vec4, nref: Vec4) : Vec4;

    @:native("vec4_mul_mat4")
    public extern static function mulMat4(v: Vec4, m: Mat4) : Vec4;

    // End
}
