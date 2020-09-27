#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        char *myargs[3];
        // program: "wc" (word count):
        myargs[0] = strdup("wc");
        // argument: file to count:
        myargs[1] = strdup("p3.c");
        // marks end of array:
        myargs[2] = NULL;

        // run the word count using execvp. It works by taking the name of an
        // executable (eg: wc), and some arguments (eg: p3.c), it loads code
        // (and static data) from that executable and overwirtes its current
        // code segment (and current static data) with it. The heap and stack
        // and other parts of memory space are re-initialized. Then the OS runs
        // the program, passing in any args. It does not create a new process;
        // rather it transforms the currently running program (formerly p3) into
        // a different running program (wc). After the exec in the child, it's
        // almost as if p3.c never ran; a successful call to exec() never
        // returns.

        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (main)

        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}
