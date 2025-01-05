/*
Exercise 18: HashInsert-OA

Insert a new element to the Hash based on a given key.

Please note:

The HashConstruct function is already implemented for you, and the Hash is initialized.
This Hash should be implemented using the Open Addressing option.
The hash table contains size entries of initialized hash data objects.
An empty hash data entry is identified when the key value is an empty string.

Requirements:
Compute an index based on the given key.
Beginning with the calculated index iterate through the hash table until an empty entry is found, or all entries are occupied.
Initialize the found entry with the key and the data.
Return SUCCESS if an empty entry was found, or ERROR otherwise.
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

#define OPEN_ADDRESSING
#include "hash.h"
#include <string.h>  /* For strcpy */

status_type HashInsert(hash_type* hash, const char* key, int data) {
    /* Compute initial hash index */
    size_t index = hash->hash_func(key) % hash->size;
    size_t original_index = index;

    /* Linear probing until we find an empty slot or wrap around */
    do {
        /* Check if current slot is empty */
        if (hash->table[index].key[0] == '\0') {
            /* Found empty slot, insert the data */
            strcpy(hash->table[index].key, key);
            hash->table[index].value = data;
            return SUCCESS;
        }

        /* Move to next slot */
        index = (index + 1) % hash->size;

    } while (index != original_index);

    /* Table is full */
    return ERROR;
}





/* ### Write your code below this line ### */


const hash_data_type* HashFind(const hash_type* hash, const char* key) {
    /* Calculate initial hash index */
    size_t index = hash->hash_func(key) % hash->size;
    size_t prober = index;
   
    /* Probe until we find the key or an empty slot */
    do {
        /* Found matching key */
        if (strcmp(hash->table[prober].key, key) == 0) {
            return &hash->table[prober];
        }
       
        /* Found empty slot - key doesn't exist */
        if (hash->table[prober].key[0] == '\0') {
            return NULL;
        }
       
        /* Move to next slot */
        prober = (prober + 1) % hash->size;
       
    } while (prober != index);  /* Stop if we've checked all slots */
   
    /* Key not found after checking all slots */
    return NULL;
}








