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
@:native("uvec4")
extern class UVec4Data
{
    public var x: UInt32;
    public var y: UInt32;
    public var z: UInt32;
    public var w: UInt32;
}

@:foward
extern abstract UVec4(UVec4Data)
{
    // End
}
