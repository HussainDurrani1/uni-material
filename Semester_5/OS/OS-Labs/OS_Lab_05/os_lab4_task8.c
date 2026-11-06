// Task 8: Write a program in which the parent creates a child and exits after 2 seconds. 
// The child prints its PPID once every second for 6 seconds. 
// From the output, identify the second at which the PPID changes. 
// Then find out the name of the process that became the new parent (use ps with the new PPID). 
// The new parent may not be PID 1 on your system. Write, in a comment in your code, what you found and why this happens.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= 6; i++) {
            sleep(1);
            printf("Second %d: PPID = %d\n", i, getppid());
        }

        // PPID changes after the original parent exits.
        // The child is adopted by init or a subreaper process,
        // because its original parent terminated.
    } else if (pid > 0) {
        sleep(2);
        printf("Parent exiting. PID = %d\n", getpid());
        exit(0);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
