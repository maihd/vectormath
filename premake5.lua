local ROOT_DIR = path.getabsolute(".")
local BUILD_DIR = path.join(ROOT_DIR, "projects")

local ENV = require(".env")
local PROJECT_PREFIX = "vectormath"

local MAILIB_PATH = path.join(ROOT_DIR, "examples/3rd_party/mailib")
local MaiLib = dofile(path.join(MAILIB_PATH, "premake5.mailib.lua"))

local vectormath = dofile(path.join(ROOT_DIR, "scripts", "vectormath.premake5.lua"))

local function vectormathproject(name)
    if (type(name) == "string") then
        project(PROJECT_PREFIX .. "_" .. name)
    else
        project(PROJECT_PREFIX)
    end

    -- Import vectormath premake5 module
    vectormath.includedirs(ROOT_DIR)
    vectormath.files(ROOT_DIR)
end

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

workspace(PROJECT_PREFIX .. "_" .. _ACTION)
do
    language "C"
    location (path.join(BUILD_DIR, _ACTION))

    configurations { 
        "DebugScalar", 
        "ReleaseScalar",
        
        "DebugSIMD",
        "ReleaseSIMD"
    }

    platforms { "x32", "x64" }

    -- Cflags
    MaiLib.cflags()
    cdialect "C11"

    startproject (PROJECT_PREFIX .. "_" .. "unit_tests")

    filter { "configurations:Debug*" }
    do
        optimize "Off"
    end

    filter { "configurations:Release*" }
    do
        optimize "Full"
    end

    filter { "configurations:*Scalar" }
    do
        defines {
            "VECTORMATH_SIMD_ENABLE=0"
        }
    end

    filter { "configurations:*SIMD" }
    do
        defines {
            "VECTORMATH_SIMD_ENABLE=1"
        }
    end

    filter {}
end

vectormathproject("unit_tests")
do
    kind "ConsoleApp"
    
    filedirs {
        "unit_tests/cases"
    }

    files {
        path.join(ROOT_DIR, "unit_tests/test_framework.h"),
        path.join(ROOT_DIR, "unit_tests/test_run_all.cpp"),
    }

    filter {}
end

if _ACTION == "vs2019" or _ACTION == "vs2022" then
    vectormathproject("msvc_c11_generics")
    do
        kind "ConsoleApp"

        files {
            path.join(ROOT_DIR, "unit_tests/msvc_c11_generics/main.c"),
        }

        filter {}
    end
end

-- examples
newoption {
    trigger = "with-examples",
    description = "Generate examples projects"
}

if _OPTIONS["with-examples"] then
    local function vectormathexample(name)
        vectormathproject(name)
        do
            kind "ConsoleApp"
            
            includedirs {
                path.join(ROOT_DIR, "examples/common"),
                path.join(ROOT_DIR, "examples", name),
                path.join(ROOT_DIR, "examples/3rd_party"),
            }

            filedirs {
                "examples/3rd_party/flecs",

                "examples/common/Native",
                "examples/common/Renderer",

                path.join("examples", name),
                path.join("examples", name, "Game"),
            }

            -- Select Vulkan renderer
            if (_OPTIONS["vulkan"]) then
                links {
                    --"vulkan-1"
                }
            
                includedirs {
                    path.join(ENV.VULKAN_DIR, "Include")
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
            else -- default to OpenGL renderer
                defines {
                    "GLEW_STATIC",
                }
            end

            filter {}

            -- Import mailib
            MaiLib.files(MAILIB_PATH)
            MaiLib.links(MAILIB_PATH)
            MaiLib.includedirs(MAILIB_PATH)

            filter {}
        end
    end

    vectormathexample("bunnymark_flecs")
    vectormathexample("bunnymark_flecs_c")
end