#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main() {

	int *v =(int*)malloc(sizeof(int));
	*v=100;
	if(fork()==1) {
		(*v)++;
		printf("value of v is the child process is %d \n",*v);
		return 0;
	}
	else {
		(*v)--;
		printf("value of v is the child process is %d \n",*v);
		return 0;
	}
}

/////////////////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// int main() {

// 	// This pointer will hold the
// 	// base address of the block created
// 	int* ptr;
// 	int n, i;

// 	// Get the number of elements for the array
// 	printf("Enter number of elements:");
// 	scanf("%d",&n);
// 	printf("Entered number of elements: %d\n", n);

// 	// Dynamically allocate memory using malloc()
// 	ptr = (int*)malloc(n * sizeof(int));

// 	// Check if the memory has been successfully
// 	// allocated by malloc or not
// 	if (ptr == NULL) {
// 		printf("Memory not allocated.\n");
// 		exit(0);
// 	}
// 	else {

// 		// Memory has been successfully allocated
// 		printf("Memory successfully allocated using malloc.\n");

// 		// Get the elements of the array
// 		for (i = 0; i < n; ++i) {
// 			ptr[i] = i + 1;
// 		}

// 		// Print the elements of the array
// 		printf("The elements of the array are: ");
// 		for (i = 0; i < n; ++i) {
// 			printf("%d, ", ptr[i]);
// 		}
// 	}

// 	return 0;
// }