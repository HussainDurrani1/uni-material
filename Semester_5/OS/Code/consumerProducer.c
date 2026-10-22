// data;
// mutex = 1;


// read()
// {
// 	axquire(&mutex); or wait(&mutex);
// 	cout<<data;
// 	release (&mutex) or simple signal(&mutex);
// }


// write()
// {

// 	acquire(&mutex); or wait(&mutex);
// 	data=getdata();
// 	release (&mutex) or simple signal(&mutex);
// }


// /////////////////////what if different mutex locks are used
// mutual exclusion is violated because the locks are different

// data;
// mutex1 = 1;
// mutex2 =1;


// read()
// {
// 	axquire(&mutex1); or wait(&mutex);
// 	cout<<data;
// 	release (&mutex1) or simple signal(&mutex);
// }


// write()
// {

// 	acquire(&mutex2); or wait(&mutex);
// 	data=getdata();
// 	release (&mutex2) or simple signal(&mutex);
// }


// Reader-Writer Algorithm-1(Reader priority and writer thread starves)/////////////////////multiple readers can enter in critical section

// rw_mutex_lock =1;
// count =0;
// mutex=1
// read
// {
// 	wait(&mutex);
// 	count++;
// 	signal(&mutex);
// 	//--> contex switch of time slice expires
// 	if(count==1)
// 		write(&rw_mutex_lock);
// 		//critical section
// 	wait(&mutex);
// 	count--;
// 	signal(&mutex);
// 	if(count==0)
// 		signal(&rw_mutex_lock);
// }


// Write()
// {

// Wait ()&rw_mutex;
// data =getdata();
// signal(&rw_mutex_Lock)
// }
// /////////////////////////////producer-consumer inter
// buffer =[10];
// count=0;     /// to chekc if there is space available in buffer
// in =0;
// out =0;
// mutex=1;
// producer() //sender
// {
// 	while (count--10){}

// 	buffer [in] = getdata();
// 	in =(in + 1)%10;

// 	wait(&mutex);
// 	count++;
// 	signal(&mutex);
// }
// Consumer() //receiver
// {
// 	while(count==0){}

// 	cout<<buffer{out};
// 	out = (out+1)%10;

// 	wait(&mutex);
// 	count--;
// 	signal(&mutex);

// }


// ////////////////////////////   checks replaced with counting semaphore
// /////////////////////////////bounded buffer problem

// buffer =[10];

// in =0;
// out =0;
// empty =10;
// full =0;

// producer() //sender
// {
	
// 	wait(&empty);
// 	buffer [in] = getdata();
// 	in =(in + 1)%10;
// 	signal(&full);


// }
// Consumer() //receiver
// {
// 	wait(&full);
// 	cout<<buffer{out};
// 	out = (out+1)%10;

// 	signal wait(&empty);

// }