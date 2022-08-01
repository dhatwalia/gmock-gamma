#ifndef CHECKOUT_HPP
#define CHECKOUT_HPP

#include <string>
#include <map>

using namespace std;

class Checkout
{
public:
    Checkout();
    virtual ~Checkout();

    void addItemPrice(string item, int price);
    void addItem(string item);
    int calculateTotal();
    void addDiscount(string item, int numItems, int discountPrice);

protected:
    struct Discount
    {
        int numItems;
        int discountPrice;
    };

    map<string, int> prices;
    map<string, int> items;
    map<string, Discount> discounts;
    int total;
};

#endif /* CHECKOUT_HPP */
