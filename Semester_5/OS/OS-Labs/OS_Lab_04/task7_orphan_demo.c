#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        /* child: show PPID now, then outlive the parent */
        printf("Child: PID = %d, PPID = %d (parent still alive)\n",
               getpid(), getppid());
        sleep(3);   /* parent exits during this sleep */
        printf("Child: PID = %d, PPID = %d (after parent exited)\n",
               getpid(), getppid());
        /*
         * Explanation: once the original parent terminates, the kernel
         * cannot leave the child parentless, so it is adopted by the
         * init process (PID 1) — on modern Linux systems this is usually
         * systemd, which acts as the subreaper. That is why the second
         * PPID printed is 1 (or the reaper's PID) instead of the
         * original parent's PID. The orphan keeps running normally.
         */
        exit(0);
    } else {
        printf("Parent: PID = %d exiting immediately\n", getpid());
        exit(0);   /* parent dies without wait() -> child orphaned */
    }
    return 0;
}
