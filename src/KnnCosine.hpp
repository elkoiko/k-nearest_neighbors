#include "Knn.hpp"

class KnnCosine: public Knn {

public:

    KnnCosine();

    double similarity;
    int predictSingle();
};