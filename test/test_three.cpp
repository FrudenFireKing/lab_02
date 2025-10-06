#include <gtest/gtest.h>
#include "three.h"

TEST(ThreeTest, ConstructorFromString) {
    Three num("120");
    EXPECT_EQ(num.toString(), "120");
}

TEST(ThreeTest, Addition) {
    Three a("12");
    Three b("10");
    Three result = a.add(b);
    EXPECT_EQ(result.toString(), "22");
}

TEST(ThreeTest, Subtraction) {
    Three a("21");
    Three b("10");
    Three result = a.subtract(b);
    EXPECT_EQ(result.toString(), "11");
}

TEST(ThreeTest, Comparison) {
    Three a("20");
    Three b("10");
    EXPECT_TRUE(a.greaterThan(b));
    EXPECT_FALSE(a.lessThan(b));
    EXPECT_FALSE(a.equals(b));
}

TEST(ThreeTest, Immutability) {
    Three original("120");
    Three copy = original;
    Three newNum("210");
    
    EXPECT_EQ(original.toString(), "120");
    EXPECT_EQ(copy.toString(), "120");
    EXPECT_FALSE(original.equals(newNum));
}