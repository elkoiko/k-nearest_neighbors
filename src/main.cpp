#include <iostream>
#include "KnnCosine.hpp"
#include "Data.hpp"

int main(int, char**) {
    Data trainingData("../../digits/digits.svm");
    Data data("../../digits/predict.svm");

    KnnCosine prediction(trainingData);
    prediction.predict(data, 5);
}
