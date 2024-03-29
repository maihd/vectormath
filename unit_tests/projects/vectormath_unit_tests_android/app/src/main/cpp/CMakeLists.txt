# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("vectormath_unit_tests_android")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        vectormath_unit_tests_android

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ../../../../../../cases/test_math_ex.cpp

        ../../../../../../cases/test_int32.cpp
        ../../../../../../cases/test_uint32.cpp

        ../../../../../../cases/test_mat4.cpp
        ../../../../../../cases/test_vec2.cpp
        ../../../../../../cases/test_vec3.cpp
        ../../../../../../cases/test_vec4.cpp

        ../../../../../../cases/test_vec4_swizzles.cpp
        ../../../../../../cases/test_vec2_swizzles_clang.cpp
        ../../../../../../cases/test_vec3_swizzles_clang.cpp
        ../../../../../../cases/test_vec4_swizzles_clang.cpp

        vectormath_unit_tests_android.cpp
        )

include_directories( # Sets the name of the library.
        vectormath_unit_tests_android

        # Provides a relative path to your header include path(s).
        ../../../../../../
        ../../../../../../../include
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        vectormath_unit_tests_android

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

target_compile_options(
        vectormath_unit_tests_android

        PRIVATE

        -DVECTORMATH_USE_EXACT_PRECISION
        -DVECTORMATH_USE_CLANG_EXT
        -DVECTORMATH_SIMD_ENABLE=1
        )