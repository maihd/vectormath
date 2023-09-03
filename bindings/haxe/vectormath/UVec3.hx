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
@:native("uvec3")
extern class UVec3Data
{
    public var x: UInt32;
    public var y: UInt32;
    public var z: UInt32;
}

@:foward
extern abstract UVec3(UVec3Data)
{
    // End
}
