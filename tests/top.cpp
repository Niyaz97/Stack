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
