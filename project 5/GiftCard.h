#ifndef GIFTCARD_H
#define GIFTCARD_H

#include <string>

// this is the declaration of the GiftCard class
class GiftCard {
public:
    // this is the constructor to initialize the GiftCard with a retailer name and an initial amount
    GiftCard(std::string retailer, double amount);

    // this getter function retrieves the retailer name
    std::string getRetailer() const;

    // this getter function retrieves the remaining amount on the GiftCard
    double getAmount() const;

    // this setter function updates the amount on the GiftCard
    void setAmount(double amount);

    // this is a method to set the amount on the GiftCard to zero, effectively emptying it
    void empty();

    // this is a method to check if the GiftCard is empty (i.e., has zero remaining amount)
    bool isEmpty() const;

    // this is a method to check if the GiftCard can be used to make a purchase of a certain amount
    bool canBeUsedToPurchase(double amount) const;

private:
    // these private member variables store the retailer name and the amount on the GiftCard
    std::string mRetailer;
    double mAmount;
};

#endif // GIFTCARD_H
