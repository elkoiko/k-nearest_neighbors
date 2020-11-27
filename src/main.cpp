#include <iostream>
#include "MyClass.hpp"

int main(int, char**) {
    MyClass myClass;

    std::cout << "Hello, Woooorld!\n";
    std::cout << "Result of 2*5: " << myClass.Formula(2, 5) << "\n";
}
