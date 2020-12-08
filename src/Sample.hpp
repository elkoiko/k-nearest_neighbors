#include <iostream>
#include "Features.hpp"
using namespace std;

class Sample {

public:
    Sample();
    Sample(string strSample);

    string toString();

    void scale();

    // Operators
    double operator[](int index);

    // Getters
    unsigned char getTag() const;
    Features getFeatures();

private:
    unsigned char _tag;
    Features _features;
};