#include "catch_amalgamated.hpp"
#include "MyClass.hpp"

TEST_CASE("Formula is computed", "[Formula]")
{

    MyClass myClass;

    REQUIRE(myClass.Formula(2, 5) == 10);
    REQUIRE(myClass.Formula(5, 5) == 25);
}