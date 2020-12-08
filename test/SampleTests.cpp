#include "catch_amalgamated.hpp"
#include "Sample.hpp"

TEST_CASE("Sample constructor with string sample", "[Constructor]") {

    Sample sample;

    sample = Sample("7 0.87 0.5 0.87");
    REQUIRE(sample.getTag() == 7);
}