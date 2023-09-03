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
@:native("ivec4")
extern class IVec4Data
{
    public var x: Int32;
    public var y: Int32;
    public var z: Int32;
    public var w: Int32;
}

@:foward
extern abstract IVec4(IVec4Data)
{
    // End
}
