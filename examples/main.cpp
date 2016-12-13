#include "stack.hpp"

int main() {

    stack<size_t> st;

    try {
        st.push(1);
        st.push(2);
        st.push(3);
    
        std::cout << "Size of stack "<< st.count() << std::endl;

        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
    }
    catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Size of stack after popping elements "<< st.count() << std::endl;

    return 0;
}
