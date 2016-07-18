#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
void swap(int* a, int* b);
void sort(int values[], int n);
void mergeSort(int values[], int n);
void merge(int left[], int right[], int values[], int n, int mln, int rln);

// Maximum value of int
const int MAX = 65536;

int main(int argc, string argv[])
{
    // list to sort
    int size;
    int haystack[MAX];
    printf("Please, input numbers:");
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("Thanks for the input.\nSorting...\n");
    mergeSort(haystack, size);
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\n", haystack[i]);
    }
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
 * Merge sort C implementation
 */
void mergeSort(int values[], int n)
{
    if(n < 2)
    {
        return;
    }
    else
    {
        int ln = n / 2;
        int rn = n / 2;
        bool f = n % 2;
        if(f)
        {
            ln = (n + 1) / 2;
            rn = (n - 1) / 2;
        }
        int *leftHalf = values;
        int *rightHalf = values + rn;
        mergeSort(leftHalf, ln);
        mergeSort(rightHalf, rn);
        //Now merge
        merge(leftHalf, rightHalf, values, n, ln, rn);
    }
}

/**
 * Swap two values in the address
 */

void merge(int left[], int right[], int values[], int n, int mln, int mrn)
{
    int *all = malloc(n * sizeof(int));

    int li = 0;
    int ri = 0;
    for(int i = 0; i < n; i++)
    {
        int leftnum = *(left + li);
        int rightnum = *(right + ri);
        if((leftnum < rightnum && (li < mln)) || mrn == ri)
        {
            *(all + i) = leftnum;
            li += 1;
        } 
        else
        {
            *(all + i) = rightnum;
            ri += 1;
        }
    }
    memcpy(values, all, (n * sizeof(int)));
}