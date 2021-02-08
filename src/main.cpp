#include <iostream>
#include "KnnCosine.hpp"
#include "Data.hpp"

int main(int, char**) {
    Data data("../../digits/digits.svm");
    const Sample& mySample = data[0];
    int* myRef = data.getNbFeatures();
    *myRef = 42;
    std::cout << "New data object has been created: " << data.toString() << "." << std::endl;
}
