#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
	T* arr;
	int front, rear;
	int size;

public:
	Queue(int s) : size(s), rear(-1), front(0) {
		arr = new T[size];
	}
	~Queue() { delete[] arr; }

	bool isEmpty() { return rear == -1; }
	bool isFull() { return rear == size - 1; }

	void print() {
		cout << "Queue: ";
		for (int i = front; i <= rear; i++) {
			cout << arr[i] << " - ";
		}
		cout << " _\n";
	}

	void enqueue(T val) {
		if (!isFull()) { arr[++rear] = val; }
		else { cout << "Cannot enqueue more values...\n"; }
	}

	T dequeue() { if (!isEmpty()) { return arr[front++]; } return T(); }

	T first() { if (!isEmpty()) { return arr[front]; } return T(); }
	T last() { if (!isEmpty()) { return arr[rear]; } return T(); }

};