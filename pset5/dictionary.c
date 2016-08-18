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
#include <string.h>
#include <strings.h>
#include <ctype.h>

//prototype hash function
int hash(const char* key);

//initiate struct node
typedef struct node
    {
        char word[LENGTH + 1];
        struct node* next;
    } node;
    
//initialize hashtable
node* hashtable[HASHSIZE];

//count dictionary words to return in size function
int wordCount = -1;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
  char newWord[LENGTH + 1];
  
  strcpy(newWord, word);
  
  for(int i = 0; word[i]; i++)
  {
      newWord[i] = tolower(newWord[i]);
  }
    
  node* cursor = malloc(sizeof(node));
  
  int hashIndex = hash(newWord);
  
  cursor = hashtable[hashIndex];
  
  while(cursor != NULL)
  {
    if(strcmp(cursor->word, newWord) == 0)
    {
        return true;
    }
    cursor = cursor->next;
  }
  return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    
    //open file in read mode and error check if it's null
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("error loading dict");
        return 1;
    }
    
    //get words in dictionary one by one
    while(!feof(fp))
    {
        //malloc memory for new_node and head
        node* new_node = malloc(sizeof(node));
        node* head = malloc(sizeof(node));
       
        //based on word length, saving to variable newWord
        fscanf(fp, "%s", new_node->word);
       
        //set hashIndex to results of hash function
        int hashIndex = hash(new_node->word);
        
        //if hashtable at index hashIndex is null, set it to newWord and set pointer to point at it (i.e. first slot)
        if(hashtable[hashIndex] == NULL)
        {
            hashtable[hashIndex] = new_node;
            new_node->next = NULL;
            head = new_node;
            wordCount++;
        } else {
            new_node->next = hashtable[hashIndex];
            head = new_node;
            hashtable[hashIndex] = new_node;
            wordCount++;
        }
       
    }
    if(feof(fp)){
        fclose(fp);
        return true;
    }

    return false;
    fclose(fp);
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
    for (int i = 0; i < 101; i++)
    {
        node* cursor = hashtable[i];
        
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        return true;
    }
    
    return false;
}

int hash(const char* key)
{
    //int keyLength = strlen(key);
    int counter = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        counter += key[i];
    }
    return counter % HASHSIZE;
}