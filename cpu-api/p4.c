#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file:
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        // This leverages an assumption about how the OS manages file
        // descriptors. Unix systems start looking for free fd's at zero, so
        // STDOUT_FILENO will be first available and get assigned when open(..)
        // is called. Subsequent wrtites, like printf, will then be routed
        // transparently to the newly-opened file instead of the screen.

        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        char *myargs[3];
        // program: "wc" (word count):
        myargs[0] = strdup("wc");
        // argument: file to count:
        myargs[1] = strdup("p3.c");
        // marks end of array:
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (main)

        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}
