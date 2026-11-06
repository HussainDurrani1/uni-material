// Task 9:

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t p1, p2, p3, p4, p5, p6;

    printf("P0: PID = %d, PPID = %d\n", getpid(), getppid());

    p1 = fork();

    if (p1 == 0) {
        // P1 creates P3 and P4
        printf("P1: PID = %d, PPID = %d\n", getpid(), getppid());

        p3 = fork();

        if (p3 == 0) {
            printf("P3: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        p4 = fork();

        if (p4 == 0) {
            printf("P4: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    }

    p2 = fork();

    if (p2 == 0) {
        // P2 creates P5 and P6
        printf("P2: PID = %d, PPID = %d\n", getpid(), getppid());

        p5 = fork();

        if (p5 == 0) {
            printf("P5: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        p6 = fork();

        if (p6 == 0) {
            printf("P6: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    }

    // P0 waits for P1 and P2
    wait(NULL);
    wait(NULL);

    return 0;
}
