#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

//prototype
int hash(char* key);

//initiate struct node
typedef struct node
    {
        char word[46];
        struct node* next;
    } node;
    
//initialize hashtable
node* hashtable[SIZE];


int main(void)
{
    FILE* fp = fopen("dictionaries/small", "r");
    
    while(!feof(fp))
    {
        node* new_node = malloc(sizeof(node));
        node* pointer = malloc(sizeof(node));
        
        fscanf(fp, "%s", new_node->word);
        
        int hashIndex = hash(new_node->word);
        
        char wd[5] = "this";
        
        int test = hash(wd);
        
        printf("%i\n", test);
      
        if(hashtable[hashIndex] == NULL)
        {
            hashtable[hashIndex] = new_node;
            new_node->next = NULL;
            pointer = new_node;
        } else {
            new_node->next = hashtable[hashIndex];
            pointer = new_node;
        }
    }
    node* cursor = malloc(sizeof(node));
    
    char wd[5] = "this";
    
    int ind = hash(wd);
    
    cursor = hashtable[ind];
    
    while(cursor != NULL)
    {
        if (strcmp(cursor->word, "this") == 0)
        {
            printf("si");
            return 0;
        } else{
            printf("not found");
            return 0;
        }
    }
    
}

int hash(char* key)
    {
        int counter = 0;
        for(int i = 0; i < strlen(key); i++)
        {
            counter += key[i];
        }
        return counter % SIZE;
    }