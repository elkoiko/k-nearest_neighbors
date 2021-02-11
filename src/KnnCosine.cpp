#include "KnnCosine.hpp"
using namespace std;

KnnCosine::KnnCosine(const Data& trainingData) : Knn(trainingData)
{

}

int KnnCosine::predict(const Data& data, int k) 
{
    for (const Sample& sample: data)
    {
        predictSingle(sample, k);
    }
    return 1;
}

// 5 similarites
// 1 | 0.7
// 4 | 0.22
// 3 | 0.3
// 6 | 0.8
// 6 | 0.98

// On veut déduire le tag avec les 5 au dessus
// On a le choix de faire une moyenne sur les tags (Ex: 2*6 donc c'est un 6)
// -> On a le choix de faire sinon par nb occurences + moyenne des similarités
// -> Ca va être 6 pour le coup donc on va retourner Similarity { 6; (0.8+0.98)/2; }

std::vector<Similarity>& KnnCosine::getKnn(std::vector<Similarity> &similarities, int k)
{
    return similarities;
}

Similarity KnnCosine::predictSingle(const Sample& sample, int k)
{
    Similarity similarity;
    vector<Similarity> tmpSimilarities;
    tmpSimilarities.reserve(_trainingData.getNbSamples());

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
    // TODO: On déduit la meilleur similarité dans similarity
    return similarity;
}