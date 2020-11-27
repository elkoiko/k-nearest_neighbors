#include "gtest/gtest.h"
#include "MyClass.hpp"

TEST(FormulaTest, TestingReturnValues) {
    EXPECT_EQ(MyClass::Formula(2, 3), 6);
    EXPECT_EQ(MyClass::Formula(3, 3), 9);
}