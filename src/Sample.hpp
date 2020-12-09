#include <iostream>
#include "Features.hpp"

class Sample {

public:
    Sample();
    Sample(std::string strSample);

    std::string toString();

    void scale();
    void initTag(const std::string &strSample);
    std::string getFeaturesString(const std::string &strSample);

    // Operators
    double operator[](int index);

    // Getters
    char getTag() const;
    Features getFeatures() const;

private:
    char _tag = 0;
    Features _features;
};