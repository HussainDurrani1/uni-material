#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int fd[2];
    char buf[20] = {0};

    pipe(fd);

    write(fd[1], "ABCDE", 5);

    int n = read(fd[0], buf, 20);

    printf("%d %s\n", n, buf);

    return 0;
}
