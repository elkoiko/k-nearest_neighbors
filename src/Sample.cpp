#include "Sample.hpp"
#include "StringUtils.hpp"
#include <vector>
using namespace std;
using namespace StringUtils;

Sample::Sample()
{
    _tag = 0;
}

// Sample takes a string representing a sample
// with each bit of data separated by a white space
// First number is the tag, other numbers are features
Sample::Sample(string strSample)
{
    // Split the string into a vector of double
    vector<double> sampleData = split(strSample, " ");

    // First element is the tag
    _tag = (int)sampleData.front();

    // We remove the tag to only keep the features
    sampleData.erase(sampleData.begin());
    _features = Features(sampleData);
}

int Sample::getTag() const
{
    return _tag;
}

Features Sample::getFeatures() const
{
    return _features;
}