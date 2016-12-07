#include "catch.hpp"
#include <stack.hpp>

SCENARIO("popping an element from stack => count of elements decreases by one")
{
    GIVEN("stack and its size")
    {
        stack<size_t > st;
        st.push(1);
        st.push(2);
        auto count = st.count();

        WHEN("pop an element")
        {
            st.pop();

            THEN("count of elements decreased by one")
            {
                REQUIRE(st.count() == count - 1);
            }
        }
    }
}

SCENARIO("popping an element => stack returns the last one")
{
    GIVEN("stack")
    {
        stack<size_t > st;
        st.push(1);
        st.push(2);

        WHEN("pop an element")
        {
            auto element = st.pop();

            THEN("popped element == 2")
            {
                REQUIRE(element == 2);
            }
        }
    }
}

SCENARIO("stack is empty => pop method throws an exception")
{
    GIVEN("empty stack")
    {
        stack<size_t> st;

        WHEN("trying to pop an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.pop(), std::logic_error &);
            }
        }
    }
}