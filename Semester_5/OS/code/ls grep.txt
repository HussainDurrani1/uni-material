#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int fds[2];                      // an array that will hold two file descriptors
  pipe(fds);                       // populates fds with two file descriptors
  pid_t pid = fork();              // create child process that is a clone of the parent
  
  if (pid == 0) {                  // if pid == 0, then this is the child process
    dup2(fds[0], STDIN_FILENO);    // fds[0] (the read end of pipe) donates its data to file descriptor 0
    close(fds[0]);                 // file descriptor no longer needed in child since stdin is a copy
    close(fds[1]);                 // file descriptor unused in child
    char *argv[] = {(char *)"sort", NULL};   // create argument vector
    if (execvp(argv[0], argv) < 0) exit(0);  // run sort command (exit if something went wrong)
  } 

  // if we reach here, we are in parent process
  close(fds[0]);                 // file descriptor unused in parent
  const char *words[] = {"pear", "peach", "apple"};
  // write input to the writable file descriptor so it can be read in from child:
  size_t numwords = sizeof(words)/sizeof(words[0]);
  for (size_t i = 0; i < numwords; i++) {
    dprintf(fds[1], "%s\n", words[i]); 
  }

  // send EOF so child can continue (child blocks until all input has been processed):
  close(fds[1]); 

  int status;
  pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
  return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}


//////////////////////////////////////////////////////////////
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);
	
	if(fork==0) //sort child
	{
	dup2(fd[0],0);
	close(fd[1]);
	
	execlp("sort", "sort", "-r", NULL);

	}
	else
	{
	dup2(fd[1],1);
	close(fd[0]);

	execlp("ls","ls",NULL)
	}
}
////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
// ls / -R| grep 'std' | more
int main()
{

int fd1[2];
int fd2[2];

pipe(fd1);
pipe(fd2);



if(fork()==0)//child process for ls

	{
	close(fd2[0]);
	close(fd2[1]);
	close(fd1[0]);

	dup2(fd1[1],1);
	execlp("ls","ls","/","-R",NULL);
	}
else //parent process
	{
	 if(fork()==0) // child for grep
	{
	close(fd1[1]);
	close(fd2[0]);

	dup2(fd1[0],0);
	dup2(fd2[1],1);
	
	execlp("grep","grep","std",NULL);
	}

	else //parent process
	if(fork()==0)
	{
	close(fd1[0]);
	close(fd1[1]);
	close(fd2[1]);

	dup2(fd2[0],0);
	execlp("more","more",NULL);
	
	}
	else
	{
	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);

	}

	
	}

}




