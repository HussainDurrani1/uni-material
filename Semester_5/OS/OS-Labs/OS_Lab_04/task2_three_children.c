#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Child %d: PID = %d\n", i, getpid());
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    printf("All children finished\n");
    return 0;
}