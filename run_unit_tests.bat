@echo off

set EXE_PATH=projects\vs2017\bin\x64\DebugScalar\vectormath_unit_tests.exe

if exist %EXE_PATH% (
    %EXE_PATH%
) else (
    echo You need to generate projects with premake5 and build DebugScalar first.
)