@echo off

set EXE_FOLDER=%~dp0
set ROOT_FOLDER=%EXE_FOLDER%\..\..
set DIST_FOLDER=%EXE_FOLDER%\dist

if not exist %DIST_FOLDER% goto DIST_NOT_FOUND

pushd %DIST_FOLDER%

start lite-server .

popd

goto END

:DIST_NOT_FOUND
echo No "dist" folder found, please make run "build.bat" first.
echo:

:END