#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t p1 = fork();

    if (p1 == 0) {
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        perror("execvp");
        exit(1);
    }

    if (p1 < 0) {
        perror("fork");
        return 1;
    }

    pid_t p2 = fork();

    if (p2 == 0) {
        execlp("date", "date", NULL);
        perror("execlp");
        exit(1);
    }

    if (p2 < 0) {
        perror("fork");
        waitpid(p1, NULL, 0);
        return 1;
    }

    int status;

    waitpid(p1, &status, 0);
    printf("Child 1 exit status: %d\n",
           WIFEXITED(status) ? WEXITSTATUS(status) : -1);

    waitpid(p2, &status, 0);
    printf("Child 2 exit status: %d\n",
           WIFEXITED(status) ? WEXITSTATUS(status) : -1);

    return 0;
}