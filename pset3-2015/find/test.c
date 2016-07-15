#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int values[], int n);


int main(void)
{
  int myArray[] = {3,2,1};
  sort(myArray, 3);
  for(int z = 0; z < 3; z++)
    printf("%i\n", myArray[z]);
}

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
