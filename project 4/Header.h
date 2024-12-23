#include <iostream>
#include <string>
#include <cassert>

using namespace std;  

int locateMinimum( const string array[ ], int n );
int findLastOccurrence( const string array[ ], int n, string target );
int flipAround( string array[ ], int n );
bool hasNoDuplicates( const string array[ ], int  n );
void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize );
int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties );
bool isInIncreasingOrder( const string array[ ], int  n );