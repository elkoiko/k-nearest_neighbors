#ifndef DATA_H
# define DATA_H

#include <fstream>
#include <vector>
#include "Sample.hpp"

class Data {

public:
    Data();
    Data(std::string strFilePath);

    void add(Sample& sample);

    // Operators
    Sample operator[](int index) const;

    std::string toString() const;

private:
    int _nbFeatures;
    int _nbSamples; // Size of _samples vector
    std::vector<Sample> _samples;
};

#endif