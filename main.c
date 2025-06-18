#include <stdio.h>
#include "allocators/linearallocator.h"

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
    // printf("running main!   ");

    linear_allocator la = linear_allocator_create(100);

    void* mem = linear_allocator_alloc(&la, 100, 128, true);
    printf("mem address is %ld", (uintptr_t)mem);
}