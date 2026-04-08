#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack {
	T* arr;
	int size, top;

public:
	Stack(int s) : size(s), top(-1) {
		arr = new T[size];
	}

	~Stack(){ delete[] arr; }

	void push(T val) { arr[++top] = val; }
	T pop() { return arr[top--]; }
	T peak() { return arr[top]; }

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == size - 1; }
};