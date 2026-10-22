// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <pthread.h>

// void* f1(void *ptr) { 
//    int* p = (int*) ptr;
//    printf("This is the value of N in thread1 %d \n",*p);
//    return NULL;
// }
 
// void* f2(void *ptr) {   
//    int* p = (int*) ptr;
//    printf("This is the value of N in thread2 %d \n",*p);
//    return NULL;
// }
 
// int main() {
//      pthread_t tid1,tid2;
//      int n1 = 100;
//      int n2 = 200;
//      pthread_create(&tid1,NULL, &f1, (void*) &n1);
//      pthread_create(&tid2,NULL, &f2, (void*) &n2);
     

//      pthread_join(tid1,NULL);
//      pthread_join(tid2,NULL);
     
//      return 0;
//  }


// ///////////////////////////////////////////////////////////////////////
// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <pthread.h>

// int N=250; int number[1000];

// void* add (void* ptr) {
// 	int *sum = (int*)malloc(sizeof(int));
// 	*sum = 0;
// 	int* array = (int*)ptr;
// 	for(int i=0;i<N;i++) *sum += array[i];
// 	return (void*)sum;
// }

// int main() {

// 	for(int i=0;i<1000;i++) number[i] = 1;
	
// 	pthread_t pid1,pid2,pid3,pid4;
// 	void* sum1, *sum2, *sum3, *sum4;

// 	pthread_create(&pid1,NULL,&add,(void*)number);
// 	pthread_create(&pid2,NULL,&add,(void*)&number[250]);
// 	pthread_create(&pid3,NULL,&add,(void*)&number[500]);
// 	pthread_create(&pid4,NULL,&add,(void*)&number[750]);

// 	pthread_join(pid1,&sum1);
// 	pthread_join(pid2,&sum2);
// 	pthread_join(pid3,&sum3);
// 	pthread_join(pid4,&sum4);

// 	int sum = *((int*)sum1)+ *((int*)sum2)+ *((int*)sum3)+ *((int*)sum3)+ *((int*)sum4);
// 	printf("SUM is %d", sum);

//    return 0;
// }
// //////////////////////////////////////////////////////////////////




// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <pthread.h>

// int* sum =0 ;

// void* f1 (void *ptr) {
//    int* p = (int*) ptr;
//    for(int i=0;i<5;i++) *sum += p[i];
//    return (void*)sum;    
// }
 
// int main() {
//    pthread_t tid1, tid2;
//    int n1[10] = {0,1,2,3,4,5,6,7,8,9};

  
//    pthread_create(&tid1,NULL, &f1, (void*) n1);
//    pthread_create(&tid2,NULL, &f1, (void*) &n1[5]);
//    void* ptr1;
//    void* ptr2;

//    pthread_join(tid1,&ptr1);
//    pthread_join(tid2,&ptr2);
    
//    printf("i am the sum %d\n",*((int*)ptr1));
//    printf("i am the sum %d\n",*((int*)ptr2));
   
//    return 0;
//  }