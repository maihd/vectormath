#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../VectorMath.h"

// ------------------------------------------------------------------------------------------
// Unit tests API
// ------------------------------------------------------------------------------------------

struct UnitTest;
typedef void UnitTestFunc(UnitTest* __unitTest);

struct UnitTest
{
    const char*     const   name;
    UnitTestFunc*   const   func;
    const char*     const   file;
    int             const   line;

    UnitTest*       const   next;
	UnitTest*				failedNext;

                            UnitTest(const char* name, UnitTestFunc* func, const char* file, const int line);
    void                    TestFailed(const char* func, const int line);
	void					HandleExitAfterFailed();
};

#ifndef CONCAT
#define CONCAT(A, B)        CONCAT_IMPL(A, B)
#define CONCAT_IMPL(A, B)   A ## B
#endif

#ifndef SYMBOL
#define SYMBOL(PREFIX)      CONCAT(PREFIX, __LINE__)
#endif

#define DEFINE_UNIT_TEST(name)                                                          \
    static void SYMBOL(UnitTestFunc)(UnitTest* __unitTest);                             \
    static UnitTest SYMBOL(UNIT_TEST)(name, SYMBOL(UnitTestFunc), __FILE__, __LINE__);  \
    static void SYMBOL(UnitTestFunc)(UnitTest* __unitTest)

#if defined(_MSC_VER) && !defined(NDEBUG)
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent(void);
#define TEST_FAILED()															\
    do {                                                                        \
		__unitTest->TestFailed(__FILE__, __LINE__);								\
        if (IsDebuggerPresent()) __debugbreak();								\
		__unitTest->HandleExitAfterFailed();									\
    } while (false)
#else
#define TEST_FAILED()															\
    do {                                                                        \
		__unitTest->TestFailed(__FILE__, __LINE__);								\
		__unitTest->HandleExitAfterFailed();									\
    } while (false)
#endif

#define TEST(condition)                                                         \
    do {                                                                        \
        if (!(condition))                                                       \
        {                                                                       \
            TEST_FAILED();                                                      \
        }                                                                       \
    } while (false)

#define TEST_EQUAL(actual, expected)                                            \
    do {                                                                        \
        if ((actual) != (expected))                                             \
        {                                                                       \
            TEST_FAILED();                                                      \
        }                                                                       \
    } while (false)

#define TEST_NOT_EQUAL(actual, expected)                                        \
    do {                                                                        \
        if ((actual) == (expected))                                             \
        {                                                                       \
            TEST_FAILED();                                                      \
        }                                                                       \
    } while (false)

// ------------------------------------------------------------------------------------------
// Define test runner
// ------------------------------------------------------------------------------------------

#ifdef RUN_UNIT_TESTS
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32)
#include <Windows.h>
#pragma comment(lib, "User32.lib")
#endif

static UnitTest*    gUnitTests          = nullptr;
static UnitTest*    gFailedUnitTests    = nullptr;

static int          gUnitTestsCount     = 0;
static int          gUnitTestsRunCount  = 0;
static int          gUnitTestsExitCode  = 0;
static const char*  gUnitTestsLogHeader = "[vectormath]";

/// `defined` operator on expression
/// @note: The implementation is hard to understand
#define IS_DEFINED(macro)               IS_DEFINED_1(#macro, macro)
#define IS_DEFINED_1(name, value)       IS_DEFINED_2(name, sizeof(name), #value, sizeof(#value))
constexpr bool IS_DEFINED_2(const char* name, const int nameLength, const char* value, const int valueLength)
{
    if (nameLength != valueLength)
    {
        return true;
    }

    for (int i = 0; i < nameLength; i++)
    {
        if (name[i] != value[i])
        {
            return true;
        }
    }

    return false;
}

#define __EMPTY_MACRO

// Test IS_DEFINED
static_assert(IS_DEFINED(__cplusplus), "IS_DEFINED is wrong!");
static_assert(IS_DEFINED(__EMPTY_MACRO), "IS_DEFINED is wrong!");
static_assert(!IS_DEFINED(__UNDEFINED_MACRO), "IS_DEFINED is wrong!");

#ifndef UNIT_TEST_GOTO_FILE_COMMAND
#define UNIT_TEST_GOTO_FILE_COMMAND     "code --goto %s:%d"
#endif

#define PRINTF_COLOR_RED		"\033[0;31m"
#define PRINTF_COLOR_BLUE		"\033[0;34m"
#define PRINTF_COLOR_BLACK		"\033[0m"
#define PRINTF_COLOR_GREEN		"\033[0;32m"
#define PRINTF_COLOR_YELLOW		"\033[0;33m"

