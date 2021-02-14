#ifndef KNN_H
# define KNN_H

#include "vector"
#include "Data.hpp"
#include "Sample.hpp"
#include "Similarity.hpp"

class Knn {

public:
  Knn(const Data& trainingData);
  void predict(const Data& data, int k);
  const std::vector<Similarity>& getPredictedSimilarities() const;

protected:
  std::vector<Similarity> _similarities;
  const Data &_trainingData;

  virtual Similarity predictSingle(const Sample& sample, int k) = 0;
  std::vector<Similarity>& getKnn(std::vector<Similarity> & similarities, int k);
  Similarity getNearestSimilarity(const std::vector<Similarity>& similarities);
  static bool compareSimilarities(const Similarity& s1, const Similarity& s2);
};

#endif /* KNN_H */