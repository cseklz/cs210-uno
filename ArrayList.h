#pragma once

#include <iostream>

template <typename T>
class ArrayList : public List<T> {
public:
	void addFront(T* value) override {
		if (size_ >= CAPACITY) {
			std::cout << "ArrayList is full." << std::endl;
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
			std::cout << "ArrayList is empty." << std::endl;
			return;
		}

		delete data_[0];
		for (int i = 0; i < size_ - 1; ++i) {
			data_[i] = data_[i + 1];
		}

		--size_;
	}

	void addAnywhere(int position, T* value) override {
		if (size_ >= CAPACITY || size_ < position || position < 0) {
			std::cout << "ArrayList is full or position outside range." << std::endl;
			return;
		}

		for (int i = size_; i > position; --i) {
			data_[i] = data_[i - 1];
		}

		data_[position] = value;
		++size_;
	}

	void deleteAnywhere(int position) override {
		if (size_ == 0 || size_ <= position || position < 0) {
			std::cout << "ArrayList is empty or position outside range." << std::endl;
			return;
		}

		delete data_[position];
		for (int i = position; i < size_ - 1; ++i) {
			data_[i] = data_[i + 1];
		}

		--size_;
	}

	void reverse() override {
		if (size_ <= 1) {
			return;
		}

		for (int i = 0; i < size_ / 2; ++i) {
			T* temp = data_[i];
			data_[i] = data_[size_ - i - 1];
			data_[size_ - i - 1] = temp;
		}
	}

	void concat(List<T>* other) override {
		if (dynamic_cast<ArrayList<T>*>(other) == nullptr) {
			std::cout << "Not an ArrayList." << std::endl;
			return;
		}

		if (size_ + other->size_ > CAPACITY) {
			std::cout << "ArrayList is full." << std::endl;
			return;
		}

		for (int i = 0; i < other->size_; ++i) {
			data_[size_ + i] = other->data_[i];
			delete other->data_[i];
		}

		size_ += other->size_;
		other->size_ = 0;
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
			std::cout << *data_[i] << ",";
		}

		std::cout << std::endl;
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