#define PRINTF_STRING_RED(string) PRINTF_COLOR_RED string PRINTF_COLOR_BLACK
#define PRINTF_STRING_BLUE(string) PRINTF_COLOR_BLUE string PRINTF_COLOR_BLACK
#define PRINTF_STRING_GREEN(string) PRINTF_COLOR_GREEN string PRINTF_COLOR_BLACK
#define PRINTF_STRING_YELLOW(string) PRINTF_COLOR_YELLOW string PRINTF_COLOR_BLACK

static void NotifyProgammer(const char* title, const char* message);

UnitTest::UnitTest(const char* name, UnitTestFunc* func, const char* file, int line)
    : name(name)
    , func(func)
    , file(file)
    , line(line)
    , next(gUnitTests)
{
    gUnitTests = this;
    gUnitTestsCount++;
}

void UnitTest::TestFailed(const char* file, const int line)
{
    char message[4096];
    printf(
		PRINTF_STRING_BLUE("%s")
		" "
        PRINTF_STRING_RED("Failed")
		"unit test %s:%d:%s\nAt %s:%d\n", 
        gUnitTestsLogHeader,
        this->file, this->line, this->name,
        file, line
    );
    
    if (!IS_DEFINED(CONTINUE_UNIT_TEST_ON_FAIL))
    {
        char notifyMessage[4096];
        snprintf(notifyMessage, sizeof(notifyMessage), "%s\nPress OK to exit!!!", (const char*)message);

        bool gotoSource = false;
        #if defined(_MSC_VER) && !defined(NDEBUG)
        if (IsDebuggerPresent())
        {
            gotoSource = false;
            snprintf(notifyMessage, sizeof(notifyMessage), "%s\nPress OK to start debug!!!", (const char*)message);
        }
        else
        {
            gotoSource = true;
            snprintf(notifyMessage, sizeof(notifyMessage), "%s\nPress OK to open source file!!!", (const char*)message);
        }
        #endif

        gUnitTestsExitCode = -1;
        NotifyProgammer("vectormath's UnitTests", notifyMessage);
        
        if (gotoSource)
        {
            char command[1024];
            snprintf(command, sizeof(command), UNIT_TEST_GOTO_FILE_COMMAND, file, line);

            system(command);
        }
    }
}

void UnitTest::HandleExitAfterFailed()
{
	if (!IS_DEFINED(CONTINUE_UNIT_TEST_ON_FAIL))
	{
		exit(gUnitTestsExitCode);
	}
	else
	{
		this->failedNext = gFailedUnitTests;
		gFailedUnitTests = this;
	}
}

#if defined(UNIT_TESTS_MAIN)
int UNIT_TESTS_MAIN(const int argc, const char* argv[])
#else
int main(const int argc, const char* argv[])
#endif
{
    if (argc > 1)
    {
        gUnitTestsLogHeader = argv[1];
    }

	printf(
		PRINTF_STRING_BLUE("%s") " Start running " PRINTF_STRING_GREEN("%d") " unit tests...\n\n",
		gUnitTestsLogHeader, gUnitTestsCount
	);

    gUnitTestsRunCount = 0;
    for (UnitTest* unitTest = gUnitTests; unitTest != nullptr; unitTest = unitTest->next)
    {
		printf(
			PRINTF_STRING_BLUE("%s") " Running new unit test\n" 
			"  Name: " PRINTF_STRING_YELLOW("\"%s\"") "\n"
			"  Defined at " PRINTF_STRING_YELLOW("%s:%d") "\n\n",
			gUnitTestsLogHeader, unitTest->name, unitTest->file, unitTest->line
		);

        unitTest->func(unitTest);
        gUnitTestsRunCount++;
    }

    if (gUnitTestsRunCount != gUnitTestsCount)
    {
        printf(
			PRINTF_STRING_BLUE("%s")
			" "
            PRINTF_STRING_RED("FAILURE")
            ": Run " PRINTF_STRING_GREEN("%d") " out of " PRINTF_STRING_GREEN("%d") " unit tests!!!\n",
            gUnitTestsLogHeader, gUnitTestsRunCount, gUnitTestsCount
        );
    }
    else
    {
        printf(
			PRINTF_STRING_BLUE("%s")
			" "
            PRINTF_STRING_GREEN("SUCCESS")
            ": Run all " PRINTF_STRING_GREEN("%d") " unit tests successfully!!!\n",
            gUnitTestsLogHeader, gUnitTestsRunCount
        );
    }
    
    return gUnitTestsExitCode;
}

void NotifyProgammer(const char* title, const char* message)
{
    #if defined(_WIN32)
    MessageBeep(MIM_ERROR);
    MessageBoxA(NULL, message, title, MB_OK);
    #else
    printf("%s", message);
    fgetc(stdin);
    #endif
}
#endif

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
