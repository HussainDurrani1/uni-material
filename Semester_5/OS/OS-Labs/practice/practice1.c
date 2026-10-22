#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if (argc > 2) {
        printf("Num 1: %s\n", argv[1]);
		printf("Num 2: %s\n", argv[2]);
		int sum = atoi(argv[1]) + atoi(argv[2]);
		printf("Sum of Num1 & Num2: %d\n", sum);
		printf("No of args: %d\n", argc);
	} else {
		printf("The executable file: %s\n", argv[0]);
        printf("Please 2 numbers in CLI arguments.\n");
		return 1;
	}

	// printf("Enter your age: ");
	// scanf("%d", &age);
	return 0;
}