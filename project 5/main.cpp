#include <iostream>
#include <string>
#include <cassert>
#include "GiftCard.h"
#include "Retailer.h"

using namespace std;

	int main()
	{
          // sample test code working with GiftCard and Retailer
         GiftCard card( "Amazon", 100.00 );
         Retailer r( "Apple Store" );
         assert( std::to_string( card.getAmount() ) == "100.000000" );
         assert( card.getRetailer() == "Amazon" );
         assert( card.isEmpty() == false );
         assert( card.canBeUsedToPurchase( 200.00 ) == false );
         assert( card.canBeUsedToPurchase( 10.00 ) );
         card.empty();
         assert( card.canBeUsedToPurchase( 10.00 ) == false ); 

         card.setAmount( 100.00 );
         assert( r.getName() == "Apple Store" );
         assert( r.purchaseItem( "Air Tags", 49.00, card ) == false );
         assert( r.returnItem( "Apple Pencil", 99.00, card ) == false );
         GiftCard card1( "Apple Store", 100.00 );
         GiftCard card2( "Apple Store", 100.00 );

         assert( r.purchaseItem( "Air Pods", 99.00, card1 ) == true );
         assert( std::to_string( card1.getAmount() ) == "1.000000" );
         assert( r.returnItem( "Air Pods", 99.00, card1 ) == true );
         assert( std::to_string( card1.getAmount() ) == "100.000000" );
         assert( r.purchaseItem( "Apple Watch", 189.00, card1, card2 ) == true );
         assert( card1.isEmpty( ) );
         assert( std::to_string( card2.getAmount() ) == "11.000000" );

         cout << "all tests passed!" << endl; 
         return( 0 ); 
    }
 


