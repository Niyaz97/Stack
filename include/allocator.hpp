#ifndef STACK_ALLOCATOR_HPP
#define STACK_ALLOCATOR_HPP

#include <iostream>

template <typename T>
class allocator {
public:

    explicit
    allocator(size_t size = 0);
    allocator(allocator const& other);
    auto operator =(allocator const& other) -> allocator& = delete;
    ~allocator();

    auto resize() -> void;
    auto allocate(const size_t) -> void;

    auto swap(allocator& other) -> void;

    auto construct(T* ptr, T const & value) -> void;
    auto destroy(T* ptr) noexcept -> void;

    auto destroy(T* first, T* last) noexcept -> void;

    auto get() noexcept -> T*;
    auto get() const noexcept -> T const*;

    auto count() const noexcept -> size_t;
    auto full() const noexcept -> bool;
    auto empty() const noexcept -> bool;

private:
    T * ptr_;
    size_t size_;
    size_t count_;
};


template <typename T>
allocator<T>::allocator(size_t size) {
    size_ = 0;
    count_ = size;
    ptr_ = static_cast<T*>(::operator new(size * sizeof(T), std::nothrow_t() ));
}

template <typename T>
allocator<T>::allocator(allocator const &other) {
    size_ = other.size_;
    count_ = other.count_;
    ptr_ = static_cast<T*>(::operator new(size_ * sizeof(T), std::nothrow_t() ));
    std::copy(other.ptr_, other.ptr_ + count_, ptr_);
}

template <typename T>
allocator<T>::~allocator() {
    if(count_ > 0) {
        destroy(ptr_, ptr_ + count_);
    }
    ::operator delete(ptr_);
}

template <typename T>
auto allocator<T>::swap(allocator &other) -> void {
    std::swap(ptr_, other.ptr_);
    std::swap(count_, other.count_);
    std::swap(size_, other.size_);
}

template <typename T>
auto allocator<T>::construct(T *ptr, T const &value) -> void {
    new(ptr) T(value);
    ++count_;
}

template <typename T>
auto allocator<T>::destroy(T *ptr) noexcept -> void {
    ptr->~T();
    --count_;
}

template <typename T>
auto allocator<T>::destroy(T* first, T* last) noexcept -> void{
    for(; first!=last; ++first){
        destroy(first);
    }
}

template <typename T>
auto allocator<T>::get() noexcept -> T* {
    return ptr_;
}


template <typename T>
auto allocator<T>::get() const noexcept -> T const* {
    return ptr_;
}

template <typename T>
auto allocator<T>::count() const noexcept -> size_t {
    return count_;
}

template <typename T>
auto allocator<T>::full() const noexcept -> bool {
    return (count_ == size_);
}

template <typename T>
auto allocator<T>::empty() const noexcept -> bool {
    return (count_ == 0);
}

template <typename T>
auto allocator<T>::resize() -> void {
    size_t st_size = size_ * 2 + (size_ == 0);
    try {
        allocate(st_size);
    }
    catch(...) {
        throw;
    }
}

template <typename T>
auto allocator<T>::allocate(const size_t st_size) -> void {

    allocator<T> temp(st_size);

    try {
        temp.count_ = count_;
        std::copy(get(), get() + size_, temp.get());
    }
    catch(...) {
        throw;
    }
    swap(temp);
}


#endif
