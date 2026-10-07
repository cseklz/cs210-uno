#pragma once

template<typename T>
class Stack {
public:
    virtual ~Stack() = default;

    virtual void push(T *value) = 0;

    virtual void pop() = 0;

    virtual T *peek() const = 0;

    [[nodiscard]] virtual bool isEmpty() const = 0;

    [[nodiscard]] virtual int size() const = 0;

    virtual void print() const = 0;
};
