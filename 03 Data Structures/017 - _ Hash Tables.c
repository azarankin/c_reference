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
