//! This file is hand-written, DONOT delete!

package vectormath;

#if cxx
import cxx.num.Int32;
import cxx.num.UInt32;
import cxx.num.Float32;
#elseif cpp
private typedef Int32 = cpp.Int32;
private typedef UInt32 = cpp.UInt32;
private typedef Float32 = cpp.Float32;
#end

extern abstract Quat(Vec4Data)
{
    //
    // Variables
    //

    public var x(get, set): Float32;
    inline function get_x() return this.x;
    inline function set_x(v: Float32) return this.x = v;

    public var y(get, set): Float32;
    inline function get_y() return this.y;
    inline function set_y(v: Float32) return this.y = v;

    public var z(get, set): Float32;
    inline function get_z() return this.z;
    inline function set_z(v: Float32) return this.z = v;

    public var w(get, set): Float32;
    inline function get_w() return this.w;
    inline function set_w(v: Float32) return this.w = v;

    //
    // Constructors
    //

    @:native("vec4_new")
    @:overload(function (): Quat {})
    @:overload(function (s: Float32): Quat {})
    public function new(x: Float32, y: Float32, z: Float32, w: Float32);

    //
    // Operators
    //

    @:op(-A)
    @:native("vec4_neg")
    public extern static function neg(v: Quat) : Quat;

    @:op(A + B)
    @:native("vec4_add")
    public extern static function add(a: Quat, b: Quat) : Quat;

    @:op(A - B)
    @:native("vec4_sub")
    public extern static function sub(a: Quat, b: Quat) : Quat;

    @:op(A * B)
    @:native("vec4_mul")
    public extern static function mul(a: Quat, b: Quat) : Quat;

    @:op(A / B)
    @:native("vec4_div")
    public extern static function div(a: Quat, b: Quat) : Quat;

    @:op(A + B)
    @:commutative
    @:native("vec4_add1")
    public extern static function add1(a: Quat, b: Float32) : Quat;

    @:op(A - B)
    @:commutative
    @:native("vec4_sub1")
    public extern static function sub1(a: Quat, b: Float32) : Quat;

    @:op(A * B)
    @:commutative
    @:native("vec4_mul1")
    public extern static function mul1(a: Quat, b: Float32) : Quat;

    @:op(A / B)
    @:commutative
    @:native("vec4_div1")
    public extern static function div1(a: Quat, b: Float32) : Quat;

    @:op(A == B)
    @:native("vec4_equal")
    public extern static function equal(a: Quat, b: Quat) : Quat;

    @:op(A != B)
    @:native("vec4_not_equal")
    public extern static function notEqual(a: Quat, b: Quat) : Quat;

    //
    // Functions
    //

    @:native("quat_inverse")
    public extern static function inverse(q: Quat) : Quat;

    @:native("quat_conj")
    public extern static function conjugate(q: Quat) : Quat;

    @:native("quat_from_axis_angle")
    public extern static function fromAxisAngle(axis: Vec3, angle: Float32) : Quat;

    @:native("quat_to_axis_angle")
    public extern static function toAxisAngle(quat: Quat) : Vec4;

    // @:native("quat_to_axis_angle_ref")
    // public extern static function toAxisAngleRef(quat: Vec4, axis: vec3 *, angle: float *) : void;

    @:native("quat_from_euler")
    public extern static function fromEuler(x: Float32, y: Float32, z: Float32) : Quat;

    // End
}
