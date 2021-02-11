#ifndef KNNCOSINE_H
# define KNNCOSINE_H

#include "Knn.hpp"

class KnnCosine: public Knn {

public:
    KnnCosine(const Data& trainingData);
    virtual int predict(const Data& data, int k);

protected:
  virtual std::vector<Similarity>& getKnn(std::vector<Similarity> & similarities, int k);
  virtual Similarity predictSingle(const Sample& sample, int k);
};

#endif