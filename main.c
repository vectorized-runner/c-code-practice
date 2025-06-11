#include <stdint.h>
#include <stdio.h>
#include <tgmath.h>

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

// #5 auto
void auto_example() {
    auto myf = 123.0f;
    auto myx = cos(myf);
}
int main(void) {
    printf("aaa");
    return 0;
}
