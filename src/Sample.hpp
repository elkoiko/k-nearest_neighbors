#include <iostream>
#include "Features.hpp"

class Sample {

public:
    Sample();
    Sample(std::string strSample);

    std::string toString();

    void scale();

    // Operators
    double operator[](int index);

    // Getters
    char getTag() const;
    Features getFeatures() const;

private:
    char _tag = 0;
    Features _features;
};