#include <stdio.h>

int main(void)
{
    int values[6] = {1,2,3,4,5,6};
    int *fh = values;
    int *sh = values + 3;
    
    printf("Left half is %i\n",(*fh + 4));
    printf("Right half is %i\n",*sh);
}