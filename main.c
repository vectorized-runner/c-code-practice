#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>
#include <_static_assert.h>

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

void example_init() {
    struct { int a[3], b; } w[] = { [0].a = {1}, [1].a[0] = 2 };
}

/*
// #6 constexpr
int calculate_t() {
    int m = 0;

    for (int i = 0; i < 10; i++) {
        m += i;
    }

    return m;
}

constexpr int t = calculate_t();
*/

// #5 static assert
void static_assert_example() {
    // static_assert(2 + 2 == 3, "you done fucked up");
}


// Stuff I couldn't make work
// auto
void auto_example() {
    //auto myf = 123.0f;
    //auto myx = cos(myf);
}

int main(void) {
    // printf("%d\n", t);
    auto m = 1;

    printf("aaa");
    return 0;
}
