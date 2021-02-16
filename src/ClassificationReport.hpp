#include <iostream>
#include <vector>
#include "Similarity.hpp"

class ClassificationReport {

public:
    ClassificationReport(const std::vector<Similarity>& predictedSimilarities, int k);

    std::string toString();

    int getNbGoodTags() const;
    int getNbWrongTags() const;
    int getNbTotalTags() const;
    double getAccuracy() const;

    ~ClassificationReport();
private:
    int **_confusionMatrix;
    int _confusionMatrixSize;
    double _accuracy;
    int _nbTags;
    int _ok;
    int _k;

    void initTagsStatistics(const std::vector<Similarity>& predictedSimilarities);
    void initConfusionMatrix(const std::vector<Similarity>& predictedSimilarities);
};