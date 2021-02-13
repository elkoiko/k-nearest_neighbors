#include "KnnCosine.hpp"
using namespace std;

KnnCosine::KnnCosine(const Data& trainingData) : Knn(trainingData)
{
}

void KnnCosine::predict(const Data& data, int k) 
{
     // Allocating memory for all similarities that will be predicted
    _similarities.reserve(data.getNbSamples());
    for (const Sample& sample: data)
    {
        _similarities.push_back(predictSingle(sample, k));
    }
}

// getKnn returns the given similarities vector with only the k nearest similarities (highest similarities values).
std::vector<Similarity>& KnnCosine::getKnn(std::vector<Similarity> &similarities, int k)
{
    sort(similarities.begin(), similarities.end(), compareSimilarities);
    similarities.erase(similarities.begin() + k, similarities.end());
    similarities.shrink_to_fit(); // Reducing the capacity in order to save memory
    return similarities;
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

Similarity KnnCosine::getNearestSimilarity(const vector<Similarity>& similarities)
{
    Similarity nearestSimilarity;
    vector<Similarity> summedSimilarities;

    for (const Similarity& similarity: similarities)
    {
        auto it = find_if(summedSimilarities.begin(), summedSimilarities.end(),
                            [&similarity](const Similarity& summedSimilarity) { return similarity.tag == summedSimilarity.tag; });
        if (it != summedSimilarities.end())
        {
            it->value += similarity.value;
        }
        else
        {
            Similarity tmpSimilarity;
            tmpSimilarity.tag = similarity.tag;
            tmpSimilarity.value = similarity.value;
            summedSimilarities.push_back(tmpSimilarity);
        }
    }
    sort(summedSimilarities.begin(), summedSimilarities.end(), compareSimilarities);
    nearestSimilarity = summedSimilarities[0];
    nearestSimilarity.predictedTag = nearestSimilarity.tag;
    nearestSimilarity.tag = -1;
    return nearestSimilarity;
}
