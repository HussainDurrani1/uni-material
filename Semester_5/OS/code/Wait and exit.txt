// C program to demonstrate working of wait()
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	if (fork()== 0)
		printf("HC: hello from child\n");
	else
	{
		printf("HP: hello from parent\n");
		wait(NULL);
		printf("CT: child has terminated\n");
	}

	printf("Bye\n");
	return 0;
}
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    fork();
printf("let us start the program\n");
   printf("Start of the program....\n");
   
   printf("Exiting the program....\n");
   exit(0);
 
   printf("End of the program....\n");

   return(0);

}