#ifndef RETAILER_H
#define RETAILER_H

#include <string>
#include "GiftCard.h"

// this is the declaration of the Retailer class
class Retailer {
public:
    // this constructor initializes the Retailer with a name
    Retailer(std::string name);

    // this getter function retrieves the retailer name
    std::string getName() const;

    // this is a method to allow a single GiftCard to purchase an item of a certain cost
    bool purchaseItem(std::string item, double cost, GiftCard& card);

    // this is a method to allow two GiftCards to collectively purchase an item of a certain cost
    bool purchaseItem(std::string item, double cost, GiftCard& card1, GiftCard& card2);

    // this is a method to allow returning an item and adding the refunded amount to the GiftCard
    bool returnItem(std::string item, double cost, GiftCard& card);

private:
    // this private member variable stores the retailer name
    std::string mName;
};

#endif // RETAILER_H
