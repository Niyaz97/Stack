#include "catch.hpp"
#include <stack.hpp>

SCENARIO("if stack is empty return true")
{

    GIVEN("empty stack")
    {
        stack<size_t> st;
        WHEN("checking if stack is empty")
        {
            THEN("return true")
            {
                REQUIRE(st.empty());
            }
        }

    }
}

SCENARIO("if stack is non-empty return false")
{
    GIVEN("non-empty stack")
    {
        stack<size_t> st;
        st.push(1);
        WHEN("checking if stack is empty")

        {
            THEN("return false")
            {
                REQUIRE_FALSE(st.empty());
            }
        }

    }
}
