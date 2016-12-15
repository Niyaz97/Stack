#include "catch.hpp"
#include <stack.hpp>


SCENARIO("popping an element => stack returns the last one")
{
    GIVEN("stack")
    {
        stack<size_t> st;
        st.push(1);
        st.push(2);

        WHEN("pop an element")
        {
            auto element = st.top();

            THEN("popped element == 2")
            {
                REQUIRE(element == 2);
            }
        }
    }
}

SCENARIO("stack is empty => top method throws an exception")
{
    GIVEN("empty stack")
    {
        stack<size_t> st;

        WHEN("trying to pop an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.top(), std::logic_error &);
            }
        }
    }
}
