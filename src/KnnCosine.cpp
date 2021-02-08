#include "KnnCosine.hpp"

KnnCosine::KnnCosine()
{

}

int KnnCosine::predict(const Data& data, int k) 
{
    for (const Sample& sample: data)
    {
        _similarities.clear(); // Reset to 0 for each sample
        predictSingle(sample, k);
    }
    _similarities.clear();
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

vector<Similarity>& KnnCosine::getKnn(const Sample& sample, int k)
{
    // Retourne les k similarités les plus proches
    return 1;
}

Similarity KnnCosine::predictSingle(const Sample& sample, int k)
{
    Similarity similarity;

    for(const Sample& trainingSample: _trainingData)
    {
        Similarity tmp;

        tmp.tag = trainingSample.tag;
        //TODO: calculate the distance and store it into tmp.distance
        _similarities.append(tmp);
    }
    vector<Similarity>& kSimilarities = getKnn(sample, k);
    // TODO: On déduit la meilleur similarité dans similarity
    return similarity;
}