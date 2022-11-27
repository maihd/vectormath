local function getincludedir(directory)
    local includedir = path.join(directory, "include")
    return includedir
end

local function getsubincludedir(directory)
    local includedir = getincludedir(directory)
    local subincludedir = path.join(includedir, "vectormath")
    return subincludedir
end

return {
    -- Get header files folder path
    -- @param: directory - where vectormath is locate
    getincludedir = getincludedir,

    -- Get header files sub folder path
    -- @param: directory - where vectormath is locate
    getsubincludedir = getsubincludedir,

    -- Add vectormath's include directory to project
    -- @param: directory - where vectormath is locate
    includedirs = function (directory)
        includedirs {
            getincludedir(directory)
        }

        filter { "action:vs*"}
        do
            files {
                path.join(directory, "vectormath_types.natvis"),
            }
        end
    end,

    -- Import vectormath's files to project
    -- @param: directory - where vectormath is locate
    files = function (directory)
        local includedir = getincludedir(directory)
        local subincludedir = getsubincludedir(directory)

        files {
            path.join(subincludedir, "sse_to_neon.h"),
            path.join(subincludedir, "stdmath_extensions.h"),
    
            path.join(subincludedir, "vectormath_types.h"),
    
            path.join(subincludedir, "vectormath_scalar.h"),
            path.join(subincludedir, "vectormath_simd.h"),
            
            path.join(subincludedir, "vectormath_operators.h"),
            path.join(subincludedir, "vectormath_swizzles.h"),
    
            path.join(includedir, "vectormath.h"),
        }
    end
}