#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

   if (argc != 3){
       printf("Error: 2 Integers are required via Command Line.\n");
       exit(1);
   }
   char *ct1 = argv[1];
   char *ct2 = argv[2];
   int t1 = atoi(argv[1]);
   int t2 = atoi(argv[2]);
   
   if ((t1 <= 0 || t1 > 9) || (t2 <= 0 && t2 > 9)){
       printf("Invalid Args: Both values must be between 1 and 9\n");
       exit(1);
   }
     
   pid_t runner_A_pid = fork();
   if (runner_A_pid < 0){
       perror("Error creating Runner A.\n");
       exit(1);
   }   
   
   if (runner_A_pid == 0) {
       printf("Runner A: PID=%d, PPID=%d.\n", getpid(), getppid());
       
       // fflush(stdout);
       execlp("sleep", "sleep", ct1, NULL);
       
       perror("Exec FAILED");
       exit(99);      
   }
   
   pid_t runner_B_pid = fork();
   if (runner_B_pid < 0){
       perror("Error creating Runner B.");
       exit(1);
   }
   
   if (runner_B_pid == 0) {
       printf("Runner B: PID=%d, PPID=%d.\n", getpid(), getppid());
       
       // fflush(stdout);
       char *args[] = {"sleep", ct2, NULL};
       execvp("sleep", args);
       
       perror("Exec FAILED");   
       exit(99);
   }
   
   char *winner = NULL;
   
   for (int i = 1; i <= 2; i++){
      int status;
      pid_t wPID = wait(&status);
      
      char *runner_name = "";
      if (wPID == runner_A_pid) {
          runner_name = "Runner A";
      }
      else if (wPID == runner_B_pid) {
          runner_name = "Runner B";
      }
      
      if (i == 1){
          winner = runner_name;
      }
      
      if (WIFEXITED(status)) {
          int exit_code = WEXITSTATUS(status);
          if (exit_code == 99) {
              printf("Finished %d: %s (PID %d), exec FAILED\n", i, runner_name, wPID);
          }
          else {
              printf("Finished %d: %s (PID %d), exit code %d \n", i, runner_name, wPID, exit_code);
          }
      }
      else if (WIFSIGNALED(status)) {
          printf("Finished %d: %s (PID %d), killed by a signal\n", i, runner_name, wPID);
      }
      
   }
   
   printf("Winner: %s.\n", winner);


    return 0;
}
