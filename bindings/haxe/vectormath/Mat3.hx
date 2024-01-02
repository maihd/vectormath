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
@:native("::mat3")
extern class Mat3Data
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
}

@:forward
extern abstract Mat3(Mat3Data)
{
    // End
}
