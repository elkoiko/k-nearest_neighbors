#include <sstream>
#include <iomanip>
#include "ClassificationReport.hpp"
using namespace std;

ClassificationReport::ClassificationReport(const vector<Similarity>& predictedSimilarities, int k) : _k(k)
{
    initTagsStatistics(predictedSimilarities);
    initConfusionMatrix(predictedSimilarities);
    _accuracy = ((double)_ok) / ((double)_nbTags);
}

void ClassificationReport::initConfusionMatrix(const vector<Similarity>& predictedSimilarities)
{
    // Searching for the maximum tag number
    _confusionMatrixSize = 0;
    for (const Similarity& similarity: predictedSimilarities)
    {
        if (similarity.tag > _confusionMatrixSize) 
        {
            _confusionMatrixSize = similarity.tag;
        }
    }
    _confusionMatrixSize += 1; // Add 1 to count the 0 for the size

    // We allocate the _confusionMatrix
    _confusionMatrix = new int*[_confusionMatrixSize];
    for(int i = 0; i < _confusionMatrixSize; i++)
    {
        _confusionMatrix[i] = new int[_confusionMatrixSize];
    }

    // Resetting the confusion matrix
    for (int x = 0; x < _confusionMatrixSize; x++)
    {
        for (int y = 0; y < _confusionMatrixSize; y++)
        {
            _confusionMatrix[x][y] = 0;
        }
    }

    // Filling in the confusion matrix
    for (const Similarity& similarity: predictedSimilarities)
    {
        // Tag is column
        // Predicted tag is line
        _confusionMatrix[similarity.predictedTag][similarity.tag] += 1;
    }
}

void ClassificationReport::initTagsStatistics(const vector<Similarity>& predictedSimilarities)
{
    _nbTags = predictedSimilarities.size();
    _ok = 0;
    for (const Similarity& similarity: predictedSimilarities)
    {
        if (similarity.predictedTag == similarity.tag)
        {
            _ok += 1;
        }
    }
}

int ClassificationReport::getNbGoodTags() const
{
    return _ok;
}

int ClassificationReport::getNbWrongTags() const
{
    return _nbTags - _ok;
}

int ClassificationReport::getNbTotalTags() const
{
    return _nbTags;
}

double ClassificationReport::getAccuracy() const
{
    return _accuracy;
}

string ClassificationReport::toString()
{
    ostringstream strRet;
    
    strRet << "Classification Report:" << endl;
    strRet << _ok << " tags were well predicted." << endl;
    strRet << getNbWrongTags() << " tags were wrongly predicted." << endl;
    strRet << "For a total of " << _nbTags << " tags, there is an accuracy of " << _accuracy * 100 << "% with k=" << _k << "." << endl;
    strRet << "*** Confusion Matrix ***" << endl;
    strRet << "Predicted tags are lines. Real tags are columns." << endl;
    strRet << " ";
    for (int i = 0; i < _confusionMatrixSize; i++)
    {
        strRet << internal << setw(5) << i;
    }
    strRet << endl;
    for (int x = 0; x < _confusionMatrixSize; x++)
    {
        strRet << x << " ";
        for (int y = 0; y < _confusionMatrixSize; y++)
        {
            strRet << internal << setw(4) << _confusionMatrix[x][y] << " ";
        }
        strRet << endl;
    }
    return strRet.str();
}

ClassificationReport::~ClassificationReport()
{
    for (int i = 0; i < _confusionMatrixSize; i++)
    {
        delete[] _confusionMatrix[i];
    }
    delete[] _confusionMatrix;
}