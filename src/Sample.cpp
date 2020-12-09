#include "Sample.hpp"
#include "StringUtils.hpp"
using namespace std;
using namespace StringUtils;

Sample::Sample()
{
    _tag = 0;
    _features = Features();
}

// Sample takes a string representing a sample
// with each bit of data separated by a white space
// First number is the tag, other numbers are features
Sample::Sample(string strSample)
{
    // TODO: Implementing vector approach instead of string
    initTag(strSample);
    _features = Features(getFeaturesString(strSample));
}

// initTag sets the tag attribute from a string representing a sample
// tag attribute is negative if not in valid format
void Sample::initTag(const string &strSample)
{
    string strTag, strTrimedSample;
    int firstSpaceIndex;

    strTrimedSample = strSample;
    trim(strTrimedSample);
    firstSpaceIndex = strTrimedSample.find_first_of(' '); 
    strTag = strTrimedSample.substr(0, firstSpaceIndex + 1);
    try
    {
        _tag = stoi(strTag);
    }
    catch(const std::invalid_argument& e)
    {
        _tag = -1;
    } 
}

// getFeaturesString splits a sample string and returns
// the substring with features only
string Sample::getFeaturesString(const string &strSample)
{
    string strFeatures = strSample.substr(strSample.find_first_of(' '));
    
    return trim(strFeatures);
}

char Sample::getTag() const
{
    return _tag;
}

Features Sample::getFeatures() const
{
    return _features;
}