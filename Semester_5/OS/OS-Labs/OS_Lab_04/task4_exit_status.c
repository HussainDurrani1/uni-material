#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    int n = atoi(argv[1]);
    pid_t pid = fork();

    if (pid == 0) {
        /* child computes the sum and returns it via exit status */
        int sum = 0;

        for (int i = 1; i <= n; i++)
            sum += i;

        exit(sum);  /* NOTE: only the low 8 bits reach the parent */
    } else if (pid > 0) {
        int status;
        wait(&status);

        if (WIFEXITED(status))
            printf("Sum of 1..%d = %d\n", n, WEXITSTATUS(status));
    }

    return 0;
}

/*
 * Test results and explanation:
 *   ./task4 5   -> prints 15   (1+2+3+4+5 = 15, fits in 8 bits)
 *   ./task4 30  -> prints 209, NOT 465.
 * Why? A process exit status is only 8 bits wide (0-255).
 * The real sum 1+...+30 = 465, but 465 mod 256 = 209, so the
 * parent sees 209. Any sum larger than 255 gets truncated to
 * its lowest 8 bits. For big results use a pipe or shared
 * memory instead of the exit status.
 */