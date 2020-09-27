#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // open file and create it:
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);
    // write some data to the file:
    int rc = write(fd, "hello world\n", 13);
    assert(rc == 13);
    // close the file, thus indicating the program won't be writing anymore data to it:
    close(fd);
    return 0;
}
