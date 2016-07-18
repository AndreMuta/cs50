#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// Prototypes
void swap(int* a, int* b)

/**
 * Merge sort C implementation
 */
void mergeSort(int values[], n)
{
    if(n < 2)
    {
        return values[0];
    }
    if(!(n % 2))
    {
        int ln = (n + 1) / 2;
        int rn = (n - 1) / 2;
    }
    int *leftHalf = values;
    int *rightHalf = values + rn;
    mergeSort(leftHalf, ln);
    mergeSort(rightHalf, rn);
    //Now merge
    
}


/**
 * Swap two values in the address
 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void merge(int left[], int right[], values[], n)
{
    int *all = malloc(sizeof(values));

    int li = 0;
    int ri = 0;
    for(i = 0; i < n; i++)
    {
        if((left+li) < (right+ri))
        {
            *(all + i) = (left + li);
            li += 1;
        } 
        else 
        {
            *(all + i) = (right + ri);
            ri += 1;
        }
    }
    memcpy(values, all, sizeof(values));
}