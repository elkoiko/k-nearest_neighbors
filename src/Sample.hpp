#include "Features.hpp"
using namespace std;

class Sample {

public:
    int scale; // Don't know yet what it's for

    Sample();
    ~Sample();

    string toString();

    // Operators
    double operator[](int index);

    // Getters
    unsigned char getTag();
    Features getFeatures();

private:
    unsigned char _tag;
    Features _features;
};