#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <allocator.hpp>


template <typename T>
class stack {
public:

    explicit
    stack(size_t size = 0);

    auto count() const noexcept -> size_t ;
    auto push(T const& value) /* strong */ -> void;

    auto top() const /* strong */ -> T;
    auto pop() noexcept -> void;

    auto empty() const noexcept -> bool;

private:
    allocator<T> alloc;
};


template <typename T>
stack<T>::stack(size_t size): alloc(size) {
}


template <typename T>
auto stack<T>::count() const noexcept -> size_t {
    return alloc.count();
}


template <typename T>
auto stack<T>::empty() const noexcept -> bool {
    return (alloc.count() == 0);
}

template <typename T>
auto stack<T>::push(T const& value) /* strong */ -> void {

    if (alloc.empty() || alloc.full()) {
        try {
            alloc.resize();
        }
        catch (...) {
            throw;
        }
    }

    try {
        alloc.construct(alloc.get() + alloc.count(), value);
    }
    catch(...) {
        throw;
    }
}

template <typename T>
auto stack<T>::top() const /* strong */ -> T try {
    if(alloc.count() == 0)
        throw std::logic_error("Error! Stack is empty!");
    return alloc.get()[alloc.count()-1];
}
catch(std::logic_error& err) {
    std::cout << err.what() << std::endl;
}
catch(...) {
    throw;
}

template <typename T>
auto stack<T>::pop() noexcept  -> void try  {
    if(alloc.count() ==  0)
        throw std::logic_error("Error! Stack is empty!");

    else alloc.destroy(alloc.get() + alloc.count() - 1);
}
catch(std::logic_error& err) {
    std::cout << err.what() << std::endl;
}


#endif
