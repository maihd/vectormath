#include <jni.h>
#include <string>
#include <pthread.h>

#define UNIT_TEST_EXIT(exit_code) end_unit_test(exit_code)

static void end_unit_test(int exit_code);

#define RUN_UNIT_TESTS
#define UNIT_TESTS_MAIN runAllTestCases
#include "test_framework.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_io_github_maihd_vectormath_1unit_1tests_1android_MainActivity_runAllTestCases(
        JNIEnv* env,
        jobject /* this */) {
    JavaVM* vm;
    env->GetJavaVM(&vm);
    vm->AttachCurrentThread(&env, 0);

    const char* argv[] = {};
    const int   argc   = 0;
    return runAllTestCases(argc, argv) == 0;
}

static void end_unit_test(int exit_code)
{
    pthread_exit(nullptr);
    exit(exit_code);
}

//! EOF
