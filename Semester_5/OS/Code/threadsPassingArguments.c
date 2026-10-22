#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

 void* f1(void *ptr)
 
 {
 
    int* p = (int*) ptr;
    printf("This is the value of N in thread1 %d \n",*p);
 }
 
  void* f2(void *ptr)
 
 {
 
   
    int* p = (int*) ptr;
    printf("This is the value of N in thread2 %d \n",*p);
 }
 
 int main()
 
 {
     pthread_t tid1,tid2;
     int n1 = 100;
     int n2 = 200;
     pthread_create(&tid1,NULL, &f1, (void*) &n1);
     pthread_create(&tid2,NULL, &f2, (void*) &n2);
     

     pthread_join(tid1,NULL);
     pthread_join(tid2,NULL);
     
     return 0;
 }
////////////////////////////////////////////////// Passing multiple arguments

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

 void* f1(void *ptr)
 
 {
 
    int* p = (int*) ptr;
    for (int i=0;i<10;i++)
    printf("This is the value of N in thread1 %d \n",p[i]);
 }
 
   int main()
 
 {
     pthread_t tid1,tid2;
     int n1[10] = {0,1,2,3,4,5,6,7,8,9};
  
    pthread_create(&tid1,NULL, &f1, (void*) n1);
    pthread_join(tid1,NULL);

     
     return 0;
 }

////////////////////////////////////multiple arguments in single thread

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

 void* f1(void *ptr)
 
 {
 
    int* p = (int*) ptr;
    for (int i=0;i<5;i++)
    printf("This is the value of N in thread1 %d \n",p[i]);
 }
 
   int main()
 
 {
     pthread_t tid1,tid2;
     int n1[10] = {0,1,2,3,4,5,6,7,8,9};
  
    pthread_create(&tid1,NULL, &f1, (void*) n1);
    pthread_create(&tid1,NULL, &f1, (void*) &n1[5]);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
     
     return 0;
 }










///////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>


int sum1 = 0 , sum2 = 0;
void* add1 (void* ptr)
{
	int* num =(int*) ptr;
	for (int i=0;i<5;i++)
		sum1 += num[i];
	return NULL;

	
}

void* add2 (void* ptr)
{
	int* num =(int*) ptr;
	for (int i=0;i<5;i++)
		sum2 += num[i];
	return NULL;

	
}


int main()

{
	pthread_t tid1, tid2;
	int number[10] = {9,7,8,6,5,4,3,1,2,7};

	pthread_create(&tid1,NULL,&add1,(void*)number);
	pthread_create(&tid2,NULL,&add2,(void*)&number[5]);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	int sum = sum1+sum2;
	printf("Sum is %d", sum);

return 0;
	
}



/////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

 void* f1(void *ptr)
 
 {
 
    int* p = (int*) ptr;
    for (int i=0;i<10;i++)
    printf("This is the value of N in thread1 %d \n",p[i]);
 }
 
  void* f2(void *ptr)
 
 {
 
   
    int* p = (int*) ptr;
    printf("This is the value of N in thread2 %d \n",*p);
 }
 
 int main()
 
 {
     pthread_t tid1,tid2;
     int n1[10] = {0,1,2,3,4,5,6,7,8,9};
     int n2 = 200;
     pthread_create(&tid1,NULL, &f1, (void*) n1);
    // pthread_create(&tid2,NULL, &f2, (void*) &n2);
     

    pthread_join(tid1,NULL);
     //pthread_join(tid2,NULL);
     
     return 0;
 }

/////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>



int sum = 0;

 void* f1(void *ptr)
 
 {
 
    int* p = (int*) ptr;
    for (int i=0;i<5;i++)
    //printf("This is the value of N in thread1 %d \n",p[i]);
    sum += p[i];
  
    
 }
 
   int main()
 
 {
     pthread_t tid1,tid2;
     int n1[10] = {0,1,2,3,4,5,6,7,8,9};
  
    pthread_create(&tid1,NULL, &f1, (void*) n1);
   // pthread_create(&tid1,NULL, &f1, (void*) &n1[5]);
    pthread_join(tid1,NULL);
   // pthread_join(tid2,NULL);
       printf("%d",sum);
     return 0;
 }

