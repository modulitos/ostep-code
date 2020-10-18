#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("location of NULL: %p\n", (void *) NULL);
    printf("location of code: %p\n", (void *) main);
    int* i = malloc(sizeof(int) * 100);
    *i = 42;
    printf("i as int: %d\n", *i);
    printf("location of heap: %p\n", i);

    // printf("location of heap: %p\n", malloc(sizeof(int) * 100));
    // printf("location of heap: %p\n", malloc(100e6));

    int x = 71;
    // printf("start of stack: %p\n", (void*) &x);
    printf("start of stack: %p\n", &x);
    return 0;
}