#include "catch_amalgamated.hpp"
#include "Features.hpp"

TEST_CASE("Features constructor with string features", "[Constructor]")
{
    std::string strFeatures  = "0.2 0.3 0.4";
    std::cout << "Running test with string " << strFeatures << std::endl;

     Features features = Features(strFeatures);

    REQUIRE(features.size == 3);
}