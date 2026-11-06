// Task 1: Declare a global integer array of 5 elements, filled with the values 1 to 5.
// Write a program in which the parent creates one child.
// The child replaces every element with its square and prints the array together with its own PID and its parent’s PID.
// The parent waits for the child, then prints its own copy of the array together with its PID and the PID of its child.
// Explain from the output why the two arrays differ.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int arr[5] = { 1, 2, 3, 4, 5 };

int main() {
    pid_t pid = fork();

    if (pid == 0) {
	// Child Process:
        for (int i = 0; i < 5; i++)
            arr[i] = arr[i] * arr[i];

        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        printf("Child array: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else if (pid > 1) {
        wait(NULL);

        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        printf("Parent array: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else {
	printf("Error creating process.");
    }

    return 0;
}
