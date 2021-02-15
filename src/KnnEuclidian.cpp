#include <cmath>
#include "KnnEuclidian.hpp"
using namespace std;

KnnEuclidian::KnnEuclidian(const Data& trainingData) : Knn(trainingData)
{

}

Similarity KnnEuclidian::predictSingle(const Sample& sample, int k)
{
    Similarity similarity;
    vector<Similarity> tmpSimilarities;

    tmpSimilarities.reserve(_trainingData.getNbSamples()); // Allocating memory once for all
    for(const Sample& trainingSample: _trainingData)
    {
        Similarity tmp;
        const Features& sampleFeatures = sample.getFeatures();
        const Features& trainingFeatures = trainingSample.getFeatures();

        tmp.value = 0;
        const int vectorSize = sampleFeatures.size;
        for (int i = 0; i < vectorSize; i++)
        {
            tmp.value += (sampleFeatures[i] - trainingFeatures[i]) * (sampleFeatures[i] - trainingFeatures[i]);
        }
        tmp.value = (-1) * sqrt(tmp.value); // Multiply by -1 to inverse the logic
        tmp.tag = trainingSample.getTag();
        tmpSimilarities.push_back(tmp);
    }
    getKnn(tmpSimilarities, k);
    // Now that we have the k nearest similarities, we must predict the correct tag

    similarity = getNearestSimilarity(tmpSimilarities);
    similarity.tag = sample.getTag();
    return similarity;
}