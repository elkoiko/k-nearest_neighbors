#ifndef KNNCOSINE_H
# define KNNCOSINE_H

#include "Knn.hpp"

class KnnCosine: public Knn {

public:
    KnnCosine(const Data& trainingData);

protected:
  virtual Similarity predictSingle(const Sample& sample, int k);
};

#endif