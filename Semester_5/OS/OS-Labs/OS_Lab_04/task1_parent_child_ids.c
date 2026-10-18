#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
    } else if (pid > 0) {
        wait(NULL);
        printf("Parent: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}