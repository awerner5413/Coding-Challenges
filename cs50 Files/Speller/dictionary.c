// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int search(node *cursor, const char *word);
void clear(node *cursor);



// TODO: Choose number of buckets in hash table
const unsigned int N = 26364;
int s = 0;
int c = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash the word being checked and get it's location in the hash table
    c = 0;
    int i = hash(word);
    node *cursor = table[i];
    // go to the hash table and see if the word is there -  if so, true, if not, false
    if (search(cursor, word) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int l = 1;
    for (int i = 0; i < 3; i++)
    {
        if (word[i] == '\0')
        {
            break;
        }
        if (word[i] == 39)
        {
            l = l * 39;
        }
        else
        {
            l = (toupper(word[i]) - 64) * l;
        }
    }

    return l;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *temp_dictionary = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        printf("Cannot open dictionary!\n");
        return false;
    }

    // Loop through each word in the dictionary and scan it into a node until fscanf returns EOF
    char temp[LENGTH + 1];
    while (fscanf(temp_dictionary, "%s", temp) != EOF)
    {
        // allocate memory, check for errors, and create a node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory.\n");
            return false;
        }
        strcpy(n->word, temp);
        n->next = NULL;

        // place node into hash table
        int i = hash(temp);
        node *p = table[i];
        n->next = p;
        table[i] = n;
        s++;
    }

    // return true if successfully completing function
    fclose(temp_dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (s == 0)
    {
        return 0;
    }
    else
    {
        return s;
    }

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        if (cursor != NULL)
        {
            clear(cursor);
        }
    }
    return true;
}

int search(node *cursor, const char *word)
{
    // take int i as the location in the has table and compare each item in that location to the word)
    if (cursor == NULL)
    {
        return c;
    }

    if (strcasecmp(cursor->word, word) == 0)
    {
        c++;
        return c;
    }

    else
    {
        cursor = cursor->next;
        search(cursor, word);
    }

    // if function finishes without returning 1, then no match and return 0
    return c;
}

void clear(node *cursor)
{
    // set cursor equal to a temp pointer, move cursor down linked list, free temp
    node *temp = cursor;
    cursor = cursor->next;
    free(temp);

    // check if there is anything else in the linked list to free
    if (cursor == NULL)
    {
        return;
    }
    else
    {
        clear(cursor);
    }
}