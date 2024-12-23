#include "GiftCard.h"

// this constructor initializes the GiftCard with a retailer name and an initial amount
GiftCard::GiftCard(std::string retailer, double amount) {
    // this assigns the retailer name directly to mRetailer
    mRetailer = retailer;
    // this sets the initial amount
    mAmount = amount;
}

// this getter function retrieves the retailer name
std::string GiftCard::getRetailer() const {
    return mRetailer;
}

// this getter function retrieves the remaining amount on the GiftCard
double GiftCard::getAmount() const {
    return mAmount;
}

// this setter function updates the amount on the GiftCard
void GiftCard::setAmount(double amount) {
    mAmount = amount;
}

// this is a method to set the amount on the GiftCard to zero, effectively emptying it
void GiftCard::empty() {
    mAmount = 0.0;
}

// this is a method to check if the GiftCard is empty (i.e., has zero remaining amount)
bool GiftCard::isEmpty() const {
    return mAmount <= 0.0;
}

// this is a method to check if the GiftCard can be used to make a purchase of a certain amount
bool GiftCard::canBeUsedToPurchase(double amount) const {
    // this checks if the requested amount is positive and does not exceed the remaining amount on the GiftCard
    return amount > 0.0 && amount <= mAmount;
}
