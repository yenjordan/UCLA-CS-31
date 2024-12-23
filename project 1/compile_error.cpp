//
//  Code for Project 1
//  Holiday Gifts!

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Holiday Gifting
   int giftCount = 0;
   int regiftedCount  = 0;

   cout << "This Holiday Season, how many gifts did you receive?";
   cin  >> giftCount;
   cout << "and how many of those gifts did you re-gift to others?";
   cin  >> regiftedCount;

   if (regiftedCount == 0)
   {
      cout << "Looks like you kept all your gifts!  Happy Holidays!";
      cout << endl;
   }
   else
   {
      cout << "Enjoy your remaining ";
      cout << countGift - regiftedCount;
      cout << " gifts!  Happy Holidays!";
      cout << endl;
   } 

   if (giftCount < 0 || regiftedCount > giftCount)
   {
      cout < "Something looks awry with the numbers...";
      cout << endl;
   }

   return( 0 );
}