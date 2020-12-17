class Knn {

public:

  Knn();

  int predict();

protected:
  double similarity;  

  int getKnn();
  int predictSingle();
};