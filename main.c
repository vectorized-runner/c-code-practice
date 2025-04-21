#include <stdint.h>
#include <stdio.h>

uint8_t mySmallInteger;

struct MyFloat {
    int a;
    int b;
    int c;
};

void is_this_allowed() {
    return;
}

int main(void) {
    // This comment is allowed! Lol.
    struct MyFloat my_float;
    my_float.a = 1;


    // Let's do for loop
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    printf("%d\n", my_float.a);
    is_this_allowed();

    printf("Hello, World! %d\n", mySmallInteger);
    return 0;
}