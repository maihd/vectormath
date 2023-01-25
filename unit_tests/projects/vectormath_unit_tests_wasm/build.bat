@echo off

:: Variables
set EXE_FOLDER=%~dp0
set ROOT_FOLDER=%EXE_FOLDER%\..\..\..
set DIST_FOLDER=%EXE_FOLDER%\dist
set CASE_FOLDER=%EXE_FOLDER%\..\..\cases

:: Setup environment
set EMSDK_QUIET=1
call emsdk_env.bat

set UNIT_TEST_FILES=

:: Comment below lines to remove unit tests
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_int32.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_mat4.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_math_ex.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_uint32.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_vec2.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_vec3.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_vec4.cpp
set UNIT_TEST_FILES=%UNIT_TEST_FILES% %CASE_FOLDER%\test_vec4_swizzles.cpp

:: Build flags
set OUTPUT=%DIST_FOLDER%\index.html
set INCDIR=-I%ROOT_FOLDER%\include
set CFLAGS=
set LFLAGS=-lGL -s WASM=1

:: Start build

if not exist %DIST_FOLDER% (
    mkdir %DIST_FOLDER%
)

call emcc %EXE_FOLDER%/../../test_run_all.cpp %UNIT_TEST_FILES% %INCDIR% -o %OUTPUT% %CFLAGS% %LFLAGS%