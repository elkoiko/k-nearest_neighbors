#include "catch_amalgamated.hpp"
#include "Sample.hpp"

TEST_CASE("initTag") {

    Sample sample;

    sample.initTag("7 0.87 0.5 0.87");
    REQUIRE(sample.getTag() == 7);

    sample.initTag(" 7 0.87 0.5 0.87");
    REQUIRE(sample.getTag() == 7);

    sample.initTag("Foo2 0.87 0.5 0.87");
    REQUIRE(sample.getTag() < 0);
}

TEST_CASE("getFeaturesString") {

    Sample sample;
    
    REQUIRE(sample.getFeaturesString("7 0.87 0.5 0.87") == "0.87 0.5 0.87");
    REQUIRE(sample.getFeaturesString("7   0.87 0.5 0.87  ") == "0.87 0.5 0.87");
}