#ifndef KNNCOSINE_H
# define KNNCOSINE_H

#include "Knn.hpp"
#include "Data.hpp"

class KnnCosine: public Knn {

public:
    KnnCosine();
    virtual int predict(const Data& data, int k);

protected:
  virtual int getKnn(int k);
  virtual Similarity predictSingle(const Sample& sample, int k) = 0;
};

#endif