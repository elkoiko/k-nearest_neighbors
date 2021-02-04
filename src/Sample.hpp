#include <iostream>
#include "Features.hpp"

class Sample {

public:
    Sample();
    Sample(std::string strSample);

    std::string toString() const;

    void scale();

    // Operators
    double operator[](int index) const;

    // Getters
    int getTag() const;
    Features getFeatures() const;

private:
    int _tag = 0;
    Features _features;
};