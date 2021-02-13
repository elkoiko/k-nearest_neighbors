#ifndef KNN_H
# define KNN_H

#include "vector"
#include "Data.hpp"
#include "Sample.hpp"
#include "Similarity.hpp"

class Knn {

public:
  Knn(const Data& trainingData);
  virtual void predict(const Data& data, int k) = 0;

protected:
  std::vector<Similarity> _similarities;
  const Data &_trainingData;

  virtual std::vector<Similarity>& getKnn(std::vector<Similarity> & similarities, int k) = 0;
  virtual Similarity predictSingle(const Sample& sample, int k) = 0;
  virtual Similarity getNearestSimilarity(const std::vector<Similarity>& similarities) = 0;
  static bool compareSimilarities(const Similarity& s1, const Similarity& s2);
};

#endif /* KNN_H */