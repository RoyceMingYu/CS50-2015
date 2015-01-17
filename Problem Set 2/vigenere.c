#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char token, int key);

int main(int argc, string argv[]) {

    // Variable declarations
    bool keySuccessful = false;
    string keyword = "";
    int keylength = 0;
    string usertext = "";
    int textlength;
    int keys = 0;

    do
    {
        if(argc != 2)
        {
            printf("Your keyword is not accepted, please enter a letter after './vigenere'.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    printf("Your input is not accepted.\n");
                    return 1;
                }
                else
                {
                    keySuccessful = true;
                    keyword = argv[1];
                }
            }
        }
    } while(!keySuccessful);
    
    keylength = strlen(keyword);
    int keycodes[keylength];

    for(int i = 0; i < keylength;i++)
    {
        keycodes[i] = toupper(keyword[i]) - 65;
    }

    usertext = GetString();
    textlength = strlen(usertext);

    for (int i = 0; i < textlength; i++)
    {
        if(!isalpha(usertext[i]))
        {
            printf("%c", usertext[i]);
        }
        else
        {
            printf("%c", caesar(usertext[i], keycodes[keys]));

            if(keys < keylength - 1)
            {
                keys++;
            }
            else
            {
                keys = 0;
            }
        }
    }
    printf("\n");
    return 0;
}

char caesar(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 97)+key)%26)+97);
    }
    else
    {
        return ((((token - 65)  +key)%26)+65);
    }
}
