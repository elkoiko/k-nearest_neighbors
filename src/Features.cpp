#include "Features.hpp"
#include <numeric>
using namespace std;

Features::Features() {
    _norm = 0;
    size = 0;
}

Features::Features(string strFeatures) {
    vector<double>  params = split(strFeatures, " ");
    _features = params;
    size = params.size();
    _norm = sqrt(*this * *this);
}

double Features::getNorm() {
    return _norm;
}

double Features::operator*(const Features &features) {
    return inner_product(_features.begin(), _features.end(), features._features.begin(), 0.0);
}

double Features::operator[](int index) {
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