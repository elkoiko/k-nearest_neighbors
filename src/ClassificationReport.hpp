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
    double getConfusion() const;
private:
    double _confusion;
    int _nbTags;
    int _ok;
    int _k;

    void initTagsStatistics(const std::vector<Similarity>& predictedSimilarities);
};