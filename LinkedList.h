#pragma once

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList() : head_(nullptr) {}

	void addFront(T* value) override {
		auto fresh = new Node<T>(value);
		fresh->next = head_;
		head_ = fresh;
		++size_;
	}

	void deleteFront() override {
		if (head_ == nullptr) {
			std::cout << "LinkedList is empty." << std::endl;
			return;
		}

		Node<T>* doomed = head_;
		head_ = head_->next;
		delete doomed->data;
		delete doomed;
		--size_;
	}

	void addAnywhere(int position, T* value) override {
		if (position < 0 || position > size_) {
			std::cout << "Position out of bounds." << std::endl;
			return;
		}

		if (position == 0) {
			addFront(value);
			return;
		}

		auto current = head_;
		for (int i = 0; i < position - 1 && current != nullptr; ++i) {
			current = current->next;
		}

		auto fresh = new Node<T>(value);
		fresh->next = current->next;
		current->next = fresh;
		++size_;
	}

	void deleteAnywhere(int position) override {
		if (position < 0 || position >= size_) {
			std::cout << "Position out of bounds." << std::endl;
			return;
		}

		if (position == 0) {
			deleteFront();
			return;
		}

		auto current = head_;
		for (int i = 0; i < position - 1 && current != nullptr; ++i) {
			current = current->next;
		}

		auto doomed = current->next;
		current->next = doomed->next;
		delete doomed->data;
		delete doomed;
		--size_;
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
			std::cout << *current->data << ",";
			current = current->next;
		}

		std::cout << std::endl;
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
	int size_{};
};
