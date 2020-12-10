#include "catch_amalgamated.hpp"
#include "Sample.hpp"

TEST_CASE("Constructor with string") {

    Sample sample;

    sample = Sample("7 0.87 0.5 0.87");
    REQUIRE(sample.getTag() == 7);
}