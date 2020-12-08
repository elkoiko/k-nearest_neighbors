#include "Sample.hpp"

Sample::Sample()
{
    _tag = 0;
}

// Sample takes a string representing a sample
// with each bit of data separated by a white space
// First number is the tag, other numbers are features
// Throws invalid argument exception if string does not contain valid numbers
Sample::Sample(string strSample)
{
    string strTag, strFeatures;
    int firstSpaceIndex;

    firstSpaceIndex = strSample.find_first_of(' '); 
    strTag = strSample.substr(0, firstSpaceIndex + 1);
    strFeatures = strSample.substr(firstSpaceIndex);
    _tag = stoi(strTag);
    _features = Features(strFeatures);
}

unsigned char Sample::getTag() const
{
    return _tag;
}