#include <stdint.h>
#include <stdio.h>

uint8_t mySmallInteger;

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

bool vec_equal(vec2 a, vec2 b) {
    return a.x == b.x && a.y == b.y;
}

void func(MyFloat f) {
    f.a = 5;
    printf("%d %d", f.a, f.b);
}

void my_init(vec2* v) {
    v->x = 1;
    v->y = 2;
}

int main(void) {
    // This comment is allowed! Lol.
    MyFloat my_float;
    my_float.a = 1;

    vec2 vec;
    // Alright, this is working w/ pointers
    my_init(&vec);

    printf("%f %f\n", vec.x, vec.y);

    vec2 myVec = { .x = 1.0f, .y = 2.0f };

    printf("%f\n", myVec.x);

    printf("Hello, World! %d\n", mySmallInteger);
    return 0;
}