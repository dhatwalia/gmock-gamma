#include "../Checkout.h"

#include <gtest/gtest.h>

class CheckoutTests : public ::testing::Test
{
public:
protected:
    Checkout checkout;
};

TEST_F(CheckoutTests, CanCalculateTotal)
{
    checkout.addItemPrice("a", 1);
    checkout.addItem("a");
    int total = checkout.calculateTotal();
    ASSERT_EQ(1, total);
}

TEST_F(CheckoutTests, CanGetTotalForMultipleItems)
{
    checkout.addItemPrice("a", 1);
    checkout.addItemPrice("b", 2);
    checkout.addItem("a");
    checkout.addItem("b");
    int total = checkout.calculateTotal();
    ASSERT_EQ(3, total);
}

TEST_F(CheckoutTests, CanAddDiscount)
{
    checkout.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalculateTotalWithDiscount)
{
    checkout.addItemPrice("a", 10);
    checkout.addDiscount("a", 3, 25);
    checkout.addItem("a");
    checkout.addItem("a");
    checkout.addItem("a");
    checkout.addItem("a");
    checkout.addItem("a");
    int total = checkout.calculateTotal();
    ASSERT_EQ(45, total);
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException)
{
    ASSERT_THROW(checkout.addItem("a"), std::invalid_argument);
}
