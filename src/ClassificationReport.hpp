#include <iostream>
using namespace std;

class ClassificationReport {

public:
    ClassificationReport();

    string toString();
private:
    int _confusion;
    int _nbTags;
    int _notOk;
    int _ok;
};