#include <stdio.h>
#include "unity.h"
#include "allocators/tests/tests_linearallocator.h"

// todo: data structure
// todo: bit hacking
// todo: memcpy, memcmp
// todo: ecs
// todo: assertions
// todo: compiler flags (-o3 or something)
// todo: allocators
// todo: unit testing
// todo: which compiler am I compiling with?

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    printf("running main!   ");

    UNITY_BEGIN();

    tests_linearallocator_run();

    // RUN_TEST(test_Addition);

    printf("tests finished.");

    return UNITY_END();
}