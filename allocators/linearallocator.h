#ifndef LINEARALLOCATOR_H
#define LINEARALLOCATOR_H
#include <stdlib.h>
#include <string.h>

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

bool is_power_of_two(uintptr_t x) {
    return (x & x - 1) == 0;
}

int align_forward_bytes(void* ptr, size_t align) {
    debug_assert(is_power_of_two(align), "alignment must be a power of two.");
    // Same as (p % a) but faster as 'a' is a power of two
    uintptr_t modulo = (uintptr_t)ptr & (align - 1);
    // printf("ptr is %ld, align is %d, modulo is %ld\n", (uintptr_t)ptr, (int)align, modulo);

    if (modulo != 0) {
        // push address forward where it is aligned
        return align - modulo;
    }

    return 0;
}

void *linear_allocator_alloc(linear_allocator* alloc, int size, int align, bool clearMemory) {
    int prevOffset = alloc->offset;
    void* prevBuffer = alloc->buffer + prevOffset;
    int align_bytes = align_forward_bytes(prevBuffer, align);
    int align_size = align_bytes + size;
    int newOffset = prevOffset + align_size;
    // printf("align size is %d align bytes is %d\n", align_size, align_bytes);
    debug_assert(newOffset <= alloc->size, "linear allocator: alloc out of bounds");

    void* ptr = &alloc->buffer[prevOffset];
    void* start = ptr + align_bytes;

    if (clearMemory) {
        memset(start, 0, size);
    }

    alloc->offset = newOffset;
    return start;
}

void linear_allocator_clear(linear_allocator* alloc) {
    alloc->offset = 0;
}

#endif //LINEARALLOCATOR_H
