#include <stdio.h>

#define RUN_UNIT_TESTS
#define UNIT_TESTS_MAIN run_all_unit_tests
#include "../../unit_tests/test_framework.h"

int main(int argc, const char* argv[])
{
    printf("Hello world from VectorMath!\n");
    return run_all_unit_tests(argc, argv);
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
