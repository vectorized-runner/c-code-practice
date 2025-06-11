#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <_assert.h>
#include "stdalign.h"
#include <_static_assert.h>
#include <stdnoreturn.h>

// todo: data structure
// todo: bit hacking
// todo: memcpy, memcmp
// todo: ecs
// todo: assertions
// todo: compiler flags (-o3 or something)
// todo: allocators
// todo: unit testing
// todo: which compiler am I compiling with?

// Flags:
// -Wall and -Wextra on GCC
// -Weverything on Clang
// /W4 or /Wall on MSVC

uint8_t mySmallInteger;
const int myVariable = 3;

struct v {
    // anonymous union
    union {
        int a;
        long b;
    };

    int c;
} v;


typedef struct {
    int a;
    int b;
    int c;
} MyFloat;

// This is the correct way to create types in modern C. Solves all the problems
typedef struct vec2 {
    float x;
    float y;
} vec2;

typedef struct {
    int a;
    int b;
    int c;
} args_t;

union my_union {
    int x;
    int y;
    int z;
};

bool vec_equal(vec2 a, vec2 b) {
    return a.x == b.x && a.y == b.y;
}

void func(MyFloat f) {
    f.a = 5;
    printf("%d %d", f.a, f.b);
}

[[deprecated("please don't use this")]]
int test_func(int x) {
    switch (x) {
        case 1:
            x = x + 10;
        [[fallthrough]];
        case 2:
            x = x + 20;
        default:
            return x;
    }

    return x;
}

// todo
// enum my_enum : unsigned int {
// };


// these attributes aren't acknowledged for some reason
/*
[[unsequenced]]
void what_is_this() {
    // todo: implement
}
*/

int r = 0;

// these attributes aren't acknowledged for some reason
/*
// Exists for compiler optimization, multiple calls = single call
[[reproducible]]
int repro_func() {
    if (r == 0) {
        r++;
        return 3;
    }

    return 5;
}
*/

// nice. this makes the rest of the code blacked out
[[noreturn]]
void kill_me() {
    exit(0);
}

[[nodiscard("this value is fucking important")]]
int my_func() {
    return 10;
}

struct sse_t {
    // this can be used. clion doesn't recognize it
    alignas(16) float sse_data[4];
};

// This embed thing didn't work
/*
const char message_text[] = {
#embed "message.txt" if_empty('M', 'i', 's', 's', 'i', 'n', 'g', '\n')
    ,'\0'
    };
*/

// Interesting
noreturn void my_noreturn() {
    exit(0);
}

int main2(void) {
    printf("%d\n", __alignof(char));
    printf("%d\n", __alignof(int));
    printf("%d\n", __alignof(int*));

    struct v myv;
    myv.a = 1;
    myv.b = 2;


    my_noreturn();

    // let's try dynamic memory allocation
    // ok. nice.
    char str[] = "almost every programmer should know memset!";
    memset (str,'-',6);
    puts (str);

    // interesting
    int a;
    typeof(a) c;
    c = 5;

    // int a  = repro_func();
    // this should be optimized away (let's see if it'll be)
    // a = repro_func();
    // printf("value of repro is %d\n", a);

    // this is crazy
    struct { int a[3], b; } w[] = { [0].a = {1}, [1].a[0] = 2 };

    //_BitInt(4) sbi;
    // kill_me();
    // bool a = true;
    // printf("fml: %d\n", a);

    printf("fml: %ld\n", sizeof(int));
    printf("union size: %ld\n", sizeof(union my_union));

    int i = 0;

    // static_assert(2 + 2 == 3, "you done fucked up");
    assert(i == 1);

    test_func(10);

    float f = {};
    vec2 v = {};
    v = (vec2){.x = 1, .y = 2, };

    my_func();

    int x;
    x = 0b111;
    x = 0b1111'1111;
    printf("%d\n", x);

    // This comment is allowed! Lol.
    MyFloat my_float;
    my_float.a = 1;

    vec2 vec;
    vec.x = 3;
    vec.x = vec.x * myVariable;

    printf("%f %f\n", vec.x, vec.y);

    vec2 myVec = { .x = 1.0f, .y = 2.0f };

    printf("%f\n", myVec.x);

    printf("Hello, World! %d\n", mySmallInteger);
    return 0;
}