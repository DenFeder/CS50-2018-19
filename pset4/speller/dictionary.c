// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 456976

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

unsigned int dictionary_size = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    int hash = 0;
    for (int i =  0; i <= strlen(word); i++)
    {
        hash = (31 * hash + tolower(word[i]))  % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO

        // creates a new note and checks if enough memory is available
        node *new_node = malloc (sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node->word, word);
            dictionary_size++ ;
        }
        // hashing new node
        int node_hash = hash(new_node->word);
        
        // inserting new node into hashed linked list
        new_node->next = hashtable[node_hash];
        hashtable[node_hash] = new_node;
    
        /* returning dictionary
        if(hashtable[node_hash] != NULL)
        {
            printf("Dictionary contains:\n");
            for (node *ptr = new_node; ptr != NULL; ptr = ptr->next)
            {
                printf("%s\n", ptr->word);
            }
        } */
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionary_size;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int word_hash = hash(word);
    node *cursor = hashtable[word_hash];
    
    while (cursor != NULL)
    {
        char *check_word = cursor->word;
        
        if (strcasecmp(check_word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    
    // Slower version
    /*for (node *cursor = hashtable[hash(word)]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp (cursor->word, word) == 0)
        {
            return true;
        }
    } */
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    bool done = false;
    
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free (temp);
        }
        hashtable[i] = NULL;
        
        /* Printing each pos in array to check content
        
        printf("Hashtable position %i contains: %s\n", i, hashtable[i]->word);
        */
        
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
        return false;
}
