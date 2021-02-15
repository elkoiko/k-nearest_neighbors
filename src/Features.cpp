#include "Features.hpp"
#include <numeric>
using namespace std;

Features::Features() {
    _norm = 0;
    size = 0;
}

Features::Features(const std::vector<double> &features)
{
    _features = features;
    size = features.size();
    _norm = sqrt(*this * *this);
}

double Features::getNorm() const {
    return _norm;
}

double Features::operator*(const Features &features) const {
    // 0.0 to cast to double
    return inner_product(_features.begin(), _features.end(), features._features.begin(), 0.0);
}

double Features::operator[](int index) const {
    return _features[index];
}

vector<double> Features::split(const string &str, const string &delim)
{
    vector<double> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos)
            pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(stod(token));
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

std::vector<double>::const_iterator Features::begin() const
{
    return _features.begin();
}

std::vector<double>::const_iterator Features::end() const
{
    return _features.end();
}