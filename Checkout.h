#ifndef CHECKOUT_HPP
#define CHECKOUT_HPP

#include <string>
#include <map>

class Checkout
{
public:
    Checkout();
    virtual ~Checkout();

    void addItemPrice(std::string item, int price);
    void addItem(std::string item);
    int calculateTotal();

protected:
    std::map<std::string, int> prices;
    int total;
};

#endif /* CHECKOUT_HPP */
