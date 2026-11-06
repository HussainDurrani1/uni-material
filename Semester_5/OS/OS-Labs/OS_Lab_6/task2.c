#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char c;

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid == 0) {
        close(fd[0]);

        write(fd[1], "hi", 2);

        close(fd[1]);
        return 0;
    }

    close(fd[1]);  // IMP correction

    while (read(fd[0], &c, 1) > 0) {
        printf("%c", c);
    }

    close(fd[0]);
    wait(NULL);

    printf("\n");

    return 0;
}
