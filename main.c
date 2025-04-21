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

void func(MyFloat f) {
    f.a = 5;
    printf("%d %d", f.a, f.b);
}

int main(void) {
    // This comment is allowed! Lol.
    MyFloat my_float;
    my_float.a = 1;

    vec2 vec;
    vec.x = 2.0f;
    vec.y = 5.0f;

    vec2 myVec = { .x = 1.0f, .y = 2.0f };

    printf("%f\n", myVec.x);

    printf("Hello, World! %d\n", mySmallInteger);
    return 0;
}