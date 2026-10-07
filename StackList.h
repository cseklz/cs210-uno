#pragma once
#include "List.h"
#include "Stack.h"

template<typename T>
class StackList : public Stack<T> {
public:
    void push(T *value) override {
        list_.addFront(value);
    }

    void pop() override {
        list_.deleteFront();
    }

    T *peek() const override {
        return list_.getFront();
    }

    [[nodiscard]] bool isEmpty() const override {
        return list_.isEmpty();
    }

    [[nodiscard]] int size() const override {
        return list_.size();
    }

    void print() const override {
        list_.print();
    }

private:
    LinkedList<T> list_;
};
