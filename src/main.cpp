#include <iostream>
#include "KnnCosine.hpp"
#include "Data.hpp"
#include "ClassificationReport.hpp"

int main(int, char**) {
    Data trainingData("../../digits/digits.svm");
    Data data("../../digits/predict.svm");
    const int k = 5;

    KnnCosine prediction(trainingData);
    prediction.predict(data, k);
    ClassificationReport report(prediction.getPredictedSimilarities(), k);
    std::cout << report.toString() << std::endl;
}
