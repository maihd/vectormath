local ROOT_DIR = path.getabsolute(".")
local BUILD_DIR = path.join(ROOT_DIR, "projects")

local ENV = require("premake5.env")

local function filedirs(dirs)
    if type(dirs) == "string" then
        files {
            path.join(ROOT_DIR, dirs, "*.h"),
            path.join(ROOT_DIR, dirs, "*.c"),
            path.join(ROOT_DIR, dirs, "*.hpp"),
            path.join(ROOT_DIR, dirs, "*.cpp"),
        }
    elseif type(dirs) == "table" then
        for _, dir in ipairs(dirs) do
            filedirs(dir)
        end
    end
end

workspace("vectormath_" .. _ACTION)
do
    language "C++"
    location (path.join(BUILD_DIR, _ACTION))

    configurations { "Debug", "Release" }

    platforms { "x32", "x64" }

    flags {
        "NoPCH",
        "NoRuntimeChecks",
        "ShadowedVariables",
        "LinkTimeOptimization",

        --"FatalWarnings",
        --"FatalLinkWarnings",
        --"FatalCompileWarnings",
    }

    cppdialect "C++11"
    staticruntime "On"
    omitframepointer "On"

    rtti "On"
    exceptionhandling "Off"

    startproject("vectormath_" .. _ACTION .. ".unit_tests")

    filter { "configurations:Debug" }
    do
        optimize "Off"
    end

    filter { "configurations:Release" }
    do
        optimize "Full"
    end

    filter {}
end

project("vectormath_" .. _ACTION)
do
    kind "ConsoleApp"

    defines {
        "GLEW_STATIC",
    }

    links {
        --"vulkan-1"
    }
    
    includedirs {
        path.join(ROOT_DIR),
        path.join(ROOT_DIR, "examples/common"),
        path.join(ROOT_DIR, "examples/developing"),
        path.join(ROOT_DIR, "examples/3rd_party"),

        -- HARD CODE, CHANGE IN YOUR SYSTEM
        path.join(ENV.VULKAN_DIR, "Include")
    }

    filedirs {
        "unit_tests/cases"
    }

    files {
        --path.join(ROOT_DIR, "unit_tests/test_run_all.cpp"),
        path.join(ROOT_DIR, "include/sse_to_neon.h"),
        path.join(ROOT_DIR, "include/stdmath_extensions.h"),

        path.join(ROOT_DIR, "include/vector_types.h"),
        path.join(ROOT_DIR, "include/vector_types.natvis"),

        path.join(ROOT_DIR, "include/vector_math.h"),
        path.join(ROOT_DIR, "include/vector_math_scalar.h"),
        path.join(ROOT_DIR, "include/vector_math_simd.h"),
        path.join(ROOT_DIR, "include/vector_math_operators.h"),

        path.join(ROOT_DIR, "unit_tests/test_framework.h"),
    }

    filedirs {
        "examples/3rd_party/flecs",

        "examples/common/Native",
        "examples/common/Container",
        "examples/common/Renderer",
        "examples/common/Runtime",

        "examples/developing",
        "examples/developing/Game",
    }

    filter "platforms:x32"
    do
        libdirs {
            path.join(ENV.VULKAN_DIR, "Lib32")
        }
    end

    filter "platforms:x64"
    do
        libdirs {
            path.join(ENV.VULKAN_DIR, "Lib")
        }
    end

    filter {}
end
