/*
Please read this introduction to 💥 Data Structures And Algorithms first before you start exercising.
Further, read about ADT (https://en.wikipedia.org/wiki/Abstract_data_type) and emphasize on Common ADTs (https://en.wikipedia.org/wiki/Abstract_data_type#Common_ADTs).
In this chapter, you will learn about and practice Dynamic Memory Allocation.

Study:
💥 Dynamic Memory Allocation
C dynamic memory allocation(https://en.wikipedia.org/wiki/C_dynamic_memory_allocation)
Allocation and release of dynamic memory using C functions (https://man7.org/linux/man-pages/man3/malloc.3.html)
Casting a void pointer to a Struct pointer

Emphasize:
Storage duration: static (https://en.wikipedia.org/wiki/Static_variable), automatic (https://en.wikipedia.org/wiki/Automatic_variable) and dynamic
Data alignment (https://en.wikipedia.org/wiki/Data_structure_alignment)
Pointer Casting (https://en.wikipedia.org/wiki/Pointer_(computer_programming)#Typed_pointers_and_casting)
*/

/*
*Data
the raw information that a user needs to process or store.

*Data Structures
helps to organize the the data for future computing

*Algorithms
used data structures to search or sort the data
manipulate and handle a program's data

*API
data structures and algorithms documented in API
a promise given by the server component that provides the service regarding its actions and output
hides the implementation details while suggesting sufficient instructions and compelling reasons to choose a particular function provided by the server component

*Time and Space Complexity
O() the consume of the task,  the time required to execute a task and the additional space it consumes.
can we use the program in given space and memory.
*/


/*
ADT - Abstract Data Types
Should offer Read Search Add Delete
*/



/*
*Dynamic memory allocation
fixed size allocation
malloc(), calloc(), realloc(), free()

It is crucial to verify whether dynamic allocation completed successfully or not. 
Error Handling
    struct Contact* ptr = malloc(sizeof(*ptr));
    if (ptr == NULL)
    {
         Handle the error: print something, return NULL, etc. 
    }
    
Another common error is when the program doesn't release buffers that are no longer in use. In such a case the memory management subsystem will not be able to supply memory blocks for allocation requests. This is called memory leak.
Unlike static memory allocation, which fixes memory sizes during compile time, dynamic allocation enables resizing data structures like arrays at runtime.
*/






/*
Exercise 1: StringDuplicate

Requirements:
Read the man page strdup (https://man7.org/linux/man-pages/man3/strdup.3.html).
Find and understand the problem in the provided implementation.
Resolve the problem by implementing the correct solution.
*/



#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

char* StringDuplicate(const char* str)
{
    char* duplicate = "";
    size_t length;
    
    
    assert(str != NULL);

    length = strlen(str) + 1;

    duplicate = (char*)malloc(length);
    if (duplicate == (char*)0)
    {
        return (char*)0;
    }

    strcpy(duplicate, str);

    return duplicate;
}





/*
Exercise 2: CreateContact
Note: This is the first of two related exercises.
First, inspect the header file, by clicking the API tab, to see the Contact struct definition and the function declarations.
Requirements:
Allocate memory for a Contact object.
Intialize the object with the given arguments (truncate the name value if necessary).
Return a pointer to the object, or NULL on memory allocation failure.
Constraints:
Use the strncpy function to copy the name value.
*/


//API contact.h

#pragma once

#define NAME_LEN 30

typedef struct Contact
{
    char name[NAME_LEN+1];
    unsigned tel_num;
} contact_type;

contact_type* CreateContact(const char* name, unsigned tel_num);
void DestroyContact(contact_type* contact);



//FUCNTION

#include "contact.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

contact_type* CreateContact(const char* name, unsigned tel_num)
{
    /* ### Write your code below this line ### */
    
    contact_type* new_contact = (contact_type*)malloc(sizeof(contact_type));

    if (new_contact == NULL) {
        return NULL;
    }

    strncpy(new_contact->name, name, NAME_LEN);

    new_contact->name[NAME_LEN] = '\0';

    new_contact->tel_num = tel_num;

    return new_contact;
    
}





/*
Exercise 3: DestroyContact

To finish this exercise, implement the opposite function of releasing a Contact object. Remember to see the function declaration under the API tab.


Requirements:
Free the memory allocated for a contact object, pointed to by the given pointer.
*/

void DestroyContact(contact_type* contact) {
    if (contact != NULL) {
        free(contact);
    }
}


