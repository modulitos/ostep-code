#include <stdio.h>
#include "../include/common_threads.h"

void* mythread(void* args) {
    long arg = (long) args;
    printf("%ld\n", arg);
    return (void*) (arg +1);
}

int main(int argc, char* argv[]) {
    pthread_t p;
    int rc, rval;
    Pthread_create(&p, NULL, mythread, (void*) 100);
    Pthread_join(p, (void**) &rval);
    printf("returned: %d\n", rval);
    return 0;
}