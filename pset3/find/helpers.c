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
    for(int i = 0; i < n; i++)
    {
        if(value == values[i])
        {
            return true;
        }
    }
    return false;
}

/**
 * Swap two values 
 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n; i++)
    {
        int min = i;
        // Find the minimum value
        for(int j = i; j < n; j++)
        {
            if(values[j] < values[min])
            {
                min = j;
            }
        }
        // Swap the minimum value to its place
        swap(&values[min], &values[i]);
    }
    return;
}
