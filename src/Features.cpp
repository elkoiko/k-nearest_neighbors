#include "Features.hpp"
#include <numeric>

Features::Features(vector<double> params){
    this->_features = params;
    this->size = params.size();
    this->_norm = sqrt(*this * *this);
}

Features::~Features(){
    return;
}

double Features::getNorm() {
    return this->_norm;
}

double Features::operator*(const Features &features) {
    return inner_product(this->_features.begin(), this->_features.end(), features._features.begin(), 0.0);
}

double Features::operator[](int index) {
    return this->_features[index];
}