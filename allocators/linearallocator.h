#ifndef LINEARALLOCATOR_H
#define LINEARALLOCATOR_H
#include <stdlib.h>
#include "../assertions/debugassert.h"

typedef struct linear_allocator {
    void* buffer;
    int size;
    int offset;
} linear_allocator;

void linear_allocator_init(linear_allocator* alloc, void* buffer, int size) {
    debug_assert(size > 0, "linear allocator: size must be positive");
    alloc->buffer = buffer;
    alloc->offset = 0;
    alloc->size = size;
}

linear_allocator linear_allocator_create(int size) {
    linear_allocator alloc;
    linear_allocator_init(&alloc, malloc(size), size);
    return alloc;
}

// TODO: Clear memory
// TODO: Alignment
void* linear_allocator_alloc(linear_allocator* alloc, int size) {
    int prevOffset = alloc->offset;
    int newOffset = prevOffset + size;
    debug_assert(newOffset <= alloc->size, "linear allocator: alloc out of bounds");
    void* newPtr = alloc->buffer + prevOffset;
    alloc->offset = newOffset;
    return newPtr;
}

#endif //LINEARALLOCATOR_H
