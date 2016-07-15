/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return(true);
        }       
    }
    return(false);
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 1, d; i < n; i++)
    {
        if(values[i-1] > values[i])
        {
            d = values[i-1];
            values[i-1] = values[i];
            values[i] = d;
            sort(values, n);
        }
        else
        {
            return;
        }  
    }
    
    
    return;
}
