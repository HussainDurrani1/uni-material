#include "Node.h"
#include "LL.h"

int main() {
	
	LL<int> list;
	list.insertAtEnd(6);
	list.insertAtFirst(9);
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.print();

	list.findMidBy2Ptr();

	list.deleteNode(9);
	list.print();

	list.findMidBy2Ptr();


	cout << "\nReversed: \n";
	list.reverse();
	list.print();

	return 0;
}