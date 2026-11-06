// Task 5: Write a program that takes an integer n from the command line
// and creates three children. Child 1 tests whether n is a prime number
// and exits with 1 if it is prime and 0 if it is not.
// Child 2 calculates the sum of the numbers from 1 to n
// and returns the sum through its exit status.
// Child 3 terminates abnormally because of a runtime error that you cause on purpose.
// The parent waits for every child and, for each one, prints the PID
// and says whether it exited normally (with its exit code) or was killed by a signal.
// Test Child 2 with n = 5 and n = 30,
// and explain what happens to the sum when it is larger than 255.

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
        printf("Enter a non-negative integer.\n");
        return 1;
    }

    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            if (i == 1) {
                int prime = n >= 2;
                for (int j = 2; j <= n / j; j++) {
                    if (n % j == 0) {
                        prime = 0;
                        break;
                    }
                }
                exit(prime ? 1 : 0);
            }

            if (i == 2) {
                int sum = n * (n + 1) / 2;
                exit(sum);
            }

            if (i == 3) {
		int *p = NULL;
                *p = 10;
                exit(0);
	    }
        }
    }

    for (int i = 0; i < 3; i++) {
        int status;
        pid_t pid = wait(&status);

        if (WIFEXITED(status))
            printf("Child PID %d exited normally with code %d\n",
                   pid, WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("Child PID %d was killed by signal %d\n",
                   pid, WTERMSIG(status));
    }

    return 0;
}
