#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            printf("Child %d (PID %d) exiting immediately\n",
                   i + 1, getpid());
            exit(0);
        }
        /* parent does NOT wait -> each child becomes a zombie */
    }

    printf("Parent (PID %d): sleeping 20 seconds.\n", getpid());
    printf("The 3 children are zombies right now.\n");
    printf("In another terminal run:  ps -l\n");
    printf("Look for state 'Z' and '<defunct>' next to the child PIDs.\n");
    sleep(20);

    printf("Parent exiting now (zombies get reaped by init).\n");
    return 0;
}
