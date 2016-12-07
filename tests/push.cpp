#include "catch.hpp"
#include <stack.hpp>

SCENARIO("pushing an element => count of elements increases by one")
{
    GIVEN("stack and its size")
    {
        stack<size_t> st;
        st.push(1);
        st.push(2);
        auto count = st.count();

        WHEN("push an element")
        {
            st.push(3);

            THEN("count of elements increases by one")
            {
                REQUIRE(st.count() == count + 1);
            }
        }
    }
}