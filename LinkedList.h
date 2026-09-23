#pragma once

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList() : head_(nullptr) {}

	void addFront(T* value) override {
		auto fresh = new Node<T>(value);
		fresh->next = head_;
		head_ = fresh;
	}

	void deleteFront() override {
		if (head_ == nullptr) {
			cout << "LinkedList is empty." << endl;
			return;
		}

		Node<T>* doomed = head_;
		head_ = head_->next;
		delete doomed->data;
		delete doomed;
	}

	bool search(T* value) const override {
		Node<T>* current = head_;
		while (current != nullptr) {
			if (*current->data == *value) {
				return true;
			}

			current = current->next;
		}

		return false;
	}

	void print() const override {
		Node<T>* current = head_;
		while (current != nullptr) {
			cout << *current->data << ",";
			current = current->next;
		}

		cout << endl;
	}

	~LinkedList() override {
		while (head_ != nullptr) {
			Node<T>* doomed = head_;
			head_ = head_->next;
			delete doomed->data;
			delete doomed;
		}
	}

private:
	Node<T>* head_;
};