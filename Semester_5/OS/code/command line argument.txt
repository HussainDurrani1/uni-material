int main(int argc, char*argv[]){}

///////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> //pid_t


int main(int n, char* argv[])
{

printf("Number of arguments are %d \n", n);
printf("\n Arg at index 0 is %s ",argv[0]);
printf("\n Arg at index 1 is %s ",argv[1]);
printf("\n Arg at index 2 is %s ",argv[2]);
printf("\n Arg at index 3 is %s ",argv[3]);
printf("Arg at index 4 is %s ",argv[4]);


}
/////////////////////////////////////////
// C program to illustrate
// command line arguments
#include<stdio.h>

int main(int argc,char* argv[])
{
	int counter;
	printf("Program Name Is: %s",argv[0]);
	if(argc==1)
		printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
	if(argc>=2)
	{
		printf("\nNumber Of Arguments Passed: %d",argc);
		printf("\n----Following Are The Command Line Arguments Passed----");
		for(counter=0;counter<argc;counter++)
			printf("\nargv[%d]: %s",counter,argv[counter]);
	}
	return 0;
}

/////////////////////////////////////////////////////
gedit hello.c
run onwork ubuntu gcc compiler


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int n, char* argv[])


{
	printf("Number of arguments are %d", n);
	printf(" Arg at index 0 is %s", argv[0]);
	printf(" Arg at index 1 is %s", argv[1]);
	return 0;
	
}


///////////////////////////////Add number


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int n, char* argv[])


{
	printf("Number of arguments are %d\n", n);
	printf(" Arg at index 0 is %s\n", argv[0]);
	printf(" Arg at index 1 is %s\n", argv[1]);
	printf(" Arg at index 1 is %s\n", argv[2]);
int i;
int j;

i = atoi(argv[1]);
j = atoi(argv[2]);
    
    int f;
    f=i+j;
    printf("the sum is %d", f);
    
	return 0;
	
}
