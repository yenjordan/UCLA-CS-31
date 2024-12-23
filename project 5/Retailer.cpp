#include "Retailer.h"

// this constructor initializes the Retailer with a name
Retailer::Retailer(std::string name) {
    // this assigns the name directly to mName
    mName = name;
}

// this getter function retrieves the retailer name
std::string Retailer::getName() const {
    return mName;
}

// this is a method to allow a single GiftCard to purchase an item of a certain cost
bool Retailer::purchaseItem(std::string item, double cost, GiftCard& card) {
    // this checks if the retailer name matches the retailer of the GiftCard and if the card has sufficient funds for the purchase
    if (mName != card.getRetailer() || !card.canBeUsedToPurchase(cost))
        return false;

    // this deducts the cost from the GiftCard's amount
    card.setAmount(card.getAmount() - cost);
    return true;
}

// this is a method to allow two GiftCards to collectively purchase an item of a certain cost
bool Retailer::purchaseItem(std::string item, double cost, GiftCard& card1, GiftCard& card2) {
    // this checks if the retailer names match the retailer of both GiftCards and if the cost is positive
    if (mName != card1.getRetailer() || mName != card2.getRetailer() || cost <= 0.0)
        return false;

    // this calculates the total amount across both GiftCards
    double totalAmount = card1.getAmount() + card2.getAmount();

    // if the total amount is less than the cost, the purchase cannot be completed
    if (totalAmount < cost)
        return false;

    // this deducts the cost from one or both GiftCards, ensuring both are used optimally
    if (card1.getAmount() >= cost) {
        card1.setAmount(card1.getAmount() - cost);
        card2.setAmount(card2.getAmount());
    } else {
        card2.setAmount(card2.getAmount() - (cost - card1.getAmount()));
        card1.setAmount(0.0);
    }
    return true;
}

// this is a method to allow returning an item and adding the refunded amount to the GiftCard
bool Retailer::returnItem(std::string item, double cost, GiftCard& card) {
    // this checks if the retailer name matches the retailer of the GiftCard and if the cost is positive
    if (mName != card.getRetailer() || cost <= 0.0)
        return false;

    // this adds the refunded amount to the GiftCard's amount
    card.setAmount(card.getAmount() + cost);
    return true;
}
