#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// Prototypes
void swap(int* a, int* b);
void sort(int values[], int n);

// Maximum value of int
const int MAX = 65536;

int main(int argc, string argv[])
{
    // list to sort
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nnumber[%i] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    sort(haystack, size);
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