// Task 7: Write a program that takes a text file name as a command line argument.
// Each line of the file holds one command with its arguments (for example, ls -l /tmp).
// The program reads the file line by line and runs every command in its own child process,
// one after the other, using one of the exec functions. After each command finishes,
// the parent prints the command, its exit status, and a message “FAILED” if the status is not zero.
// A command that

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char line[256], *args[32];
    FILE *file;
    int status, i;
    pid_t pid;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("File error");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("Command: %s", line);

        i = 0;
        args[i] = line;

        for (char *p = line; *p; p++) {
            if (*p == ' ' || *p == '\n' || *p == '\t') {
                *p = '\0';

                if (p[1] != '\0' && p[1] != ' ' &&
                    p[1] != '\n' && p[1] != '\t')
                    args[++i] = p + 1;
            }
        }

        args[++i] = NULL;

        if (!args[0][0])
            continue;

        pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("Command failed");
            exit(127);
        } else if (pid > 0) {
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                int result = WEXITSTATUS(status);
                printf("Exit status: %d", result);
                if (result != 0)
                    printf(" FAILED");
                printf("\n");
            } else {
                printf("Terminated abnormally FAILED\n");
            }
        } else {
            perror("fork failed");
        }
    }

    fclose(file);
    return 0;
}
