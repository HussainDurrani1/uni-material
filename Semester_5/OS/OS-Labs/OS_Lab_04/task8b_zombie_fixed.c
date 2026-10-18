#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
    }

    /* FIX: reap every child so none is left as a zombie */
    for (int i = 0; i < 3; i++)
        wait(NULL);

    printf("Parent: all 3 children reaped, no zombies remain.\n");
    printf("Run 'ps -l' now: no Z-state / <defunct> entries.\n");
    sleep(20);   /* ps during this sleep confirms: no zombies */
    printf("Parent exiting.\n");
    return 0;
}
