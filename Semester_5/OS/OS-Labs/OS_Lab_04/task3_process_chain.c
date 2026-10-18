#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0) {
        pid_t gpid = fork();

        if (gpid == 0) {
            printf("Grandchild: PID = %d, PPID = %d\n",
                   getpid(), getppid());
        } else if (gpid > 0) {
            wait(NULL);
            printf("Child: PID = %d, PPID = %d\n",
                   getpid(), getppid());
        }
    } else if (pid > 0) {
        wait(NULL);
        printf("Parent: PID = %d, PPID = %d\n",
               getpid(), getppid());
    }

    return 0;
}