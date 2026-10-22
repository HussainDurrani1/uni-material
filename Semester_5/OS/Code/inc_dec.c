#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int v=100;

    if(fork() == 0) {
        v--;
        printf("Value of V in chilf is %d \n",v);
        return 0;
    }

    else {
        v++;
        printf("Value of V is Parent is %d \n",v);
        return 0;
    }
    return 0;
}