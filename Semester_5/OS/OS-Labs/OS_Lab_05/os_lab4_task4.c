// Task 4: Write a program that builds this tree: the original process (P) creates two children,
//  C1 and C2, and C1 creates one child of its own, G1.
//  Every process prints a line giving its role (P, C1, C2 or G1), its PID and its PPID.
//  Arrange the waits so that G1 always finishes before C1, and both C1 and C2 finish before P.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("P: PID = %d, PPID = %d\n", getpid(), getppid());

    pid_t c1 = fork();

    if (c1 == 0) {
        printf("C1: PID = %d, PPID = %d\n", getpid(), getppid());

        pid_t g1 = fork();

        if (g1 == 0) {
            printf("G1: PID = %d, PPID = %d\n", getpid(), getppid());
            return 0;
        }

        wait(NULL);
        return 0;
    }

    pid_t c2 = fork();

    if (c2 == 0) {
        printf("C2: PID = %d, PPID = %d\n", getpid(), getppid());
        return 0;
    }

    waitpid(c1, NULL, 0);
    waitpid(c2, NULL, 0);

    return 0;
}
