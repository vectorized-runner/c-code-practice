#include <stdint.h>
#include <stdio.h>

uint8_t mySmallInteger;
const int myVariable = 3;

typedef struct {
    int a;
    int b;
    int c;
} MyFloat;

typedef struct {
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

[[nodiscard("this value is fucking important")]]
int my_func() {
    return 10;
}


int main(void) {
    //_BitInt(4) sbi;

    printf("fml: %d\n", sizeof(int));
    printf("union size: %ld\n", sizeof(union my_union));

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