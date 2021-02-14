#include "Knn.hpp"
using namespace std;

Knn::Knn(const Data& trainingData) : _trainingData(trainingData)
{
}

bool Knn::compareSimilarities(const Similarity& s1, const Similarity& s2)
{
    return s1.value > s2.value;   
}

const std::vector<Similarity>& Knn::getPredictedSimilarities() const
{
    return _similarities;
}

void Knn::predict(const Data& data, int k)
{
     // Allocating memory for all similarities that will be predicted
    _similarities.reserve(data.getNbSamples());
    for (const Sample& sample: data)
    {
        _similarities.push_back(predictSingle(sample, k));
    }
}

Similarity Knn::getNearestSimilarity(const vector<Similarity>& similarities)
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

// getKnn returns the given similarities vector with only the k nearest similarities (highest similarities values).
vector<Similarity>& Knn::getKnn(vector<Similarity> &similarities, int k)
{
    sort(similarities.begin(), similarities.end(), compareSimilarities);
    similarities.erase(similarities.begin() + k, similarities.end());
    similarities.shrink_to_fit(); // Reducing the capacity in order to save memory
    return similarities;
}