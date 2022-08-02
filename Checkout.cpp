#include "Checkout.h"

#include <string>

using namespace std;

Checkout::Checkout() : total(0) {}

Checkout::~Checkout() {}

void Checkout::addItemPrice(string item, int price)
{
    prices[item] = price;
}

void Checkout::addItem(string item)
{
    map<string, int>::iterator priceIter = prices.find(item);
    if (priceIter == prices.end())
        throw std::invalid_argument("Invalid item. No price");
    items[item]++;
}

int Checkout::calculateTotal()
{
    total = 0;
    for (auto const &iter : items)
    {
        string item = iter.first;   // "a"
        int quantity = iter.second; // 5

        // After Discount: We bundle items together for discount
        int bundles = quantity / discounts[item].numItems;  // 1
        int pricePerBundle = discounts[item].discountPrice; // 25

        // Before Discount: Remaining items that couldn't form a bundle
        int remaining = quantity % discounts[item].numItems; // 2
        int pricePerItem = prices[item];                     // 10

        total += bundles * pricePerBundle + remaining * pricePerItem;
    }
    return total;
}

void Checkout::addDiscount(string item, int numItems, int discountPrice)
{
    Discount discount;
    discount.numItems = numItems;
    discount.discountPrice = discountPrice;
    discounts[item] = discount;
}
