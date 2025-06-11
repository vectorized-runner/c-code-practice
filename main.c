#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <_static_assert.h>
#include <__stddef_unreachable.h>

// C23 - Oct 2024

// #1: Integer names
uint8_t a;
uint16_t b;
uint32_t c;

// #2 bool
bool x = true;

// #3 typedef hack
struct my_data {
    int x;
};

typedef struct my_data_typedef {
    int x;
} my_data_typedef;

void example_typedef() {
    struct my_data instance;
    my_data_typedef instance2;
}

// #4 value initialization - simple
typedef struct my_point {
    int x;
    int y;
    int z;
} my_point;

my_point example_init_1() {
    my_point p = {.x = 1, .y = 2, .z = 3 };
    return p;
}

// #5 value initialization - advanced
void example_init_advanced() {
    struct { int a[3], b; } w[] = { [0].a = {1}, [1].a[0] = 2 };
    struct { int x[100]; } m = { .x[99] = 0 };
}

// #6 static assert
void static_assert_example() {
    // static_assert(2 + 2 == 3, "you done fucked up");
}

// #7 noreturn
[[noreturn]]
void kill_program() {
    exit(0);
}

// #8 nodiscard
[[nodiscard("return value is fucking important")]]
int nodiscard_example() {
    return 10;
}

// #9 Bit assignment
void bit_assign() {
    int x = 0b111; // x = 7
}

// #10 Empty Initializer
void empty_init_example() {
    my_point p = { }; // p.x = 0, p.y = 0, p.z = 0
    int ia[5] = {}; // == [0, 0, 0, 0, 0]
}

// #11 Deprecated
[[deprecated("old function")]]
void deprecated_example() {
}

// #12 Typeof
void typeof_example() {
    int a = 0;
    typeof(a) b; // b is int
}

// #13 Fallthrough
int fallthrough_example(int x) {
    switch (x) {
        case 1:
            x = x + 10;
            [[fallthrough]];
        case 2:
            x = x + 20;
        default:
            return x;
    }
}

// #14 Unreachable
// Executing unreachable() results in undefined behavior.
// An implementation may use this to optimize impossible code branches away
// (typically, in optimized builds) or to trap them to prevent further execution (typically, in debug builds).
void unreachable_ex(int i) {
    if (i == 1) {
    } else
        unreachable();
}


// Stuff I couldn't make work

// auto
void auto_example() {
    //auto myf = 123.0f;
    //auto myx = cos(myf);
}

// bit fields
void bitfield_example() {

}

int main(void) {
    // kill_program();

    unreachable_ex(2);

    printf("%d\n", fallthrough_example(1));
    nodiscard_example();
    deprecated_example();

    bit_assign();
    // printf("%d\n", t);

    printf("aaa");
    return 0;
}
