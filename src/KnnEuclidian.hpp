#ifndef KNN_EUCLIDIAN_H
# define KNN_EUCLIDIAN_H

#include "Knn.hpp"

class KnnEuclidian: public Knn {

public:
    KnnEuclidian(const Data& trainingData);

protected:
    virtual Similarity predictSingle(const Sample& sample, int k);

};

#endif