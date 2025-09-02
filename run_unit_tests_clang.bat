@echo off

pushd unit_tests

if "%1" == "clean" (
    make clean
)

make CC=clang

popd