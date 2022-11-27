#include <jni.h>
#include <string>

#define RUN_UNIT_TESTS
#define UNIT_TESTS_MAIN runAllTestCases
#include "test_framework.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_io_github_maihd_vectormath_1unit_1tests_1android_MainActivity_runAllTestCases(
        JNIEnv* env,
        jobject /* this */) {
    (void)env;

    const char* argv[] = {};
    const int   argc   = 0;
    return runAllTestCases(argc, argv) == 0;
}