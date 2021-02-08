#ifndef KNN_H
# define KNN_H

#include "vector"
#include "Data.hpp"
#include "Sample.hpp"
#include "Similarity.hpp"

class Knn {

public:

  virtual int predict(const Data& data, int k) = 0;

protected:
  vector<Similarity> _similarities;
  Data _trainingData;

  virtual int getKnn(const Sample& sample, int k) = 0;
  virtual Similarity predictSingle(const Sample& sample, int k) = 0;
};

#endif /* KNN_H */