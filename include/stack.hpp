#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>

template <typename T>
class stack {
public:

    stack();
    ~stack();

    auto count() const noexcept -> size_t ;
    auto push(T const& value) noexcept -> void;
    auto top() const /* strong */ -> T;
    auto pop() /* strong */ -> void;

    auto empty() const noexcept -> bool;

private:
    T * array_;
    size_t array_size_;
    size_t count_;
};


template <typename T>
stack<T>::stack() : count_(0), array_(nullptr),  array_size_(0) {
}

template <typename T>
stack<T>::~stack() {
    delete[] array_;
}

template <typename T>
auto stack<T>::count() const noexcept -> size_t {
    return count_;
}

template <typename T>
auto stack<T>::empty() const noexcept -> bool {
    return (count_==0);
}

template <typename T>
auto stack<T>::push(T const& value) noexcept -> void {

    if (count_ == array_size_) {
        size_t size = array_size_ * 2 + (array_size_ == 0);
        T* n_array;
        try {
            n_array = new T[size];
            std::copy(array_, array_ + array_size_, n_array);
            delete[] array_;
            array_ = n_array;
            array_size_ = size;
        }
        catch(...){
            delete[] n_array;
            return;
        }
    }
    try {
        ++count_;
        array_[count_ - 1] = value;
    }
    catch(...) {}
}

template <typename T>
auto stack<T>::top() const /* strong */ -> T {
    if(empty())
        throw std::logic_error("Error! Stack is empty!");
    return array_[count_-1];
}

template <typename T>
auto stack<T>::pop() /* strong */ -> void {
    if(empty())
        throw std::logic_error("Error! Stack is empty!");

    else --count_;
}


#endif
