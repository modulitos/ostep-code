#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0;
int loops;

// This is a function returning a pointer to void (aka "void pointer"). Can also be written as: `void* worker(void
// *arg)`

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {

        // Unfortunately, when this shared counter is incremented, it takes 3 instructions: one to load the value of the
        // counter from memory into a register, one to increment it, and one to store it back into memory.

        counter++;
    }
    return NULL;
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: threads <value>\n");
        exit(1);
    }
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);

    // why can't we do this?
//    void (*fun_ptr)(void *arg) = &worker;
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value : %d\n", counter);
    return 0;
}
