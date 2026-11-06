#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child PID: %d, PPID: %d\n", getpid(), getppid());
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    printf("Parent PID: %d, PPID: %d\n", getpid(), getppid());

    return 0;
}
