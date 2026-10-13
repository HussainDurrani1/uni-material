

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int ret = 1;
int status;
pid = fork();

if (pid == -1){

	printf("can't fork, error occured\n");
	exit(EXIT_FAILURE);
}
else if (pid == 0){


	printf("child process, pid = %u\n",getpid());
	printf("parent of child process, pid = %u\n",getppid());

	char * argv_list[] = {"ls","-lart","/home",NULL};

	execv("ls",argv_list);
	exit(0);
}
else{

	printf("Parent Of parent process, pid = %u\n",getppid());
	printf("parent process, pid = %u\n",getpid());

	
		if (waitpid(pid, &status, 0) > 0) {
			
			if (WIFEXITED(status) && !WEXITSTATUS(status))
			printf("program execution successful\n");
			
			else if (WIFEXITED(status) && WEXITSTATUS(status)) {
				if (WEXITSTATUS(status) == 127) {

					printf("execv failed\n");
				}
				else
					printf("program terminated normally,"
					" but returned a non-zero status\n");				
			}
			else
			printf("program didn't terminate normally\n");			
		}
		else {
			printf("waitpid() failed\n");
		}
	exit(0);
}
return 0;
}



/////////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
pid_t pid;
int ret = 1;
int status;
pid = fork();

	printf("child process, pid = %u\n",getpid());
	printf("parent of child process, pid = %u\n",getppid());

	char * argv_list[] = {"ls","-lart","/home",NULL};

	execv("ls",argv_list);
	exit(0);

return 0;
}


////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

	printf("Before exec call \n");

	execl("/bin/ls", "ls","-l", NULL);

	printf("After exec call \n");
}