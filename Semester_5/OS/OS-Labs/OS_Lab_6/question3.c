#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    int p1[2], p2[2], p3[2], p4[2];

    if (pipe(p1) == -1 || pipe(p2) == -1 || pipe(p3) == -1 || pipe(p4) == -1) {
        perror("Pipe failed");
        return 1;
    }
    pid_t c1 = fork();

    if (c1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c1 == 0) {
        // Child 1: Calculate sum
        close(p1[1]);
        close(p2[0]);

        close(p3[0]);
        close(p3[1]);
        close(p4[0]);
        close(p4[1]);

        int numbers[n];

        if (read(p1[0], numbers, sizeof(numbers)) != sizeof(numbers)) {
            return 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        write(p2[1], &sum, sizeof(sum));

        close(p1[0]);
        close(p2[1]);

        return 0;
    }

    pid_t c2 = fork();

    if (c2 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (c2 == 0) {
        // Child 2: Find minimum
        close(p3[1]);
        close(p4[0]);

        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);

        int numbers[n];
        if (read(p3[0], numbers, sizeof(numbers)) != sizeof(numbers)) { return 1; }

        int min = numbers[0];
        for (int i = 1; i < n; i++) {
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
        write(p4[1], &min, sizeof(min));

        close(p3[0]);
        close(p4[1]);

        return 0;
    }

    // Parent
    close(p1[0]);
    close(p2[1]);
    close(p3[0]);
    close(p4[1]);

    write(p1[1], arr, sizeof(arr));
    write(p3[1], arr, sizeof(arr));

    close(p1[1]);
    close(p3[1]);

    int sum, min;
    if (read(p2[0], &sum, sizeof(sum)) != sizeof(sum)) { return 1; }

    if (read(p4[0], &min, sizeof(min)) != sizeof(min)) { return 1; }

    printf("Sum = %d\n", sum);
    printf("Minimum = %d\n", min);

    close(p2[0]);
    close(p4[0]);

    wait(NULL);
    wait(NULL);

    return 0;
}
