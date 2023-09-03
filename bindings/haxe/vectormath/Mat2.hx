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
@:native("mat2")
extern class Mat2Data
{
    public var m00: Float32;
    public var m01: Float32;

    public var m10: Float32;
    public var m11: Float32;
}

@:foward
extern abstract Mat2(Mat2Data)
{
    // End
}
