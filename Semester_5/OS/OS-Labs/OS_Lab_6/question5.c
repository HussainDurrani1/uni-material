#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

    int fd[2];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t c1 = fork();

    if (c1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c1 == 0) {
        // Child 1: grep

        int input = open("input.txt", O_RDONLY);

        if (input < 0) {
            perror("Input file failed");
            return 1;
        }

        // stdin comes from input.txt
        if (dup2(input, 0) == -1) {
            perror("dup2 failed");
            return 1;
        }

        close(input);

        // stdout goes to pipe
        close(fd[0]);

        if (dup2(fd[1], 1) == -1) {
            perror("dup2 failed");
            return 1;
        }

        close(fd[1]);

        execlp("grep", "grep", "m", (char *)NULL);

        perror("Exec grep failed");
        return 1;
    }

    pid_t c2 = fork();

    if (c2 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c2 == 0) {
        // Child 2: sort
        int output = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

        if (output < 0) {
            perror("Output file failed");
            return 1;
        }

        // stdin comes from pipe
        close(fd[1]);

        if (dup2(fd[0], 0) == -1) {
            perror("dup2 failed");
            return 1;
        }

        close(fd[0]);

        // stdout goes to output.txt
        if (dup2(output, 1) == -1) {
            perror("dup2 failed");
            return 1;
        }

        close(output);

        execlp("sort", "sort", (char *)NULL);

        perror("Exec sort failed");
        return 1;
    }

    // Parent closes both pipe ends
    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    printf("Sorted results saved in output.txt\n");

    return 0;
}
