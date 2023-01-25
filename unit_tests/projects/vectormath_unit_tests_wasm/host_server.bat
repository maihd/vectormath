@echo off

if not exist dist goto DIST_NOT_FOUND

pushd dist

start lite-server .

popd

goto END

:DIST_NOT_FOUND
echo No "dist" folder, please run "build.bat" first.
echo:

:END