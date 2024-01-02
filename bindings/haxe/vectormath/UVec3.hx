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
@:native("::uvec3")
extern class UVec3Data
{
    public var x: UInt32;
    public var y: UInt32;
    public var z: UInt32;
}

@:forward
extern abstract UVec3(UVec3Data)
{
    // End
}
