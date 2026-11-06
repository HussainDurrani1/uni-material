// Task 6:

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid[4];
    int status, i;

    for (i = 0; i < 4; i++) {
        pid[i] = fork();

        if (pid[i] == 0) {
            switch (i) {
                case 0:
                    // Uses l: execl()
                    execl("/bin/echo", "echo", "Hello from exec", NULL);
                    break;

                case 1:
                    // Uses v: execv()
                    {
                        char *args[] = {"wc", "-l", "/etc/passwd", NULL};
                        execv("/usr/bin/wc", args);
                    }
                    break;

                case 2:
                    // Uses p: execvp()
                    {
                        char *args[] = {"ls", "-l", NULL};
                        execvp("ls", args);
                    }
                    break;

                case 3:
                    // Uses e: execle()
                    {
                        char *env[] = {"MY_VAR=Hello", NULL};
                        execle("/usr/bin/env", "env", NULL, env);
                    }
                    break;
            }

            perror("exec failed");
            exit(1);
        }
        else if (pid[i] < 0) {
            perror("fork failed");
            exit(1);
        }
    }

    for (i = 0; i < 4; i++) {
        waitpid(pid[i], &status, 0);

        printf("Child PID: %d, ", pid[i]);

        if (WIFEXITED(status))
            printf("Exit status: %d\n", WEXITSTATUS(status));
        else
            printf("Terminated abnormally\n");
    }

    return 0;
}
