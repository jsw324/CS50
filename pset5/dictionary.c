/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

//prototype hash function
int hash(char* key);

//count dictionary words to return in size function
 int wordCount = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
   // char word[LENGTH + 1];
   
    
    typedef struct node
    {
        char *word;
        struct node* next;
    } node;
    
    char* hashtable[HASHSIZE];
    
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("error loading dict");
        return 1;
    }
    
    //initialize newWord
    
    char* newWord = NULL;
    
    //get words in dictionary one by one
    while(fscanf(fp, "%s\n", newWord) != EOF);
    {
        int wordLength = 0;
        while(newWord[wordLength] != '\0')
        {
            wordLength++;
        }
        
       
        
        fgets(newWord, wordLength, fp);
        
        node* new_node = malloc(sizeof(node));
        node* head = malloc(sizeof(node));
        wordCount++;
        
        new_node->word = newWord;
        new_node->next = NULL;
       
        int hashIndex = hash(newWord);
        
        if(hashtable[hashIndex] == NULL)
        {
            hashtable[hashIndex] = newWord;
            new_node->word = newWord;
            head->next = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
       
    }

    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}

int hash(char* key)
{
    //int keyLength = strlen(key);
    int counter = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        counter += key[i];
    }
    return counter % HASHSIZE;
}