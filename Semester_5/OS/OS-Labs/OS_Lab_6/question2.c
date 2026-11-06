#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    int p2c[2];
    int c2p[2];

    if (pipe(p2c) == -1) {
        perror("Pipe failed");
        return 1;
    }

    if (pipe(c2p) == -1) {
        perror("Pipe failed");
        close(p2c[0]);
        close(p2c[1]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");

        close(p2c[0]);
        close(p2c[1]);
        close(c2p[0]);
        close(c2p[1]);

        return 1;
    }

    if (pid == 0) {
        // Child
        close(p2c[1]);
        close(c2p[0]);

        int num;
        if (read(p2c[0], &num, sizeof(num)) != sizeof(num)) {
            perror("Child read failed");
            return 1;
        }

        int prime = 1;

        if (num < 2) {
            prime = 0;
        }
        else {
            for (int i = 2; i <= num / i; i++) {
                if (num % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        write(c2p[1], &prime, sizeof(prime));

        close(p2c[0]);
        close(c2p[1]);
    }
    else {
        close(p2c[0]);
        close(c2p[1]);

        write(p2c[1], &n, sizeof(n));
        close(p2c[1]);

        int result;

        if (read(c2p[0], &result, sizeof(result)) != sizeof(result)) {
            perror("Parent read failed");
            return 1;
        }

        if (result == 1) {
            printf("%d is prime\n", n);
        }
        else {
            printf("%d is not prime\n", n);
        }
        close(c2p[0]);

        wait(NULL);
    }

    return 0;
}
