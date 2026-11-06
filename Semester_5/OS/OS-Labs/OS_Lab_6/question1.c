#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        return 1;
    }
    int fd[2];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid == 0) {
        close(fd[1]);

        char str[100];
        int n = read(fd[0], str, sizeof(str) - 1);

        if (n < 0) {
            perror("Read failed");
            close(fd[0]);
            return 1;
        }
        str[n] = '\0';
        int len = strlen(str);

        printf("Reversed string: ");
        for (int i = len - 1; i >= 0; i--) { printf("%c", str[i]); }
        printf("\n");

        close(fd[0]);
    }
    else {
        close(fd[0]);

        if (strlen(argv[1]) >= 100) {
            printf("String too long\n");
            close(fd[1]);
            wait(NULL);
            return 1;
        }
        write(fd[1], argv[1], strlen(argv[1]) + 1);
        close(fd[1]);

        wait(NULL);
    }

    return 0;
}
