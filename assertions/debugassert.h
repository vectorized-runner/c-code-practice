#ifndef DEBUGASSERT_H
#define DEBUGASSERT_H
#include <stdio.h>
#include <stdlib.h>

const int assertion_exit = 10;

void debug_assert(bool condition, const char* message) {
    if (!condition) {
        printf("Assertion Failed '%s'\n", message);
        exit(assertion_exit);
    }
}

#endif //DEBUGASSERT_H
