#include <iostream>
#include "KnnCosine.hpp"
#include "Data.hpp"

int main(int, char**) {
    Data data("../../digits/digits.svm");
    std::cout << "New data object has been created: " << data.toString() << "." << std::endl;
}
