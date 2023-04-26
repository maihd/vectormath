@echo off

:: Variables
set EXE_FOLDER=%~dp0
set ROOT_FOLDER=%EXE_FOLDER%\..\..
set DIST_FOLDER=%EXE_FOLDER%\dist

set THIRD_PARTY_DIR=%ROOT_FOLDER%\examples\3rd_party
set THIRD_PARTY_SRC=%THIRD_PARTY_DIR%\flecs\flecs.c

set BUNNYMARK_DIR=%ROOT_FOLDER%\examples\bunnymark_flecs
set BUNNYMARK_SRC=%BUNNYMARK_DIR%\Game\Game.cpp %BUNNYMARK_DIR%\Game\Components.cpp

set SRCDIR=%ROOT_FOLDER%\examples\wasm\Renderer
set SRC=%THIRD_PARTY_SRC% %BUNNYMARK_SRC% %SRCDIR%\Renderer.cpp

:: Build flags
set OUTPUT=%DIST_FOLDER%\index.html
set INCDIR=-I%ROOT_FOLDER%\include -I%EXE_FOLDER% -I%THIRD_PARTY_DIR% -I%BUNNYMARK_DIR% -I%SRCDIR%
set CFLAGS=-O3 -s ASYNCIFY -Wno-enum-constexpr-conversion 
set LFLAGS=-lGL -sUSE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="[""png""]" -sWASM=1 -sFULL_ES3=1 -sALLOW_MEMORY_GROWTH=1 --preload-file ../assets/sprites.png@sprites.png

:: Setup environment
@REM set EMSDK_QUIET=1
@REM call emsdk_env.bat

:: Start build
if not exist %DIST_FOLDER% (
    mkdir %DIST_FOLDER%
)

call emcc %EXE_FOLDER%\main.cpp %SRC% %INCDIR% -o %OUTPUT% %CFLAGS% %LFLAGS%