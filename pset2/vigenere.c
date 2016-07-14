/**
 * devigenere.c
 *
 * André Muta
 * andremuta@gmail.com
 *
 * encrypt given text with the choosen keyword
 *using the vigenere cipher
 */
 
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[])
{
    
    if (argc > 2 || argc < 2)
    {
        printf("The root must be only one string\n");
        return(1);
    }
    
    char* keyword = argv[1];
    char* text;
    int base;
    int keylen = strlen(keyword);
    int keyx = 0;
    int root;
    int point;
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("The keyword is not entirely composed of alphabet char\n");
            return(1);
        }
    }
    
    do
    {
        text = GetString();
    }
    while (text == NULL);
    
    for (int i = 0; i < strlen(text); i++)
    {
 
        if (keyword[keyx] > 64 && keyword[keyx] < 91)
        {
            base = 65;
        }   
        else
        {
            base = 97;
        }
        root = keyword[keyx] - base;
        if (text[i] > 64 && text[i] < 91)
        {
 
            point = (((text[i] - 65) + root) % 26) + 65;
            printf("%c", point);
            keyx = ((keyx + 1) % keylen);
            
            
        }
        else if (text[i] > 96 && text[i] < 123)
        {
            point = (((text[i] - 97) + root) % 26) + 97;
            printf("%c", point);   
            keyx = ((keyx + 1) % keylen);   
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}