#include <iostream>
#include "KnnCosine.hpp"
#include "KnnEuclidian.hpp"
#include "Data.hpp"
#include "ClassificationReport.hpp"

int main(int argc, char** argv) {

    if (argc != 4)
    {
        std::cerr << "ERROR: Expecting 3 arguments." << std::endl;
        std::cout << "Expects 3 arguments: k-nearest_neighbors path/to/training/data.svm path/to/untagged/data.svm k" << std::endl;
        return -1;
    }

    std::string strPathToTrainingData = argv[1];
    std::string strPathToUntaggedData = argv[2];
    const int k = atoi(argv[3]);

    Data trainingData(strPathToTrainingData);
    Data data(strPathToUntaggedData);

    // Cosine prediction
    std::cout << "COSINE PREDICTION" << std::endl;
    KnnCosine cosinePrediction(trainingData);
    cosinePrediction.predict(data, k);
    ClassificationReport reportCosine(cosinePrediction.getPredictedSimilarities(), k);
    std::cout << reportCosine.toString() << std::endl;

    // Euclidian prediction
    std::cout << "EUCLIDIAN PREDICTION" << std::endl;
    KnnEuclidian euclidianPrediction(trainingData);
    euclidianPrediction.predict(data, k);
    ClassificationReport reportEuclidian(euclidianPrediction.getPredictedSimilarities(), k);
    std::cout << reportEuclidian.toString() << std::endl;

}
