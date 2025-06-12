#ifndef LINEARALLOCATOR_H
#define LINEARALLOCATOR_H
#include <stdlib.h>

typedef struct linear_allocator {
    void* buffer;
    int size;
    int current;
} linear_allocator;

linear_allocator linear_allocator_create(int size) {
    linear_allocator alloc;
    alloc.buffer = malloc(size);
    alloc.size = size;
    alloc.current = 0;
    return alloc;
}

// TODO: Clear memory
// TODO: Alignment
void* linear_allocator_alloc(linear_allocator* alloc, int size) {
    int prevCurrent = alloc->current;
    int newCurrent = prevCurrent + size;
    if (newCurrent > alloc->size) {
        return nullptr;
    }

    void* newPtr = alloc->buffer + prevCurrent;
    alloc->current = newCurrent;
    return newPtr;
}

#endif //LINEARALLOCATOR_H
