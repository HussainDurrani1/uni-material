#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process

        int fd = open("input.txt",
                      O_CREAT | O_WRONLY | O_TRUNC,
                      0644);

        if (fd < 0) {
            perror("File opening failed");
            return 1;
        }

        // Redirect stdout to input.txt
        if (dup2(fd, 1) == -1) {
            perror("dup2 failed");
            close(fd);
            return 1;
        }

        close(fd);

        // Execute ls / -l
        execlp("ls", "ls", "/", "-l", (char *)NULL);

        perror("Exec failed");
        return 1;
    }
    else {
        wait(NULL);

        printf("Output saved in input.txt\n");
    }

    return 0;
}
