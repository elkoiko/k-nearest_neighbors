#include "Sample.hpp"
using namespace std;

class Data {

public:
    Data();
    ~Data();

    void add(Sample sample);

    // Factory method
    static Data fromFile();

    // Operators
    double operator[](int index);

    string toString();

private:
    int _nbFeatures;
    int _nbSamples; // Size of _samples vector
    vector<Sample> _samples;
};