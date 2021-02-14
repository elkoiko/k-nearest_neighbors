#include <sstream>
#include "ClassificationReport.hpp"
using namespace std;

ClassificationReport::ClassificationReport(const vector<Similarity>& predictedSimilarities, int k) : _k(k)
{
    initTagsStatistics(predictedSimilarities);
    _confusion = ((double)_ok) / ((double)_nbTags);
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

double ClassificationReport::getConfusion() const
{
    return _confusion;
}

string ClassificationReport::toString()
{
    ostringstream strRet;
    
    strRet << "Classification Report:" << endl;
    strRet << _ok << " tags were well predicted." << endl;
    strRet << getNbWrongTags() << " tags were wrongly predicted." << endl;
    strRet << "For a total of " << _nbTags << " tags, there is a confusion of " << _confusion * 100 << "% with k=" << _k << "." << endl;
    return strRet.str();
}