#pragma once

#include "List.h"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
	void addFront(T* value) override {
		if (size_ == CAPACITY) {
			cout << "ArrayList is full." << endl;
			return;
		}

		for (int i = size_; i > 0; --i) {
			data_[i] = data_[i - 1];
		}

		data_[0] = value;
		++size_;
	}

	void deleteFront() override {
		if (size_ == 0) {
			cout << "ArrayList is empty." << endl;
			return;
		}

		delete data_[0];
		for (int i = 0; i < size_ - 1; ++i) {
			data_[i] = data_[i + 1];
		}

		--size_;
	}

	bool search(T* value) const override {
		for (int i = 0; i < size_; ++i) {
			if (*data_[i] == *value) {
				return true;
			}
		}

		return false;
	}

	void print() const override {
		for (int i = 0; i < size_; ++i) {
			cout << *data_[i] << ",";
		}

		cout << endl;
	}

	~ArrayList() override {
		for (int i = 0; i < size_; ++i) {
			delete data_[i];
		}
	}

private:
	static constexpr int CAPACITY = 20;
	T* data_[CAPACITY]{};
	int size_{};
};