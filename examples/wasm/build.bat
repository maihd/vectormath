@echo off

set EMSDK_QUIET=1
call emsdk_env.bat

if not exist dist (
    mkdir dist
)

set UNIT_TEST_FILES=

:: Comment below lines to remove unit tests
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_int32.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_mat4.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_math_ex.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_uint32.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_vec2.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_vec3.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_vec4.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% ../../unit_tests/cases/test_vec4_swizzles.cpp

:: Build flags
set OUTPUT=dist/index.html
set INCDIR=-I../../include
set CFLAGS=-O3
set LFLAGS=-lGL -s USE_SDL=2 -s WASM=1

call emcc main.cpp %UNIT_TEST_FILES% %INCDIR% -o %OUTPUT% %CFLAGS% %LFLAGS%