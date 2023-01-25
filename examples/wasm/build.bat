@echo off

:: Variables
set EXE_FOLDER=%~dp0
set ROOT_FOLDER=%EXE_FOLDER%\..\..
set DIST_FOLDER=%EXE_FOLDER%\dist

:: Build flags
set OUTPUT=%DIST_FOLDER%\index.html
set INCDIR=-I%ROOT_FOLDER%\include
set CFLAGS=-O3
set LFLAGS=-lGL -sUSE_SDL=2 -sWASM=1

:: Setup environment
set EMSDK_QUIET=1
call emsdk_env.bat

:: Start build
if not exist %DIST_FOLDER% (
    mkdir %DIST_FOLDER%
)

call emcc %EXE_FOLDER%\main.cpp %INCDIR% -o %OUTPUT% %CFLAGS% %LFLAGS%