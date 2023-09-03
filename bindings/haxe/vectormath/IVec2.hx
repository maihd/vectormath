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
@:native("ivec2")
extern class IVec2Data
{
    public var x: Int32;
    public var y: Int32;
}

@:foward
extern abstract IVec2(IVec2Data)
{
    // End
}
