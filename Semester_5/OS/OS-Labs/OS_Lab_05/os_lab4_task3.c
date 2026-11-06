// Task 3: Write a program that takes an integer n from the command line.
// The parent creates exactly n children using a loop.
// Child number i prints “Child i, PID = …, PPID = …” and exits.
// The parent waits for every child and then prints how many children it reaped.
// Test with n = 1, 4 and 0, and with a negative n.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 0) {
        printf("n must be non-negative.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (fork() == 0) {
            printf("Child %d, PID = %d, PPID = %d\n", i, getpid(), getppid());
            exit(0);
        }
    }

    int reaped = 0;
    while (wait(NULL) > 0) reaped++;

    printf("Parent: Reaped %d children.\n", reaped);

    return 0;
}
