/**
 * mario.c
 *
 * André Muta
 * andremuta@gmail.com
 *
 * Creates a mario's pyramid with hashes and spaces
 */
 
#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    int height;
    int hashes;
    int spaces;
    int totalchar;
    do
    {
        printf("height:");
        height = GetInt();
    }
    while ((height < 0) || (height > 23));
    
    for(int row = 0; row < height; row++)
    {
        totalchar = height + 1;
        spaces = height - 1 - row;
        hashes = totalchar - spaces;
        for(int countspaces = 0; countspaces < spaces; countspaces++)
        {
            printf(" ");
        }
        for(int counthashes = 0; counthashes < hashes; counthashes++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}    