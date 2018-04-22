#pragma once
#include<iostream>
#include<vector>
template<class T>
struct node {
	T data;
	node* next;
};
template<class T>
class linked_bag {
private:
	node<T>* head = NULL;
	int size = 0;
public:
	bool add(const T & element) {
		node<T>* insertion_node = new node<T>;
		insertion_node->data = element;
		insertion_node->next = NULL;
		if (!head) {
			head = insertion_node;
		}
		else {
			node<T>* temp = head;
			head = insertion_node;
			head->next = temp;
		}
		size++;
		return true;
	}
	bool remove(const T & element) {
		node<T>* iterator = head;
		bool found = false;
		while (!found && iterator->next) {
			if (iterator->data == element) {
				found = true;
				break;
			}
			iterator = iterator->next;
		}
		if (found) {
			iterator->data = head->data;
			head = head->next;
			size--;
		}
		return found;
	}
	//this one is a bit broken!!!
	T* to_array() {
		T* arr = new T[size];
		node<T>* iterator = head;
		for (int i = 0; i < size; i++) {
			arr[i] = iterator->data;
			iterator = iterator->next;
		}
		return arr;
	}
	void print() {
		node<T>* iterator = head;
		while (iterator->next) {
			std::cout << iterator->data << std::endl;
			iterator = iterator->next;
		}
	}
	int bag_size() {
		return size;
	}
};
