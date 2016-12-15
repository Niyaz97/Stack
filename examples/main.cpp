#include "stack.hpp"

int main() {

    stack<size_t> st;


    try {
        st.push(1);
        st.push(2);
        st.push(3);

        std::cout << "Size of stack " << st.count() << std::endl;
        std::cout << st.top() << std::endl;
        st.pop();
        std::cout << st.top() << std::endl;
        st.pop();
        std::cout << st.top() << std::endl;
        st.pop();

    }
    catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Size of stack after popping elements " << st.count() << std::endl;
    if(st.empty()) std::cout<< "Stack is empty" << std::endl;

    return 0;
}
