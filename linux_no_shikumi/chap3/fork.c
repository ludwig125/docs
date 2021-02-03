#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
    printf("I'm child my pid is %d.\n", getpid());
    exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
    printf("I'm parent my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret;
    ret = fork();
    printf("main pid is %d.\n", getpid());
    if (ret == -1)
        err(EXIT_FAILURE, "fork() faild");
    if (ret == 0) {
        // child process came here because fork() returns 0 for child process
        child();
    } else {
        // parent proces came here because fork() returns the pid of newly created child process (> 1)
        printf("ret %d,\n", ret);
        parent(ret);
    }
    // shouldn't reach here

    err(EXIT_FAILURE, "shouldn't reach here");
}
