#include<iostream>
#include<exception>

template<typename T, const unsigned S>
class MyStack {

    T data[S];
    size_t size = 0;

public:
    void push(const T& obj);
    void push(T&& obj);

    void pop();
    const T& peek() const;

    bool isEmpty() const;
    bool isFull() const;
};


template<typename T, const unsigned S>
void MyStack<T, S>::push(const T& obj) {
    if (size >= S)
        return;

    data[size++] = obj;
}


template<typename T, const unsigned S>
void MyStack<T, S>::push(T&& obj) {
    if (size >= S)
        return;

    data[size++] = std::move(obj);
}

template<typename T, const unsigned S>
void MyStack<T, S>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("The data array is already empty.");
    }

    size--;
}

template<typename T, const unsigned S>
bool MyStack<T, S> ::isEmpty() const{
    return size == 0;
}

template<typename T, const unsigned S>
bool MyStack<T, S> ::isFull() const{
    return size == S;
}
template<typename T, const unsigned S>
const T& MyStack<T, S>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("There are no elements left.");
    }

    return data[size - 1];
}
