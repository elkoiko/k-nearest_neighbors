#include <vector>
#include <iostream>

class Features {

public:
    int size;

    Features();
    Features(std::string strFeatures);

    // Operators
    double operator*(const Features &features);
    double operator[](int index);

    // Getters
    double getNorm();

private:
    double _norm;
    std::vector<double> _features;
    std::vector<double> split(const std::string &str, const std::string &delim);
};