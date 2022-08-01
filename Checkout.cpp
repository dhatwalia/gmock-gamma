#include "Checkout.h"

Checkout::Checkout() : total(0) {}

Checkout::~Checkout() {}

void Checkout::addItemPrice(std::string item, int price)
{
    prices[item] = price;
}

void Checkout::addItem(std::string item)
{
    total += prices[item];
}

int Checkout::calculateTotal()
{
    return total;
}
