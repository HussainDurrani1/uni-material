#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {    
	printf(" Hello\n");    
	if (fork() == 0) {        
		printf("C: World\n");    
	}    
	else {        
		printf("P: World\n");    
	}
}

///////////////////////////////////

// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// void forkexample() {
// 	// child process because return value zero
// 	if (fork() == 0) printf("Hello from Child!\n");

// 	// parent process because return value non-zero.
// 	else printf("Hello from Parent!\n");
// }

// int main() {
// 	forkexample();
// 	return 0;
// }

//////////////////////////////////////////////

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>
// int main() {
// 	pid_t pid;           /* fork a child process */
// 	pid = fork();
// 	if (pid < 0) { /* error occurred */
// 		fprintf(stderr, "Fork Failed");
// 		return 1;
// 	} 
// 		else if (pid == 0) { /* child process */
// 		execlp("/bin/ls","ls",NULL);
// 	}
// 	else { 
// 		// parent process: parent will wait for the child to complete */wait(NULL)
// 		printf("Child Complete");
// 	}
// 	return 0;
// }