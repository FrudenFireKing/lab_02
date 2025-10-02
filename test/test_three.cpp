#include <gtest/gtest.h>
#include "three.h"

TEST(ThreeTest, StringConstructor) {
    Three num("210");
    EXPECT_EQ(num.tostr(), "210");
}

TEST(ThreeTest, CopyConstructor) {
    Three num1("120");
    Three num2(num1);
    EXPECT_EQ(num2.tostr(), "120");
}

TEST(ThreeTest, MoveConstructor) {
    Three num1("210");
    Three num2(std::move(num1));
    EXPECT_EQ(num2.tostr(), "210");
    EXPECT_EQ(num1.getSize(), 0);
}

TEST(ThreeTest, Addition) {
    Three num1("12");
    Three num2("21");
    Three result = num1.plus(num2);
    EXPECT_EQ(result.tostr(), "110");
}

TEST(ThreeTest, Subtraction) {
    Three num1("210");
    Three num2("120");
    Three result = num1.minus(num2);
    EXPECT_EQ(result.tostr(), "20");
}

TEST(ThreeTest, Comparison) {
    Three num1("210");
    Three num2("120");
    
    EXPECT_TRUE(num1.bigger(num2));
    EXPECT_FALSE(num1.lower(num2));
    EXPECT_FALSE(num1.equal(num2));
}

TEST(ThreeTest, AddAndAssign) {
    Three num1("12");
    Three num2("21");
    Three result = num1.plus_assign(num2);
    EXPECT_EQ(result.tostr(), "110");
}

TEST(ThreeTest, SubtractAndAssign) {
    Three num1("210");
    Three num2("120");
    Three result = num1.minus_assign(num2);
    EXPECT_EQ(result.tostr(), "20");
}

TEST(ThreeTest, EdgeCases) {
    Three zero;
    EXPECT_TRUE(zero.iszero());

    Three big("222222");
    EXPECT_EQ(big.tostr(), "222222");
    
    Three num("121");
    Three result = num.minus(num);
    EXPECT_TRUE(result.iszero());
}

TEST(ThreeTest, ExceptionHandling) {
    EXPECT_THROW(Three(3, 5), std::invalid_argument);
    
    EXPECT_THROW(Three({1, 2, 5}), std::invalid_argument);
    
    EXPECT_THROW(Three("345"), std::invalid_argument);
    
    Three small("12");
    Three large("210");
    EXPECT_THROW(small.minus(large), std::invalid_argument);
}