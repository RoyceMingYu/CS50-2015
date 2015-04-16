/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

//define structure as nodes
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

//Creating hashtable
#define SIZE 1000000
node* hashtable[SIZE] = {NULL};
int hash (const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;
        
        // comma case
        else
            n = 27;
            
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}

//Variable to count dictionary size
int Size = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // creates a temp variable that stores a lower-cased version of the word
    char temp[LENGTH + 1];
    int len = strlen(word);
    for(int i = 0; i < len; i++)
    temp[i] = tolower(word[i]);
    temp[len] = '\0';
    
    // find what index of the array the word should be in
    int index = hash(temp);
    
    // if hashtable is empty at index, return false
    if (hashtable[index] == NULL)
    {
        return false;
    }
    
    // create cursor to compare to word
    node* cursor = hashtable[index];
    
    // if hashtable is not empty at index, iterate through words and compare
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    
    // if you don't find the word, return false
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //opens dictionary
    FILE* file = fopen(dictionary, "r");
    
    //creating an array for word storage
    char word[LENGTH+1];
    
    //load each word into hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        Size++;
        node* newWord = malloc(sizeof(node));
        strcpy(newWord->word, word);
        int index = hash(word);
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }      
    }
    
    // close file
    fclose(file);
    
    // return true if successful 
    return true;
    
    //return false if unsucessful
    if (file == NULL)
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    //Returns the number of words loaded
    if (Size > 0)
    {
        return Size;
    }
    else
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    while(hashtable[0] != NULL)
    {
        node* cursor = hashtable[0];
        hashtable[0] = cursor->next;
        free(cursor);
    }
    return true;
}
