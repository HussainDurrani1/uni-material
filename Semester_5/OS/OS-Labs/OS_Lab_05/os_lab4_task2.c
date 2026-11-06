// Task 2: Write a program that calls fork() three times one after the other,
// with no conditions. After the calls, every process prints its PID and PPID.
// Run it and count the lines printed, then draw the process tree from your output,
// and state how many processes exist in total and why.
// Finally, modify the program so that only the original parent creates the three children,
// and the children create nothing further, and compare the number of lines printed.

#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();

    printf("PID: %d, PPID: %d\n", getpid(), getppid());

    return 0;
}
