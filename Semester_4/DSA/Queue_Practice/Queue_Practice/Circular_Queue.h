#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Circular_Queue {
	T* arr;
	int front, rear;
	int size;

public:
	Circular_Queue(int s) : size(s), rear(-1), front(0) {
		arr = new T[size];
	}
	~Circular_Queue() { delete[] arr; }

	bool isEmpty() { return rear == -1; }
	bool isFull() { return (rear + 1) % size == front && rear != -1; }

	void print() {
		if (isEmpty()) {
			cout << "Queue is empty.\n";
			return;
		}
		cout << "Queue: ";
		for (int i = front; i != rear; i = (i + 1) % size) {
			cout << arr[i] << " - ";
		}
		cout << " _\n";
	}

	void enqueue(T val) {
		if (!isFull()) { rear = (rear + 1) % size; arr[rear] = val; }
		else { cout << "Cannot enqueue more values...\n"; }
	}

	T dequeue() {
		if (!isEmpty()) {
			T val = arr[front];
			if (front == rear) {
				front = 0;
				rear = -1;
			}
			else {
				front = (front + 1) % size;
			}
			return val;
		}
		return T();
	}

	T first() { if (!isEmpty()) { return arr[front]; } return T(); }
	T last() { if (!isEmpty()) { return arr[rear]; } return T(); }
};