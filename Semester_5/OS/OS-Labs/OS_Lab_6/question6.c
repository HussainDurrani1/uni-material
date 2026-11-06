#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int p1[2], p2[2], p3[2];

    if (pipe(p1) == -1) {
        perror("Pipe 1 failed");
        return 1;
    }

    if (pipe(p2) == -1) {
        perror("Pipe 2 failed");
        return 1;
    }

    if (pipe(p3) == -1) {
        perror("Pipe 3 failed");
        return 1;
    }

    // Child 1: ls / -lR
    // Child 1 (updated): ls . -lR
    pid_t c1 = fork();

    if (c1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c1 == 0) {
        int error = open("error.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

        if (error < 0) {
            perror("File failed");
            return 1;
        }

        // stderr -> error.txt
        if (dup2(error, 2) == -1) {
            perror("dup2 failed");
            return 1;
        }
        close(error);

        // stdout -> pipe 1
        if (dup2(p1[1], 1) == -1) {
            perror("dup2 failed");
            return 1;
        }
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("ls", "ls", ".", "-lR", (char *)NULL);

        perror("Exec ls failed");
        return 1;
    }

    // Child 2: grep Nov

    pid_t c2 = fork();

    if (c2 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c2 == 0) {
        // stdin <- pipe 1
        if (dup2(p1[0], 0) == -1) {
            perror("dup2 failed");
            return 1;
        }

        // stdout -> pipe 2
        if (dup2(p2[1], 1) == -1) {
            perror("dup2 failed");
            return 1;
        }

        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("grep", "grep", "Nov", (char *)NULL);

        perror("Exec grep failed");
        return 1;
    }

    // Child 3: sort
    pid_t c3 = fork();

    if (c3 < 0) {
        perror("Fork failed");
        return 1;
    }
    if (c3 == 0) {
        // stdin <- pipe 2
        if (dup2(p2[0], 0) == -1) {
            perror("dup2 failed");
            return 1;
        }

        // stdout -> pipe 3
        if (dup2(p3[1], 1) == -1) {
            perror("dup2 failed");
            return 1;
        }
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("sort", "sort", (char *)NULL);

        perror("Exec sort failed");
        return 1;
    }

    // Child 4: less
    pid_t c4 = fork();

    if (c4 < 0) {
        perror("Fork failed");
        return 1;
    }
    if (c4 == 0) {
        // stdin <- pipe 3
        if (dup2(p3[0], 0) == -1) {
            perror("dup2 failed");
            return 1;
        }
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        close(p3[0]);
        close(p3[1]);

        execlp("less", "less", (char *)NULL);

        perror("Exec less failed");
        return 1;
    }

    // Parent closes all pipes
    close(p1[0]);
    close(p1[1]);
    close(p2[0]);
    close(p2[1]);
    close(p3[0]);
    close(p3[1]);

    // Wait for all four children

    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}
