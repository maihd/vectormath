@echo off

:: Variables
set EXE_FOLDER=%~dp0
set ROOT_FOLDER=%EXE_FOLDER%\..\..
set DIST_FOLDER=%EXE_FOLDER%\dist

set THIRD_PARTY_DIR=%ROOT_FOLDER%\examples\3rd_party
set THIRD_PARTY_SRC=%THIRD_PARTY_DIR%\flecs\flecs.c

set BUNNYMARK_DIR=%ROOT_FOLDER%\examples\wasm_raylib
set BUNNYMARK_SRC=%BUNNYMARK_DIR%\Game\Game.cpp %BUNNYMARK_DIR%\Game\Components.cpp

set SRCDIR=%ROOT_FOLDER%\examples\wasm_raylib\Renderer
set SRC=%THIRD_PARTY_SRC% %BUNNYMARK_SRC% %SRCDIR%\Renderer.cpp

:: Build flags
set OUTPUT=%DIST_FOLDER%\index.html
set INCDIR=-I%ROOT_FOLDER%\include -I%EXE_FOLDER% -I%THIRD_PARTY_DIR% -I%THIRD_PARTY_DIR%\raylib_4.5.0\include -I%BUNNYMARK_DIR% -I%SRCDIR%
set CFLAGS=-O3 -Wno-enum-constexpr-conversion 
set LFLAGS=-sUSE_GLFW=3 -sWASM=1 -sALLOW_MEMORY_GROWTH=1 -sTOTAL_MEMORY=16777216 -sFORCE_FILESYSTEM=1 %THIRD_PARTY_DIR%\raylib_4.5.0\lib\wasm32\libraylib.a
set ASSETS=--preload-file ../assets/sprites_lite.png@assets/sprites.png

:: Setup environment
set EMSDK_QUIET=1
call emsdk_env.bat

:: Start build
if not exist %DIST_FOLDER% (
    mkdir %DIST_FOLDER%
)

call emcc %EXE_FOLDER%\main.cpp %SRC% %INCDIR% -o %OUTPUT% %CFLAGS% %LFLAGS% %ASSETS%