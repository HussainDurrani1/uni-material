#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Error: Please enter a valid number of elements (at least 2).\n");
        return 1;
    }

    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d array elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    int largest, second_largest;
    if (ptr[0] > ptr[1]) {
        largest = ptr[0];
        second_largest = ptr[1];
    } else {
        largest = ptr[1];
        second_largest = ptr[0];
    }

    for (i = 2; i < n; i++) {
        if (ptr[i] > largest) {
            second_largest = largest;
            largest = ptr[i];
        } else if (ptr[i] > second_largest && ptr[i] != largest) {
            second_largest = ptr[i];
        }
    }

    printf("Output: %d\n", second_largest);

    free(ptr);
    return 0;
}