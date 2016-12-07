#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>

template <typename T>
class stack {
public:

    stack();
    ~stack();

    auto count() const noexcept -> size_t ;
    auto push(T const& value) -> void;
    auto pop() -> T;


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
auto stack<T>::push(T const& value) -> void {
    if (count_ == array_size_) {
        size_t size = array_size_ * 2 + (array_size_ == 0);
        T * m_array = new T[size];
        std::copy(array_, array_ + array_size_, m_array);
        delete[] array_;
        array_ = m_array;
        array_size_ = size;
    }
    ++count_;
    array_[count_ - 1] = value;
}

template <typename T>
auto stack<T>::pop() -> T{
    if(count_==0)
        throw std::logic_error("stack is empty!");

    return array_[--count_];
}

#endif
