#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>

template <typename T>
class allocator{
protected:
    allocator(size_t size=0);
    allocator(allocator const&) = delete;
    ~allocator();

    auto swap(allocator& other) -> void;
    auto operator =(allocator const&) -> allocator& = delete;

    auto allocate(const size_t) -> void;
    auto deallocate() -> void;
    T * ptr_;
    size_t size_;
    size_t count_;
};


template <typename T>
allocator<T>::allocator(size_t size) {
    size_=0;
    count_=size;
    ptr_=static_cast<T*>(::operator new(size * sizeof(T)));
}

template <typename T>
allocator<T>::~allocator() {
    for(int i = 0; i < count_; ++i)
        ptr_[i].~T();
    ::operator delete(ptr_);
}

template <typename T>
auto allocator<T>::swap(allocator &other) ->void {
    std::swap(ptr_, other.ptr_);
    std::swap(count_, other.count_);
    std::swap(size_, other.size_);
}


template <typename T>
auto allocator<T>::allocate(const size_t st_size) -> void {

    allocator<T> temp(st_size);

    try {
        temp.count_ = count_;
        std::copy(ptr_, ptr_ + size_, temp.ptr_);
    }
    catch(...) {
        throw;
    }
    swap(temp);
}

template <typename T>
auto allocator<T>::deallocate() -> void {
    allocator<T> temp(size_);
    std::copy(ptr_, ptr_ + count_, temp.ptr_);
    swap(temp);
}

template <typename T>
class stack : private allocator<T> {
public:

    stack(size_t size = 0);

    auto count() const noexcept -> size_t ;
    auto push(T const& value) /* strong */ -> void;

    auto top() const /* strong */ -> T;
    auto pop() noexcept -> void;

    auto empty() const noexcept -> bool;
};


template <typename T>
stack<T>::stack(size_t size): allocator<T>(size) {
}


template <typename T>
auto stack<T>::count() const noexcept -> size_t {
    return allocator<T>::count_;
}

template <typename T>
auto stack<T>::empty() const noexcept -> bool {
    return (allocator<T>::count_==0);
}

template <typename T>
auto stack<T>::push(T const& value) /* strong */ -> void {
    T* s_array = allocator<T>::ptr_;
    bool  flag = false;
    size_t st_size = allocator<T>::size_ * 2 + (allocator<T>::size_ == 0);

    if (allocator<T>::count_ == allocator<T>::size_) {
        try {
            allocator<T>::allocate(st_size);
            flag = true;
        }
        catch (...) {
            throw;
        }
    }
    try {
        allocator<T>::ptr_[allocator<T>::count_] = value;
    }
    catch(...) {
        if(flag) allocator<T>::allocate(st_size/2);
        throw;
    }
    allocator<T>::count_++;
}

template <typename T>
auto stack<T>::top() const /* strong */ -> T try {
    if(allocator<T>::count_== 0)
        throw std::logic_error("Error! Stack is empty!");
    return allocator<T>::ptr_[allocator<T>::count_-1];
}
catch(std::logic_error& err) {
    std::cout << err.what() << std::endl;
}
catch(...) {
    throw;
}

template <typename T>
auto stack<T>::pop() noexcept  -> void try  {
    if(allocator<T>::count_==  0)
        throw std::logic_error("Error! Stack is empty!");

    else --allocator<T>::count_;
}
catch(std::logic_error& err)
{
    std::cout << err.what() << std::endl;
}


#endif
