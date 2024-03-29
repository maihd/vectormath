local ROOT_DIR = path.getabsolute("..")
local BUILD_DIR = path.join(ROOT_DIR, "projects")

local ENV = dofile(path.join(ROOT_DIR, ".env.lua"))
local PROJECT_PREFIX = "vectormath"

-- local MAILIB_PATH = path.join(ROOT_DIR, "examples/3rd_party/mailib")
-- local MaiLib = dofile(path.join(MAILIB_PATH, "premake5.mailib.lua"))

local vectormath = dofile(path.join(ROOT_DIR, "scripts", "vectormath.genie.lua"))

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

solution(PROJECT_PREFIX .. "_" .. _ACTION)
do
    language "C++"
    location (path.join(BUILD_DIR, _ACTION))

    configurations { 
        "DebugScalar", 
        "ReleaseScalar",
        
        "DebugSIMD",
        "ReleaseSIMD"
    }

    platforms { "x32", "x64" }

    -- Cflags
    --MaiLib.cflags()

    startproject (PROJECT_PREFIX .. "_" .. "unit_tests")

    configuration "Debug*"
    do
        -- optimize "Off"
    end

    configuration "Release*"
    do
        -- optimize "Full"
    end

    configuration "*Scalar"
    do
        defines {
            "VECTORMATH_SIMD_ENABLE=0"
        }
    end

    configuration "*SIMD"
    do
        defines {
            "VECTORMATH_SIMD_ENABLE=1"
        }
    end

    configuration {}
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

    configuration {}
end

-- examples
newoption {
    trigger = "examples",
    description = "Generate examples projects"
}

-- if _OPTIONS["examples"] then
--     local function vectormathexample(name)
--         vectormathproject(name)
--         do
--             kind "ConsoleApp"
            
--             includedirs {
--                 path.join(ROOT_DIR, "examples/common"),
--                 path.join(ROOT_DIR, "examples", name),
--                 path.join(ROOT_DIR, "examples/3rd_party"),
--             }

--             filedirs {
--                 "examples/3rd_party/flecs",

--                 "examples/common/Native",
--                 "examples/common/Renderer",

--                 path.join("examples", name),
--                 path.join("examples", name, "Game"),
--             }

--             -- Select Vulkan renderer
--             if (_OPTIONS["vulkan"]) then
--                 links {
--                     --"vulkan-1"
--                 }
            
--                 includedirs {
--                     path.join(ENV.VULKAN_DIR, "Include")
--                 }

--                 configuration "x32"
--                 do
--                     libdirs {
--                         path.join(ENV.VULKAN_DIR, "Lib32")
--                     }
--                 end

--                 configuration "x64"
--                 do
--                     libdirs {
--                         path.join(ENV.VULKAN_DIR, "Lib")
--                     }
--                 end
--             else -- default to OpenGL renderer
--                 defines {
--                     "GLEW_STATIC",
--                 }
--             end

--             configuration {}

--             -- Import mailib
--             MaiLib.files(MAILIB_PATH)
--             MaiLib.links(MAILIB_PATH)
--             MaiLib.includedirs(MAILIB_PATH)

--             configuration {}
--         end
--     end

--     vectormathexample("bunnymark_flecs")
-- end