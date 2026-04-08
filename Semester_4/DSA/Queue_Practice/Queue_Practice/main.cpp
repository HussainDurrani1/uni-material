#include "Queue.h"
#include "Circular_Queue.h"

int main() {
	Circular_Queue<int> cq(5);
	cq.enqueue(1);
	cq.enqueue(2);
	cq.enqueue(3);
	cq.enqueue(4);
	cq.enqueue(5);

	cq.print();

	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();

	return 0;
}


//int main() {
//	Queue<int> q(5);
//	q.enqueue(1);
//	q.enqueue(2);
//	q.enqueue(3);
//	q.enqueue(4);
//	q.enqueue(5);
//
//	q.print();
//
//	q.dequeue();
//	q.print();
//	q.dequeue();
//	q.print();
//	q.dequeue();
//	q.print();
//	q.dequeue();
//	q.print();
//	q.dequeue();
//	q.print();
//
//	return 0;
//}