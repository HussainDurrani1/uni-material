#include <stdio.h>

int main() {
    int arr[15];
    int original[15];
    int size = 0;
    int input;

    printf("Input Sequence: ");
    
    while (size < 15) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        arr[size] = input;
        original[size] = input;
        size++;
    }

    printf("\nThe entered sequence is : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Updated sequence is:     ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
