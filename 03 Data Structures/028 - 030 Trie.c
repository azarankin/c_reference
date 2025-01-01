/*
In this worksheet you will implement Trie.

Study:
Trie(https://en.wikipedia.org/wiki/Trie).
*/



/*
Exercise 18: TrieInsert

Insert a word (arbitrary sequnce of letters) into the Trie data structure.


Requirements:
Select letters from word sequentially and navigate through the Trie as long as a child node is present.
Insert the remaining letters in the Trie, by allocating memory for nodes (use calloc).
Set is_terminalI to one (true) in the last node to indicate end of word.
Handle memory allocation failures and return ERROR or SUCCESS accordingly.
Implement the helper functions listed below.

Constraints:
Char2Index: Converts a letter to uppercase and computes the index for the letter.
Crawl: Recursively, navigates the Trie by calculating indexes from the given word's letters as long as a child node is present, updates the string pointer pointed to by word and returns the last node found.
InsertHelper: Recursively, allocates memory for new nodes while handling memory allocation failures, and inserts the nodes at the appropriate indexes into the children array of the parent node.
*/



//API trie.h
#pragma once

#include "status.h"

#define ALPHABET_SIZE ('Z' - 'A' + 1)

/* single node */
typedef struct TrieNode trie_node_type;

struct TrieNode
{
    int is_terminal;
    trie_node_type* children[ALPHABET_SIZE];
};

/* Trie control struct */
typedef struct Trie
{
    trie_node_type* root;
} trie_type;

status_type TrieInsert(trie_type* trie, const char* word);
int TrieContains(trie_type* trie, const char* word);



// function
#include "trie.h"

static int Char2Index(char c) { return ((c & 0x5f) - 'A'); }

/*
static trie_node_type* Crawl(trie_node_type* node, const char** word)
static trie_node_type* InsertHelper(trie_node_type* node, const char* word)
*/

/* ### Write your code below this line ### */

#include "status.h"
#include <stdlib.h>


static trie_node_type* Crawl(trie_node_type* node, const char** word)
{
    trie_node_type* iter;

    if ((*word)[0] == '\0' || (iter = node->children[ Char2Index((*word)[0]) ]) == NULL)
        return node;

    (*word)++;
    return Crawl(iter, word);
}

static trie_node_type* InsertHelper(trie_node_type* node, const char* word)
{
    trie_node_type* new_node = NULL;

    if (word[0] == '\0')
        return node;

    new_node = calloc(1, sizeof(*node));
    if (new_node == NULL)
        return NULL;

    node->children[ Char2Index(word[0]) ] = new_node;

    return InsertHelper(new_node, ++word);
}

status_type TrieInsert(trie_type* trie, const char* word)
{
    trie_node_type* node = Crawl(trie->root, &word);

    if (word[0] != '\0')
    {
        node = InsertHelper(node, word);
    }

    if (node == NULL)
        return ERROR;

    node->is_terminal = 1;
    return SUCCESS;
}




/*
Exercise 18: TrieContains

Return 1 (true) or 0 (false) if a word is found or not in the Trie, respectively.


Requirements:
Select letters from word sequentially and navigate through the Trie as long as a child node is present.
If all the word's letters were found in the Trie and is_terminal in the last node is true, return 1 (true); otherwise, return 0 (false).

Constraints:
Use the function Crawl that you have implemented previously.
*/


status_type TrieInsert(trie_type* trie, const char* word)
{
    trie_node_type* node = Crawl(trie->root, &word);
    
    if (word[0] != '\0')
    {
        node = InsertHelper(node, word);
    }
    
    if (node == NULL)
    {
        return ERROR;
    }
    
    node->is_terminal = 1;
    
    return SUCCESS;
}

int TrieContains(trie_type* trie, const char* word)
{
    trie_node_type* node = Crawl(trie->root, &word);
    
    return (word[0] == '\0' && node->is_terminal);
}


// anther version


int TrieContains1(trie_type* trie, const char* word) {
    const char* remaining;
    trie_node_type* node;
    int index;
    
    /* Validate input parameters */
    if (trie == NULL || word == NULL || trie->root == NULL) {
        return 0;
    }

    /* Use Crawl to navigate through the word */
    remaining = word;
    node = Crawl(trie->root, &remaining);
    
    /* If Crawl stopped before end of word, word not in trie */
    if (*remaining != '\0') {
        return 0;
    }
    
    /* Navigate to final node */
    node = trie->root;
    while (*word != '\0') {
        index = Char2Index(*word);
        node = node->children[index];
        word++;
    }
    
    /* Return 1 only if node is terminal */
    return node->is_terminal;
}














