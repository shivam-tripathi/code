#include <stdio.h>
#include <stdlib.h>
#define VECTOR_INITIAL_CAPACITY 10

typedef struct{
    int size;
    int capacity;
    int *data;
} Vector;

void init(Vector *vector){
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector-> data = malloc( vector->capacity * sizeof(int) );
}

void doubleCap(Vector *vector){
    vector->capacity *= 2;
    printf("New capacity = %d \n", vector->capacity);
    vector->data = realloc( vector->data, vector->capacity * sizeof(int));
}

void append(Vector *vector, int value){
    if (vector->size == vector->capacity)
        doubleCap(vector);
    vector->data[vector->size++] = value;
}

int getItemAt(Vector *vector, int index){
    if (0 <= index && index < vector->size)
        return vector->data[index];
    else
        fprintf(stderr, "Index out of bounds\n");
}

void set(Vector *vector, int index, int value){
    if (0 <= index && index < vector-> size)
        vector->data[index] = value;
    else
        fprintf(stderr, "Index out of bounds\n");
}


void freeMemory(Vector *vector){
    free(vector->data);
}

void print(Vector *vector){
    int i;
    for(i = 0; i < vector->size; i++)
        printf("%d) %d\n", i+1, vector->data[i]);
}

int main(){
    Vector vector;
    init(&vector);

    int i;
    for(i = 0; i < vector.capacity; i++)
        append(&vector, i*2);
    printf("size : %d, capacity : %d\n", vector.size, vector.capacity);

    print(&vector);

    int temp = vector.capacity;

    for(i = vector.size; i < 3*temp - 2; i++)
        append(&vector, i*3);

    printf("size : %d, capacity : %d\n", vector.size, vector.capacity);

    print(&vector);
}

