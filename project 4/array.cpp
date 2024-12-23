#include <iostream>
#include <string>
#include <cassert>
#include "Header.h"

using namespace std;

int locateMinimum( const string array[ ], int n )
{
    int minimum = 0; // Initialize the index of the minimum value to the first element

    if (n <= 0)
    {
        return -1; // If the array is empty or has negative size, return -1 (invalid input)
    }
    else
    {
        for (int i = 0; i < n; i++) // Iterate through the array to find the minimum value
        {
            if (array[i] < array[minimum]) // Compare the current element with the element at the current minimum index
            {
                minimum = i; // If the current element is smaller, update the minimum index
            }
        }
    }
    return minimum;
}


int findLastOccurrence( const string array[ ], int n, string target )
{
    int largest = -1; // Initialize the index of the last occurrence to an invalid value

    if (n <= 0)
    {
        return -1; // If the array is empty or has negative size, return -1 (invalid input)
    }

    else
    {
        for (int i = 0; i < n; i++) // Iterate through the array to find the last occurrence of the target
        {
            if (array[i] == target)
            {
                largest = i; // If the current element matches the target, update the last occurrence index
            }
        }
    }
    return largest;
}


int flipAround( string array[ ], int n )
{
    int total = 0; // Initialize the total number of swaps to zero

    if (n <= 0)
    {
        return -1; // If the array is empty or has negative size, return -1 (invalid input)
    }
    else
    {
        for (int i = 0; i < (n / 2); i++) // Iterate through the first half of the array (up to n/2)
        {
            if (i != n - i - 1)
            {
                // Swap the elements at indices i and n-i-1
                string temp = array[i];
                array[i] = array[n - i - 1];
                array[n - i - 1] = temp;
                total++;
            }
        }
    }
    return total;
}


bool hasNoDuplicates( const string array[ ], int  n )
{
    if (n < 0)
    {
        return false; // If the array size is negative, return false (no duplicates in an empty array)
    }
    else
    {
        for (int i = 0; i < n; i++) // Iterate through each element in the array
        {
            for (int j = 0; j < n; j++) // Compare the current element with all other elements
            {
                if (array[i] == array[j] && i != j) // If the elements are equal and not at the same index, we found a duplicate
                {
                    return false; // Array contains duplicates
                }
            }
        }
        return true; // No duplicates found, return true
    }
}


void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize )
{
    if (n1 <= 0 || n2 <= 0)
    {
        resultingSize = -1; // If either array size is non-positive, set resultingSize to -1 (invalid input)
    }
    else
    {
        resultingSize = 0; // Initialize resultingSize to 0
        
        for (int i = 0; i < n1; i++) // Process elements from array1
        {
            bool located = false; // Flag to track if the element is already in resultingString
            
            for (int j = 0; j < resultingSize; j++) // Check if the current element exists in resultingString
            {
                if (resultingString[j] == array1[i])
                {
                    located = true; // Element found, mark as located
                }
            }
            if (!located) 
            {
                resultingString[resultingSize++] = array1[i]; // If not located, add the element to resultingString
            }
        }
        for (int k = 0; k < n2; k++) // Process elements from array2 (similar logic as above)
        {
            bool located = false;

            for (int l = 0; l < resultingSize; l++)
            {
                if (resultingString[l] == array2[k])
                {
                    located = true;
                }
            }
            if (!located)
            {
                resultingString[resultingSize++] = array2[k];
            }
        }
    }
}


int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties) 
{
    if (n < 0 || amount > n) 
    {
        return -1; // Invalid input: array size is negative or amount exceeds array size
    } 
    else if (amount == 0) 
    {
        return n; // No shift needed, return original array size
    } 
    else if (amount < 0) 
    {
        return 0; // Invalid input: negative shift amount
    }
    
    for (int i = n - 1; i >= amount; i--) // Shift elements to the right by 'amount' positions
    {
        array[i] = array[i - amount]; // Move element i - 'amount' positions to the right
    }

    for (int i = 0; i < amount; i++) // Fill the empty positions at the beginning with the specified placeholder
    {
        array[i] = placeholderToFillEmpties;
    }

    return n - amount; // Return the new array size after shifting
}


bool isInIncreasingOrder( const string array[ ], int  n )
{
    if (n < 0)
    {
        return false; // Check for invalid input: negative array size
    }
    else if (n == 0 || n == 1)
    {
        return true; // If the array is empty or has only one element, it is considered in increasing order
    }
    else
    {
        for (int i = 1; i < n; i++) // Iterate through the array starting from the second element
        {
            if (array[i] <= array[i - 1]) // Compare the current element with the previous element
            {
                return false; // If the current element is less than or equal to the previous element, it's not in increasing order
            }
        }
        return true; // If all elements are in increasing order, return true
    }
}