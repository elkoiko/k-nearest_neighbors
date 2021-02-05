#ifndef KNNCOSINE_H
# define KNNCOSINE_H

#include "Features.hpp"
#include "Knn.hpp"

class KnnCosine: public Knn {

public:
    KnnCosine();
    virtual int predict(const Features& features);

protected:
  virtual int getKnn();
  virtual int predictSingle();
};

#endif