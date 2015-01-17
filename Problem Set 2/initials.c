#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //Prompts user for name and makes the first letter capital
    string name = GetString();
    printf("%c", toupper(name[0]));
    //loops the previous command
    for ( int i = 0, n = strlen(name); i < n; i++)
    {
        if ( name[i] == ' ' && name[i + 1] != '\0') 
        {
            printf("%c",toupper(name[i + 1])); 
            i++;
        }
       
    }
    //neatness purposes, I'm a neatomaniac :)
    printf("\n");
    return 0;
}
