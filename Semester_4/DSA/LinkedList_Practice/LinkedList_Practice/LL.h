#pragma once
#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;

template <class T>
class LL {
	
	Node<T>* first;

public:
	LL() { first = nullptr; }
	bool isEmpty() { return first == nullptr; }

	void insertAtEnd(int value) {
		Node<T>* temp = new Node<T>(value);
		if (!isEmpty()) {
			Node<T>* curr = first;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = temp;
		}
		else { first = temp; }
	}

	void insertAtFirst(int val) {
		Node<T>* temp = new Node<T>(val);
		if (!isEmpty()) { temp->next = first; }
		first = temp;
	}

	void insertAtAnyLocation(int newVal, int nodeNo) {
		Node<T>* curr = first;
		Node<T>* temp = new Node<T>(newVal);
		if (!isEmpty()) {
			for (int i = 1; i < nodeNo; i++){
				if (curr->next != nullptr) {
					curr = curr->next;
				}
			}
			if (curr->next != nullptr) { temp->next = curr->next; }
			curr->next = temp;
		}
		else { first = temp; }
	}

	void insertAtAnyLocation(T newVal, Node<T>* node) {
		Node<T>* curr = first;
		Node<T>* temp = new Node<T>(newVal);
		if (!isEmpty()) {
			while (curr != node){
				if (curr->next != nullptr) {
					curr = curr->next;
				}
			}
			if (curr->next != nullptr) { temp->next = curr->next; }
			curr->next = temp;
		}
		else { first = temp; }
	}

	void print() {
		Node<T>* curr = first;
		cout << "Linked List = ";
		while (curr != nullptr) {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << "NULL\n";
	}

	bool search(int val) {
		if (isEmpty()) { return false; }
		else {
			Node<T>* curr = first;
			while (curr != nullptr) {
				if (curr->data == val) { return true; }
				curr = curr->next;
			}
		}
		return false;
	}

	Node<T>* searchNode(int val) {
		if (isEmpty()) { return nullptr; }
		else {
			Node<T>* curr = first;
			while (curr != nullptr) {
				if (curr->data == val) { return curr; }
				curr = curr->next;
			}
		}
		return nullptr;
	}

	Node<T>* searchNode(Node<T>* node) {
		if (isEmpty()) { return nullptr; }
		else {
			Node<T>* curr = first;
			while (curr != nullptr) {
				if (curr == node) { return curr; }
				curr = curr->next;
			}
		}
		return nullptr;
	}


	void deleteNode(int val) {
		if (isEmpty()) { cout << "List is Empty...\n"; }
		else {
			Node<T>* curr = searchNode(val);
			if (curr != nullptr){
				if (curr == first) { first = first->next; curr->next = nullptr; }
				else {
					Node<T>* prev = first;
					while (prev->next != curr) { prev = prev->next; }
					if (curr->next == nullptr) { prev->next = nullptr; }
					else {
						prev->next = curr->next;
						curr->next = nullptr;
					}
				}
				delete curr;
			}
		}
	}


	void deleteNode(Node<T> node) {
		if (isEmpty()) { cout << "List is Empty...\n"; }
		else {
			Node<T>* curr = searchNode(node);
			if (curr != nullptr){
				if (curr == first) { first = first->next; curr->next = nullptr; }
				else {
					Node<T>* prev = first;
					while (prev->next != curr) { prev = prev->next; }
					if (curr->next == nullptr) { prev->next = nullptr; }
					else {
						prev->next = curr->next;
						curr->next = nullptr;
					}
				}
				delete curr;
			}
		}
	}


	void findMid() {
		Node<T>* curr = first;
		int count = 0;
		while (curr != nullptr) { curr = curr->next; count++; }
		curr = first;
		for (int i = 0; i < count/2; i++) { curr = curr->next; }
		cout << "MID: " << curr->data << "\n";
	}

	void findMidBy2Ptr() {
		Node<T>* slow = first;
		Node<T>* fast = first;

		if (!isEmpty()) {
			while (fast != nullptr && fast->next != nullptr) {
				slow = slow->next;
				fast = fast->next->next;
			}
		}
		cout << "MID: " << slow->data << "\n";
	}


	// Stack Data Structure
	// Postfix, Infix, Prefix Notations
	// Applications of Stack
	void reverse() {
		if (!isEmpty()) {
			Stack<Node<T>*> s(10);
			int count = 0;
			while (first->next != nullptr) {
				s.push(first);
				first = first->next;
				count++;
			}
			Node<T>* curr = first;
			for (int i = 0; i < count; i++) {
				curr->next = s.pop();
				curr = curr->next;
			}
			curr->next = nullptr;
		}
	}

	void reverseBy3Ptr() {
		Node<T>* prev = nullptr;
		Node<T>* curr = first;
		Node<T>* next = nullptr;

		while (curr != nullptr) {
			next = curr->next;   
			curr->next = prev;   
			prev = curr;         
			curr = next;         
		}

		first = prev; 
	}

};