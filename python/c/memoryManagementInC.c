// Dynamic memory management in c

/*
Functions for memory allocation and management in c are found in <stdlib.h>

void *calloc(int num, int size);
    Allocates an array of num items each of size bytes.

void free(void *address);
    This commands frees the block of memory allocated to the specified address.

void *malloc(int num);
    This function allocates an array of num bytes and leaves them uninitialised.

void *realloc(void *address, int newSize);
    Reallocates memory extending it upto newSize.

At the end of execution, C automatically deallocates previously dynamically
allocated memory. But it is a good practice to deallocate memory using free()
method.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void){
    char name[100];
    char *description;
    strcpy(name, "Firstname Surname");
    printf("Give size of description.\n");
    int size;
    scanf("%d", &size);
    description = malloc(size * sizeof(char));
    // Instead of above, this is also valid: calloc(200, sizeof(char))
    if (description == NULL){
        fprintf(stderr, "Error allocating memory.\n");
    }
    else{
        strcpy(description, "Firstname Surname is not a real name!");
    }

    int l = strlen(description);

    description = realloc(description, (2 * size) * sizeof(char));
    if (description == NULL){
        fprintf(stderr, "Error allocating memory.\n");
    }
    else{
        strcat(description, " The message just got extended.");
    }
    printf("Name of the person is : %s\n", name);
    printf("Something special about the name : %s\n", description);
    printf("Initial lenght of description = %d\n", l);

    // Free the allocated memory.
    free(description);
}

