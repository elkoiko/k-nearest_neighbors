#ifndef KNN_H
# define KNN_H

#include "vector"
#include "Data.hpp"
#include "Sample.hpp"
#include "Similarity.hpp"

class Knn {

public:
  Knn(const Data& trainingData);
  virtual int predict(const Data& data, int k) = 0;

protected:
  std::vector<Similarity> _similarities;
  const Data &_trainingData;

  virtual std::vector<Similarity>& getKnn(std::vector<Similarity> & similarities, int k) = 0;
  virtual Similarity predictSingle(const Sample& sample, int k) = 0;
};

#endif /* KNN_H */