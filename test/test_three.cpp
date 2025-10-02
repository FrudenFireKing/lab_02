#include <gtest/gtest.h>
#include "three.h"

TEST(ThreeTest, DefaultConstructor) {
    Three num;
    EXPECT_EQ(num.getSize(), 1);
    EXPECT_EQ(num.toString(), "0");
}

TEST(ThreeTest, SizeValueConstructor) {
    Three num(3, 1);
    EXPECT_EQ(num.getSize(), 3);
    EXPECT_EQ(num.toString(), "111");
}

TEST(ThreeTest, InitializerListConstructor) {
    Three num{1, 2, 0};
    EXPECT_EQ(num.toString(), "120");
}

TEST(ThreeTest, StringConstructor) {
    Three num("210");
    EXPECT_EQ(num.toString(), "210");
}

TEST(ThreeTest, CopyConstructor) {
    Three num1("120");
    Three num2(num1);
    EXPECT_EQ(num2.toString(), "120");
}

TEST(ThreeTest, MoveConstructor) {
    Three num1("210");
    Three num2(std::move(num1));
    EXPECT_EQ(num2.toString(), "210");
    EXPECT_EQ(num1.getSize(), 0);
}

TEST(ThreeTest, Addition) {
    Three num1("12");
    Three num2("21");
    Three result = num1.add(num2);
    EXPECT_EQ(result.toString(), "110");
}

TEST(ThreeTest, Subtraction) {
    Three num1("210");
    Three num2("120");
    Three result = num1.subtract(num2);
    EXPECT_EQ(result.toString(), "20");
}

TEST(ThreeTest, Comparison) {
    Three num1("210");
    Three num2("120");
    
    EXPECT_TRUE(num1.greaterThan(num2));
    EXPECT_FALSE(num1.lessThan(num2));
    EXPECT_FALSE(num1.equals(num2));
}

TEST(ThreeTest, AddAndAssign) {
    Three num1("12");
    Three num2("21");
    Three result = num1.addAndAssign(num2);
    EXPECT_EQ(result.toString(), "110");
}

TEST(ThreeTest, SubtractAndAssign) {
    Three num1("210");
    Three num2("120");
    Three result = num1.subtractAndAssign(num2);
    EXPECT_EQ(result.toString(), "20");
}

TEST(ThreeTest, EdgeCases) {
    Three zero;
    EXPECT_TRUE(zero.isZero());

    Three big("222222");
    EXPECT_EQ(big.toString(), "222222");
    
    Three num("121");
    Three result = num.subtract(num);
    EXPECT_TRUE(result.isZero());
}

TEST(ThreeTest, ExceptionHandling) {
    EXPECT_THROW(Three(3, 5), std::invalid_argument);
    
    EXPECT_THROW(Three({1, 2, 5}), std::invalid_argument);
    
    EXPECT_THROW(Three("345"), std::invalid_argument);
    
    Three small("12");
    Three large("210");
    EXPECT_THROW(small.subtract(large), std::invalid_argument);
}