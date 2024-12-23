#include <iostream>
#include <string>
using namespace std;

int main() 
{
    // this declares variables to store user input and calculated values
    string membershipPlan;
    string membershipType;
    string days;
    string facilities;
    string autopayBilling;
    string paperlessBilling;
    double amount, planCost;
    string errorMessage = "";

    // this gathers user input for gym membership details
    cout << "What kind of gym membership plan do you want to buy? ";
    getline(cin, membershipPlan);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "What type of gym membership do you want to buy? ";
    getline(cin, membershipType);

    cout << "Which days do you want to workout? ";
    getline(cin, days);

    cout << "Which facilities do you want to access? ";
    getline(cin, facilities);

    cout << "Are you on autopay? ";
    getline(cin, autopayBilling);

    cout << "Are you on paperless billing? ";
    getline(cin, paperlessBilling);

    // this checks for errors in user input
    if (membershipPlan != "Basic" && membershipPlan != "Executive") 
    {
        errorMessage = "Your kind of membership plan is not valid!";
    }
    else if (membershipType != "Adult" && membershipType != "Child" && membershipType != "Senior") 
    {
        errorMessage = "Your type of membership is not valid!";
    }
    else if (days != "Even" && days != "Odd" && days != "Everyday")
    {
        errorMessage = "Your membership days are not valid!";
    }
    else if (facilities != "Just One" && facilities != "Regional" && facilities != "National")
    {
        errorMessage = "Your facilities choice is not valid!";
    }
    else if (autopayBilling != "Yes" && autopayBilling != "No")
    {
        errorMessage = "Your autopay is not valid!";
    }
    else if (paperlessBilling != "Yes" && paperlessBilling != "No")
    {
        errorMessage = "Your paperless billing is not valid!";
    }

    // this prints the first occurring error message, if any
    if (!errorMessage.empty()) 
    {
        cout << errorMessage;
        return 1; // exit the program with an error code
    }

    // this processes the input and calculate the final cost if there are no errors
    if (membershipPlan == "Basic")
    {
        amount = 50;
        planCost = amount;
    }
    else if (membershipPlan == "Executive")
    {
        amount = 100;
        planCost = amount;
    }

    // this applies additional costs based on selected days and facilities
    if (days == "Everyday")
    {
        planCost += 25;
    }

    if (facilities == "Regional")
    {
        planCost += 30;
    }
    else if (facilities == "National")
    {
        planCost += 50;
    }

    // this adjusts the plan cost based on membership type
    if (membershipType == "Child")
    {
        planCost *= 0.5;
    }
    else if (membershipType == "Senior")
    {
        planCost *= 0.75;
    }

    // this applies discounts for autopay and paperless billing
    if (autopayBilling == "Yes")
    {
        planCost -= 2;
    }

    if (paperlessBilling == "Yes")
    {
        planCost -= 3;
    }

    // this displays the final gym membership cost to the user
    cout << "Your " << membershipPlan << " gym membership costs $" << planCost;

    return 0;
}
