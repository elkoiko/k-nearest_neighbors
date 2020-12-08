#include <vector>
using namespace std;

class Features {

public:
    int size;

    Features(vector<double> params);
    ~Features();

    // Operators
    double operator*(const Features &features);
    double operator[](int index);

    // Getters
    double getNorm();

private:
    double _norm;
    vector<double> _features;
};