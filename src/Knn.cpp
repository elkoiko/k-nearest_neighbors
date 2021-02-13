#include "Knn.hpp"

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