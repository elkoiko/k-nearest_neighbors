#ifndef FEATURES_H
# define FEATURES_H

#include <vector>
#include <iostream>

class Features {

public:
    int size;

    Features();
    Features(const std::vector<double> &features);

    // Operators
    double operator*(const Features &features) const;
    double operator[](int index) const;

    // Getters
    double getNorm() const;

    // Iterators
    std::vector<double>::const_iterator begin() const;
    std::vector<double>::const_iterator end() const;

private:
    double _norm;
    std::vector<double> _features;
    std::vector<double> split(const std::string &str, const std::string &delim);
};

#endif