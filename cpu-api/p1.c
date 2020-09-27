#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    // `fork` creates a process that is an (almost) _exact copy of the calling
    // process_. To the OS, there are 2 processes - one being a parent and the
    // other a child.

    // It's not an _exact_ copy, however. Although it has its own copy of the
    // address space, its own registers, PC, etc, the returned value from fork()
    // is different. The child receives a return code of `0`, which we can use
    // to handle the two different cases.

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    }
    return 0;
}
