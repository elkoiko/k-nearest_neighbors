#ifndef KNNCOSINE_H
# define KNNCOSINE_H

#include "Knn.hpp"

class KnnCosine: public Knn {

public:
    KnnCosine(const Data& trainingData);
    virtual void predict(const Data& data, int k);

protected:
  virtual std::vector<Similarity>& getKnn(std::vector<Similarity> & similarities, int k);
  virtual Similarity predictSingle(const Sample& sample, int k);
  virtual Similarity getNearestSimilarity(const std::vector<Similarity>& similarities);
};

#endif