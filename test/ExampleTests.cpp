#include "../Example.hpp"
#include "../Example.cpp"

#include <gtest/gtest.h>

struct ExampleTests : public ::testing::Test
{
    int *x;

    int GetX()
    {
        return *x;
    }

    virtual void SetUp() override
    {
        x = new int(42);
    }

    virtual void TearDown() override
    {
        delete x;
    }
};

TEST_F(ExampleTests, MAC)
{
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + GetX() * y;
    EXPECT_EQ(
        expectedNewSum,
        MAC(GetX(), y, sum));
    EXPECT_EQ(
        expectedNewSum,
        sum);
}

TEST_F(ExampleTests, Square)
{
    int expectedSquare = GetX() * GetX();
    EXPECT_EQ(
        expectedSquare,
        Square(GetX()));
}
