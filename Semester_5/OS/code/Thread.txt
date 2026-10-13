#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>


void* f1(void* ptr)
{
	while(1)
		printf("Thread 1");

}


void* f2(void* ptr)
{
	while(1)
		printf("Thread 2");

}


int main()
{
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,&f1,NULL);
	pthread_create(&tid2,NULL,&f2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

return 0;
}

///////////////////////////////////////////main thread wait

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>


void* f1(void* ptr)
{
	while(1)
		printf("Thread 1");

}


void* f2(void* ptr)
{
	while(1)
		printf("Thread 2");

}


int main()
{
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,&f1,NULL);
	pthread_create(&tid2,NULL,&f2,NULL);
	sleep(5);

	//pthread_join(tid1,NULL);
	//pthread_join(tid2,NULL);

return 0;
}
/////////////////////////////////////////#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

 void* f1(void *ptr)
 
 {
 
    while(1)
    printf("i am function 1 for thread 1 \n");
 }
 
  void* f2(void *ptr)
 
 {
 
    while(1)
    printf("i am function 2 for thread 2 \n");
 }
 
 int main()
 
 {
     pthread_t tid1,tid2;
     pthread_create(&tid1,NULL, &f1,NULL);
     pthread_create(&tid2,NULL, &f2,NULL);
     
     while(1)
      printf("i am main \n");
     
     
     pthread_join(tid1,NULL);
     pthread_join(tid2,NULL);
     
     return 0;
 }