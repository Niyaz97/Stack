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
