#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;

void* increment (void* ptr)
{
	for (int i=0;i<10000;i++)
	var++;
}

void* decrement (void* ptr)
{
	for (int i=0;i<10000;i++)
	var--;
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}

//////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	var++;
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	var--;
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}

////////////////////////////////////////////////////


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	var++;
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	var--;
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_join(tid1,NULL);


pthread_create(&tid2,NULL,&decrement,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}



///////////////////////////////////////critical section Problem solution mutual exclusion

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0; int turn = 0;

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	 while(turn!=0);    //entry section
	     var++;         //critical section
	     turn =1;       //exit section
	}
	
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	 while(turn!=1);        //entry section
        var--;              //critical section
    	turn =0;            //exit section
	}
	
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}

////////////////////////////////////////////////critical section progress part

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0; int turn = 0;

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	 while(turn!=0);    //entry section
	     var++;         //critical section
	     turn =1;       //exit section
	     printf("%d\n",var);
	}
	
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	 while(turn!=1);        //entry section
        var--;              //critical section
    	turn =0;            //exit section
	 printf("%d\n",var);
	}
	
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
//pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
//pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}
////////////////////////////////////////////secision making indefinitly prolonged



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;  int flag[2] = {0,0};

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	flag[0] = 1;
	 while(flag[1]==1);    //entry section
	     var++;         //critical section
	     flag[0]=0;       //exit section
	    
	}
	
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	flag[1]=1;
	 while(flag[0]==1);        //entry section
        var--;              //critical section
    	flag[1]=0;           //exit section
	}
	
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}

////////////////////////////////////////////////// problem 1 satisfies



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;  int flag[2] = {0,0};

void* increment (void* ptr)
{
	for (int i=0;i<50000;i++)
	{
	flag[0] = 1;
	 while(flag[1]==1);    //entry section
	     var++;         //critical section
	     flag[0]=0;       //exit section
	    
	}
	
}

void* decrement (void* ptr)
{
	for (int i=0;i<50000;i++)
	{
	flag[1]=1;
	 while(flag[0]==1);        //entry section
        var--;              //critical section
    	flag[1]=0;           //exit section
	}
	
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
//pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
//pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}


//////////////////////////////////// merg turn and flag  Peterson soltuin


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>

int var = 0;  int flag[2] = {0,0}; int turn =0;

void* increment (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	flag[0] = 1;
	turn=1;
	 while(flag[1]==1 && turn ==1);    //entry section
	     var++;         //critical section
	     flag[0]=0;       //exit section
	    
	}
	
}

void* decrement (void* ptr)
{
	for (int i=0;i<1000000;i++)
	{
	flag[1]=1;
	turn=0;
	 while(flag[0]==1 && turn ==0);        //entry section
        var--;              //critical section
    	flag[1]=0;           //exit section
	}
	
}

int main()

{

pthread_t tid1,tid2;

pthread_create(&tid1,NULL,&increment,NULL);
pthread_create(&tid2,NULL,&decrement,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
printf("%d\n",var);
return 0;

}