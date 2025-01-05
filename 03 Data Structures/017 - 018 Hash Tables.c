/*
In this worksheet you will implement Hash Table.

Study:
Hash table (https://en.wikipedia.org/wiki/Hash_table).

Emphasize:
Hash function
Collision resolution (https://en.wikipedia.org/wiki/Hash_table#Collision_resolution)
Separate chaning (https://en.wikipedia.org/wiki/Hash_table#Separate_chaining)
Open addressing

Highlights:
Search for and study some well known hash functions for strings.
*/ 



/*
Exercise 17: HashInsert-SC
Insert a new element to the Hash based on a given key.
Please note:

The HashConstruct function is already implemented for you, and the Hash is initialized.
This Hash should be implemented using the Separate Chaining (https://en.wikipedia.org/wiki/Hash_table#Separate_chaining) option.
The hash table has size entries, each of which is an initialized Linked List.

Requirements:
Allocate memory for a new hash node.
Initialize the node with the key (using strcpy) and the data.
Compute the index for the new node based on the key using the Hash Function (specified in the Hash's control struct), modulo the hash table size.
Insert the new node into the list at the calculated index in the hash table.
Handle memory allocation failures and return ERROR or SUCCESS accordingly.
*/





//API hash.h

#pragma once

#include <stddef.h> /* size_t */

#include "status.h"
#include "list.h" /* only for Separate Chaining */

#define KEY_MAX_LEN 10

typedef struct
{
    char key[KEY_MAX_LEN+1];
    int value;
} hash_data_type;

typedef size_t(*hash_func_type)(const char*);

typedef struct Hash
{
#if defined (SEPARATE_CHAINING)
    list_type* table;
#elif defined (OPEN_ADDRESSING)
    hash_data_type* table;
#endif
    size_t size;
    hash_func_type hash_func;
} hash_type;


status_type HashInsert(hash_type* hash, const char* key, int data);
const hash_data_type* HashFind(const hash_type* hash, const char* key);





//function


#define SEPARATE_CHAINING
#include "hash.h"

typedef struct
{
    list_node_type link;
    hash_data_type data;
} hash_node_type;

/* ### Write your code below this line ### */


status_type HashInsert(hash_type* hash, const char* key, int data) {
    /* Allocate memory for new node */
    size_t index = 0;
    hash_node_type* new_node = NULL;
    
    new_node = (hash_node_type*)malloc(sizeof(hash_node_type));

    /* Check if memory allocation failed */
    if (new_node == NULL) {
        return ERROR;
    }
    
    /* Initialize the node's data */
    strcpy(new_node->data.key, key);
    new_node->data.value = data;
    
    /* Initialize list node pointers */
    new_node->link.next = NULL;
    new_node->link.prev = NULL;
    
    /* Compute hash index */
    index = hash->hash_func(key) % hash->size;
    
    /* Insert into appropriate linked list */
    ListInsert(&hash->table[index].head, &new_node->link);
    
    return SUCCESS;
}




/*
Exercise 18: HashFind-SC

Requirements:
Compute an index based on the key.
Use ListFind to locate the required node in the list at the calculated index in the hash table.
Return the address of the node's data if the node was found, or NULL otherwise.
Implement the helper function listed below.

Constraints:
KeysEqual: The function is given a Linked List node and a key (as a C string), and should return 1 (true) if the node's data key matches the given key (using strcmp), or 0 (false) otherwise.
*/


/* Main HashFind function */
const hash_data_type* HashFind(const hash_type* hash, const char* key) {
    hash_node_type* found_node= NULL;
    /* Compute hash index */
    size_t index = hash->hash_func(key) % hash->size;
    
    /* Find the node with matching key in the list */
    found_node = (hash_node_type*)ListFind(&hash->table[index], KeysEqual, key);
    
    /* If node was found, return its data */
    if (found_node != NULL) {
        return &found_node->data;
    }
    
    /* Node not found */
    return NULL;
}







