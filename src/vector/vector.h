//
// Created by Andrew Nester on 1/10/17.
//

#ifndef DATA_STRUCURES_VECTOR_H
#define DATA_STRUCURES_VECTOR_H

#define INITIAL_CAPACITY 2

#include <stddef.h>
#include <stdbool.h>

typedef struct vectors {
    size_t size;
    size_t capacity;
    int *data;
} vector;

size_t size(vector v);
bool is_empty(vector v);
vector init_vector();
int get(vector v, int i, int *error);
void push_back(vector *v, int val, int *error);
void insert(vector *v, int index, int val, int *error);
void remove(vector *v, int index, int *error);

void __resize(vector *v, int *error);

#endif //DATA_STRUCURES_VECTOR_H
