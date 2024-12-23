#include <iostream>
#include <string>
#include <cassert>
#include "Header.h"

using namespace std; 

int main()
{
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" }; 
    assert( hasNoDuplicates( a, 3 ) == true );  
    assert( hasNoDuplicates( a, 6 ) == false );	    
    cerr << "All tests succeeded" << endl;
    return( 0 );
}