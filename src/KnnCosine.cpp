#include "KnnCosine.hpp"
using namespace std;

KnnCosine::KnnCosine(const Data& trainingData) : Knn(trainingData)
{ 
}

Similarity KnnCosine::predictSingle(const Sample& sample, int k)
{
    Similarity similarity;
    vector<Similarity> tmpSimilarities;

    tmpSimilarities.reserve(_trainingData.getNbSamples()); // Allocating memory once for all
    for(const Sample& trainingSample: _trainingData)
    {
        Similarity tmp;
        const Features& sampleFeatures = sample.getFeatures();
        const Features& trainingFeatures = trainingSample.getFeatures();

        tmp.value = (sampleFeatures * trainingFeatures) / (sampleFeatures.getNorm() * trainingFeatures.getNorm());
        tmp.tag = trainingSample.getTag();
        tmpSimilarities.push_back(tmp);
    }
    getKnn(tmpSimilarities, k);
    // Now that we have the k nearest similarities, we must predict the correct tag

    similarity = getNearestSimilarity(tmpSimilarities);
    similarity.tag = sample.getTag();
    return similarity;
}
