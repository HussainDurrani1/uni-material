#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: Incorrect number of arguments.\n");
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1, num2;
    sscanf(argv[1], "%d", &num1);
    sscanf(argv[2], "%d", &num2);

    if (num2 == 0) {
        printf("Error: The second number cannot be zero.\n");
        return 1;
    }

    printf("Sum: %d\n", num1 + num2);
    printf("Difference: %d\n", num1 - num2);

    return 0;
}