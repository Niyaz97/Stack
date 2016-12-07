#include "catch.hpp"
#include <stack.hpp>

SCENARIO("count of empty stack must be 0")
{
    GIVEN("empty stack")
    {
        stack<size_t> st;

        WHEN("count")
        {
            THEN("count must be 0")
            {
                REQUIRE(st.count() == 0);
            }
        }
    }
}

SCENARIO("count of non-empty stack mustn't be 0")
{
    GIVEN("non-empty stack")
    {
        stack<size_t> st;
        st.push(1);
        st.push(2);

        WHEN("count")
        {
            THEN("count mustn't be 0")
            {
                REQUIRE(st.count() != 0);
            }
        }
    }
}
