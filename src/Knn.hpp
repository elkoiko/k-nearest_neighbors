#ifndef KNN_H
# define KNN_H

#include "Data.hpp"

class Knn {

public:

  virtual int predict() = 0;

protected:
  double _similarity;
  Data _trainingData;

  virtual int getKnn() = 0;
  virtual int predictSingle() = 0;
};

#endif /* KNN_H */